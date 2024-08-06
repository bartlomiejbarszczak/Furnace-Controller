#include "eeprom.h"


#define EEPROM_ADDRESS		0xA0
#define WRITE_TIMEOUT		5

static I2C_HandleTypeDef eeprom_I2C;
static uint32_t last_write;
static bool is_set = false;


static void eeprom_wait() {
	while (HAL_GetTick() - last_write <= WRITE_TIMEOUT) {

	}
}


void eeprom_init(I2C_HandleTypeDef* eeprom_i2c) {
	eeprom_I2C = *eeprom_i2c;
	is_set = true;
}


HAL_StatusTypeDef eeprom_write(uint32_t address, uint8_t* data, uint32_t size) {
	if (!is_set) return HAL_ERROR;

	HAL_StatusTypeDef res;
	eeprom_wait();

	// fix to use DMA
//	res = HAL_I2C_Mem_Write_DMA(&eeprom_I2C, EEPROM_ADDRESS, address, 1, (uint8_t*)data, size);

	res = HAL_I2C_Mem_Write(&eeprom_I2C, EEPROM_ADDRESS, address, 1, data, size, 10000);
	last_write = HAL_GetTick();

	return res;
}


HAL_StatusTypeDef eeprom_read(uint32_t address, uint8_t* data, uint32_t size) {
	if (!is_set) return HAL_ERROR;

	eeprom_wait();

	// fix to use DMA
//	return HAL_I2C_Mem_Read_DMA(&eeprom_I2C, EEPROM_ADDRESS, address, 1, data, size);

	return HAL_I2C_Mem_Read(&eeprom_I2C, EEPROM_ADDRESS, address, 1, data, size, 10000);
}
