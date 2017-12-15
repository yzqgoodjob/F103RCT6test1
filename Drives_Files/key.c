#include "key.h"
#include "includes.h"

void KEY_Init(void)//按键初始化
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);//使能PORTA,PORTC时钟

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//关闭jtag，使能SWD，可以用SWD模式调试
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_15;//PA15
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA15
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5;//PC5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOC5
 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//PA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0
	
} 


/**************************************************************
 *作者：yzq
 *输入：mode:暂无
 *输出：KEY0->1  KEY1->2  WK_UP->3
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
		delay_ms(10);//消抖
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

