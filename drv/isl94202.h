#ifndef ISL94202_H_
#define ISL94202_H_

#include <stdint.h>

void read_register_list(void);

// 0x00
uint16_t isl94202_getOverVoltThreshold(void);

// 0x02
uint16_t isl94202_getOverVoltRecoveryThreshold(void);

// 0x24
void isl94202_setCellBalanceOnTime(uint8_t unit, uint16_t time);

// 0x26
void isl94202_setCellBalanceOffTime(uint8_t unit, uint16_t time);

// 0x49
uint8_t isl94202_getCellSelect(void);
void isl94202_setCellSelect(uint8_t num);

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
uint8_t isl94202_CellBalanceFETControl(void);

// 0x85
uint16_t isl94202_getCurrentGain(void);

// 0x86
uint8_t isl94202_geControl1(void);
void isl94202_chargeSwitch(uint8_t enable);
void isl94202_dischargeSwitch(uint8_t enable);

// 0x88
void isl94202_powerdown(void);

// 0x89
uint8_t isl94202_getEEPROMAccess(void);
void isl94202_enableEEPROMAccess(void);
void isl94202_disableEEPROMAccess(void);

// Data Registers
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
