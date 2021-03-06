/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usart.h"
#include "dr16.h"
#include "windmill.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
//osPoolId RDmemHandle;
/* USER CODE END Variables */
osThreadId RUNHandle;
osThreadId MSGHandle;
osThreadId flow_arrowHandle;
osMessageQId RDHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void TaskRUN(void const * argument);
void TaskMSG(void const * argument);
void Task_flow_arrow(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
//  osPoolDef(RDmem,16,RemoteData_t);
//  RDmemHandle = osPoolCreate(osPool(RDmem));
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of RD */
  osMessageQDef(RD, 16, uint32_t);
  RDHandle = osMessageCreate(osMessageQ(RD), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of RUN */
  osThreadDef(RUN, TaskRUN, osPriorityAboveNormal, 0, 128);
  RUNHandle = osThreadCreate(osThread(RUN), NULL);

  /* definition and creation of MSG */
  osThreadDef(MSG, TaskMSG, osPriorityHigh, 0, 128);
  MSGHandle = osThreadCreate(osThread(MSG), NULL);

  /* definition and creation of flow_arrow */
  osThreadDef(flow_arrow, Task_flow_arrow, osPriorityHigh, 0, 128);
  flow_arrowHandle = osThreadCreate(osThread(flow_arrow), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_TaskRUN */
/**
* @brief Function implementing the RUN thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TaskRUN */
void TaskRUN(void const * argument)
{
  /* USER CODE BEGIN TaskRUN */
  /* Infinite loop */
	param_init();
	R_light();//下载到工程板单独用（真的抽象）
	WS2812_reset();
  for(;;)
  {
		windmill_Process();
    osDelay(1);
  }
  /* USER CODE END TaskRUN */
}

/* USER CODE BEGIN Header_TaskMSG */
/**
  * @brief  Function implementing the MSG thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_TaskMSG */
void TaskMSG(void const * argument)
{
  /* USER CODE BEGIN TaskMSG */
	uint8_t last_buf = 0;
  /* Infinite loop */
  for(;;)
  {
    if(last_buf != uart2_buf)queue_insert(uart2_buf);
		last_buf = uart2_buf;//to recive the message, maybe have better way
    osDelay(10);
  }
  /* USER CODE END TaskMSG */
}

/* USER CODE BEGIN Header_Task_flow_arrow */
/**
* @brief Function implementing the flow_arrow thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Task_flow_arrow */
void Task_flow_arrow(void const * argument)
{
  /* USER CODE BEGIN Task_flow_arrow */
  /* Infinite loop */
  for(;;)
  {
		if(armour_state)//before the flow effect,lighten the armour
		{
			armour();
			armour_state = 0;
		}
		if(flow_state)Run_led();
    osDelay(1);

  }
  /* USER CODE END Task_flow_arrow */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
