#include "pid.h"
/**
  * @brief  增量式PID初始化.
  * @param  PID结构体地址，P,I,D,积分限幅，增量限幅.
  * @note   .
  * @retval none.
  */
void pid_init_increment(PID_IncrementType *PID, float kp, float ki, float kd, float IncLim) //PID初始化系数
{
    PID->kp = kp;
    PID->ki = ki;
    PID->kd = kd;
    PID->IncLim = IncLim;
}

/**
  * @brief  普通的增量式PID（可以进行增量限幅）.
  * @param  目标值，反馈值，PID结构体地址.
  * @note   返回的并非是增量，而直接是需要输出的值.
  * @retval 需要输出的量.
  */
float pid_increment_update(float Target, float Current, PID_IncrementType *PID)
{
    float dErrP, dErrI, dErrD;

    PID->errNow = Target - Current; //误差量：目标-目前（相邻两次测量值取差分）

    dErrP = PID->errNow - PID->errOld1;					   //计算比例分量----微分：现误差-上一个误差
    dErrI = PID->errNow;								   //计算积分分量——————现误差
    dErrD = PID->errNow - 2 * PID->errOld1 + PID->errOld2; //计算微分分量——————现误差-2*一阶误差微分+二阶误差微分

    /*增量式PID计算*/
    PID->dCtrOut = PID->kp * dErrP + PID->ki * dErrI + PID->kd * dErrD; //PID合成输出量

    PID->errOld2 = PID->errOld1; //二阶误差微分
    PID->errOld1 = PID->errNow;  //一阶误差微分

    if (PID->dCtrOut < -PID->IncLim)
        PID->dCtrOut = -PID->IncLim;
    else if (PID->dCtrOut > PID->IncLim)
        PID->dCtrOut = PID->IncLim;

    PID->ctrOut += PID->dCtrOut;

    return PID->ctrOut;
}

/**
  * @brief  绝对式PID初始化.
  * @param  PID结构体地址，P,I,D,积分限幅.
  * @note   .
  * @retval none.
  */
void pid_init_absolute(PID_AbsoluteType *PID, float kp, float ki, float kd, float errlimit)
{
    PID->kp = kp;
    PID->ki = ki;
    PID->kd = kd;
    PID->errLim = errlimit;
    PID->errNow = 0;
    PID->errP = 0;
    PID->errI = 0;
    PID->errD = 0;
    PID->errOld = 0;
    PID->ctrOut = 0;
}
/**
  * @brief  普通绝对式PID.
  * @param  目标值，实际值，PID结构体地址.
  * @note   .
  * @retval 需要输出的值.
  */
float pid_absolute_update(float Target, float Current, PID_AbsoluteType *PID)
{
    PID->errNow = Target - Current;

    PID->errP = PID->errNow; //读取现在的误差，用于kp控制

    PID->errI += PID->errNow; //误差积分，用于ki控制

    if (PID->errLim != 0) //微分上限和下限
    {
        if (PID->errI > PID->errLim)
            PID->errI = PID->errLim;
        else if (PID->errI < -PID->errLim)
            PID->errI = -PID->errLim;
    }

    PID->errD = PID->errNow - PID->errOld; //误差微分，用于kd控制

    PID->errOld = PID->errNow; //保存现在的误差

    PID->ctrOut = PID->kp * PID->errP + PID->ki * PID->errI + PID->kd * PID->errD; //计算绝对式PID输出

    return PID->ctrOut;
}

