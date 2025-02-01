#include <REGX52.H>
#include "Clock_Show.h"
#include "Clock_Modify.h"
#include "Timer0.h"
#include "Globals.h"

void main()
{
	Clock_Init();
	Clock_Show_Init();
	while(1)
	{
		Clock_Show_Inform();
		Clock_query_Modify();
	}
}

