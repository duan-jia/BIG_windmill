/**
  ******************************************************************************
  * @file    
  * @author  sy
  * @brief   
  * @date     
  ******************************************************************************
  * @attention
  *
  * Copyright (c) CSU_RM_FYT
  * All rights reserved.
  *
  * This software component is licensed by SY under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  * opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MOTOR_H
#define _MOTOR_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "pid.h"
/* typedef -------------------------------------------------------------------*/
typedef struct _Mcircle_t
{
    int32_t Circle;
    uint16_t Angle;
}Mcircle_t;

typedef struct _MotorData_t
{
    int16_t Angle;
    int16_t Speed;
    int16_t Current;
    uint8_t Tep;
}MotorData_t;

typedef struct _M3508_t
{
    int16_t TarSpeed;
//	  int16_t Tarangle;/**/
    int16_t TarCurrent;
    MotorData_t Rx;
    MotorData_t LPf;
    PID_IncrementType PidSpeed;
    PID_IncrementType PidCurrent;
	  PID_AbsoluteType Pidangle;/**/
	  PID_AbsoluteType pidspeed;/**/
	  Mcircle_t Tar;
	  Mcircle_t Mc;/**/
    int16_t Output;
    int16_t OutputLpf;
}M3508_t;

/* define --------------------------------------------------------------------*/
/* variables -----------------------------------------------------------------*/
/* function ------------------------------------------------------------------*/
void Circle_Continue(Mcircle_t *Mc, uint16_t angle);
#ifdef __cplusplus
}
#endif

#endif /* */
  
/************************ (C) COPYRIGHT CSU_RM_FYT *************END OF FILE****/
