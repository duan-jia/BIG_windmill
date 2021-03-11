
#include "M6020_motor.h"

int16_t Tar_speed;
move_t move = {0};

void MOVE_pidinit(void)
{
	pid_init_increment(&move.M3508.PidSpeed,4,0.005,0.004,9999);//pidÎªÕû¶¨
}


void MOVE_GetMoveData()
{
	move.M3508.Rx.Speed = Tar_speed;
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

void MOVE_Process(void)
{
	MOVE_GetMoveData();
	MOVE_PidRun();
	MOVE_CanTransmit();
}
