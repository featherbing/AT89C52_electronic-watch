#include "Globals.h"
#include "Key.h"
#include "LCD1602.h"
#include "Delay.h"
#include "Timer0.h"

unsigned char KeyNum, Mode = 0;

/**
  * @brief 	查询按键，按键1：显示修改互相切换； 按键2：选择修改位置；按键3、4：加、减 
  * @param
  * @retval
*/
void Clock_query_Modify() 
{
	unsigned char Set = 1;
	KeyNum = Key();
	while(Mode==1)
	{
		KeyNum = Key();
		if(Mode!=1) break;
		//按键2切换修改内容
		if(KeyNum==2)
		{
			Set++;
			if(Set>6)
			{
				Set = 1;
			}
		}
		//按键3数字加1，按键4数字减1
		switch(Set)
		{	
			case 1 : 
				LCD_ShowString(1, 1, "  ");Delayms(50);
				LCD_ShowNum(1, 1, Year, 2);Delayms(50);
				if(KeyNum==3){Year++;if(Year>99) Year = 0;}
				if(KeyNum==4){Year--;if(Year<0) Year = 99;}
				break;
			case 2 :
				LCD_ShowString(1, 4, "  ");Delayms(50);
				LCD_ShowNum(1, 4, Month, 2);Delayms(50);
				if(KeyNum==3){Month++;if(Month>12) Month = 1;}
				if(KeyNum==4){Month--;if(Month<1) Month = 12;}
				break;
			case 3 :
				LCD_ShowString(1, 7, "  ");Delayms(50);
				LCD_ShowNum(1, 7, Day, 2);Delayms(50);
				if(KeyNum==3){Day++;if(Day>DayMax[Month-1][YearForm]) Day = 1;}
				if(KeyNum==4){Day--;if(Day<1) Day = DayMax[Month-1][YearForm];}
				break;
			case 4 :
				LCD_ShowString(2, 1, "  ");Delayms(50);
				LCD_ShowNum(2, 1, Hour, 2);Delayms(50);
				if(KeyNum==3){Hour++;if(Hour>=60) Hour = 0;}
				if(KeyNum==4){Hour--;if(Hour<0) Hour = 23;}
				break;
			case 5 :
				LCD_ShowString(2, 4, "  ");Delayms(50);
				LCD_ShowNum(2, 4, Minute, 2);Delayms(50);
				if(KeyNum==3){Minute++;if(Minute>=60) Minute = 0;}
				if(KeyNum==4){Minute--;if(Minute<0) Minute = 59;}
				break;
			case 6 :
				LCD_ShowString(2, 7, "  ");Delayms(50);
				LCD_ShowNum(2, 7, Second, 2);Delayms(50);
				if(KeyNum==3){Second++;if(Second>=60) Second = 0;}
				if(KeyNum==4){Second--;if(Second<0) Second = 59;}
				break;
		}		
	}
}

