#ifndef _MYMATH_H_
#define _MYMATH_H_
#include "stm32f10x.h"

int limit(int x, int min, int max);//����
int limit_delta(int x, int x_old, int zoom);//��������
void fun_sort(u8 *list, u8 num);//�����С����
	
#endif
