#include "systemstart.h"
#include "includes.h"

void system_start(void)
{
	LCD_Clear(BLACK);
	POINT_COLOR=YELLOW;	//������ʾΪ��ɫ
	AT24CXX_Read(0,run_time,4);  //��ȡϵͳ����ʱ�䣬������24C02��
}
