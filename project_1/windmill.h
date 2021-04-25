#ifndef _WINDMILL_H
#define _WINDMILL_H

#include "headfile.h"
#include "M6020_motor.h"
#include "ws2812.h"

//指令

#define armour_ok 1
#define success_hit 2
#define fail_hit 3
#define orange_color 4
#define cyan_color 5

#define MAX_NUM 62   //中间每排灯珠数
#define TOTAL1 130 //上边灯数unknow
#define TOTAL2 62*7 //中间边灯数433
#define TOTAL3 (130+14)  //下边灯数130
#define TOTAL4  68 //for armour
#define TOTAL5  68 //for armour

extern _Bool flow_state,armour_state;

void windmill_Process(void);
uint8_t queue_get(void);
void queue_insert(uint8_t control_id);
void Get_next_lamp(void);
void Run_led(void);
void param_init(void);
void WS2812_reset(void);
void change_lamp(int i);
void armour(void);
void R_light(void);
#endif
