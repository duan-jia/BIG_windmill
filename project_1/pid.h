#ifndef __PID_H
#define __PID_H
#include "stdio.h"
typedef struct
{
    /*PID�㷨�ӿڱ��������ڸ��û���ȡ���޸�PID�㷨������*/
    float kp; //����ϵ��
    float ki; //����ϵ��
    float kd; //΢��ϵ��

    float errNow;  //��ǰ�����
    float dCtrOut; //�����������
    float ctrOut;  //�������

    float IncLim; //�����޷�
    /*PID�㷨�ڲ���������ֵ�����޸�*/
    float errOld1;
    float errOld2;
} PID_IncrementType;

typedef struct
{
    float kp;
    float ki;
    float kd;
    float errILim_up;   //��������
    float errILim_down; //��������
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
