#ifndef ISL94202_H_
#define ISL94202_H_

#include <stdint.h>

void read_register_list(void);
uint8_t isl94202_readEEPROMAccess(void);
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
uint16_t isl94202_getInternalTemp(void);
uint16_t isl94202_getExternalTemp1(void);
uint16_t isl94202_getExternalTemp2(void);
uint16_t isl94202_getPackVolt(void);
uint16_t isl94202_getRGOVolt(void);
uint16_t isl94202_getADCVolt(void);

#endif /* ISL94202_H_ */
