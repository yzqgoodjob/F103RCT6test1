#ifndef _TIME_H_
#define _TIME_H_
#include "stm32f10x.h"

extern u8 time_dis_en;//显示屏刷新使能
extern u8 run_time[4];//运行时间  天、时、分、秒
extern u8 cnt_100;//100ms++

void TIM3_Init(u16 arr); //TIM3初始化 频率10KHZ

#endif
