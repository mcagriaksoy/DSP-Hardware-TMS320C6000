# DSP-Hardware

This repo is created for Digital Signal Processing Hardware Lecture which is ongoing 2018 Anadolu University. 

Course Website: http://eem.eskisehir.edu.tr/Ders.aspx?dersId=182


Lab1: - Introduction the board, sin wave creation in DSP

Lab2: - In this laboratory, we experienced to generate a waveform from look-up table or sin() function from math.h library. It was more sensible to generate the sine wave using the sin function from library instead of the look-up table because producing the table has disadvantage both in time and space complexity. Look-up table occupies a memory section. Instead we can use math.h function to do calculation and give result instead of store them. Also, we can adjust frequency easily with Part B method.

Lab 2 Part C Ramp Wave Result:
![DSP-HW](https://github.com/mcagriaksoy/DSP-Hardware-TMS320C6000/blob/master/Lab2_DSP/c.JPG)

Lab3: - In this experiment, normal assembly and linear assembly languages were processed. The differences between them were seen. Some interactions (like SUB, ADD, ABS..) were practiced by writing the code. By defining a threshold point, this limit was used in both normal and linear assembly languages.

Lab4: - Power calculation from mic. input and output the input sound. Inthis experiment, we discussed about the effect of the sampling frequencies and power values. At both low and high frequencies, the sound was heard not good. But at 44 Khz, the best sound was heard.And second part, we observed that the sound power variesaccording to the sound leveland as a result of our observations in thisexperiment, we found a linear relationship between the these two.


Lab5: FIR Low-Pass Filter design and integrate on board. Take data from input (mic) multiply with our filter and output the data.

Lab 5 Output of filter (below image):
![DSP-HW](https://github.com/mcagriaksoy/DSP-Hardware-TMS320C6000/blob/master/Lab5/50_son.PNG)




# Board

![DSP-HW](https://github.com/mcagriaksoy/DSP-Hardware-TMS320C6000/blob/master/s-l1600.jpg)

