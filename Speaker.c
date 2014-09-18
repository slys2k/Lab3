#include <stdio.h>
#include <stdint.h>
int w,h,plapotatoTime,songElapsed=0;
int random,potato;
void PlapotatoMusic(int* song){
	int16_t songPart = 0;            
  int16_t songWidth = w;            
  int i = random*(potato - 41);

  if ((songWidth <= i) &&((songWidth - songPart + 41) <= songElapsed) ){ // just make sure song is valid

		return;                            
  }
   
}

	
