#include "ultrasonic.h"
#include "includes.h"

u16 distence_ultrasonic=0;

void ultrasonic_get(u8 rx_data)
{
	static u8 flag=0;
	static u8 ultra_tmp;
	if(flag==0)
	{
		flag = 1;
		ultra_tmp = rx_data;
	}
	else if(flag==1)
	{
		flag = 0;
		distence_ultrasonic = ((ultra_tmp<<8)+rx_data);
//		distence_ultrasonic = ((ultra_tmp<<8)+rx_data)/10*10;
	}
}
