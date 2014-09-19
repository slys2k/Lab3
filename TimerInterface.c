// TimerInterface.c
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
void LCD_Init(void){
   ST7735_InitR(INITR_REDTAB);
   return;
}
