//loop_poll.c loop program using polling
#include "DSK6713_AIC23.h"	        //codec support
Uint32 fs=DSK6713_AIC23_FREQ_44KHZ;	//set sampling rate
#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC; // select input



float estimatePower(short int inputSample, float decayCoeff, float prevPower) {

    float estPower;

    estPower = decayCoeff*inputSample*inputSample;

    estPower = estPower + (1-decayCoeff)*prevPower;

    return estPower;

}



void main()
{
  short sample_data;

  int i= 1;
  float estPower[128];

  estPower[0] = 0;


  comm_poll();	            //init DSK, codec, McBSP
  while(1)				    //infinite loop
  {
    sample_data = input_left_sample(); //input sample

    estPower[i] = estimatePower(sample_data, 0.1, estPower[i-1]);

    if(i == 128) {
    	i =0;
    }

    i++;

    output_left_sample(sample_data);   //output sample


  }
}
 
