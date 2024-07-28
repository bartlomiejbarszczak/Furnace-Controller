/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "fatfs.h"
#include "i2c.h"
#include "rtc.h"
#include "sdmmc.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "stdbool.h"
#include "lcd_seven_segment.h"
#include "one_wire.h"
#include "eeprom.h"
#include "fire_controller_configuration.h"
#include "sd_controll.h"
#include "lcd.h"
#include "menu.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum {
	FSM_IDLE = 0,
	FSM_PREHEATING,
	FSM_WORK,
	FSM_EXTINCTION,
	FSM_OVERHEATING,
	FSM_BLOWOUT,
}FSM;

typedef struct {
	GPIO_TypeDef* Port;
	uint16_t Pin;
} PUMP_GPIO;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NO_SENSORS						4
#define FURNACE_OVERHEAT_TEMPERATURE 	(float)95.0f
#define OUT_WATER_OVERHEAT_TEMPERATURE 	(float)90.0f
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static LCD_GPIO lcd_cs = {LCD_CS_GPIO_Port, LCD_CS_Pin};
static LCD_GPIO lcd_dc = {LCD_DC_GPIO_Port, LCD_DC_Pin};
static LCD_GPIO lcd_rst = {LCD_RST_GPIO_Port, LCD_RST_Pin};
static LCD_GPIO enc_btn = {ENC_BTN_GPIO_Port, ENC_BTN_Pin};
static PUMP_GPIO furnace_pump = {FURNACE_PUMP_GPIO_Port, FURNACE_PUMP_Pin};		// TODO
static PUMP_GPIO mixing_pump = {MIXING_PUMP_GPIO_Port, MIXING_PUMP_Pin};			// TODO
static PUMP_GPIO underfloor_pump = {UNDERFLOOR_PUMP_GPIO_Port, UNDERFLOOR_PUMP_Pin};		// TODO
static PUMP_GPIO blower = {BLOWER_GPIO_Port, BLOWER_Pin};				// TODO
static FCC fcc = {60, 2, 30, 50, 15, 6, 60, 55, 4, 10, 40, 4, 0, 45, 1, 1};
static float temperature_array[NO_SENSORS] = {0};
static uint8_t encoder_value = 0;
static bool do_log = true;
static bool do_blowout = false;
static bool stop_blowout = true;
static uint16_t sd_counter = 0;
static uint16_t blowout_activ_time = 0;
static uint16_t blowout_break_time = 0;
static FSM current_state = FSM_IDLE;
static FSM last_state = FSM_IDLE;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
static void do_counts() {
	sd_counter++;
	if (do_blowout) {
		blowout_activ_time++;
	}
	if (stop_blowout) {
		blowout_break_time++;
	}


	if (sd_counter == 3600) {
		sd_counter = 0;
		do_log = true;
	}

	if (blowout_break_time >= (fcc.blowout_break * 60)) {
		do_blowout = true;
		stop_blowout = false;
	}

	if (blowout_activ_time >= fcc.blowout_time) {
		do_blowout = false;
		stop_blowout = true;
	}

}


int __io_putchar(int ch)
{
  if (ch == '\n') {
    __io_putchar('\r');
  }

  HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, HAL_MAX_DELAY);

  return 1;
}


void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if (hspi == &hspi1)
	{
		lcd_transfer_done();
	}
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim == &htim7) {
	  get_all_temperature(temperature_array, fcc.temperature_offset);
	  do_counts();
  }
}


static void read_encoder_data() {
	encoder_value =__HAL_TIM_GET_COUNTER(&htim2) >> 1;

	if (encoder_value > 16 && encoder_value <= 18){
		  __HAL_TIM_SET_COUNTER(&htim2, 32);
		  encoder_value = 16;
	}
	else if (encoder_value > 18) {
		__HAL_TIM_SET_COUNTER(&htim2, 0);
		encoder_value = 0;
	}
}

static void activate_pump(PUMP_GPIO* pump) {
	HAL_GPIO_WritePin(pump->Port, pump->Pin, GPIO_PIN_SET);
}

static void deactivate_pump(PUMP_GPIO* pump) {
	HAL_GPIO_WritePin(pump->Port, pump->Pin, GPIO_PIN_RESET);
}

static bool is_pump_activated(PUMP_GPIO* pump) {
	if (HAL_GPIO_ReadPin(pump->Port, pump->Pin) == GPIO_PIN_SET) {
		return true;
	}
	return false;
}

static bool start_preheating() {

	/*
	 * Rozpoczenie rozpalania
	 * */

	return false;
}


static bool wrong_sensor_read() {
	for(uint8_t i = 0; i < NO_SENSORS; i++) {
		if (temperature_array[i] == 500.0f)
			return true;
	}
	return false;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_TIM6_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_TIM7_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  MX_RTC_Init();
  MX_SPI1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start(&htim6);
  OW_init(&huart3, &htim6); // init One Wire DS18B20 library
  eeprom_init(&hi2c1);		// init EEPROM library
  menu_init(&encoder_value, &enc_btn, &fcc, temperature_array); // init Menu library

  read_fc_configuration(&fcc); // read furance config from EEPORM
  if (set_rtc_datatime() != HAL_OK)
	  printf("RTC Error\n");

  // init LCD library
  if (lcd_init(&hspi1, &lcd_cs, &lcd_dc, &lcd_rst) != HAL_OK)
	  printf("LCD ERROR\n");

  get_all_temperature(temperature_array, fcc.temperature_offset);  // read temperatures

  HAL_TIM_Base_Start_IT(&htim7);

  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  uint8_t last_encoder_value = 255;
  SD_Controll_Status sd_res;

  while (1) {
	  switch(current_state) {
	  case FSM_IDLE: {
		  deactivate_pump(&furnace_pump);
		  deactivate_pump(&mixing_pump);
		  deactivate_pump(&underfloor_pump);
		  deactivate_pump(&blower);

		  if (wrong_sensor_read()) {
			  break;
		  }

		  if (temperature_array[0] >= fcc.furnace_turn_off_temperature || start_preheating()) {
			  last_state = current_state;
			  current_state = FSM_PREHEATING;
		  }

		  if (temperature_array[0] >= FURNACE_OVERHEAT_TEMPERATURE || temperature_array[1] >= OUT_WATER_OVERHEAT_TEMPERATURE) {
			  last_state = current_state;
			  current_state = FSM_OVERHEATING;
		  }

		  break;
	  }
	  case FSM_PREHEATING: {
		  if (wrong_sensor_read()) {
			  current_state = FSM_IDLE;
			  break;
		  }

		  if (fcc.blower_active) {
			  activate_pump(&blower);
		  }

		  if (temperature_array[0] >= fcc.furnace_pump_activation_temperature + (fcc.furnace_pump_hysteresis >> 1)) {
			  activate_pump(&furnace_pump);

			  if (fcc.underfloor_pump_active) {
				  activate_pump(&underfloor_pump);
			  }
		  }

		  if (temperature_array[0] >= fcc.furnace_temperature) {
			  last_state = current_state;
			  current_state = FSM_WORK;
		  }


		  // TODO przejscie do IDLE gdy nie uda sie rozpalic

		  break;
	  }
	  case FSM_WORK: {
		  // bledne odczytywanie temperatury
		  if (wrong_sensor_read()) {
			  current_state = FSM_IDLE;
			  break;
		  }

		  if (!is_pump_activated(&furnace_pump)) {
			  activate_pump(&furnace_pump);

			  if (fcc.underfloor_pump_active && !is_pump_activated(&underfloor_pump)) {
				  activate_pump(&underfloor_pump);
			  }
		  }

		  // zalacznie dmuchawy
		  if (temperature_array[0] >= fcc.furnace_temperature + (fcc.blower_hysteresis >> 1) && fcc.blower_active) {
			  deactivate_pump(&blower);
		  }
		  else if (temperature_array[0] < fcc.furnace_temperature - (fcc.blower_hysteresis >> 1) && fcc.blower_active) {
			  activate_pump(&blower);
		  }

		  // przejscie do przedmuchu
		  if (do_blowout && fcc.blower_active) {
			  last_state = current_state;
			  current_state = FSM_BLOWOUT;
		  }

		  // zalaczanie pompy mieszajacej
		  if (temperature_array[2] - temperature_array[3] >= fcc.furnace_tank_temperature_difference
				  && temperature_array[2] >= fcc.water_tank_pump_activation_temperature + (fcc.water_tank_pump_hysteresis >> 1)) {
			  activate_pump(&mixing_pump);
		  }
		  else if (temperature_array[2] - temperature_array[3] < fcc.furnace_tank_temperature_difference
				  || temperature_array[2] < fcc.water_tank_pump_activation_temperature - (fcc.water_tank_pump_hysteresis >> 1)) {
			  deactivate_pump(&mixing_pump);
		  }
		  else {
			  deactivate_pump(&mixing_pump);
		  }

		  // przejscie do przegrzania
		  if (temperature_array[0] >= FURNACE_OVERHEAT_TEMPERATURE || temperature_array[1] >= OUT_WATER_OVERHEAT_TEMPERATURE) {
			  last_state = current_state;
			  current_state = FSM_OVERHEATING;
		  }

		  break;
	  }
	  case FSM_EXTINCTION: {
		  if (wrong_sensor_read()) {
			  current_state = FSM_IDLE;
			  break;
		  }

		  deactivate_pump(&underfloor_pump);
		  deactivate_pump(&furnace_pump);
		  deactivate_pump(&blower);
		  deactivate_pump(&mixing_pump); // mieszanie wody?

		  if (temperature_array[0] >= FURNACE_OVERHEAT_TEMPERATURE || temperature_array[1] >= OUT_WATER_OVERHEAT_TEMPERATURE) {
			  last_state = current_state;
			  current_state = FSM_OVERHEATING;
		  }

		  break;
	  }
	  case FSM_OVERHEATING: {
		  if (wrong_sensor_read()) {
			  current_state = FSM_OVERHEATING;
			  break;
		  }

		  activate_pump(&underfloor_pump);
		  activate_pump(&mixing_pump);
		  activate_pump(&furnace_pump);
		  deactivate_pump(&blower);

		  if (temperature_array[0] <= (float)fcc.furnace_temperature + 20.0f && temperature_array[1] <= 80.0f) {
			  current_state = last_state;
			  last_state = FSM_OVERHEATING;
		  }

		  break;
	  }
	  case FSM_BLOWOUT: {
		  if (wrong_sensor_read()) {
			  current_state = FSM_IDLE;
			  break;
		  }

		  activate_pump(&blower);

		  if (stop_blowout) {
			  deactivate_pump(&blower);
			  last_state = current_state;
			  current_state = FSM_WORK;
		  }

		  if (temperature_array[0] >= FURNACE_OVERHEAT_TEMPERATURE || temperature_array[1] >= OUT_WATER_OVERHEAT_TEMPERATURE) {
			  last_state = FSM_WORK;
			  current_state = FSM_OVERHEATING;
		  }

		  break;
	  }
	  default: {
		  current_state = FSM_IDLE;
		  break;
	  }
	  }

	  read_encoder_data(); // read data from encoder
	  if (last_encoder_value != encoder_value) {
		  printf("Encoder = %d\n", encoder_value);
	  	  last_encoder_value = encoder_value;
	  }

	  if (render_menu() != HAL_OK) {
		  printf("SPI DMA error! Error code = %d\n", hspi1.State);
	  }

	  printf("T1= %f C\tT2= %f C\n", temperature_array[0], temperature_array[1]);

	  if (do_log) {
		  do_log = false;
		  sd_res = log_data(temperature_array[0]);
		  if (sd_res != SD_OK)
			  printf("SD ERROR %d\t", sd_res);
	  }

	  HAL_Delay(50);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV4;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
