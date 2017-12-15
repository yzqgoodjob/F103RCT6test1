#include "key.h"
#include "includes.h"

void KEY_Init(void)//������ʼ��
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);//ʹ��PORTA,PORTCʱ��

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//�ر�jtag��ʹ��SWD��������SWDģʽ����
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;//PA15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA15
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5;//PC5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��GPIOC5
 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//PA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0���ó����룬Ĭ������	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA.0
	
} 


/**************************************************************
 *���ߣ�yzq
 *���룺mode:����
 *�����KEY0->1  KEY1->2  WK_UP->3
 *KEY0 KEY1 WK_UP
 **************************************************************/
//u8 key_status = 0;
u8 key_scan(void)
{	 
	if(KEY0&KEY1&!WK_UP)
	{
		return(0);
	}
	if(!(KEY0&KEY1&!WK_UP))
	{
		delay_ms(10);//����
		if(KEY0==0)  return(1);
		else if(KEY1==0)  return(2);
		else if(WK_UP==1) return(3);
		else return(0);
	}
	else
	{
		return (0);
	}
}

