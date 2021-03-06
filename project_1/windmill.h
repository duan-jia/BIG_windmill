#include "motor.h"
#include "dr16.h"
#include "pid.h"


typedef struct _move_t
{
    M3508_t M3508;
    uint8_t CanData[8];
//    MoveData_t MoveData;
}move_t;

void MOVE_pidinit(void);

