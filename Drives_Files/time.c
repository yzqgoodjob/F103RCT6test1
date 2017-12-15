#include "time.h"
#include "includes.h"

void TIM3_Init(u16 arr)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;//申明初始化要用到的结构体
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能
	
	TIM_TimeBaseStructure.TIM_Period = arr; //自动重装值 计数到5000为500ms arr=4999
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //分频值 7199为10KHZ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割 TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据结构体中的值初始化
 
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断函数名称
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //抢占优先级0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //响应优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);  //根据结构体中的值初始化

	TIM_ITConfig(TIM3, TIM_IT_Update ,ENABLE);//中断使能
	TIM_Cmd(TIM3, ENABLE);  //使能TIM3
							 
}

u8 time_dis_en=0;
u8 run_time[4]={0};
u8 cnt_100=0;
void TIM3_IRQHandler(void)   //TIM3中断函数 1S一个中断
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //检查指定中断是否发生
		{
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //清除中断标志位
			if(++cnt_100>=10) //100ms++
			{
				cnt_100 = 0;
				time_dis_en = 1;
				run_time[0]++;
			}
			if(run_time[0]>=60)//秒
			{
				run_time[0] = 0;
				run_time[1]++;
				AT24CXX_Write(0, (u8*)run_time, 4);  //每分钟保存一次时间
				if(run_time[1]>=60)//分
				{
					run_time[1] = 0;
					run_time[2]++;
					if(run_time[2]>=24)//时
					{
						run_time[2] = 0;
						run_time[3]++;
					}
				}
			}
		}
}

