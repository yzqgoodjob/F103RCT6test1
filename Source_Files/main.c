#include "includes.h"

int init_finish;

int main(void)
{
	u8 cnt_old=0,sonic_old;
	u8 dis_time[40];//存放运行时间字符串
	u8 dis_ultrasonic[5];
	init_finish = all_init();//初始化函数
	if(init_finish) 
	{
		system_start();
	}

	//LED0 = 0;
	
	while(1)
	{
		
		if(cnt_100!=cnt_old)
		{
			cnt_old = cnt_100;
			USART2->DR = 0x55;
			while((USART2->SR&0X40)==0);//等待发送结束
			sonic_old = distence_ultrasonic; 
			if(distence_ultrasonic<25||distence_ultrasonic>1950)
			{
				LED0 = 0;
			}
			else
			{
				LED0 = 1;
			}
			distence_ultrasonic = limit(distence_ultrasonic,20,2000);
			sprintf((char*)dis_ultrasonic,"ultrasonic:%dmm",distence_ultrasonic);
			LCD_Fill(120,100,200,116,BLACK);
			LCD_ShowString(50,100,150,16,16,dis_ultrasonic);
		}
		
		
		
		if(time_dis_en)
		{
			time_dis_en = 0;
			sprintf((char*)dis_time,"system run time:%dD-%d:%d:%d",
				       run_time[3],run_time[2],run_time[1],run_time[0]);
			LCD_Fill(124,303,219,319,BLACK);	//清除显示数字区域
			LCD_ShowString(5,303,240,16,16,dis_time);
		}
	}
}
