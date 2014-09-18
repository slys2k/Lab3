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




int main2(void){
  int x, y, dx, dy;
//  uint8_t red, green, blue;
  PLL_Init();                           // set system clock to 80 MHz
  // test DrawChar() and DrawCharS()
  ST7735_InitR(INITR_REDTAB);
  ST7735_DrawCharS(0, 0, 'c', ST7735_Color565(255, 0, 0), 0, 1);
  ST7735_DrawCharS(6, 0, 'h', ST7735_Color565(255, 128, 0), 0, 1);
  ST7735_DrawCharS(12, 0, 'a', ST7735_Color565(255, 255, 0), 0, 1);
  ST7735_DrawCharS(18, 0, 'r', ST7735_Color565(128, 255, 0), 0, 1);
  ST7735_DrawCharS(30, 0, 'T', ST7735_Color565(0, 255, 0), 0, 1);
  ST7735_DrawCharS(36, 0, 'E', ST7735_Color565(0, 255, 255), 0, 1);
  ST7735_DrawCharS(42, 0, 'S', ST7735_Color565(0, 0, 255), 0, 1);
  ST7735_DrawCharS(48, 0, 'T', ST7735_Color565(128, 0, 255), 0, 1);

  ST7735_DrawCharS(0, 8, 'c', ST7735_Color565(255, 0, 0), 0, 2);
  ST7735_DrawCharS(12, 8, 'h', ST7735_Color565(255, 128, 0), 0, 2);
  ST7735_DrawCharS(24, 8, 'a', ST7735_Color565(255, 255, 0), 0, 2);
  ST7735_DrawCharS(36, 8, 'r', ST7735_Color565(128, 255, 0), 0, 2);
  ST7735_DrawCharS(60, 8, 'T', ST7735_Color565(0, 255, 0), 0, 2);
  ST7735_DrawCharS(72, 8, 'E', ST7735_Color565(0, 255, 255), 0, 2);
  ST7735_DrawCharS(84, 8, 'S', ST7735_Color565(0, 0, 255), 0, 2);
  ST7735_DrawCharS(96, 8, 'T', ST7735_Color565(128, 0, 255), 0, 2);

  ST7735_DrawCharS(0, 24, 'c', ST7735_Color565(255, 0, 0), 0, 3);
  ST7735_DrawCharS(18, 24, 'h', ST7735_Color565(255, 128, 0), 0, 3);
  ST7735_DrawCharS(36, 24, 'a', ST7735_Color565(255, 255, 0), 0, 3);
  ST7735_DrawCharS(54, 24, 'r', ST7735_Color565(128, 255, 0), 0, 3);
  ST7735_DrawCharS(90, 24, 'T', ST7735_Color565(0, 255, 0), 0, 3);
  ST7735_DrawCharS(108, 24, 'E', ST7735_Color565(0, 255, 255), 0, 3);
  ST7735_DrawCharS(126, 24, 'S', ST7735_Color565(0, 0, 255), 0, 3); // off the screen
  ST7735_DrawCharS(144, 24, 'T', ST7735_Color565(128, 0, 255), 0, 3); // totally off the screen

  ST7735_DrawCharS(0, 48, 'c', ST7735_Color565(255, 0, 0), 0, 4);
  ST7735_DrawCharS(24, 48, 'h', ST7735_Color565(255, 128, 0), 0, 4);
  ST7735_DrawCharS(48, 48, 'a', ST7735_Color565(255, 255, 0), 0, 4);
  ST7735_DrawCharS(72, 48, 'r', ST7735_Color565(128, 255, 0), 0, 4);
  ST7735_DrawCharS(120, 48, 'T', ST7735_Color565(0, 255, 0), 0, 4); // off the screen
  ST7735_DrawCharS(144, 48, 'E', ST7735_Color565(0, 255, 255), 0, 4); // totally off the screen
  ST7735_DrawCharS(168, 48, 'S', ST7735_Color565(0, 0, 255), 0, 4); // totally off the screen
  ST7735_DrawCharS(192, 48, 'T', ST7735_Color565(128, 0, 255), 0, 4); // totally off the screen

  ST7735_DrawCharS(0, 80, 'c', ST7735_Color565(255, 0, 0), 0, 6);
  ST7735_DrawCharS(36, 80, 'h', ST7735_Color565(255, 128, 0), 0, 6);
  ST7735_DrawCharS(72, 80, 'a', ST7735_Color565(255, 255, 0), 0, 6);
  ST7735_DrawCharS(108, 80, 'r', ST7735_Color565(128, 255, 0), 0, 6); // off the screen

  ST7735_DrawChar(0, 135, 'A', ST7735_Color565(255, 128, 128), 0, 2);
  ST7735_DrawChar(12, 135, 'd', ST7735_Color565(255, 0, 0), 0, 2);
  ST7735_DrawChar(24, 135, 'v', ST7735_Color565(255, 128, 0), 0, 2);
  ST7735_DrawChar(48, 135, 'c', ST7735_Color565(255, 255, 0), 0, 2);
  ST7735_DrawChar(60, 135, 'h', ST7735_Color565(128, 255, 0), 0, 2);
  ST7735_DrawChar(72, 135, 'a', ST7735_Color565(0, 255, 0), 0, 2);
  ST7735_DrawChar(84, 135, 'r', ST7735_Color565(0, 255, 255), 0, 2);
  ST7735_DrawChar(108, 135, 't', ST7735_Color565(0, 0, 255), 0, 2);
  ST7735_DrawChar(120, 135, 'e', ST7735_Color565(128, 0, 255), 0, 2); // off the screen
  ST7735_DrawChar(132, 135, 's', ST7735_Color565(255, 0, 255), 0, 2); // totally off the screen
  ST7735_DrawChar(144, 135, 't', ST7735_Color565(255, 255, 255), 0, 2); // totally off the screen

  ST7735_DrawChar(0, 151, 'A', ST7735_Color565(255, 128, 128), 0, 1);
  ST7735_DrawChar(6, 151, 'd', ST7735_Color565(255, 0, 0), 0, 1);
  ST7735_DrawChar(12, 151, 'v', ST7735_Color565(255, 128, 0), 0, 1);
  ST7735_DrawChar(24, 151, 'c', ST7735_Color565(255, 255, 0), 0, 1);
  ST7735_DrawChar(30, 151, 'h', ST7735_Color565(128, 255, 0), 0, 1);
  ST7735_DrawChar(36, 151, 'a', ST7735_Color565(0, 255, 0), 0, 1);
  ST7735_DrawChar(42, 151, 'r', ST7735_Color565(0, 255, 255), 0, 1);
  ST7735_DrawChar(54, 151, 't', ST7735_Color565(0, 0, 255), 0, 1);
  ST7735_DrawChar(60, 151, 'e', ST7735_Color565(128, 0, 255), 0, 1);
  ST7735_DrawChar(66, 151, 's', ST7735_Color565(255, 0, 255), 0, 1);
  ST7735_DrawChar(72, 151, 't', ST7735_Color565(255, 255, 255), 0, 1);
  DelayWait10ms(1000);

  // test DrawBitmap() including clipping test with images off the screen
  ST7735_FillScreen(0xFFFF);            // set screen to white
  ST7735_DrawBitmap(0, 5, Test2, 5, 6);   // top left corner of the screen
  ST7735_DrawBitmap(59, 74, Test2, 5, 6); // center of the screen
  ST7735_DrawBitmap(125, 74, Test2, 5, 6);// clip right
  ST7735_DrawBitmap(59, 162, Test2, 5, 6);// clip bottom
  ST7735_DrawBitmap(-2, 74, Test2, 5, 6); // clip left
  ST7735_DrawBitmap(59, 2, Test2, 5, 6);  // clip top
  DelayWait10ms(1000);

  ST7735_FillScreen(0xFFFF);            // set screen to white
  x = 44;
  y = 159;
  dx = 1;
  dy = 1;
  while(1){
    ST7735_DrawBitmap(x, y, Logo, 40, 160);
    x = x + dx;
    y = y + dy;
    if((x >= (ST7735_TFTWIDTH - 40 + 15)) || (x <= -15)){
      dx = -1*dx;
    }
    if((y >= (ST7735_TFTHEIGHT + 8)) || (y <= (ST7735_TFTHEIGHT - 8))){
      dy = -1*dy;
    }
  }
}
// private function draws a color band on the screen
void static drawthecolors(uint8_t red, uint8_t green, uint8_t blue){
  static uint16_t y = 0;
  ST7735_DrawFastHLine(0, y, ST7735_TFTWIDTH, ST7735_Color565(red, green, blue));
  y = y + 1;
  if(y >= ST7735_TFTHEIGHT){
     y = 0;
  }
  DelayWait10ms(1);
}
int main3(void){
  uint8_t red, green, blue;
  PLL_Init();                           // set system clock to 80 MHz
  // test DrawChar() and DrawCharS()
  ST7735_InitR(INITR_REDTAB);
>>>>>>> origin/master

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
