#include <stdio.h>
#include <stdint.h>
#include "ST7735.h"
#include "inc/tm4c123gh6pm.h"
#include "LCDTime.h"
void DrawTimeLine(int time){
	
	for (int i=0;i<100;i++)
	{
		ST7735_DrawPixel(i,i,ST7735_BLACK);
	}
	
}
