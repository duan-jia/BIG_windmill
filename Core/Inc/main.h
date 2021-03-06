/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define Lamp2_3_Pin GPIO_PIN_2
#define Lamp2_3_GPIO_Port GPIOA
#define Lamp2_2_Pin GPIO_PIN_3
#define Lamp2_2_GPIO_Port GPIOA
#define Lamp2_1_Pin GPIO_PIN_4
#define Lamp2_1_GPIO_Port GPIOA
#define Lamp1_1_Pin GPIO_PIN_5
#define Lamp1_1_GPIO_Port GPIOA
#define Lamp1_2_Pin GPIO_PIN_6
#define Lamp1_2_GPIO_Port GPIOA
#define Lamp1_3_Pin GPIO_PIN_7
#define Lamp1_3_GPIO_Port GPIOA
#define Lamp3_3_Pin GPIO_PIN_13
#define Lamp3_3_GPIO_Port GPIOD
#define Lamp3_2_Pin GPIO_PIN_14
#define Lamp3_2_GPIO_Port GPIOD
#define Lamp3_1_Pin GPIO_PIN_15
#define Lamp3_1_GPIO_Port GPIOD
#define Lamp4_1_Pin GPIO_PIN_8
#define Lamp4_1_GPIO_Port GPIOA
#define Lamp4_2_Pin GPIO_PIN_9
#define Lamp4_2_GPIO_Port GPIOA
#define Lamp4_3_Pin GPIO_PIN_10
#define Lamp4_3_GPIO_Port GPIOA
#define R_orange_Pin GPIO_PIN_3
#define R_orange_GPIO_Port GPIOD
#define R_cyan_Pin GPIO_PIN_4
#define R_cyan_GPIO_Port GPIOD
#define blueteeth_T_Pin GPIO_PIN_5
#define blueteeth_T_GPIO_Port GPIOD
#define blueteeth_R_Pin GPIO_PIN_6
#define blueteeth_R_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_6
#define LED1_GPIO_Port GPIOB
#define Lamp5_3_Pin GPIO_PIN_8
#define Lamp5_3_GPIO_Port GPIOB
#define Lamp5_2_Pin GPIO_PIN_9
#define Lamp5_2_GPIO_Port GPIOB
#define Lamp5_1_Pin GPIO_PIN_0
#define Lamp5_1_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
