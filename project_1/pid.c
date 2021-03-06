#include "pid.h"
/**
  * @brief  ����ʽPID��ʼ��.
  * @param  PID�ṹ���ַ��P,I,D,�����޷��������޷�.
  * @note   .
  * @retval none.
  */
void pid_init_increment(PID_IncrementType *PID, float kp, float ki, float kd, float IncLim) //PID��ʼ��ϵ��
{
    PID->kp = kp;
    PID->ki = ki;
    PID->kd = kd;
    PID->IncLim = IncLim;
}

/**
  * @brief  ��ͨ������ʽPID�����Խ��������޷���.
  * @param  Ŀ��ֵ������ֵ��PID�ṹ���ַ.
  * @note   ���صĲ�������������ֱ������Ҫ�����ֵ.
  * @retval ��Ҫ�������.
  */
float pid_increment_update(float Target, float Current, PID_IncrementType *PID)
{
    float dErrP, dErrI, dErrD;

    PID->errNow = Target - Current; //�������Ŀ��-Ŀǰ���������β���ֵȡ��֣�

    dErrP = PID->errNow - PID->errOld1;					   //�����������----΢�֣������-��һ�����
    dErrI = PID->errNow;								   //������ַ��������������������
    dErrD = PID->errNow - 2 * PID->errOld1 + PID->errOld2; //����΢�ַ��������������������-2*һ�����΢��+�������΢��

    /*����ʽPID����*/
    PID->dCtrOut = PID->kp * dErrP + PID->ki * dErrI + PID->kd * dErrD; //PID�ϳ������

    PID->errOld2 = PID->errOld1; //�������΢��
    PID->errOld1 = PID->errNow;  //һ�����΢��

    if (PID->dCtrOut < -PID->IncLim)
        PID->dCtrOut = -PID->IncLim;
    else if (PID->dCtrOut > PID->IncLim)
        PID->dCtrOut = PID->IncLim;

    PID->ctrOut += PID->dCtrOut;

    return PID->ctrOut;
}

/**
  * @brief  ����ʽPID��ʼ��.
  * @param  PID�ṹ���ַ��P,I,D,�����޷�.
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
  * @brief  ��ͨ����ʽPID.
  * @param  Ŀ��ֵ��ʵ��ֵ��PID�ṹ���ַ.
  * @note   .
  * @retval ��Ҫ�����ֵ.
  */
float pid_absolute_update(float Target, float Current, PID_AbsoluteType *PID)
{
    PID->errNow = Target - Current;

    PID->errP = PID->errNow; //��ȡ���ڵ�������kp����

    PID->errI += PID->errNow; //�����֣�����ki����

    if (PID->errLim != 0) //΢�����޺�����
    {
        if (PID->errI > PID->errLim)
            PID->errI = PID->errLim;
        else if (PID->errI < -PID->errLim)
            PID->errI = -PID->errLim;
    }

    PID->errD = PID->errNow - PID->errOld; //���΢�֣�����kd����

    PID->errOld = PID->errNow; //�������ڵ����

    PID->ctrOut = PID->kp * PID->errP + PID->ki * PID->errI + PID->kd * PID->errD; //�������ʽPID���

    return PID->ctrOut;
}

