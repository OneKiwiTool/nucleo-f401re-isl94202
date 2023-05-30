#ifndef HAL_I2C_H_
#define HAL_I2C_H_

#include <stdint.h>

void i2c_detect(void);
void i2c_read_register(uint8_t device_address, uint8_t register_address, uint8_t* data);
void i2c_write_register(uint8_t device_address, uint8_t register_address, uint8_t data);
void i2c_read_registers(uint8_t device_address, uint8_t register_address, uint8_t* buffer, uint8_t count);
void i2c_write_registers(uint8_t device_address, uint8_t register_address, uint8_t* buffer, uint8_t count);

#endif /* HAL_I2C_H_ */
