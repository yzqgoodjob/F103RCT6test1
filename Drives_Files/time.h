#ifndef _TIME_H_
#define _TIME_H_
#include "stm32f10x.h"

extern u8 time_dis_en;//��ʾ��ˢ��ʹ��
extern u8 run_time[4];//����ʱ��  �졢ʱ���֡���
extern u8 cnt_100;//100ms++

void TIM3_Init(u16 arr); //TIM3��ʼ�� Ƶ��10KHZ

#endif
