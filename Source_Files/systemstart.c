#include "systemstart.h"
#include "includes.h"

void system_start(void)
{
	LCD_Clear(BLACK);
	POINT_COLOR=YELLOW;	//内容显示为黄色
	AT24CXX_Read(0,run_time,4);  //读取系统运行时间，保存在24C02内
}
