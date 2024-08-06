/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SD_Select_Pin GPIO_PIN_15
#define SD_Select_GPIO_Port GPIOC
#define BLOWER_Pin GPIO_PIN_12
#define BLOWER_GPIO_Port GPIOB
#define UNDERFLOOR_PUMP_Pin GPIO_PIN_13
#define UNDERFLOOR_PUMP_GPIO_Port GPIOB
#define MIXING_PUMP_Pin GPIO_PIN_14
#define MIXING_PUMP_GPIO_Port GPIOB
#define FURNACE_PUMP_Pin GPIO_PIN_15
#define FURNACE_PUMP_GPIO_Port GPIOB
#define ENCODER_BTN_Pin GPIO_PIN_8
#define ENCODER_BTN_GPIO_Port GPIOA
#define LCD_RST_Pin GPIO_PIN_10
#define LCD_RST_GPIO_Port GPIOA
#define LCD_CS_Pin GPIO_PIN_4
#define LCD_CS_GPIO_Port GPIOB
#define LCD_DC_Pin GPIO_PIN_5
#define LCD_DC_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
