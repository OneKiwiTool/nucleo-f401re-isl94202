#include "bms.h"
#include "isl94202.h"
#include "isl94202_reg.h"
#include <stddef.h>

static const int32_t temp_volt[] = {153, 295, 463, 710, 755};
static const int32_t temp_degc[] = {8000, 50000, 25000, 0, -40000};
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(*array))

// interpolated value of array b at position value_a
int16_t interpolate(const int32_t a[], const int32_t b[], size_t size, uint16_t value_a)
{
    if (a[0] < a[size - 1]) {
        for (unsigned int i = 0; i < size; i++) {
            if (value_a <= a[i]) {
                if (i == 0) {
                    return b[0]; // value_a smaller than first element
                }
                else {
                    return b[i - 1] + (b[i] - b[i - 1]) * (value_a - a[i - 1]) / (a[i] - a[i - 1]);
                }
            }
        }
        return b[size - 1]; // value_a larger than last element
    }
    else {
        for (unsigned int i = 0; i < size; i++) {
            if (value_a >= a[i]) {
                if (i == 0) {
                    return b[0]; // value_a smaller than first element
                }
                else {
                    return b[i - 1] + (b[i] - b[i - 1]) * (value_a - a[i - 1]) / (a[i] - a[i - 1]);
                }
            }
        }
        return b[size - 1]; // value_a larger than last element
    }
}

void bms_setNumCells(uint8_t num)
{
    isl94202_setCellSelect(num);
}

void bms_shutdown(void)
{
    isl94202_powerdown();
}

void bms_chargeSwitch(uint8_t enable)
{
    isl94202_chargeSwitch(enable);
}

void bms_dischargeSwitch(uint8_t enable)
{
    isl94202_dischargeSwitch(enable);
}

#if 0
void bms_updateBalancing(Bms *bms)
{
    uint8_t status;
    uint8_t data = 0;
    status = isl94202_getStatus3();

    /*
     * System scans for voltage, current and temperature measurements happen in different
     * intervals depending on the mode. Cell balancing should be off during voltage scans.
     *
     * Each scan takes max. 1.7 ms. Choosing 16 ms off-time for voltages to settle.
     */

    if (status & ISL94202_STATUS3_INIDLE_MASK) {
        // IDLE mode: Scan every 256 ms
        isl94202_setCellBalanceOnTime(ISL94202_DELAY_MS, 240);
        isl94202_setCellBalanceOffTime(ISL94202_DELAY_MS, 16);
    }
    else if (status & ISL94202_STATUS3_INDOZE_MASK) {
        // DOZE mode: Scan every 512 ms
        isl94202_setCellBalanceOnTime(ISL94202_DELAY_MS, 496);
        isl94202_setCellBalanceOffTime(ISL94202_DELAY_MS, 16);
    }
    else if (!(status & ISL94202_STATUS3_INSLEEP_MASK)) {
        // NORMAL mode: Scan every 32 ms
        isl94202_setCellBalanceOnTime(ISL94202_DELAY_MS, 16);
        isl94202_setCellBalanceOffTime(ISL94202_DELAY_MS, 16);
    }

    /*
     * Balancing is done automatically, just reading status here (even though the datasheet
     * tells that the CBFC register value cannot be used for indication if a cell is
     * balanced at the moment)
     */

    data = isl94202_CellBalanceFETControl();

    bms->status.balancing_status = data;
}
#endif

void bms_updateCurrent(BmsTypeDef *bms)
{
    uint32_t data = 0;
    uint16_t gain = 0;
    uint16_t sign = 0;
    uint16_t adc = 0;

    // gain
    gain = isl94202_getCurrentGain();

    // direction / sign
    sign = isl94202_getCurrentDirection();

    // adc
    // current (A) = value*1.8/(4095*Gain*Rsense)
    // current (mA) = value*1.8*1000/(4095*Gain*Rsense)
    //              = value*1800/(4095*Gain*Rsense) = value*360/(819*Gain*Rsense)
    adc = isl94202_getPackCurrent();
    data = (sign*360*adc)/(819*gain*bms->curr.r_sense);
    bms->curr.i_sense = data;
    bms->curr.v_sense = bms->curr.i_sense*bms->curr.r_sense;
}

void bms_updateVoltages(BmsTypeDef *bms)
{
    uint32_t data = 0;

    data = isl94202_getCellMinVolt();
    // volt_min (V) = value*1.8*8/(4095*3)
    // volt_min (mV) = value*1.8*8*1000/(4095*3) = 4800/4095 = 960/819
    data = data*960/819;
    bms->volt.cell_min = data;

    data = isl94202_getCellMaxVolt();
    // volt_max (V) = value*1.8*8/(4095*3)
    // volt_max (mV) = value*1.8*8*1000/(4095*3) = 4800/4095 = 960/819
    data = data*960/819;
    bms->volt.cell_max = data;

    for (uint8_t i = 0; i < 8; i++) {
        data = isl94202_getCellsVolt(REG_ISL94202_CELL1 + 2*i);
        // volt (V) = value*1.8*8/(4095*3)
        // volt (mV) = value*1.8*8*1000/(4095*3) = 4800/4095 = 960/819
        data = data*960/819;
        bms->volt.cells[i] = data;
    }

    data = isl94202_getPackVolt();
    // volt (V) = value*1.8*32/4095
    // volt (mV) = value*1.8*32*1000/4095 = 57600/4095 = 11520/819
    data = data*11520/819;
    bms->volt.vbat = data;

    data = isl94202_getRGOVolt();
    // volt (V) = value*1.8*2/4095
    // volt (mV) = value*1.8*2*1000/4095 = 3600/4095 = 720/819
    data = data*720/819;
    bms->volt.vrgo = data;

    if (BMS_NUM_CELLS == 7) {
        bms->volt.cells[5] = bms->volt.cells[6];
        bms->volt.cells[6] = bms->volt.cells[7];
        bms->volt.cells[7] = bms->volt.cells[8];
        bms->volt.cells[8] = 0;
    }

    if (BMS_NUM_CELLS == 6) {
        bms->volt.cells[4] = bms->volt.cells[6];
        bms->volt.cells[5] = bms->volt.cells[7];
        bms->volt.cells[6] = bms->volt.cells[8];
        bms->volt.cells[7] = 0;
        bms->volt.cells[8] = 0;
    }

    if (BMS_NUM_CELLS == 5) {
        bms->volt.cells[4] = bms->volt.cells[7];
        bms->volt.cells[5] = bms->volt.cells[8];
        bms->volt.cells[6] = 0;
        bms->volt.cells[7] = 0;
        bms->volt.cells[8] = 0;
    }

    if (BMS_NUM_CELLS == 4) {
        bms->volt.cells[3] = bms->volt.cells[7];
        bms->volt.cells[4] = bms->volt.cells[8];
        bms->volt.cells[5] = 0;
        bms->volt.cells[6] = 0;
        bms->volt.cells[7] = 0;
        bms->volt.cells[8] = 0;
    }

    if (BMS_NUM_CELLS == 3) {
        bms->volt.cells[3] = bms->volt.cells[8];
        bms->volt.cells[4] = 0;
        bms->volt.cells[5] = 0;
        bms->volt.cells[6] = 0;
        bms->volt.cells[7] = 0;
        bms->volt.cells[8] = 0;
    }

    bms->volt.cell_diff = bms->volt.cell_max - bms->volt.cell_min;
    bms->volt.cell_sum = 0;
    for (uint8_t i = 0; i < 8; i++) {
        bms->volt.cell_sum += bms->volt.cells[i];
    }
}

// using default setting TGain = 0 (GAIN = 2) with 22k resistors
void bms_updateTemperatures(BmsTypeDef *bms)
{
    uint32_t adc_raw;

    // Internal temperature
    adc_raw = isl94202_getInternalTemp();
    // Tempv = value*1.8/4095
    // mTempv = value*1.8*1000/4095 = value*360/1365
    bms->temp.it_volt = adc_raw*360/1365;

    // Temp = Tempv*1000/1.8527 - 273.15
    bms->temp.it_degc = 1000*(bms->temp.it_volt/1.8527 - 273.15);

    // External temperature 1
    adc_raw = isl94202_getExternalTemp1();
    bms->temp.xt1_volt = adc_raw*360/1365/2;
    bms->temp.xt1_degc = interpolate(temp_volt, temp_degc, ARRAY_SIZE(temp_degc), bms->temp.xt1_volt);


    // External temperature 2 (used for MOSFET temperature sensing)
    adc_raw = isl94202_getExternalTemp2();
    bms->temp.xt2_volt = adc_raw*360/1365/2;
    bms->temp.xt2_degc = interpolate(temp_volt, temp_degc, ARRAY_SIZE(temp_degc), bms->temp.xt2_volt);
}

#if 0
void bms_getAdcVoltage(Bms *bms)
{
    uint32_t data = 0;
    data = isl94202_getADCVolt();
    if(data < 8191){
        // adc (V) = value*1.8/8191
        // adc (mV) = value*1.8*1000/8191 = 1800/8191
        data = data*1800/8191;
    } else {
        // adc (V) = (value-16384)*1.8/8191
        // adc (mV) = (value-16384)*1.8*1000/8191 = 1800*(value-16384)/8191
        data = 1800*(data-16384)/8191;
    }
    data = data*720/819;
    bms->status.adc_voltage = data;
}
#endif

void bms_updateStatus(BmsTypeDef *bms)
{
    bms->stat0.data = isl94202_getStatus0();
    bms->stat1.data = isl94202_getStatus1();
    bms->stat2.data = isl94202_getStatus2();
    bms->stat3.data = isl94202_getStatus3();
}
