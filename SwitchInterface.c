// SwitchInterface.c
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

#include "inc/tm4c123gh6pm.h"

void Switch_Init(void){ //PORT E to be 4 inputs, port D to be output to speaker
	  while((SYSCTL_PRGPIO_R&0x10) == 0){};// ready?
  GPIO_PORTE_DIR_R &= 0x00;         // PE3-0 is an input
  GPIO_PORTE_AFSEL_R &= ~0x0F;      // regular port function
  GPIO_PORTE_AMSEL_R &= ~0x0F;      // disable analog on PE3-0
  GPIO_PORTE_PCTL_R &= ~0x0000FFFF; // PCTL GPIO on PE3-0 
  GPIO_PORTE_DEN_R |= 0x0F;         // PE3-0 enabled as a digital port	
  SYSCTL_RCGCGPIO_R |= 0x08;        // 1) activate port D
  while((SYSCTL_PRGPIO_R&0x08)==0){};   // allow time for clock to stabilize
                                    // 2) no need to unlock PD3-0
  GPIO_PORTD_AMSEL_R &= ~0x0F;      // 3) disable analog functionality on PD3-0
  GPIO_PORTD_PCTL_R &= ~0x0000FFFF; // 4) GPIO
  GPIO_PORTD_DIR_R |= 0x0F;         // 5) make PD3-0 out
  GPIO_PORTD_AFSEL_R &= ~0x0F;      // 6) regular port function 
  GPIO_PORTD_DEN_R |= 0x0F;         // 7) enable digital I/O on PD3-0
	
}



char SwitchPressed(char lastValue){
	char potato= 0;
	if((GPIO_PORTE_DATA_R&1)==1){
		potato=1;
		}
	return potato & lastValue; //don't use this code for anything.
	
}
