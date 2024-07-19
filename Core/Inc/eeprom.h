#ifndef INC_EEPROM_H_
#define INC_EEPROM_H_

#include "stm32l4xx.h"
#include "main.h"
#include "i2c.h"
#include "stdbool.h"


void eeprom_init(I2C_HandleTypeDef* eeprom_i2c);
HAL_StatusTypeDef eeprom_write(uint32_t address, const uint8_t* data, uint32_t size);
HAL_StatusTypeDef eeprom_read(uint32_t address, uint8_t* data, uint32_t size);


#endif /* INC_EEPROM_H_ */
