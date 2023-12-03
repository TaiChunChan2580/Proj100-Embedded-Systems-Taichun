#include "mbed.h"

DigitalIn ButtonA(PG_0);                    //Button A
DigitalIn BlueButton(USER_BUTTON);          //Blue user button
DigitalOut redLED(PC_2);                    //Red Traffic 1

int main()
{
    redLED = 0;

    while (true) {

        //Wait for a press
        //while (ButtonA==0) { };
        while (BlueButton==0) { };

        //Wait for bounce to settle
        //wait_us(100000); // task 4
        //wait_us(1); //task 5
        wait_us(5000000); //task 6

        //Toggle LED
        redLED = !redLED;

        //Wait for release
        //while (ButtonA==1) { };
        while (BlueButton==1) { };

        //Wait for bounce to settle
        //wait_us(100000); // task 4
        //wait_us(1); //task 5
        wait_us(5000000); //task 6
    }
}

//task 3
//the button seems to be running fine all the time when it is Button A
//But for the Blue button sometimes the light flickers

//task 4
//It improves it alot as it doesn't flicker now

//task 5
//The 1 us wait time is to quick and it bouces quite often

//task 6
//5 seconds is way too long even though the dounce is resolved the led takes to long to light up