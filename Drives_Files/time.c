#include "time.h"
#include "includes.h"

void TIM3_Init(u16 arr)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;//������ʼ��Ҫ�õ��Ľṹ��
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʱ��ʹ��
	
	TIM_TimeBaseStructure.TIM_Period = arr; //�Զ���װֵ ������5000Ϊ500ms arr=4999
	TIM_TimeBaseStructure.TIM_Prescaler =7199; //��Ƶֵ 7199Ϊ10KHZ
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ� TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //���ݽṹ���е�ֵ��ʼ��
 
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�жϺ�������
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //��Ӧ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);  //���ݽṹ���е�ֵ��ʼ��

	TIM_ITConfig(TIM3, TIM_IT_Update ,ENABLE);//�ж�ʹ��
	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM3
							 
}

u8 time_dis_en=0;
u8 run_time[4]={0};
u8 cnt_100=0;
void TIM3_IRQHandler(void)   //TIM3�жϺ��� 1Sһ���ж�
{
	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET) //���ָ���ж��Ƿ���
		{
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //����жϱ�־λ
			if(++cnt_100>=10) //100ms++
			{
				cnt_100 = 0;
				time_dis_en = 1;
				run_time[0]++;
			}
			if(run_time[0]>=60)//��
			{
				run_time[0] = 0;
				run_time[1]++;
				AT24CXX_Write(0, (u8*)run_time, 4);  //ÿ���ӱ���һ��ʱ��
				if(run_time[1]>=60)//��
				{
					run_time[1] = 0;
					run_time[2]++;
					if(run_time[2]>=24)//ʱ
					{
						run_time[2] = 0;
						run_time[3]++;
					}
				}
			}
		}
}

