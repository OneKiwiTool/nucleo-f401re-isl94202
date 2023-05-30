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
uint16_t isl94202_getOverVoltThreshold(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_COV, buffer, 2);
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

uint16_t isl94202_getOverVoltRecoveryThreshold(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_OVR, buffer, 2);
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    return data;
}

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

#if 0
void isl94202_writeEEPROM(uint8_t reg, uint8_t value)
{
	if ((reg > 0x58 && reg < 0x7F) || reg > 0xAB)
		return;
	//^ Datasheet mentions a warning not to write to these areas as they are for factory use

	isl94202_enableEEPROMAccess();
	uint8_t buffer[4];    //We need to write in pages
	uint8_t i;
	uint8_t base = reg & 0xFC;
	buffer[0] = I2C_readReg8(slaveAdd, base);
	HAL_Delay(1000);        //delay to allow EEPROM refresh
	I2C_readMany(slaveAdd, base, 4, buffer);

	//We have read in the buffer
	//Update the buffer
	buffer[(uint8_t) (reg & 0x03)] = value;

	I2C_writeReg8(slaveAdd, base, buffer[0]);
	HAL_Delay(35000);        //delay to allow EEPROM write

	//^Special case for first uint8_t causing EEPROM reload
	for (i = 0; i < 4; i++)
	{
	I2C_writeReg8(slaveAdd, base + i, buffer[i]);
	HAL_Delay(35000);    //35ms
	//pause for EEPROM write
	}

	isl94202_disableEEPROMAccess();
}
#endif


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
    //CellVolt = data*1.8*8/(4095*3)
    //CellmVolt = data*1.8*8*1000/(4095*3) = 4800*data/4095
    //data = 4800*data/4095;
    return data;
}

uint16_t isl94202_getCell2Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL2, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    //CellVolt = data*1.8*8/(4095*3)
    //CellmVolt = data*1.8*8*1000/(4095*3) = 4800*data/4095
    //data = 4800*data/4095;
    return data;
}

uint16_t isl94202_getCell3Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL3, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    //CellVolt = data*1.8*8/(4095*3)
    //CellmVolt = data*1.8*8*1000/(4095*3) = 4800*data/4095
    //data = 4800*data/4095;
    return data;
}

uint16_t isl94202_getCell4Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL4, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    //CellVolt = data*1.8*8/(4095*3)
    //CellmVolt = data*1.8*8*1000/(4095*3) = 4800*data/4095
    //data = 4800*data/4095;
    return data;
}

uint16_t isl94202_getCell5Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL5, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    //CellVolt = data*1.8*8/(4095*3)
    //CellmVolt = data*1.8*8*1000/(4095*3) = 4800*data/4095
    //data = 4800*data/4095;
    return data;
}

uint16_t isl94202_getCell6Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL6, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    //CellVolt = data*1.8*8/(4095*3)
    //CellmVolt = data*1.8*8*1000/(4095*3) = 4800*data/4095
    //data = 4800*data/4095;
    return data;
}


uint16_t isl94202_getCell7Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL7, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    //CellVolt = data*1.8*8/(4095*3)
    //CellmVolt = data*1.8*8*1000/(4095*3) = 4800*data/4095
    //data = 4800*data/4095;
    return data;
}

uint16_t isl94202_getCell8Volt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_CELL8, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    //CellVolt = data*1.8*8/(4095*3)
    //CellmVolt = data*1.8*8*1000/(4095*3) = 4800*data/4095
    //data = 4800*data/4095;
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

/*
 * return: mili voltage (mV)
*/
uint16_t isl94202_getPackVolt(void)
{
    uint8_t buffer[2];
    uint16_t data = 0;
    i2c_read_registers(BMS_ADDR, REG_ISL94202_VBATT, buffer, 2);
    buffer[1] = buffer[1] & 0x0F;
    data = (uint16_t)((buffer[1] << 8)|buffer[0]);
    //PackVolt = data*1.8*32/4095
    //PackmVolt = data*1.8*32*1000/4095
    //data = 57600*data/4095;
    return data;
}

/*
 * return: mili voltage (mV)
*/
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
