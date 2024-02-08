#include "uop_msb.h"
#include <chrono>
#include <ratio>
using namespace uop_msb;
using namespace chrono;

//Count variable
int counter=0;

InterruptIn btnA(BTN1_PIN);
InterruptIn btnB(BTN2_PIN);
Ticker tick;

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);


void funcA()//Task 3 led part
{
    redLED = !redLED;//Task 3 led part
}

void funcB()//Task 3 led part
{
    yellowLED = !yellowLED;//Task 3 led part
}

void funcTmr()//Task 3 led part
{
    greenLED = !greenLED;//Task 3 led part
}

int main()
{
    //Set up interrupts
    btnA.rise(&funcA);//Task 3 led part
    btnB.fall(&funcB);//Task 3 led part
    tick.attach(&funcTmr, 500ms);
    
    //Main loop - mostly sleeps :)
    while (true) {
        sleep();

        printf("I have been woken %d times\n", ++counter);
    }
}

//Task 2
//and the counter increaces by 1 every time

//task 7 
//when a is pressed red led gets toggled on or off

//task 9 
//when b is pressed yellow led gets toggled on or off

