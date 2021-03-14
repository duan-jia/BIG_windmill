
#include "ws2812.h"

#define     RGB_LED_HIGH    (HAL_GPIO_WritePin(LED_PORT_1, LED_Pin_1, GPIO_PIN_SET))
#define     RGB_LED_LOW     (HAL_GPIO_WritePin(LED_PORT_1, LED_Pin_1, GPIO_PIN_RESET))


GPIO_TypeDef* LED_PORT_1;
GPIO_TypeDef* LED_PORT_2;
GPIO_TypeDef* LED_PORT_3;
uint16_t LED_Pin_1,LED_Pin_2,LED_Pin_3;

void delay_us(uint16_t n)
{
  while(n) n--;
}

void RGB_LED_Write0(void)
{
  RGB_LED_HIGH;
  user_delay_us(5);
  RGB_LED_LOW;
  user_delay_us(15);
}

void RGB_LED_Write1(void)
{
	 RGB_LED_HIGH;
   user_delay_us(10);
	 RGB_LED_LOW;
   user_delay_us(8);
}


void RGB_LED_Write_Byte(uint8_t byte)
{
	uint8_t i;
	for(i=0;i<8;i++)
			{
					if(byte&0x80)
					{
									RGB_LED_Write1();
					}
					else
					{
									RGB_LED_Write0();
					}
			byte <<= 1;
	}
}

void RGB_LED_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue)//GRB......
{
	RGB_LED_Write_Byte(green);
	RGB_LED_Write_Byte(red);
	RGB_LED_Write_Byte(blue);
}

void Led_reset(void)
{
 RGB_LED_LOW;
 user_delay_us(860);//ÑÓÊ±86us,2800Ò²¿É
}
