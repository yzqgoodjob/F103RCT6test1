#include "includes.h"

int init_finish;

int main(void)
{
	u8 cnt_old=0;
	u8 dis_ultrasonic[5];
	init_finish = all_init();//初始化函数
	if(init_finish) 
	{
		system_start();
	}

	while(1)
	{
		
		if(cnt_100!=cnt_old)
		{
			cnt_old = cnt_100;
			USART2->DR = 0x55;
			while((USART2->SR&0X40)==0);//等待发送结束
			if(distence_ultrasonic<30||distence_ultrasonic>1900)
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
		
		lcd_display();
		
	}
}
