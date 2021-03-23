#include "windmill.h"

#define     SPEED1 500
#define     SPEED2 1000 //速度未知
#define     SPEED3 0




/*************************order-control***************************/
uint16_t Start;
uint16_t run_time_num, flow_num ;//flow_num控制流动时间间隔,run_time_num用于判定是否超时
uint8_t target, success_count, Random_Num;
uint8_t queue[20], st, ed, queue_num;
//uint8_t number[] = {2,3,4,5};
uint8_t number[] = {1};//for test
_Bool color_id ,flow_state;
int start0 ,count , period_count ;

uint8_t queue_get(void)
{
		if(!queue_num) return 0;
		if(queue_num != 0)
		{
		  queue_num--;
		  if(st > 19) st -= 20;
		  return queue[st++];
		}
		return  0;
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

void param_init(void)
{
	target = 1;
	Start = 1;
	success_count = 0;
	Random_Num = 0;
	run_time_num = 0;
	flow_num = 0;
	flow_state = 0;
	st = ed = 0;
	queue_num = 0;
	color_id = 1;
	memset(queue, 0, sizeof queue);
}

/******light water*********/
void Run_led(void)
{
		if(success_count == 5) {flow_state = 0;return;}
//		if(run_time_num > 156) {queue_insert(fail_hit);return;}//超过2.5s未击中
//		run_time_num ++;
//		flow_num++;
//		if(flow_num >= 2) flow_num -= 2;//每47ms，流动一次
//		if(flow_num) return;
//		Led_reset();
		count = 1;
		start0--;
		if(start0 < 1) start0 += 7;
		period_count = start0;
		while(count <= TOTAL2)
		{
			 //if(count == MAX_NUM) break;
			if(period_count>=5){
					color_id?RGB_LED2_Write_24Bits(0x20,0X7F,0X00):RGB_LED2_Write_24Bits(0x60,0X00,0X43);
				}
				else RGB_LED2_Write_24Bits(0x00,0X00,0X00);
				
				count++;

				if(count == MAX_NUM + 1){//第二排 上
						period_count = 6 - period_count;
						if(period_count < 1) period_count += 7;
				}
				else if(count == 2*MAX_NUM + 1){//第三排 下
						period_count = 4 - period_count;
						if(period_count > 7) period_count -= 7;
				}		
				else if(count == 3*MAX_NUM + 1){//第四排 上
						period_count = 6 - period_count;
						if(period_count < 1) period_count += 7;
				}
				else if(count == 4*MAX_NUM + 1){//第五排 下
						period_count = 6 -  period_count;
						if(period_count > 7) period_count -= 7;
				}
				else if(count == 5*MAX_NUM + 1){//第六排 上
						period_count = 4 - period_count;
						if(period_count > 7) period_count -= 7;
				}
				else if(count == 6*MAX_NUM + 1){//第七排 下
						period_count = 6 - period_count;
						if(period_count > 7) period_count -= 7;
				}
				else period_count ++;
				if(period_count > 7) period_count -= 7;
	  }
					 HAL_Delay(100);
}


void WS2812_reset(void)
{
	success_count = 0;
	int count1 = 1,count2 = 1,count3 = 1;
		while(count1 <= TOTAL1)
	{
	  RGB_LED1_Write_24Bits(0x00,0X00,0X00);
	  count1++;
	}
	while(count2 <= TOTAL2) {
	  RGB_LED2_Write_24Bits(0x00,0X00,0X00);
	  count2++;
	}
	while(count3 <= TOTAL3)
	{
    RGB_LED3_Write_24Bits(0x00,0X00,0X00);
	  count3++;
	}
  Get_next_lamp();
}

void Reset(void){
	
	success_count = 0;
	
  HAL_GPIO_WritePin(Lamp1_1_GPIO_Port,Lamp1_1_Pin,GPIO_PIN_RESET);HAL_Delay(10);
	HAL_GPIO_WritePin(Lamp1_2_GPIO_Port,Lamp1_2_Pin,GPIO_PIN_RESET);HAL_Delay(10);
	HAL_GPIO_WritePin(Lamp1_3_GPIO_Port,Lamp1_3_Pin,GPIO_PIN_RESET);HAL_Delay(10);

  HAL_GPIO_WritePin(Lamp2_1_GPIO_Port,Lamp2_1_Pin,GPIO_PIN_RESET);user_delay_us(3000);
	HAL_GPIO_WritePin(Lamp2_2_GPIO_Port,Lamp2_2_Pin,GPIO_PIN_RESET);user_delay_us(3000);
	HAL_GPIO_WritePin(Lamp2_3_GPIO_Port,Lamp2_3_Pin,GPIO_PIN_RESET);user_delay_us(3000);

  HAL_GPIO_WritePin(Lamp3_1_GPIO_Port,Lamp3_1_Pin,GPIO_PIN_RESET);user_delay_us(3000);
	HAL_GPIO_WritePin(Lamp3_2_GPIO_Port,Lamp3_2_Pin,GPIO_PIN_RESET);user_delay_us(3000);
	HAL_GPIO_WritePin(Lamp3_3_GPIO_Port,Lamp3_3_Pin,GPIO_PIN_RESET);user_delay_us(3000);

  HAL_GPIO_WritePin(Lamp4_1_GPIO_Port,Lamp4_1_Pin,GPIO_PIN_RESET);user_delay_us(3000);
	HAL_GPIO_WritePin(Lamp4_2_GPIO_Port,Lamp4_2_Pin,GPIO_PIN_RESET);user_delay_us(3000);
	HAL_GPIO_WritePin(Lamp4_3_GPIO_Port,Lamp4_3_Pin,GPIO_PIN_RESET);user_delay_us(3000);

  HAL_GPIO_WritePin(Lamp5_1_GPIO_Port,Lamp5_1_Pin,GPIO_PIN_RESET);user_delay_us(3000);
	HAL_GPIO_WritePin(Lamp5_2_GPIO_Port,Lamp5_2_Pin,GPIO_PIN_RESET);user_delay_us(3000);
	HAL_GPIO_WritePin(Lamp5_3_GPIO_Port,Lamp5_3_Pin,GPIO_PIN_RESET);user_delay_us(3000);
  Get_next_lamp();
}


void Get_next_lamp(void)
{
	start0 = Start;/*初始为1*/
	flow_num = 0;
	run_time_num = 0;
  if(success_count == 5) return;
//	target = number[Random_Num];//将要点亮的灯的序号U8 number[] = {2,3,4,5};初始化时为target赋值为1
//	Random_Num++;
	if(Random_Num == 3) return;
			 
	switch(target){
		 case 1:
		 {
			 LED_PORT_1 = Lamp1_1_GPIO_Port;
			 LED_PORT_2 = Lamp1_2_GPIO_Port;
			 LED_PORT_3 = Lamp1_3_GPIO_Port;
			 LED_Pin_1  = Lamp1_1_Pin;
			 LED_Pin_2  = Lamp1_2_Pin;
			 LED_Pin_3  = Lamp1_3_Pin;
		 };break;
		 case 2:
		 {
			 LED_PORT_1 = Lamp2_1_GPIO_Port;
			 LED_PORT_2 = Lamp2_2_GPIO_Port;
			 LED_PORT_3 = Lamp2_3_GPIO_Port;
			 LED_Pin_1  = Lamp2_1_Pin;
			 LED_Pin_2  = Lamp2_2_Pin;
			 LED_Pin_3  = Lamp2_3_Pin;
		 };break;
		 case 3:
		 {
			 LED_PORT_1 = Lamp3_1_GPIO_Port;
			 LED_PORT_2 = Lamp3_2_GPIO_Port;
			 LED_PORT_3 = Lamp3_3_GPIO_Port;
			 LED_Pin_1  = Lamp3_1_Pin;
			 LED_Pin_2  = Lamp3_2_Pin;
			 LED_Pin_3  = Lamp3_3_Pin;
		 };break;
		 case 4:
		 {
			 LED_PORT_1 = Lamp4_1_GPIO_Port;
			 LED_PORT_2 = Lamp4_2_GPIO_Port;
			 LED_PORT_3 = Lamp4_3_GPIO_Port;
			 LED_Pin_1  = Lamp4_1_Pin;
			 LED_Pin_2  = Lamp4_2_Pin;
			 LED_Pin_3  = Lamp4_3_Pin;
		 };break;
		 case 5:
		 {
			 LED_PORT_1 = Lamp5_1_GPIO_Port;
			 LED_PORT_2 = Lamp5_2_GPIO_Port;
			 LED_PORT_3 = Lamp5_3_GPIO_Port;
			 LED_Pin_1  = Lamp5_1_Pin;
			 LED_Pin_2  = Lamp5_2_Pin;
			 LED_Pin_3  = Lamp5_3_Pin;
		 };break;
	 }
//	flow_state = 1;

}

void Finish_target(void)//激活成功
{
	int count1 = 1,count2 = 1,count3 =1 ;

	while(count1 <= TOTAL1)
	{
	  color_id?RGB_LED1_Write_24Bits(0x20,0X7F,0X00):RGB_LED1_Write_24Bits(0x60,0X00,0X43);
	  count1++;
	}

	while(count2 <= TOTAL2)
	{
	  color_id?RGB_LED2_Write_24Bits(0x20,0X7F,0X00):RGB_LED2_Write_24Bits(0x60,0X00,0X43);
	  count2++;
	}

	while(count3 <= TOTAL3)
	{
	  color_id?RGB_LED3_Write_24Bits(0x20,0X7F,0X00):RGB_LED3_Write_24Bits(0x60,0X00,0X43);
		count3++;
	}
	
//	success_count++;
	if(success_count != 5) Get_next_lamp();
//		 HAL_Delay(2000);
}



void windmill_Process(void)
{
	 switch(queue_get())
	 {
		 case run_led:
			 flow_state = 1; break;    
		 case success_hit:
			 flow_state = 0;
			 Finish_target();break;
		 case fail_hit:
			 flow_state = 0;
			 WS2812_reset();break;
		 case orange_color:
			 color_id = 1; break;
		 case cyan_color:
			 color_id = 0; break;
   }

//	 MOVE_Process();
}

void fortest(void)
{
		LED_PORT_1 = Lamp1_1_GPIO_Port;
		LED_PORT_2 = Lamp1_2_GPIO_Port;
		LED_PORT_3 = Lamp1_3_GPIO_Port;
		LED_Pin_1  = Lamp1_1_Pin;
		LED_Pin_2  = Lamp1_2_Pin;
		LED_Pin_3  = Lamp1_3_Pin;
//	  queue_insert(2);
//	  queue_insert(3);
//	for(int i =1; i < 10; i++)
//    queue_insert(2);
    
}
