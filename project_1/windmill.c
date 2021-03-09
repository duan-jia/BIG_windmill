#include "windmill.h"
#include  "gpio.h"
#include "can.h"

#define     RGB_LED_HIGH    (HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET))
#define     RGB_LED_LOW     (HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET))
#define     SPEED1 500
#define     SPEED2 1000 //速度未知
#define     SPEED3 0



/*************************order-control***************************/
uint8_t queue[20], st, ed, queue_num;

uint8_t queue_get(void)
{
		if(!queue_num) return 1;
		if(queue_num == 1)	return queue[st];
		if(queue_num > 1) 
		{
			st ++;
			queue_num --;
		  if(st > 19) st -= 20;
	    return queue[st];
	  }
}

void queue_insert(uint8_t control_id)
{
   queue[ed] = control_id;
   ed ++;
   if(ed > 19) ed -= 20;
   queue_num++;
}

void queue_clear(void)
{
  st = ed = queue_num = 0;
}

void Run_led(void)
{
	color_id?RGB_LED_Write_24Bits(0x20,0X7F,0X00):RGB_LED_Write_24Bits(0x60,0X00,0X43);
	//控制灯的流动效果，以后再做
}




/*************************WS2812——LED***************************/
void delay_us(uint16_t n)
{
	  while(n) n--;
}

void RGB_LED_Write0(void)
{
	 RGB_LED_HIGH;
	 delay_us(6);
   RGB_LED_LOW;
	 delay_us(21);
}

void RGB_LED_Write1(void)
{
	 RGB_LED_HIGH;
	 delay_us(25);
	 RGB_LED_LOW;
	 delay_us(3);
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

void Reset(void)
{
	RGB_LED_LOW;
	delay_us(2900);
}
/*************************motor***************************/

move_t move = {0};

void MOVE_pidinit(void)
{
	pid_init_increment(&move.M3508.PidSpeed,4,0.005,0.004,9999);//pid为整定
}


void MOVE_GetMoveData()
{
	move.M3508.Rx.Speed = Tar_speed;
}



void MOVE_PidRun(void)
{
	
	move.M3508.LPf.Speed=0.8 * move.M3508.Rx.Speed + 0.2 * move.M3508.LPf.Speed;//滤波器
	move.M3508.Output = pid_increment_update(move.M3508.TarSpeed, move.M3508.LPf.Speed, &move.M3508.PidSpeed);
	move.M3508.OutputLpf = 0.8 * move.M3508.Output + 0.2 * move.M3508.OutputLpf;//滤波器
}

void MOVE_CanTransmit(void)
{
	move.CanData[6]=(uint8_t)(move.M3508.OutputLpf>>8);
	move.CanData[7]=(uint8_t)(move.M3508.OutputLpf);
	CAN1_Transmit(0x200,move.CanData);
}

void MOVE_Process(void)
{
	MOVE_GetMoveData();
	MOVE_PidRun();
	MOVE_CanTransmit();
}
/*************************main function***************************/

int16_t Tar_speed;
_Bool color_id;
void windmill_Process(void)
{
	 switch(queue_get())
	 {
		 case run_led:
			 Run_led(); break;
     case motor_stop:
			 Tar_speed = SPEED3; break;
		 case run_motor:
			 Tar_speed = SPEED1; break;
		 case orange_color:
			 color_id = 1; break;
		 case cyan_color:
			 color_id = 0; break;
		 case led_reset:
			 Reset(); break;
			 
   }
	 MOVE_Process();
}
