#include "isl94202.h"
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
