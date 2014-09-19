// Lab3.c
// Runs on LM4F120/TM4C123
// This program implements an alarm clock with functionality to set time, alarm
// time, and display mode. It also implements an external speaker for the buzzer
// of the alarm clock.
// patterns to the LCD.
// Keith Cyr and Omar Marawi
// September 19, 2013

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


/******* includes ******/
#include <stdio.h>
#include <stdint.h>
#include "inc/tm4c123gh6pm.h"          // Dev Board files
#include "PLL.h"                       // Phase Lock Loop driver
#include "SysTick.h"                     // Sets up timers and interrupts
#include "LCDInterface.h"              // OLED driver
#include "TimerInterface.h"            // Timer interface to activate SysTick
#include "SwitchInterface.h"           // Alarm Clock external switch interface
#include "SpeakerInterface.h"          // Alarm Clock external speaker interface

/****** defined constants ******/
#define SYSTICKFREQ 0x00FFFFFF         // @OMAR What is this?

/****** global variables ******/
int interruptNumber = 0;
int currentTime = 1;
int timeKeep[3];
int x = 0;

/****** native test function prototypes ******/
// function declarations can be found below main().

/****** native utility function prototypes ******/
// function declarations can be found below main().
// ideally, this should be a near-empty list given proper modularity
void DelayWait10ms(uint32_t n);        // 

/****** main algorithm ******/

int main(void){
// declare and initialize local variables

// Initialize Modules
   PLL_Init();                         // 80 Mhz
   SysTick_Init();                     // initialize systick and interrupts
   Speaker_Init();                     // 
   Timer_Init();                       // 
   LCD_Init();                         // 
   Switch_Init();                      //

// main loop
   while(1){
   // get current time
   // update display
   // 
   
   
   }
}

/****** mains used for unit test ******/

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


