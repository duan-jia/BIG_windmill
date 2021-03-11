#ifndef _M6020_MOTOR_H
#define _M6020_MOTOR_H

#include "headfile.h"

typedef struct _move_t
{
    M3508_t M3508;
    uint8_t CanData[8];
}move_t;

extern int16_t Tar_speed;

void MOVE_pidinit(void);
void MOVE_Process(void);

#endif
