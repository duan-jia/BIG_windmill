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
#ifndef _DR16_H
#define _DR16_H

#ifdef __cplusplus
 extern "C" {
#endif 

/* includes ------------------------------------------------------------------*/
#include "usart.h"
//#include "motor.h"
/* typedef -------------------------------------------------------------------*/
typedef struct 
{
	uint8_t w;
	uint8_t s;
	uint8_t a;
	uint8_t d;	
    uint8_t shift;
	uint8_t ctrl;
	uint8_t q;
	uint8_t e;
	uint8_t r;
	uint8_t f;
	uint8_t g;
	uint8_t z;
	uint8_t x;
	uint8_t c;
	uint8_t v;
	uint8_t b;
}Kb16_t,*Kb16_p;

typedef	struct	_remote_data_t
{
	int16_t	    Ch0;	
	int16_t	    Ch1;	
	int16_t	    Ch2;	
	int16_t	    Ch3;
	uint8_t	    S1;
	uint8_t	    S2;	
		
	int16_t	    Mouse_x;			
	int16_t	    Mouse_y;			
	uint8_t	    MouseClick_left;		
	uint8_t	    MouseClick_right;
	
    uint16_t    Key;
    Kb16_t      KeyBoard;
    
    int16_t     Wheel;
}RemoteData_t;

/* define --------------------------------------------------------------------*/
#define KEY_PRESSED_OFFSET_W	    (1U << 0)
#define KEY_PRESSED_OFFSET_S	    (1U << 1)
#define KEY_PRESSED_OFFSET_A	    (1U << 2)
#define KEY_PRESSED_OFFSET_D	    (1U << 3)
#define KEY_PRESSED_OFFSET_SHIFT	(1U << 4)
#define KEY_PRESSED_OFFSET_CTRL	    (1U << 5)
#define KEY_PRESSED_OFFSET_Q	    (1U << 6)
#define KEY_PRESSED_OFFSET_E	    (1U << 7)
#define KEY_PRESSED_OFFSET_R	    (1U << 8)
#define KEY_PRESSED_OFFSET_F	    (1U << 9)
#define KEY_PRESSED_OFFSET_G	    (1U << 10)
#define KEY_PRESSED_OFFSET_Z	    (1U << 11)
#define KEY_PRESSED_OFFSET_X	    (1U << 12)
#define KEY_PRESSED_OFFSET_C	    (1U << 13)
#define KEY_PRESSED_OFFSET_V	    (1U << 14)
#define KEY_PRESSED_OFFSET_B	    (1U << 15)
/* variables -----------------------------------------------------------------*/

/* function ------------------------------------------------------------------*/
void RemoteDataMsg_Process(RemoteData_t *RDMsg);

/* extern --------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif /* */
  
/************************ (C) COPYRIGHT CSU_RM_FYT *************END OF FILE****/
