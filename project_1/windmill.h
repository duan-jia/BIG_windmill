#include "motor.h"
#include "dr16.h"
#include "pid.h"


//ЦёБо
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

typedef struct _move_t
{
    M3508_t M3508;
    uint8_t CanData[8];
//    MoveData_t MoveData;
}move_t;

void MOVE_pidinit(void);
void MOVE_Process(void);
void RGB_LED_Write_24Bits(uint8_t green,uint8_t red,uint8_t blue);//GRB......
void Run_led(void);
uint8_t queue_get(void);
extern int16_t Tar_speed;
extern _Bool color_id;
	
