#include <REGX52.H>
#include "Delay.h"
#include "Globals.h"
#include "LCD1602.h"



/**
  * @brief 获取独立按键键码
  * @param 无
  * @retval 按下按键的键码，范围0~4，无按键按下时返回值为0
*/
unsigned char Key()
{
	unsigned char KeyNumber = 0;
	if(P3_1==0){Delayms(20);while(P3_1==0);Delayms(20);KeyNumber=1;Mode=!Mode;EA=~EA;}
	if(P3_0==0){Delayms(20);while(P3_0==0);Delayms(20);KeyNumber=2;}
	if(P3_2==0){Delayms(20);while(P3_2==0);Delayms(20);KeyNumber=3;}
	if(P3_3==0){Delayms(20);while(P3_3==0);Delayms(20);KeyNumber=4;}
	LCD_ShowString(1, 13, "TEST");
	return KeyNumber;
}
