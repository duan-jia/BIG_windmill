#ifndef _WINDMILL_H
#define _WINDMILL_H

#include "headfile.h"
#include "M6020_motor.h"
#include "ws2812.h"

//ָ��
#define led_reset 1
#define run_led 2

#define motor_stop 3
#define run_motor 4

#define orange_color 5
#define cyan_color 6

#define success_hit 7
#define fail_hit 8

#define movement_normal 9
#define movement_other 10

#define MAX_NUM 62   //�м�ÿ�ŵ�����
#define TOTAL1 100 //�ϱߵ���
#define TOTAL2 7*MAX_NUM //�м�ߵ���
#define TOTAL3 100  //�±ߵ���



void windmill_Process(void);
void Run_led(void);
uint8_t queue_get(void);
void Get_next_lamp(void);	
void fortest(void);

#endif
