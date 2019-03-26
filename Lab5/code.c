//MCA

#include "DSK6713_AIC23.h"	        
#include "coeffTable.h"  

// j Unutma !!

Uint32 fs=DSK6713_AIC23_FREQ_16KHZ;	//set sampling rate

#define DSK6713_AIC23_INPUT_MIC 0x0015
#define DSK6713_AIC23_INPUT_LINE 0x0011
Uint16 inputsource=DSK6713_AIC23_INPUT_MIC; 

short n = 11;
short output = 0;
short dummy[11];

void main()
{
  short sample_data = 0;

  comm_poll();	            
  DSK6713_LED_init();			      
  DSK6713_DIP_init();			      


  while(1)				    
  {
    sample_data = input_left_sample(); //input sample
	
    if(DSK6713_DIP_get(0)==0) 		  //DIP switch is pressed?
    {

    	short i;
    	output = 0;
    	dummy[0] = sample_data;
	
		//Applying FILTER:
    	for(i = 0; i<n; i++) {
			
    		output += ( fir_10[i] * dummy[i] ); 
			
		}
		
    	for(i = n-1; i>0; i--) {
			
    		dummy[i] = dummy[i-1]; 
			
		}

    	output_left_sample(output);

    }

    else { output_left_sample(sample_data);   }


  }
}
 
