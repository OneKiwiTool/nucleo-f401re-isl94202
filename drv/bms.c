#include "bms.h"
#include "isl94202.h"
#include "isl94202_reg.h"

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

void bms_updateBalancing(Bms *bms)
{
    uint8_t status;
    uint8_t data = 0;
    status = isl94202_getStatus3();
    //isl94202_read_bytes(ISL94202_STAT3, &stat3, 1);

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

void bms_getCurrent(Bms *bms)
{
    uint8_t data = 0;
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
    data = (sign*360*adc)/(819*gain*bms->conf.shunt_res_mOhm);
    bms->status.pack_current = data;
}

void bms_getVoltages(Bms *bms)
{
    uint16_t data = 0;

    data = isl94202_getCellMinVolt();
    // volt_min (V) = value*1.8*8/(4095*3)
    // volt_min (mV) = value*1.8*8*1000/(4095*3) = 4800/4095 = 960/819
    data = data*960/819;
    bms->status.cell_voltage_min = data;

    data = isl94202_getCellMaxVolt();
    // volt_max (V) = value*1.8*8/(4095*3)
    // volt_max (mV) = value*1.8*8*1000/(4095*3) = 4800/4095 = 960/819
    data = data*960/819;
    bms->status.cell_voltage_max = data;

    for (uint8_t i = 0; i < BMS_NUM_CELLS; i++) {
        data = isl94202_getCellsVolt(REG_ISL94202_CELL1 + 2*i);
        // volt (V) = value*1.8*8/(4095*3)
        // volt (mV) = value*1.8*8*1000/(4095*3) = 4800/4095 = 960/819
        data = data*960/819;
        bms->status.cell_voltages[i] = data;
    }

    data = isl94202_getPackVolt();
    // volt (V) = value*1.8*32/4095
    // volt (mV) = value*1.8*32*1000/4095 = 57600/4095 = 11520/819
    data = data*11520/819;
    bms->status.pack_voltage = data;

    data = isl94202_getRGOVolt();
    // volt (V) = value*1.8*2/4095
    // volt (mV) = value*1.8*2*1000/4095 = 3600/4095 = 720/819
    data = data*720/819;
    bms->status.vrgo_voltage = data;
}

void bms_getAdcVoltage(Bms *bms)
{
    uint16_t data = 0;
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

void bms_updateErrorFlags(Bms *bms)
{
    uint32_t error_flags = 0;
    uint8_t stat0 = 0;
    uint8_t stat1 = 0;
    uint8_t ctrl1 = 0;
    stat0 = isl94202_getStatus0();
    stat1 = isl94202_getStatus1();
    ctrl1 = isl94202_geControl1();

    if (stat0 & ISL94202_STATUS0_OVF_MASK)
        error_flags |= 1U << BMS_ERR_CELL_OVERVOLTAGE;
    if (stat0 & ISL94202_STATUS0_UVF_MASK)
        error_flags |= 1U << BMS_ERR_CELL_UNDERVOLTAGE;
    if (stat0 & ISL94202_STATUS0_DOTF_MASK)
        error_flags |= 1U << BMS_ERR_DIS_OVERTEMP;
    if (stat0 & ISL94202_STATUS0_DUTF_MASK)
        error_flags |= 1U << BMS_ERR_DIS_UNDERTEMP;
    if (stat0 & ISL94202_STATUS0_COTF_MASK)
        error_flags |= 1U << BMS_ERR_CHG_OVERTEMP;
    if (stat0 & ISL94202_STATUS0_CUTF_MASK)
        error_flags |= 1U << BMS_ERR_CHG_UNDERTEMP;
    
    if (stat1 & ISL94202_STATUS1_IOTF_MASK)
        error_flags |= 1U << BMS_ERR_INT_OVERTEMP;
    if (stat1 & ISL94202_STATUS1_COCF_MASK)
        error_flags |= 1U << BMS_ERR_CHG_OVERCURRENT;
    if (stat1 & ISL94202_STATUS1_DOCF_MASK)
        error_flags |= 1U << BMS_ERR_DIS_OVERCURRENT;
    if (stat1 & ISL94202_STATUS1_DSCF_MASK)
        error_flags |= 1U << BMS_ERR_SHORT_CIRCUIT;
    if (stat1 & ISL94202_STATUS1_CELLF_MASK)
        error_flags |= 1U << BMS_ERR_CELL_FAILURE;
    if (stat1 & ISL94202_STATUS1_OPENF_MASK)
        error_flags |= 1U << BMS_ERR_OPEN_WIRE;

    if (!(ctrl1 & ISL94202_CONTROL1_DFET_MASK)
        && (bms->status.state == BMS_STATE_DIS || bms->status.state == BMS_STATE_NORMAL))
    {
        error_flags |= 1U << BMS_ERR_DIS_OFF;
    }

    if (!(ctrl1 & ISL94202_CONTROL1_CFET_MASK)
        && (bms->status.state == BMS_STATE_CHG || bms->status.state == BMS_STATE_NORMAL))
    {
        error_flags |= 1U << BMS_ERR_CHG_OFF;
    }

    bms->status.error_flags = error_flags;
}