#include "fire_controller_configuration.h"


static bool has_changes = false;


void serialize_FCC(FCC* data, uint8_t* buffer) {
	memcpy(buffer, data, sizeof(FCC));
}


void deserialize_FCC(FCC* data, uint8_t* buffer) {
	memcpy(data, buffer, sizeof(FCC));
}


// read the furnace controller configuration
HAL_StatusTypeDef read_fc_configuration(FCC* fcc) {
	uint8_t n = sizeof(FCC) / sizeof(uint8_t);
	uint8_t fcc_buffer[n];

	for (uint8_t i = 0; i < n; i++) {
		if (eeprom_read(i, &fcc_buffer[i], sizeof(fcc_buffer[i])) != HAL_OK)
			return HAL_ERROR;
	}

	deserialize_FCC(fcc, fcc_buffer);

	return HAL_OK;
}


// save the furnace controller configuration
HAL_StatusTypeDef write_fc_configuration(FCC* fcc) {
	if (has_changes) {
		uint8_t n = sizeof(FCC) / sizeof(uint8_t);
		uint8_t fcc_buffer[n];

		serialize_FCC(fcc, fcc_buffer);

		for (uint8_t i = 0; i < n; i++) {
			if (eeprom_write(i, &fcc_buffer[i], sizeof(fcc_buffer[i])) != HAL_OK)
				return HAL_ERROR;
		}

		printf("EEPROM write data\n");

		has_changes = false;
	}

	return HAL_OK;
}


void made_changes(void) {
	has_changes = true;
}


// set furnace temperature
void fcc_set_furnace_temperature(FCC* fcc, uint8_t furnace_temperature) {
	fcc->furnace_temperature = furnace_temperature;
	has_changes = true;
}


// set blower hysteresis
void fcc_set_blower_hysteresis(FCC* fcc, uint8_t blower_hysteresis) {
	fcc->blower_hysteresis = blower_hysteresis;
	has_changes = true;
}


// set blower min power
void fcc_set_blower_min_power(FCC* fcc, uint8_t blower_min_power) {
	fcc->blower_min_power = blower_min_power;
	has_changes = true;
}


// set blower max power
void fcc_set_blower_max_power(FCC* fcc, uint8_t blower_max_power) {
	fcc->blower_max_power = blower_max_power;
	has_changes = true;
}


// set blowout time
void fcc_set_blowout_time(FCC* fcc, uint8_t blowout_time) {
	fcc->blowout_time = blowout_time;
	has_changes = true;
}


// set blowout break
void fcc_set_blowout_break(FCC* fcc, uint8_t blowout_break) {
	fcc->blowout_break = blowout_break;
	has_changes = true;
}


// set water tank temperature
void fcc_set_water_tank_temperature(FCC* fcc, uint8_t water_tank_temperature) {
	fcc->water_tank_temperature = water_tank_temperature;
	has_changes = true;
}


// set water tank pump activation temperature
void fcc_set_water_tank_pump_activation_temperature(FCC* fcc, uint8_t water_tank_pump_activation_temperature) {
	fcc->water_tank_pump_activation_temperature = water_tank_pump_activation_temperature;
	has_changes = true;
}


// set water tank pump hysteresis
void fcc_set_water_tank_pump_hysteresis(FCC* fcc, uint8_t water_tank_pump_hysteresis) {
	fcc->water_tank_pump_hysteresis = water_tank_pump_hysteresis;
	has_changes = true;
}


// set furnace tank temperature difference
void fcc_set_furnace_tank_temperature_difference(FCC* fcc, uint8_t furnace_tank_temperature_difference) {
	fcc->furnace_tank_temperature_difference = furnace_tank_temperature_difference;
	has_changes = true;
}


// set furnace pump activation temperature
void fcc_set_furnace_pump_activation_temperature(FCC* fcc, uint8_t furnace_pump_activation_temperature) {
	fcc->furnace_pump_activation_temperature = furnace_pump_activation_temperature;
	has_changes = true;
}


// set furnace pump hysteresis
void fcc_set_furnace_pump_hysteresis(FCC* fcc, uint8_t furnace_pump_hysteresis) {
	fcc->furnace_pump_hysteresis = furnace_pump_hysteresis;
	has_changes = true;
}


// set temperature offset
void fcc_set_temperature_offset(FCC* fcc, int8_t temperature_offset) {
	fcc->temperature_offset = temperature_offset;
	has_changes = true;
}


// set furnace turn off temperature
void fcc_set_furnace_turn_off_temperature(FCC* fcc, uint8_t furnace_turn_off_temperature) {
	fcc->furnace_turn_off_temperature = furnace_turn_off_temperature;
	has_changes = true;
}


// set underfloor pump active
void fcc_set_underfloor_pump_active(FCC* fcc, uint8_t underfloor_pump_active) {
	fcc->underfloor_pump_active = underfloor_pump_active;
	has_changes = true;
}


// set blower active
void fcc_set_blower_active(FCC* fcc, uint8_t blower_active) {
	fcc->blower_active = blower_active;
	has_changes = true;
}
