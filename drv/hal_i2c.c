#include "hal_i2c.h"
#include "main.h"
#include <stdio.h>

extern I2C_HandleTypeDef hi2c1;

void i2c_detect(void)
{
	uint8_t devices = 0u;
	//extern I2C_HandleTypeDef hi2c1;

	printf("Searching for I2C devices on the bus...\n");
	printf("     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\n");
	printf("00:         ");

	/* Values outside 0x03 and 0x77 are invalid. */
	for (uint8_t i = 0x03u; i < 0x78u; i++)
	{
		uint8_t address = i << 1u ;
		if( i%16 == 0){
			printf("\n%02x:", i);
		}
		/* In case there is a positive feedback, print it out. */
		if (HAL_OK == HAL_I2C_IsDeviceReady(&hi2c1, address, 3u, 10u))
		{
			printf(" %02x", i);
			devices++;
		} else {
			printf(" --");
		}
	}
	/* Feedback of the total number of devices. */
	if (0u == devices)
	{
		printf("\nNo device found.\n");
	}
	else
	{
		printf("\nTotal found devices: %d\n", devices);
	}
}

void i2c_read_register(uint8_t device_address, uint8_t register_address, uint8_t* data)
{
	uint8_t address = device_address << 1;
	HAL_I2C_Master_Transmit(&hi2c1, address, &register_address, 1, 1000);
	HAL_I2C_Master_Receive(&hi2c1, address, data, 1, 1000);
}

void i2c_write_register(uint8_t device_address, uint8_t register_address, uint8_t data)
{
	uint8_t address = device_address << 1;
    uint8_t bytes[2] = {register_address, data};
    HAL_I2C_Master_Transmit(&hi2c1, address, bytes, 2, 1000);
}

void i2c_read_registers(uint8_t device_address, uint8_t register_address, uint8_t* buffer, uint8_t count)
{
	uint8_t address = device_address << 1;
	/* Send register address */
	HAL_I2C_Master_Transmit(&hi2c1, address, &register_address, 1, 1000);
	/* Receive multiple byte */
	HAL_I2C_Master_Receive(&hi2c1, address, buffer, count, 1000);

}

void i2c_write_registers(uint8_t device_address, uint8_t register_address, uint8_t* buffer, uint8_t count)
{
	uint8_t address = device_address << 1;
	/* Try to transmit via I2C */
	HAL_I2C_Mem_Write(&hi2c1, address, register_address, register_address > 0xFF ? I2C_MEMADD_SIZE_16BIT : I2C_MEMADD_SIZE_8BIT, buffer, count, 1000);
}
