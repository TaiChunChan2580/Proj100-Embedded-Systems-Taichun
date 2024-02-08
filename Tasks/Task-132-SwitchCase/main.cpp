#include "uop_msb.h"
using namespace uop_msb;

BusIn buttons(PG_0, PG_1, PG_2, PG_3);

DigitalOut redLED(TRAF_RED1_PIN);       //Red Traffic 1
DigitalOut yellowLED(TRAF_YEL1_PIN);    //Yellow Traffic 1
DigitalOut greenLED(TRAF_GRN1_PIN);     //Green Traffic 1

//Dual Digit 7-segment Display
LatchedLED disp(LatchedLED::SEVEN_SEG);

int main()
{
    int count = 0;
    
    //Configure switches
    buttons[2].mode(PullDown);
    buttons[3].mode(PullDown);

    //Turn ON the 7-segment display
    disp.enable(true);

    //Update display
    disp = count;

    while (true) {
        
        //Read button without blocking
        int btn = buttons;     //Local to the while-loop  

        //switch (btn) {
        //    case 0:
            //Nothing pressed
        //    greenLED = 0;
        //    yellowLED = 0;
        //    redLED = !redLED;
        //    break;

        //    case 1:
            //Button A only
        //    redLED = 0;
        //    yellowLED = 0;            
        //    greenLED = !greenLED;
        //    break;

        //    case 3: 
            //Button A and B
        //    redLED = 0;
        //    yellowLED = !yellowLED;            
        //    greenLED = 0;
        //    break;

        //    default:
            //All others
        //    greenLED = 0;
        //    yellowLED = 0;
        //    redLED = 0;
        //    break;

        //}

        //Task 4
        switch (btn) {
            case 1:
            //when A is pressed the red led flashes
            greenLED = 0;
            yellowLED = 0;
            redLED = !redLED;
            break;

            case 2:
            //when B is pressed the yellow led flashes
            redLED = 0;
            yellowLED = !yellowLED;            
            greenLED = 0;
            break;

            case 4:
            //when C is pressed the green led flashes
            redLED = 0;
            yellowLED = 0;            
            greenLED = !greenLED;
            break;

            //Task 5
            case 8:
            //when D is pressedat all all leds flashes
            redLED = !redLED;
            yellowLED = !yellowLED;            
            greenLED = !greenLED;
            break;

            //Task 5
            case 9:
            //when D is pressedat all all leds flashes
            redLED = !redLED;
            yellowLED = !yellowLED;            
            greenLED = !greenLED;
            break;

            //Task 5
            case 10:
            //when D is pressedat all all leds flashes
            redLED = !redLED;
            yellowLED = !yellowLED;            
            greenLED = !greenLED;
            break;

            //Task 5
            case 11:
            //when D is pressedat all all leds flashes
            redLED = !redLED;
            yellowLED = !yellowLED;            
            greenLED = !greenLED;
            break;

            //Task 5
            case 12:
            //when D is pressedat all all leds flashes
            redLED = !redLED;
            yellowLED = !yellowLED;            
            greenLED = !greenLED;
            break;

            //Task 5
            case 13:
            //when D is pressedat all all leds flashes
            redLED = !redLED;
            yellowLED = !yellowLED;            
            greenLED = !greenLED;
            break;

            //Task 5
            case 14:
            //when D is pressedat all all leds flashes
            redLED = !redLED;
            yellowLED = !yellowLED;            
            greenLED = !greenLED;
            break;

            //Task 5
            case 15:
            //when D is pressedat all all leds flashes
            redLED = !redLED;
            yellowLED = !yellowLED;            
            greenLED = !greenLED;
            break;

            default:
            //All others
            greenLED = 1;
            yellowLED = 1;
            redLED = 1;
            break;

        }

        // Slow it down a bit (and debounce the switches)
        wait_us(100000);  
    }
}


//Task 2
//When A is pressed only green light is flashing
//when A B is pressed only yellow light flashes
//when A B C is pressed no lights are on because the default as that is where the case of ABC button press would lead too
