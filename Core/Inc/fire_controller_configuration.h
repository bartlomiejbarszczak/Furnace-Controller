#ifndef INC_FIRE_CONTROLLER_CONFIGURATION_H_
#define INC_FIRE_CONTROLLER_CONFIGURATION_H_

#include "main.h"
#include "eeprom.h"
#include "string.h"
#include "stdbool.h"


// configuration structure
typedef struct FCC {
	uint8_t furnace_temperature; 						// docelowa temperatura pieca
	uint8_t blower_hysteresis;							// histereza pracy dmuchawy
	uint8_t blower_min_power;							// minimalna moc dmuchawy
	uint8_t blower_max_power;							// maksymalna moc dmuchawy
	uint8_t blowout_time;								// czas trwania przedmuchu
	uint8_t blowout_break;								// dlugosc przerwy miedzy przedmuchami
	uint8_t water_tank_temperature;						// docelowa temperatura bojlera
	uint8_t water_tank_pump_activation_temperature;		// temperatura pracy pompy mieszajacej wode
	uint8_t water_tank_pump_hysteresis;					// histereza pompy mieszajacej wode
	uint8_t furnace_tank_temperature_difference;		// roznica temperatury pieca i bojlera   ---- czy to potrzebne?
	uint8_t furnace_pump_activation_temperature;		// temperatura pracy pompy obiegowej
	uint8_t furnace_pump_hysteresis;					// histereza pompy obiegowej
	int8_t temperature_offset;							// korekta temperatury
	uint8_t furnace_turn_off_temperature;				// temperatura wygaszania pieca
	uint8_t underfloor_pump_active;						// czy pompa podlogowki ma byc wlaczana
	uint8_t blower_active; 								// czy dmuchawa ma byc wlaczana
} FCC;



HAL_StatusTypeDef read_fc_configuration(FCC* fcc);
HAL_StatusTypeDef write_fc_configuration(FCC* fcc);
void serialize_FCC(FCC* data, uint8_t* buffer);
void deserialize_FCC(FCC* data, uint8_t* buffer);
void made_changes(void);

void fcc_set_furnace_temperature(FCC* fcc, uint8_t furnace_temperature);
void fcc_set_blower_hysteresis(FCC* fcc, uint8_t blower_hysteresis);
void fcc_set_blower_min_power(FCC* fcc, uint8_t blower_min_power);
void fcc_set_blower_max_power(FCC* fcc, uint8_t blower_max_power);
void fcc_set_blowout_time(FCC* fcc, uint8_t blowout_time);
void fcc_set_blowout_break(FCC* fcc, uint8_t blowout_break);
void fcc_set_water_tank_temperature(FCC* fcc, uint8_t water_tank_temperature);
void fcc_set_water_tank_pump_activation_temperature(FCC* fcc, uint8_t water_tank_pump_activation_temperature);
void fcc_set_water_tank_pump_hysteresis(FCC* fcc, uint8_t water_tank_pump_hysteresis);
void fcc_set_furnace_tank_temperature_difference(FCC* fcc, uint8_t furnace_tank_temperature_difference);
void fcc_set_furnace_pump_activation_temperature(FCC* fcc, uint8_t furnace_pump_activation_temperature);
void fcc_set_furnace_pump_hysteresis(FCC* fcc, uint8_t furnace_pump_hysteresis);
void fcc_set_temperature_offset(FCC* fcc, int8_t temperature_offset);
void fcc_set_furnace_turn_off_temperature(FCC* fcc, uint8_t furnace_turn_off_temperature);
void fcc_set_underfloor_pump_active(FCC* fcc, uint8_t underfloor_pump_active);
void fcc_set_blower_active(FCC* fcc, uint8_t blower_active);



#endif /* INC_FIRE_CONTROLLER_CONFIGURATION_H_ */
