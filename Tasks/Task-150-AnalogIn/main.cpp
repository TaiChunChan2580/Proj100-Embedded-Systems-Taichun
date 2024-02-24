#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Fun output stuff
LCD_16X2_DISPLAY disp;
Buzzer buzz;
LatchedLED ledDisp(LatchedLED::STRIP);

//Analogue Inputs
AnalogIn pot(AN_POT_PIN);
AnalogIn ldr(AN_LDR_PIN);
AnalogIn mic(MIC_AN_PIN);

//led pins Task 13
DigitalOut red(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellow(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut green(TRAF_GRN1_PIN);     //Green Traffic 1

int main()
{

    //Test LED Bar Display
    ledDisp.enable(true);

    ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;

    ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;
    
    ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }     
    ledDisp = 0;


    while (true) {
        //Read Analog to Digital Converter values (16 bit)
        unsigned short potVal   = pot.read_u16();
        unsigned short lightVal = ldr.read_u16();
        //unsigned 
        //short 
        int micVal   = mic.read_u16(); //Task 11

        //Write to terminal
        printf("--------------------------------\n");
        printf("Potentiometer: %X\n", potVal);
        //printf("Light Dependant Resistor: %X\n", lightVal);
        //printf("Microphone: %X\n", micVal);   

        //Task 13
        if (potVal > 0x8000){
            yellow = 1;
        }
        else{
            yellow = 0;
        }
        printf("Light Dependant Resistor: %d\n", lightVal);
        if (lightVal < 2000){
            green = 1 ;
        }
        else{
            green = 0 ;
        }
        
        //when clap
        int count = micVal - 0x8000 ;
        printf("Microphone: %d\n", count);   
        if (micVal > 0x8000){
            red = 1;
        }
        else{
            red=0 ;
        }

        //Wait 0.25 seconds
        wait_us(500000);

    }
}

//Task 3 
//the value on the light depenent resistor decreaces

//Task 4
//the value on the potentiometer dial changes from 0 to FFFF where 0 is min and FFFFis max

//Task5
//i was able to generate bigger changes in the microphone value by brushing the microphone

//Task 6
//for the light dependent resistor it might be because of external effects and for the microphone it might because of white noises from the surounding and for the potentiometer it because of external affects

//task 7
//the value goes down when the light is shone on it

//task 8 
//the resistance on the LDR goes down and am able to reach 0 and FFFF on the pot

//Task 9
//it is hard to get the excat value since a little change in pot has big change in value

//Task 10
//about 8100

//Task 12
//it dont seem to go negative but just very large value

//Task 13
//possible but difficult