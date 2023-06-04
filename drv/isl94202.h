#ifndef ISL94202_H_
#define ISL94202_H_

#include <stdint.h>

void read_register_list(void);

// Configuration Registers
// 0x00
uint16_t isl94202_getOverVolt(void);
void isl94202_setOverVolt(uint16_t data);

// 0x02
uint16_t isl94202_getOverVoltRecovery(void);
void isl94202_setOverVoltRecovery(uint16_t data);

// 0x04
uint16_t isl94202_getUnderVolt(void);
void isl94202_setUnderVolt(uint16_t data);

// 0x06
uint16_t isl94202_getUnderVoltRecovery(void);
void isl94202_setUnderVoltRecovery(uint16_t data);

// 0x08
uint16_t isl94202_getOverVoltLockout(void);
void isl94202_setOverVoltLockout(uint16_t data);

// 0x0A
uint16_t isl94202_getUnderVoltLockout(void);
void isl94202_setUnderVoltLockout(uint16_t data);

// 0x0C
uint16_t isl94202_getEndOfCharge(void);
void isl94202_setEndOfCharge(uint16_t data);

// 0x0E
uint16_t isl94202_getLowVoltageCharge(void);
void isl94202_setLowVoltageCharge(uint16_t data);

// 0x10
uint16_t isl94202_getOverVoltDelay(void);
void isl94202_setOverVoltDelay(uint16_t data);

// 0x12
uint16_t isl94202_getUnderVoltDelay(void);
void isl94202_setUnderVoltDelay(uint16_t data);

// 0x14 
uint16_t isl94202_getOpenWireTiming(void);
void isl94202_setOpenWireTiming(uint16_t data);

// 0x16 
uint16_t isl94202_getDischargeOverCurrentTimer(void);
void isl94202_setDischargeOverCurrentTimer(uint16_t data);

// 0x18
uint16_t isl94202_getChargeOverCurrentTimer(void);
void isl94202_setChargeOverCurrentTimer(uint16_t data);

// 0x1A 
uint16_t isl94202_getDischargeShortCircuitTimer(void);
void isl94202_setDischargeShortCircuitTimer(uint16_t data);

// 0x1C
uint16_t isl94202_getCBMinVolt(void);
void isl94202_setCBMinVolt(uint16_t data);

// 0x1E
uint16_t isl94202_getCBMaxVolt(void);
void isl94202_setCBMaxVolt(uint16_t data);

// 0x20
uint16_t isl94202_getCBMinDelta(void);
void isl94202_setCBMinDelta(uint16_t data);

// 0x22
uint16_t isl94202_getCBMaxDelta(void);
void isl94202_setCBMaxDelta(uint16_t data);

// 0x24
uint16_t isl94202_getCellBalanceOn(void);
void isl94202_setCellBalanceOn(uint16_t data);
void isl94202_setCellBalanceOnTime(uint8_t unit, uint16_t time);

// 0x26
uint16_t isl94202_getCellBalanceOff(void);
void isl94202_setCellBalanceOff(uint16_t data);
void isl94202_setCellBalanceOffTime(uint8_t unit, uint16_t time);

// Ox28
uint16_t isl94202_getCBUnderTemp(void);
void isl94202_setCBUnderTemp(uint16_t data);

// Ox2A
uint16_t isl94202_getCBUnderTempRecovery(void);
void isl94202_setCBUnderTempRecovery(uint16_t data);

// Ox2C
uint16_t isl94202_getCBOverTemp(void);
void isl94202_setCBOverTemp(uint16_t data);

// Ox2E
uint16_t isl94202_getCBOverTempRecovery(void);
void isl94202_setCBOverTempRecovery(uint16_t data);

// Ox30
uint16_t isl94202_getChargeOverTemp(void);
void isl94202_setChargeOverTemp(uint16_t data);

// Ox32
uint16_t isl94202_getChargeOverTempRecovery(void);
void isl94202_setChargeOverTempRecovery(uint16_t data);

// Ox34
uint16_t isl94202_getChargeUnderTemp(void);
void isl94202_setChargeUnderTemp(uint16_t data);

// Ox36
uint16_t isl94202_getChargeUnderTempRecovery(void);
void isl94202_setChargeUnderTempRecovery(uint16_t data);

// Ox38
uint16_t isl94202_getDischargeOverTemp(void);
void isl94202_setDischargeOverTemp(uint16_t data);

// Ox3A
uint16_t isl94202_getDischargeOverTempRecovery(void);
void isl94202_setDischargeOverTempRecovery(uint16_t data);

// Ox3C
uint16_t isl94202_getDischargeUnderTemp(void);
void isl94202_setDischargeUnderTemp(uint16_t data);

// Ox3E
uint16_t isl94202_getDischargeUnderTempRecovery(void);
void isl94202_setDischargeUnderTempRecovery(uint16_t data);

// Ox40
uint16_t isl94202_getInterOverTemp(void);
void isl94202_setInterOverTemp(uint16_t data);

// Ox42
uint16_t isl94202_getInterOverTempRecovery(void);
void isl94202_setInterOverTempRecovery(uint16_t data);

// 0x44
uint16_t isl94202_getSleepLevelVolt(void);
void isl94202_setSleepLevelVolt(uint16_t data);

// 0x46
uint16_t isl94202_getWatchdogTimer(void);
void isl94202_setWatchdogTimer(uint16_t data);

// 0x48
uint8_t isl94202_getModeTimer(void);
void isl94202_setModeTimer(uint8_t data);

// 0x49
uint8_t isl94202_getCellSelect(void);
void isl94202_setCellSelect(uint8_t num);

// 0x4A
uint8_t isl94202_getSetup0(void);
void isl94202_setSetup0(uint8_t data);

// 0x4B
uint8_t isl94202_getSetup1(void);
void isl94202_setSetup1(uint8_t data);

// 0x50 - 0x57
uint8_t isl94202_readUserEEPROM(uint8_t reg);
void isl94202_writeUserEEPROM(uint8_t reg, uint8_t data);

// 0x80
uint8_t isl94202_getStatus0(void);

// 0x81
uint8_t isl94202_getStatus1(void);

// 0x82
uint8_t isl94202_getStatus2(void);
uint8_t isl94202_getCurrentDirection(void);

// 0x83
uint8_t isl94202_getStatus3(void);

// 0x84
uint8_t isl94202_getCellBalanceFETControl(void);
void isl94202_setCellBalanceFETControl(uint8_t data);

// 0x85
uint8_t isl94202_geControl0(void);
void isl94202_setControl0(uint8_t data);
uint16_t isl94202_getCurrentGain(void);

// 0x86
uint8_t isl94202_geControl1(void);
void isl94202_setControl1(uint8_t data);
void isl94202_chargeSwitch(uint8_t enable);
void isl94202_dischargeSwitch(uint8_t enable);

// 0x87
uint8_t isl94202_getControl2(void);
void isl94202_setControl2(uint8_t data);

// 0x88
uint8_t isl94202_getControl3(void);
void isl94202_setControl3(uint8_t data);
void isl94202_powerdown(void);

// 0x89
uint8_t isl94202_getEEPROMAccess(void);
void isl94202_enableEEPROMAccess(void);
void isl94202_disableEEPROMAccess(void);

// 0x8A - 0xAA
uint16_t isl94202_getCellMinVolt(void);
uint16_t isl94202_getCellMaxVolt(void);
uint16_t isl94202_getPackCurrent(void);
uint16_t isl94202_getCell1Volt(void);
uint16_t isl94202_getCell2Volt(void);
uint16_t isl94202_getCell3Volt(void);
uint16_t isl94202_getCell4Volt(void);
uint16_t isl94202_getCell5Volt(void);
uint16_t isl94202_getCell6Volt(void);
uint16_t isl94202_getCell7Volt(void);
uint16_t isl94202_getCell8Volt(void);
uint16_t isl94202_getCellsVolt(uint8_t reg);
uint16_t isl94202_getInternalTemp(void);
uint16_t isl94202_getExternalTemp1(void);
uint16_t isl94202_getExternalTemp2(void);
uint16_t isl94202_getPackVolt(void);
uint16_t isl94202_getRGOVolt(void);
uint16_t isl94202_getADCVolt(void);


static const uint16_t ISL94202_CurrentGain[] = {50, 5, 500, 500};

// Scale Value for delay times (first 2 bytes)
#define ISL94202_DELAY_US  (0U)
#define ISL94202_DELAY_MS  (1U)
#define ISL94202_DELAY_S   (2U)
#define ISL94202_DELAY_MIN (3U)

#endif /* ISL94202_H_ */
