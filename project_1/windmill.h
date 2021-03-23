#ifndef _WINDMILL_H
#define _WINDMILL_H

#include "headfile.h"
#include "M6020_motor.h"
#include "ws2812.h"

//ָ��
//#define led_reset 1
#define run_led 1
#define success_hit 2
#define fail_hit 3
#define orange_color 4
#define cyan_color 5



#define movement_normal 9
#define movement_other 10

#define MAX_NUM 62   //�м�ÿ�ŵ�����
#define TOTAL1 130 //�ϱߵ���unknow
#define TOTAL2 62*7 //�м�ߵ���433
#define TOTAL3 130  //�±ߵ���130

extern _Bool flow_state;

void windmill_Process(void);
uint8_t queue_get(void);
void queue_insert(uint8_t control_id);
void fortest(void);
void Get_next_lamp(void);
void Run_led(void);
void param_init(void);
#endif
