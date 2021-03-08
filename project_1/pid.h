#ifndef __PID_H
#define __PID_H
#include "stdio.h"
typedef struct
{
    /*PID算法接口变量，用于给用户获取或修改PID算法的特性*/
    float kp; //比例系数
    float ki; //积分系数
    float kd; //微分系数

    float errNow;  //当前的误差
    float dCtrOut; //控制增量输出
    float ctrOut;  //控制输出

    float IncLim; //增量限幅
    /*PID算法内部变量，其值不能修改*/
    float errOld1;
    float errOld2;
} PID_IncrementType;

typedef struct
{
    float kp;
    float ki;
    float kd;
    float errILim_up;   //积分上限
    float errILim_down; //积分上限
    float errLim;
    float errNow;
    float errOld;
    float errP;
    float errI;
    float errD;
    float ctrOut;
} PID_AbsoluteType;

void pid_init_increment(PID_IncrementType *PID, float kp, float ki, float kd, float IncLim);
float pid_increment_update(float Target, float Current, PID_IncrementType *PID);
void pid_init_absolute(PID_AbsoluteType *PID, float kp, float ki, float kd, float errlimit);
float pid_absolute_update(float Target, float Current, PID_AbsoluteType *PID);

#endif
