/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "global.h"
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
#define BUTTON0_Pin GPIO_PIN_13
#define BUTTON0_GPIO_Port GPIOC
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON2_Pin GPIO_PIN_1
#define BUTTON2_GPIO_Port GPIOA
#define LED_TEST_Pin GPIO_PIN_5
#define LED_TEST_GPIO_Port GPIOA
#define LSB2_Pin GPIO_PIN_10
#define LSB2_GPIO_Port GPIOB
#define D9_Pin GPIO_PIN_7
#define D9_GPIO_Port GPIOC
#define D7_Pin GPIO_PIN_8
#define D7_GPIO_Port GPIOA
#define D8_Pin GPIO_PIN_9
#define D8_GPIO_Port GPIOA
#define MSB1_Pin GPIO_PIN_3
#define MSB1_GPIO_Port GPIOB
#define MSB2_Pin GPIO_PIN_4
#define MSB2_GPIO_Port GPIOB
#define LSB1_Pin GPIO_PIN_5
#define LSB1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
