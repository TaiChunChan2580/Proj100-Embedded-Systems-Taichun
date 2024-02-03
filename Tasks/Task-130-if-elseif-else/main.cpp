#include "uop_msb.h"
using namespace uop_msb;

DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1); //Button B
DigitalIn ButtonC(PG_2, PullDown); //Button C
DigitalIn ButtonD(PG_3, PullDown); //Button D

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    int count = 0;

    //Turn ON the 7-segment display
    disp.enable(true);

    //Update display
    disp = count;

    while (true) {
        
        //Read button without blocking
        int btnA = ButtonA;     //Local to the while-loop  

        //Task 5
        int btnB = ButtonB;

        //Test Button A
        if (btnA == 1) {
            redLED = !redLED;    //Toggle RED led
            count = count + 1;           //Increment count
            disp = count;       //Update display
        }

        ////Task 5
        //if (btnB == 1) {
        //    redLED = !redLED;    //Toggle RED led
        //    count = count - 1;            //Increment count
        //    disp = count;       //Update display
        //}

        //Task 7
        else if (btnB == 1) {
            redLED = !redLED;    //Toggle RED led
            //count = count - 1;            //Increment count
            //Task 10
            count = count - ((count>0) ? 1 : 0 );            //Increment count
            disp = count;       //Update display
        }

        else if (btnA == 1 & btnB == 1) {
            redLED = !redLED;    //Toggle RED led
            count = count + 1;            //Increment count
            disp = count;       //Update display
        }

        //Task 8
        else {
            greenLED = 1;// green light turns on
            wait_us(100000);//wait a 0.1s
            greenLED = 0;// green light turns off
            wait_us(100000);//wait a 0.1s
        }

        //Task 9
        if (count > 99) { //if count is larger than 99 then it keeps count at 99
            count = 99;
            disp = count;
        }

        //else if (count < 0) { //if count is smaller than 0 then it keeps count at 0
        //    count = 0;
        //    disp = count;
        //}


        // Slow it down a bit (and debounce the switches)
        wait_us(100000);  
    }
}

//task 3
//The number goes to .1 instead of going up

//Task 6
//when both button is pressed the number does not increase or decrease