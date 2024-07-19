#ifndef INC_DS18B20_H_
#define INC_DS18B20_H_

#include "main.h"




void OW_init(UART_HandleTypeDef *one_wire_UART, TIM_HandleTypeDef *one_wire_TIM);
HAL_StatusTypeDef wire_read_ROM(uint8_t* data);
HAL_StatusTypeDef DS18B20_get_temperature(uint8_t* ROM, float* temperature, uint8_t offset);
void get_all_temperature(float* temperature_array, uint8_t user_offset);


#endif /* INC_DS18B20_H_ */
