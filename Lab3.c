// Lab3.c
// Runs on LM4F120/TM4C123
// This program implements an alarm clock 
// patterns to the LCD.
// Daniel Valvano
// September 12, 2013

/****** Connections for the ST7735 LCD ******/
// Backlight (pin 10) connected to +3.3 V
// MISO (pin 9) unconnected 
// SCK (pin 8) connected to PA2 (SSI0Clk)
// MOSI (pin 7) connected to PA5 (SSI0Tx)
// TFT_CS (pin 6) connected to PA3 (SSI0Fss)
// CARD_CS (pin 5) unconnected
// Data/Command (pin 4) connected to PA6 (GPIO)
// RESET (pin 3) connected to PA7 (GPIO)
// VCC (pin 2) connected to +3.3 V
// Gnd (pin 1) connected to ground

#include <stdio.h>
#include <stdint.h>
#include "ST7735.h"
#include "PLL.h"
#include "SysTick.h"
#include "Switch.h"
#include "inc/tm4c123gh6pm.h"

#define SYSTICKFREQ 0x00FFFFFF
void DelayWait10ms(uint32_t n);

int interruptNumber=0;
int currentTime=1;
int timeKeep[3];
int x=0;

void UserTask(void){
		interruptNumber++;
		if (interruptNumber>80000000) // one second at 80Mhz
		{
			
			currentTime++;
			if(currentTime>43199)
			{
				currentTime=1; // just passed 11:59.59, 
			}
			interruptNumber=0;
		}
		
	/*static int i = 0;
  LEDS = COLORWHEEL[i&(WHEELSIZE-1)];
  i = i + 1;*/
}

//returns hours,minutes,seconds. hours in array[0],mins in array[1], secs in array[2]
void DecipherTime(int time, int* array){
	array[0]=time/3600;
	int x=(time%3600);
	array[1]=(x)/60;
	array[2]=(x)%60;
	
	
}

//Expected time[0]=hours,time[1]=minutes,time[2]=seconds
void DisplayTime(int* time){
	
}

//Draw a line from center of clock to sides.
void DrawTime(){
	
	
	
}
void DrawClock(){
	//ST7735_DrawBitmap(40,22,ClockBMP,80,80);
	DrawTime();
}



int main(void){uint32_t j;
  PLL_Init(); //80 Mhz
	SysTick_Init(); //initialize systick and interrupts
	SwitchInit();
	
	
	
  ST7735_InitR(INITR_REDTAB);
  ST7735_OutString("Graphics test\n");
  ST7735_OutString("cubic function\n");
  ST7735_PlotClear(0,4095);  // range from 0 to 4095
  for(j=0;j<128;j++){
    ST7735_PlotPoints(j*j/2+900-(j*j/256)*j,32*j); // cubic,linear
    ST7735_PlotNext(); 
  }   // called 128 times
  while(1){
  }
}

#define PF2   (*((volatile uint32_t *)0x40025010))

// Make PF2 an output, enable digital I/O, ensure alt. functions off
void SSR_Init(void){ 
  SYSCTL_RCGCGPIO_R |= 0x20;        // 1) activate clock for Port F
  while((SYSCTL_PRGPIO_R&0x20)==0){}; // allow time for clock to start
                                    // 2) no need to unlock PF2
  GPIO_PORTF_PCTL_R &= ~0x00000F00; // 3) regular GPIO
  GPIO_PORTF_AMSEL_R &= ~0x04;      // 4) disable analog function on PF2
  GPIO_PORTF_DIR_R |= 0x04;         // 5) set direction to output
  GPIO_PORTF_AFSEL_R &= ~0x04;      // 6) regular port function
  GPIO_PORTF_DEN_R |= 0x04;         // 7) enable digital port
}

// Subroutine to wait 10 msec
// Inputs: None
// Outputs: None
// Notes: ...
void DelayWait10ms(uint32_t n){
	uint32_t volatile time;
  while(n){
    time = 727240*2/91;  // 10msec
    while(time){
	  	time--;
    }
    n--;
  }
}


