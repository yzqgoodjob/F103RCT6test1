#include "init.h"
#include "includes.h"

int all_init()
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组2
	
	delay_init();	    	//延时函数初始化	  
	
	uart1_init(9600);	 	//串口1初始化为9600，电脑USB
	
	uart2_init(9600);   //串口2初始化为9600，超声波
	
	LED_Init();		  		//初始化与LED连接的硬件接口
	
	KEY_Init();         //按键初始化
	
	TIM3_Init(999);    //TIM3初始化 计数到5000为500ms
	
	IIC_Init();         //IIC初始化 PC11、PC12
	
	LCD_Init();         //LCD屏初始化 
		
	return (1);
}
