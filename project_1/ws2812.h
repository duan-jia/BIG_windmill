#ifndef _WS2812_H
#define _WS2812_H

#include "headfile.h"


extern GPIO_TypeDef* LED_PORT_1;
extern GPIO_TypeDef* LED_PORT_2;
extern GPIO_TypeDef* LED_PORT_3;
extern uint16_t LED_Pin_1,LED_Pin_2,LED_Pin_3;

void RGB_LED1_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue);
void RGB_LED2_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue);
void RGB_LED3_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue);

#endif
