// LCDInterface.c
// Runs on LM4F120/TM4C123
// @TODO: This program...
// Keith Cyr and Omar Marawi
// September 19, 2013

/******* includes ******/
#include <stdio.h>
#include <stdint.h>

/****** defined constants ******/

/****** global variables ******/

/****** private functions ******/

/****** public utility functions ******/

#include <stdint.h>
#include "ST7735.h"
#include "inc/tm4c123gh6pm.h"
#include "LCDInterface.h"
void DrawTimeLine(int time){
	
	for (int i=0;i<100;i++)
	{
		ST7735_DrawPixel(i,i,ST7735_BLACK);
	}
	
}
