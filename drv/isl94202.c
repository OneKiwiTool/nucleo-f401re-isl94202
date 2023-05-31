#include "isl94202.h"
#include "isl94202_reg.h"
#include "hal_i2c.h"
#include <stdio.h>

#define BMS_ADDR 0x28

void read_register_list(void)
{
    uint8_t data = 0;
    for (uint8_t i = 0; i < 0x4c; i++)
    {
        i2c_read_register(BMS_ADDR, i, &data);
        printf("reg 0x%02x: 0x%02x\n", i, data);
    }
}

// Configuration Registers
// 0x00
uint16_t isl94202_getOverVoltThreshold(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_COV, buffer, 2);
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

// 0x02
uint16_t isl94202_getOverVoltRecoveryThreshold(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_OVR, buffer, 2);
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

// 0x24
void isl94202_setCellBalanceOnTime(uint8_t unit, uint16_t time)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    if (unit > ISL94202_DELAY_MIN || time > 1023) {
        return;
    }
    data = (unit << 0x0A) | time;
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBON, buffer, 2);
}

// 0x26
void isl94202_setCellBalanceOffTime(uint8_t unit, uint16_t time)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    if (unit > ISL94202_DELAY_MIN || time > 1023) {
        return;
    }
    data = (unit << 0x0A) | time;
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBOFF, buffer, 2);
}

// 0x49
uint8_t isl94202_getCellSelect(void)
{
    uint8_t data = 0;
    uint8_t num = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CELL_SEL, &data);
    switch (data) {
        case 0x83:
            num = 3;
            break;
        case 0xC3:
            num = 4;
            break;
        case 0xC7:
            num = 5;
            break;
        case 0xE7:
            num = 6;
            break;
        case 0xEF:
            num = 7;
            break;
        case 0xFF:
            num = 8;
            break;
    }
    return num;
}

void isl94202_setCellSelect(uint8_t num)
{
    uint8_t data = 0;
    if ((num < 3)&&(num > 8))
    {
        return;
    }
    
    switch (num) {
        case 3:
            data = 0x83;
            break;
        case 4:
            data = 0xC3;
            break;
        case 5:
            data = 0xC7;
            break;
        case 6:
            data = 0xE7;
            break;
        case 7:
            data = 0xEF;
            break;
        case 8:
            data = 0xFF;
            break;
    }
    i2c_write_register(BMS_ADDR, REG_ISL94202_CELL_SEL, data);
}

// 0x80
uint8_t isl94202_getStatus0(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_STATUS0, &data);
    return data;
}

// 0x81
uint8_t isl94202_getStatus1(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_STATUS1, &data);
    return data;
}

// 0x82
uint8_t isl94202_getCurrentDirection(void)
{
    uint8_t data = 0;
    uint8_t sign = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_STATUS2, &data);
    sign += (data & ISL94202_STATUS2_CHING_MASK) >> ISL94202_STATUS2_CHING;
    sign -= (data & ISL94202_STATUS2_DCHING_MASK) >> ISL94202_STATUS2_DCHING;
    return sign;
}

// 0x83
uint8_t isl94202_getStatus3(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_STATUS3, &data);
    return data;
}

// 0x84
uint8_t isl94202_CellBalanceFETControl(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CBFC, &data);
    return data;
}

// 0x85
uint16_t isl94202_getCurrentGain(void)
{
    uint8_t data = 0;
    uint16_t gain = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CONTROL0, &data);
    data = (data & ISL94202_CONTROL0_CG_MASK) >> ISL94202_CONTROL0_CG;
    gain = data < 3 ? ISL94202_CurrentGain[data] : 500;
    return gain;
}

// 0x86
uint8_t isl94202_geControl1(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CONTROL1, &data);
    return data;
}

void isl94202_chargeSwitch(uint8_t enable)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CONTROL1, &data);
    if (enable) {
        data |= ISL94202_CONTROL1_CFET_MASK;
    } else {
        data &= ~ISL94202_CONTROL1_CFET_MASK;
    }
    i2c_write_register(BMS_ADDR, REG_ISL94202_CONTROL1, data);
}

void isl94202_dischargeSwitch(uint8_t enable)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CONTROL1, &data);
    if (enable) {
        data |= ISL94202_CONTROL1_DFET_MASK;
    } else {
        data &= ~ISL94202_CONTROL1_DFET_MASK;
    }
    i2c_write_register(BMS_ADDR, REG_ISL94202_CONTROL1, data);
}

// 0x88
void isl94202_powerdown(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CONTROL3, &data);
    data |= ISL94202_CONTROL3_PDWN_MASK;
    i2c_write_register(BMS_ADDR, REG_ISL94202_CONTROL3, data);
}

// 0x89
uint8_t isl94202_getEEPROMAccess(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_EEPROM, &data);
    return data;
}

void isl94202_enableEEPROMAccess(void)
{
    //Set the bit to change to read/write EEPROM
    i2c_write_register(BMS_ADDR, REG_ISL94202_EEPROM, 0x01);
}

void isl94202_disableEEPROMAccess(void)
{
    //Set the bit to change to read/write EEPROM
    i2c_write_register(BMS_ADDR, REG_ISL94202_EEPROM, 0x00);
}

// 0x8A
uint16_t isl94202_getCellMinVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELLMIN, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getCellMaxVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELLMAX, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getPackCurrent(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_IPACK, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getCell1Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL1, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getCell2Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL2, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getCell3Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL3, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getCell4Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL4, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getCell5Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL5, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getCell6Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL6, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}


uint16_t isl94202_getCell7Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL7, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getCell8Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL8, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getCellsVolt(uint8_t reg)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    if((reg>=REG_ISL94202_CELL1)&&(reg<=REG_ISL94202_CELL8))
    {
        i2c_read_registers(BMS_ADDR, reg, buffer, 2);
        buffer[1] = buffer[1] & 0x0F;
        data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    }
    return data;
}


uint16_t isl94202_getInternalTemp(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_IT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getExternalTemp1(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_XT1, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getExternalTemp2(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_XT2, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getPackVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_VBATT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getRGOVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;

    i2c_read_registers(BMS_ADDR, REG_ISL94202_VRGO, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    //RGO_Volt = data*1.8*2/4095
    //RGO_miliVolt = data*1.8*2*1000/4095
    //data = 3600*data/4095;
    return data;
}

uint16_t isl94202_getADCVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_ADC, buffer, 2);
    buffer[1] = buffer[1] & 0x3F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}