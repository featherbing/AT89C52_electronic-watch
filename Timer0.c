#include <REGX52.H>
#include "Globals.h"
#include "Key.h"
#include "Delay.h"

/**
  * @brief 定时器0初始化，1毫秒@11.0592MHz
  * @param 无
  * @retval 无
*/
void Timer0_Init()
{
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TF0 = 0;
	TR0 = 1;

	//TL0 = 0x66;			//理想设定值
	TL0 = 0x8B;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

/**
  * @brief 	计数器1初始化，独立按键2控制中断，测试用
  * @param	无
  * @retval	无
*/
void Timer1_Init()
{
	TMOD &= 0x0F;
	TMOD |= 0xE0;
	TF1 = 0;
	TR1 = 1;
	TL1 = 0xFF;
	TH1 = 0xFF;
	ET1 = 1;
	EA = 1;
	PT1 = 1;
}

//TEST
//void Timer1_ISR() interrupt 2
//{
//	Delayms(20);
//	KeyNum = Key();
//}

/*定时器T0中断函数模板
void Timer0_Routine() interrupt 1
{
	static int T0Count;
	TL0 = 0x66;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	T0Count++;
	if(T0Count > 1000)
	{
		T0Count = 0;
		P2_0 = ~P2_0;
	}
}
*/