/**
  ******************************************************************************
  * @file    
  * @author  sy
  * @brief
  * @date     
  ******************************************************************************
  * @attention
  *
  * Copyright (c) CSU_RM_FYT.
  * All rights reserved.
  *
  * This software component is licensed by SY under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  * opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* includes ------------------------------------------------------------------*/
#include "dr16.h"
//#include "tim.h"
//#include "motor.h"
/* typedef -------------------------------------------------------------------*/
/* define --------------------------------------------------------------------*/
/* variables -----------------------------------------------------------------*/
/* function ------------------------------------------------------------------*/
void RemoteDataMsg_Process(RemoteData_t *RDMsg)
{
    RDMsg->Ch0  = (  (int16_t) uart1_buf[0]       | ( (int16_t) uart1_buf[1]  << 8 )) & 0x07FF;
    RDMsg->Ch0 -= 1024;
    RDMsg->Ch1  = (( (int16_t) uart1_buf[1] >> 3) | ( (int16_t) uart1_buf[2]  << 5 )) & 0x07FF;
    RDMsg->Ch1 -= 1024;
    RDMsg->Ch2  = (( (int16_t) uart1_buf[2] >> 6) | ( (int16_t) uart1_buf[3]  << 2 )  
                                                   | ( (int16_t) uart1_buf[4]  << 10)) & 0x07FF;
    RDMsg->Ch2 -= 1024;
    RDMsg->Ch3  = (( (int16_t) uart1_buf[4] >> 1) | ( (int16_t) uart1_buf[5]  << 7 )) & 0x07FF;
    RDMsg->Ch3 -= 1024;
    RDMsg->S1   = (            uart1_buf[5] >> 6)                                     & 0x03;
    RDMsg->S2   = (            uart1_buf[5] >> 4)                                     & 0x03;
    
    RDMsg->Mouse_x = ( (int16_t) uart1_buf[6] | (int16_t) uart1_buf[7] << 8);
    RDMsg->Mouse_y = ( (int16_t) uart1_buf[8] | (int16_t) uart1_buf[9] << 8);
    
    RDMsg->MouseClick_left  = uart1_buf[12];
    RDMsg->MouseClick_right = uart1_buf[13]; 
    
    RDMsg->Key     = ( (int16_t) uart1_buf[14] |   (int16_t) uart1_buf[15] << 8 );
    RDMsg->Wheel   = ( (int16_t) uart1_buf[16] | ( (int16_t) uart1_buf[17] << 8 )) & 0x07FF;
    RDMsg->Wheel   = -RDMsg->Wheel + 1024;
        
    RDMsg->KeyBoard.w     = RDMsg->Key & KEY_PRESSED_OFFSET_W;
    RDMsg->KeyBoard.s     = RDMsg->Key & KEY_PRESSED_OFFSET_S;
    RDMsg->KeyBoard.a     = RDMsg->Key & KEY_PRESSED_OFFSET_A;
    RDMsg->KeyBoard.d     = RDMsg->Key & KEY_PRESSED_OFFSET_D;
    RDMsg->KeyBoard.shift = RDMsg->Key & KEY_PRESSED_OFFSET_SHIFT;
    RDMsg->KeyBoard.ctrl  = RDMsg->Key & KEY_PRESSED_OFFSET_CTRL;
    RDMsg->KeyBoard.q     = RDMsg->Key & KEY_PRESSED_OFFSET_Q;
    RDMsg->KeyBoard.e     = RDMsg->Key & KEY_PRESSED_OFFSET_E;
    RDMsg->KeyBoard.r     = RDMsg->Key & KEY_PRESSED_OFFSET_R;
    RDMsg->KeyBoard.f     = RDMsg->Key & KEY_PRESSED_OFFSET_F;
    RDMsg->KeyBoard.g     = RDMsg->Key & KEY_PRESSED_OFFSET_G;
    RDMsg->KeyBoard.z     = RDMsg->Key & KEY_PRESSED_OFFSET_Z;
    RDMsg->KeyBoard.x     = RDMsg->Key & KEY_PRESSED_OFFSET_X;
    RDMsg->KeyBoard.c     = RDMsg->Key & KEY_PRESSED_OFFSET_C;
    RDMsg->KeyBoard.v     = RDMsg->Key & KEY_PRESSED_OFFSET_V;
    RDMsg->KeyBoard.b     = RDMsg->Key & KEY_PRESSED_OFFSET_B;
    
}




/************************ (C) COPYRIGHT CSU_RM_FYT *************END OF FILE****/
