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
uint16_t isl94202_getOverVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_COV, buffer, 2);
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setOverVolt(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_COV, buffer, 2);
}

// 0x02
uint16_t isl94202_getOverVoltRecovery(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_OVR, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setOverVoltRecovery(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_OVR, buffer, 2);
}

// 0x04
uint16_t isl94202_getUnderVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_UVL, buffer, 2);
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setUnderVolt(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_UVL, buffer, 2);
}

// 0x06
uint16_t isl94202_getUnderVoltRecovery(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_UVR, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setUnderVoltRecovery(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_UVR, buffer, 2);
}

// 0x08
uint16_t isl94202_getOverVoltLockout(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_OVLO, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setOverVoltLockout(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_OVLO, buffer, 2);
}

// 0x0A
uint16_t isl94202_getUnderVoltLockout(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_UVLO, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setUnderVoltLockout(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_UVLO, buffer, 2);
}

// 0x0C
uint16_t isl94202_getEndOfCharge(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_EOC, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setEndOfCharge(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_EOC, buffer, 2);
}

// 0x0E
uint16_t isl94202_getLowVoltageCharge(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_LVCL, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setLowVoltageCharge(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_LVCL, buffer, 2);
}

// 0x10
uint16_t isl94202_getOverVoltDelay(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_OVDT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setOverVoltDelay(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_OVDT, buffer, 2);
}

// 0x12
uint16_t isl94202_getUnderVoltDelay(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_UVDT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setUnderVoltDelay(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_UVDT, buffer, 2);
}

// 0x14 
uint16_t isl94202_getOpenWireTiming(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_OWT, buffer, 2);
    buffer[1] = buffer[1] & 0x03;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setOpenWireTiming(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_OWT, buffer, 2);
}

// 0x16 
uint16_t isl94202_getDischargeOverCurrentTimer(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_DOCT, buffer, 2);
    buffer[1] = buffer[1] & 0x7F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setDischargeOverCurrentTimer(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_DOCT, buffer, 2);
}

// 0x18
uint16_t isl94202_getChargeOverCurrentTimer(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_COCT, buffer, 2);
    buffer[1] = buffer[1] & 0x7F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setChargeOverCurrentTimer(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_COCT, buffer, 2);
}

// 0x1A 
uint16_t isl94202_getDischargeShortCircuitTimer(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_DSCT, buffer, 2);
    buffer[1] = buffer[1] & 0x7F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setDischargeShortCircuitTimer(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_DSCT, buffer, 2);
}

// 0x1C
uint16_t isl94202_getCBMinVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBMIN, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCBMinVolt(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBMIN, buffer, 2);
}

// 0x1E
uint16_t isl94202_getCBMaxVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBMAX, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCBMaxVolt(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBMAX, buffer, 2);
}

// 0x20
uint16_t isl94202_getCBMinDelta(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBMIND, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCBMinDelta(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBMIND, buffer, 2);
}

// 0x22
uint16_t isl94202_getCBMaxDelta(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBMAXD, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCBMaxDelta(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBMAXD, buffer, 2);
}

// 0x24
uint16_t isl94202_getCellBalanceOn(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBON, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCellBalanceOn(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBON, buffer, 2);
}

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
uint16_t isl94202_getCellBalanceOff(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBOFF, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCellBalanceOff(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBOFF, buffer, 2);
}

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

// Ox28
uint16_t isl94202_getCBUnderTemp(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBUT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCBUnderTemp(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBUT, buffer, 2);
}

// Ox2A
uint16_t isl94202_getCBUnderTempRecovery(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBUTR, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCBUnderTempRecovery(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBUTR, buffer, 2);
}

// Ox2C
uint16_t isl94202_getCBOverTemp(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBOT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCBOverTemp(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBOT, buffer, 2);
}

// Ox2E
uint16_t isl94202_getCBOverTempRecovery(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CBOTR, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setCBOverTempRecovery(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CBOTR, buffer, 2);
}

// Ox30
uint16_t isl94202_getChargeOverTemp(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_COT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setChargeOverTemp(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_COT, buffer, 2);
}

// Ox32
uint16_t isl94202_getChargeOverTempRecovery(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_COTR, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setChargeOverTempRecovery(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_COTR, buffer, 2);
}

// Ox34
uint16_t isl94202_getChargeUnderTemp(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CUT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setChargeUnderTemp(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CUT, buffer, 2);
}

// Ox36
uint16_t isl94202_getChargeUnderTempRecovery(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CUTR, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setChargeUnderTempRecovery(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_CUTR, buffer, 2);
}

// Ox38
uint16_t isl94202_getDischargeOverTemp(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_DOT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setDischargeOverTemp(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_DOT, buffer, 2);
}

// Ox3A
uint16_t isl94202_getDischargeOverTempRecovery(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_DOTR, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setDischargeOverTempRecovery(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_DOTR, buffer, 2);
}

// Ox3C
uint16_t isl94202_getDischargeUnderTemp(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_DUT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setDischargeUnderTemp(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_DUT, buffer, 2);
}

// Ox3E
uint16_t isl94202_getDischargeUnderTempRecovery(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_DUTR, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setDischargeUnderTempRecovery(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_DUTR, buffer, 2);
}

// Ox40
uint16_t isl94202_getInterOverTemp(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_IOT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setInterOverTemp(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_IOT, buffer, 2);
}

// Ox42
uint16_t isl94202_getInterOverTempRecovery(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_IOTR, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setInterOverTempRecovery(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_IOTR, buffer, 2);
}

// 0x44
uint16_t isl94202_getSleepLevelVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_SLV, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setSleepLevelVolt(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_SLV, buffer, 2);
}

// 0x46
uint16_t isl94202_getWatchdogTimer(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_SLT_WDT, buffer, 2);
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

void isl94202_setWatchdogTimer(uint16_t data)
{
    uint8_t buffer[2];
    buffer[0] = data & 0xFF;
    buffer[1] = data >> 8;
    i2c_write_registers(BMS_ADDR, REG_ISL94202_SLT_WDT, buffer, 2);
}

// 0x48
uint8_t isl94202_getModeTimer(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_MODE_TIMER, &data);
    return data;
}

void isl94202_setModeTimer(uint8_t data)
{
    i2c_write_register(BMS_ADDR, REG_ISL94202_MODE_TIMER, data);
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

// 0x4A
uint8_t isl94202_getSetup0(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_SETUP0, &data);
    return data;
}

void isl94202_setSetup0(uint8_t data)
{
    i2c_write_register(BMS_ADDR, REG_ISL94202_SETUP0, data);
}

// 0x4B
uint8_t isl94202_getSetup1(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_SETUP1, &data);
    return data;
}

void isl94202_setSetup1(uint8_t data)
{
    i2c_write_register(BMS_ADDR, REG_ISL94202_SETUP1, data);
}

// 0x50 - 0x57
uint8_t isl94202_readUserEEPROM(uint8_t reg)
{
	uint8_t data = 0;
    if ((reg>=0x50) && (reg<=0x57)){
        isl94202_enableEEPROMAccess();
        i2c_read_register(BMS_ADDR, reg, &data);
        isl94202_disableEEPROMAccess();
    }
    return data;
}

void isl94202_writeUserEEPROM(uint8_t reg, uint8_t data)
{
    if ((reg>=0x50) && (reg<=0x57)){
        isl94202_enableEEPROMAccess();
        i2c_write_register(BMS_ADDR, reg, data);
        isl94202_disableEEPROMAccess();
    }
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
uint8_t isl94202_getStatus2(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_STATUS2, &data);
    return data;
}

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
uint8_t isl94202_getCellBalanceFETControl(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CBFC, &data);
    return data;
}

void isl94202_setCellBalanceFETControl(uint8_t data)
{
    i2c_write_register(BMS_ADDR, REG_ISL94202_CBFC, data);
}

// 0x85
uint8_t isl94202_geControl0(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CONTROL0, &data);
    return data;
}

void isl94202_setControl0(uint8_t data)
{
    i2c_write_register(BMS_ADDR, REG_ISL94202_CONTROL0, data);
}

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

void isl94202_setControl1(uint8_t data)
{
    i2c_write_register(BMS_ADDR, REG_ISL94202_CONTROL1, data);
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

// 0x87
uint8_t isl94202_getControl2(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CONTROL2, &data);
    return data;
}

void isl94202_setControl2(uint8_t data)
{
    i2c_write_register(BMS_ADDR, REG_ISL94202_CONTROL2, data);
}

// 0x88
uint8_t isl94202_getControl3(void)
{
    uint8_t data = 0;
    i2c_read_register(BMS_ADDR, REG_ISL94202_CONTROL3, &data);
    return data;
}

void isl94202_setControl3(uint8_t data)
{
    i2c_write_register(BMS_ADDR, REG_ISL94202_CONTROL3, data);
}

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
    i2c_write_register(BMS_ADDR, REG_ISL94202_EEPROM, 0x01);
}

void isl94202_disableEEPROMAccess(void)
{
    i2c_write_register(BMS_ADDR, REG_ISL94202_EEPROM, 0x00);
}

// 0x8A - 0xAA
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
