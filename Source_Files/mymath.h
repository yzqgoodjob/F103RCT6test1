#ifndef _MYMATH_H_
#define _MYMATH_H_
#include "stm32f10x.h"

int limit(int x, int min, int max);//限制
int limit_delta(int x, int x_old, int zoom);//限制增量
void fun_sort(u8 *list, u8 num);//排序从小到大
	
#endif
