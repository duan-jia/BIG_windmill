
#include "ws2812.h"

#define     RGB_LED1_HIGH    (HAL_GPIO_WritePin(LED_PORT_1, LED_Pin_1, GPIO_PIN_SET))
#define     RGB_LED1_LOW     (HAL_GPIO_WritePin(LED_PORT_1, LED_Pin_1, GPIO_PIN_RESET))
#define     RGB_LED2_HIGH    (HAL_GPIO_WritePin(LED_PORT_2, LED_Pin_2, GPIO_PIN_SET))
#define     RGB_LED2_LOW     (HAL_GPIO_WritePin(LED_PORT_2, LED_Pin_2, GPIO_PIN_RESET))
#define     RGB_LED3_HIGH    (HAL_GPIO_WritePin(LED_PORT_3, LED_Pin_3, GPIO_PIN_SET))
#define     RGB_LED3_LOW     (HAL_GPIO_WritePin(LED_PORT_3, LED_Pin_3, GPIO_PIN_RESET))

GPIO_TypeDef* LED_PORT_1;
GPIO_TypeDef* LED_PORT_2;
GPIO_TypeDef* LED_PORT_3;
uint16_t LED_Pin_1,LED_Pin_2,LED_Pin_3;

void delay_us(uint16_t n)
{
  while(n) n--;
}

/***********LED1********************/
void RGB_LED1_Write0(void)
{
  RGB_LED1_HIGH;
  delay_us(6);//4
  RGB_LED1_LOW;
  delay_us(21);//9
}

void RGB_LED1_Write1(void)
{
	  RGB_LED1_HIGH;
	  delay_us(25);
    RGB_LED1_LOW;
	  delay_us(3);
}

void RGB_LED1_Write_Byte(uint8_t byte)
{
	uint8_t i;
	for(i=0;i<8;i++)
			{
					if(byte&0x80)
					{
									RGB_LED1_Write1();
					}
					else
					{
									RGB_LED1_Write0();
					}
			byte <<= 1;
	}
}

void RGB_LED1_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue)//GRB......
{
	RGB_LED1_Write_Byte(green);
	RGB_LED1_Write_Byte(red);
	RGB_LED1_Write_Byte(blue);
}
/***********LED2********************/
void RGB_LED2_Write0(void)
{
  RGB_LED2_HIGH;
  delay_us(6);//4
  RGB_LED2_LOW;
  delay_us(21);//9
}

void RGB_LED2_Write1(void)
{
	  RGB_LED2_HIGH;
	  delay_us(25);
    RGB_LED2_LOW;
	  delay_us(3);
}

void RGB_LED2_Write_Byte(uint8_t byte)
{
	uint8_t i;
	for(i=0;i<8;i++)
			{
					if(byte&0x80)
					{
									RGB_LED2_Write1();
					}
					else
					{
									RGB_LED2_Write0();
					}
			byte <<= 1;
	}
}

void RGB_LED2_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue)//GRB......
{
	RGB_LED2_Write_Byte(green);
	RGB_LED2_Write_Byte(red);
	RGB_LED2_Write_Byte(blue);
}

/***********LED3********************/
void RGB_LED3_Write0(void)
{
  RGB_LED3_HIGH;
  delay_us(6);//4
  RGB_LED3_LOW;
  delay_us(21);//9
}

void RGB_LED3_Write1(void)
{
	  RGB_LED3_HIGH;
	  delay_us(25);
    RGB_LED3_LOW;
	  delay_us(3);
}

void RGB_LED3_Write_Byte(uint8_t byte)
{
	uint8_t i;
	for(i=0;i<8;i++)
			{
					if(byte&0x80)
					{
									RGB_LED3_Write1();
					}
					else
					{
									RGB_LED3_Write0();
					}
			byte <<= 1;
	}
}

void RGB_LED3_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue)//GRB......
{
	RGB_LED3_Write_Byte(green);
	RGB_LED3_Write_Byte(red);
	RGB_LED3_Write_Byte(blue);
}


void Led_reset(void)
{
	 RGB_LED1_LOW;
	 user_delay_us(3000);//ÑÓÊ±86us,2800Ò²¿É
}
