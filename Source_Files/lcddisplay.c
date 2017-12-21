#include "lcddisplay.h"
#include "includes.h"

u8 dis_time[40];//存放运行时间字符串
void lcd_display()
{
	if(time_dis_en)//运行时间刷新
		{
			time_dis_en = 0;
			sprintf((char*)dis_time,"system run time:%dD-%d:%d:%d",
				       run_time[3],run_time[2],run_time[1],run_time[0]);
			LCD_Fill(124,303,219,319,BLACK);	//清除显示数字区域
			LCD_ShowString(5,303,240,16,16,dis_time);
		} 
		
}
