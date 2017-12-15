#ifndef _KEY_H_
#define _KEY_H_
#include "stm32f10x.h"

//#define KEY0 PCin(5)   	
//#define KEY1 PAin(15)	 
//#define WK_UP  PAin(0)	 

#define KEY0    GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5) //��ȡ����0��0����
#define KEY1    GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)//��ȡ����1��0����
#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0) //��ȡ����2��1����

//#define KEY0_PRES	1		//KEY0  
//#define KEY1_PRES	2		//KEY1 
//#define WKUP_PRES	3		//WK_UP  

//extern u8 key_status;//����״̬���������
void KEY_Init(void);
u8 key_scan(void);

#endif
