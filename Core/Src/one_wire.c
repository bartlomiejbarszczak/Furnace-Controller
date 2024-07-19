#include "one_wire.h"

#define DS18B20_SEARCH_ROM		 	0xf0
#define DS18B20_READ_ROM         	0x33
#define DS18B20_MATCH_ROM      	    0x55
#define DS18B20_SKIP_ROM           	0xcc
#define DS18B20_ALARM_SEARCH	   	0xec
#define DS18B20_CONVERT_T          	0x44
#define DS18B20_WRITE_SCRATCHPAD   	0xeh
#define DS18B20_READ_SCRATCHPAD    	0xbe
#define DS18B20_COPY_SCRACHPAD	   	0x48
#define DS18B20_RECALL_E2		   	0xb8
#define BS18B20_READ_POWER_SUPPLY	0x4h

#define OFFSET						0
#define NO_SENSORS					(uint8_t)2

static TIM_HandleTypeDef OW_Tim;
static UART_HandleTypeDef OW_UART;

static uint8_t ROM_array[2][8] = {
		{0x28, 0x61, 0x2b, 0x0e, 0x00, 0x00, 0x00, 0x77},
		{0x28, 0xea, 0x73, 0x10, 0x00, 0x00, 0x00, 0xe3}
};
static uint8_t retry_measure = 0;
static uint8_t cannot_read_attempt = 0;


static void delay_us(uint32_t delay) {
	__HAL_TIM_SET_COUNTER(&OW_Tim, 0);

	while (__HAL_TIM_GET_COUNTER(&OW_Tim) < delay) {

	}
}


static void set_baudrate(uint32_t baudrate)
{
  OW_UART.Init.BaudRate = baudrate;

  if (HAL_HalfDuplex_Init(&OW_UART) != HAL_OK)
  {
    Error_Handler();
  }
}


static HAL_StatusTypeDef wire_init() {
	uint8_t data_out = 0xF0;
	uint8_t data_in = 0;

	set_baudrate(9600);
	HAL_UART_Transmit(&OW_UART, &data_out, 1, HAL_MAX_DELAY);
	HAL_UART_Receive(&OW_UART, &data_in, 1, HAL_MAX_DELAY);
	set_baudrate(115200);

	if (data_in != 0xf0) return HAL_OK;
	else return HAL_ERROR;
}


static void Write_DQ(int value) {
	if (value) {
		uint8_t data_out = 0xff;
		HAL_UART_Transmit(&OW_UART, &data_out, 1, HAL_MAX_DELAY);
	}
	else {
		uint8_t data_out = 0x0;
		HAL_UART_Transmit(&OW_UART, &data_out, 1, HAL_MAX_DELAY);
	}
}


static uint8_t Read_DQ(void) {
	uint8_t data_out = 0xFF;
	uint8_t data_in = 0;
	HAL_UART_Transmit(&OW_UART, &data_out, 1, HAL_MAX_DELAY);
	HAL_UART_Receive(&OW_UART, &data_in, 1, HAL_MAX_DELAY);

	return data_in & 0x01;
}


static void Write_byte(uint8_t byte) {
	for (uint8_t i = 0; i < 8; i++) {
		Write_DQ(byte & 0x01);
		byte >>= 1;
	}
}


static uint8_t Read_byte() {
	uint8_t byte = 0;

	for (uint8_t i = 0; i < 8; i++) {
		byte >>= 1;
		if (Read_DQ() == 1)
			byte |= 0x80;
		else
			byte |= 0x00;
	}

	return byte;
}


static uint8_t byte_crc(uint8_t crc, uint8_t byte) {
	for (uint8_t i = 0; i < 8; i++) {
		uint8_t b = crc ^ byte;
		crc >>= 1;
		if (b & 0x01)
			crc ^= 0x8c;
		byte >>= 1;
	}
	return crc;
}


static uint8_t Wire_calculate_crc(const uint8_t* data, uint8_t lenght) {
    uint8_t crc = 0;

    for (uint8_t i = 0; i < lenght; i++)
    	crc = byte_crc(crc, data[i]);

    return crc;
}


static HAL_StatusTypeDef DS18B20_convert_temperature(uint8_t* ROM) {
	if (wire_init() != HAL_OK) {
			return HAL_ERROR;
	}
	Write_byte(DS18B20_MATCH_ROM);

	for (uint8_t i = 0; i < 8; i++) {
		Write_byte(*(ROM + i));
	}

	Write_byte(DS18B20_CONVERT_T);

	delay_us(800);

	return HAL_OK;
}


static HAL_StatusTypeDef DS18B20_read_scrachpad(uint8_t* ROM, uint16_t* temperature, uint8_t* sign) {
	uint8_t crc;
	uint8_t data[9];

	if (wire_init() != HAL_OK)
		return HAL_ERROR;

	Write_byte(DS18B20_MATCH_ROM);

	for (uint8_t i = 0; i < 8; i++) {
		Write_byte(*(ROM + i));
	}
	Write_byte(DS18B20_READ_SCRATCHPAD);

	for (uint8_t i = 0; i < 9; i++) {
		data[i] = Read_byte();
	}
	crc = Wire_calculate_crc(data, 8);

	if (crc != data[8])
		return HAL_ERROR;

	*temperature = ((data[1] << 13) | (data[0] << 5)) >> 5;
	*sign = data[1] & 0xf8;

	return HAL_OK;
}




void OW_init(UART_HandleTypeDef *one_wire_UART, TIM_HandleTypeDef *one_wire_TIM) {
	OW_UART = *one_wire_UART;
	OW_Tim = *one_wire_TIM;
}


HAL_StatusTypeDef wire_read_ROM(uint8_t* data) {
	uint8_t crc = 0;

	if (wire_init() != HAL_OK) {
		return HAL_ERROR;
	}
	Write_byte(DS18B20_READ_ROM);

	for (int i = 0; i < 8; i++) {
		*(data + i) = Read_byte();
	}

	crc = Wire_calculate_crc(data, 7);

	if (crc != *(data + 7))
		return HAL_ERROR;

	return HAL_OK;
}


HAL_StatusTypeDef DS18B20_get_temperature(uint8_t* ROM, float* temperature, uint8_t user_offset) {
	uint16_t raw_temperature;
	uint8_t sign;

	if (DS18B20_convert_temperature(ROM) != HAL_OK)
		return HAL_ERROR;

	if (DS18B20_read_scrachpad(ROM, &raw_temperature, &sign) != HAL_OK)
		return HAL_ERROR;

	if (sign) {
		raw_temperature = (~(raw_temperature)) + 1;
	}

	*temperature = (raw_temperature / 16.0);

	if (*temperature == 85.0 && retry_measure < 3) {
		retry_measure++;
		DS18B20_get_temperature(ROM, temperature, user_offset);
	}
	retry_measure = 0;

	if (sign){
		*temperature += (float)(OFFSET + user_offset);
	}
	else {
		*temperature -= (float)(OFFSET + user_offset);
	}

	return HAL_OK;
}


void get_all_temperature(float* temperature_array, uint8_t user_offset) {
	for (uint8_t i = 0; i < NO_SENSORS; i++) {
		while(DS18B20_get_temperature(ROM_array[i], (temperature_array + i), user_offset) != HAL_OK && cannot_read_attempt < 10) {
			cannot_read_attempt++;
		}
		if (cannot_read_attempt == 10) {
			*(temperature_array + i) = 500.0;
		}
		cannot_read_attempt = 0;
	}
}


