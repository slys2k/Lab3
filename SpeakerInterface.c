// SpeakerInterface.c
// Runs on LM4F120/TM4C123
// @TODO: This program...
// Keith Cyr and Omar Marawi
// September 19, 2013

/******* includes ******/
#include <stdio.h>
#include <stdint.h>

/****** defined constants ******/

/****** global variables ******/
int w;
int h;
int plapotatoTime;
int songElapsed = 0;
int random;
int potato;

/****** private functions ******/

/****** public utility functions ******/



void PlapotatoMusic(int* song){
   int16_t songPart = 0;            
  int16_t songWidth = w;            
  int i = random*(potato - 41);

  if ((songWidth <= i) &&((songWidth - songPart + 41) <= songElapsed) ){ // just make sure song is valid

      return;                            
  }
   
}

   
