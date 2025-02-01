#include <REGX52.H>
#include "LCD1602.h"
#include "Timer0.h"
#include "Globals.h"

char Year = 25, Month = 2, Day = 1, Hour = 21, Minute = 42, Second = 59;
char DayMax[12][2] = {
					{31, 31}, {29, 28}, {31, 31}, {30, 30}, {31, 31}, {30, 30},
					{31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};
unsigned char YearForm = 0;

/**
  * @brief 	LCD初始化
  * @param	无
  * @retval	无
*/
void Clock_Init()
{
	LCD_Init();
	Timer0_Init();
	Timer1_Init();
}

/**
  * @brief 	时钟初始化
  * @param	无
  * @retval	无
*/
void Clock_Show_Init()
{
	LCD_ShowString(1, 1, "  -  -");
	LCD_ShowString(2, 1, "  :  :");
}

/**
	* @brief 	时钟信息显示: 第一行：年、月、日； 第二行：时、分、秒
  * @param	无
  * @retval	无
*/
void Clock_Show_Inform()
{
	LCD_ShowNum(1, 1, Year, 2);
	LCD_ShowNum(1, 4, Month, 2);
	LCD_ShowNum(1, 7, Day, 2);
	LCD_ShowNum(2, 1, Hour, 2);
	LCD_ShowNum(2, 4, Minute, 2);
	LCD_ShowNum(2, 7, Second, 2);
}

/**
  * @brief 	时钟正常运行
  * @param	无
  * @retval	无
*/
void Clock_Show_Run() interrupt 1
{
	static int T0Count;
	//TL0 = 0x66;			//理想设定值
	TL0 = 0x8B;				//设置定时初始值
	TH0 = 0xFC;				//设置定时初始值
	YearForm = Year % 4;
	T0Count++;
	if(T0Count > 1000)
	{
		T0Count = 0;
		Second++;
		if(Second>=60)
		{
			Second = 0;
			Minute++;
			if(Minute>=60)
			{
				Minute = 0;
				Hour++;
				if(Hour>=24)
				{
					Hour = 0;
					Day++;
					if(Day>DayMax[Month-1][YearForm])
					{
						Day = 1;
						Month++;
						if(Month>12)
						{
							Month = 1;
							Year++;
							if(Year>99)
							{
								Year = 0;
							}
						}
					}
				}
			}
		}
	}
}