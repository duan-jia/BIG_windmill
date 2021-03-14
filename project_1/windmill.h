#ifndef _WINDMILL_H
#define _WINDMILL_H

#include "headfile.h"
#include "M6020_motor.h"
#include "ws2812.h"

//指令
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

#define MAX_NUM 62   //中间每排灯珠数
#define TOTAL1 100 //上边灯数
#define TOTAL2 7*MAX_NUM //中间边灯数
#define TOTAL3 100  //下边灯数



void windmill_Process(void);
void Run_led(void);
uint8_t queue_get(void);
void Get_next_lamp(void);	
void fortest(void);

#endif
