#include "windmill.h"
#include  "gpio.h"
#include "can.h"

#define     RGB_LED_HIGH    (HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET))
#define     RGB_LED_LOW     (HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET))



void windmill_Process(void)
{
	



}
/*************************order-control***************************/
uint8_t queue[20], st, ed, queue_num, color_id;
uint8_t queue_get(void)
{
	if(!queue_num) return 1;
	if(queue_num == 1)	return queue[st];
	if(queue_num > 1) {
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






/*************************WS2812¡ª¡ªLED***************************/
void RGB_LED_Write0(void)
{
	 RGB_LED_HIGH;
	 HAL_Delay(6);
   RGB_LED_LOW;
	 HAL_Delay(21);
}

void RGB_LED_Write1(void)
{
	 RGB_LED_HIGH;
	 HAL_Delay(25);
   RGB_LED_LOW;
	 HAL_Delay(3);
}

void RGB_LED_Write_Byte(uint8_t byte)
{
    uint8_t i;
   	 // irq_close();
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
	//irq_restore();
}

void RGB_LED_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue)//GRB......
{
//	  irq_close();
    RGB_LED_Write_Byte(green);
    RGB_LED_Write_Byte(red);
    RGB_LED_Write_Byte(blue);
//		irq_restore();
}

void Reset(void)
{
	RGB_LED_LOW;HAL_Delay(2900);
}
/*************************motor***************************/

move_t move = {0};

void MOVE_pidinit(void)
{
  
    pid_init_increment(&move.M3508.PidSpeed,4,0.005,0.004,9999);//pidÎªÕû¶¨

}


void MOVE_GetMoveData()
{

}



void MOVE_PidRun(void)
{
	move.M3508.LPf.Speed=0.8 * move.M3508.Rx.Speed + 0.2 * move.M3508.LPf.Speed;//ÂË²¨Æ÷
  move.M3508.Output = pid_increment_update(move.M3508.TarSpeed, move.M3508.LPf.Speed, &move.M3508.PidSpeed);
	move.M3508.OutputLpf = 0.8 * move.M3508.Output + 0.2 * move.M3508.OutputLpf;//ÂË²¨Æ÷
}

void MOVE_CanTransmit(void)
{
    move.CanData[6]=(uint8_t)(move.M3508.OutputLpf>>8);
    move.CanData[7]=(uint8_t)(move.M3508.OutputLpf);
		CAN1_Transmit(0x200,move.CanData);
}

void MOVE_Process(RemoteData_t RDMsg)
{
	
    MOVE_GetMoveData();

    MOVE_PidRun();

    MOVE_CanTransmit();
}

