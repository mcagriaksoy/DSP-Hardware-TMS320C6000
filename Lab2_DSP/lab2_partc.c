//sine8_LED.c  sine generation with DIP switch control

#include "dsk6713_aic23.h"  	       //codec support
#include "sinTable.h"
#include <math.h>

Uint32 fs = DSK6713_AIC23_FREQ_96KHZ;   //set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011

Uint16 inputsource=DSK6713_AIC23_INPUT_MIC;//select input
#define LOOPLENGTH 0x3fff
short loopindex = 0x00;         	      //table index
float gain = 0.5;			          //gain factor


void main()
{

  comm_poll();              	      //init DSK,codec,McBSP
  DSK6713_LED_init();			      //init LED from BSL
  DSK6713_DIP_init();			      //init DIP from BSL
  double i = 0 ;
  while(1) 				              //infinite loop
  {
    if(DSK6713_DIP_get(0)==0) 		  //=0 if DIP switch #0 pressed
    {
      DSK6713_LED_on();//turn LED #0 ON

      output_left_sample((short)(loopindex*gain)); //output sample
      loopindex += 0x20;

      if (loopindex >= LOOPLENGTH) loopindex = 0; //reset table index
    }
    else DSK6713_LED_off(0); 		  //turn LED off if not pressed
  }                                   //end of while(1) infinite loop
}					                  //end of main
