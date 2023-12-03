#include "mbed.h"

DigitalIn ButtonA(PG_0); //Button A
DigitalIn ButtonB(PG_1); //Button B task 4
DigitalIn ButtonC(PG_2, PinMode::PullDown); //Button C Task 6
DigitalIn ButtonD(PG_3, PinMode::PullDown); //Button D Task 6
DigitalOut redLED(PC_2); //Red Traffic 1

// main() runs in its own thread in the OS
int main()
{
    //int btnA;
    int btnp; // button pressed
    // Turn OFF the red LED
    redLED = 0;

    while (true) {
    
        // Wait for the button to be pressed
        //do {
        //    btnA = ButtonA; //Read button A
        //} while (btnA == 0);

        //Task 5
        //Wait for A or B to be pressed
        //do {
        //    btnp = ButtonA || ButtonB; //Read either A or B when pressed
        //} while (btnp == 0);

        //Toggle the red LED
        //redLED = !redLED;

        //Wait for noise to settle
        //wait_us(10000);

        // Wait for the button to be released
        //do {
        //    btnA = ButtonA; //Read button A
        //} while (btnA == 1);

        //Task 5
        //Wait for A or B to be released
        //do {
        //    btnp = ButtonA || ButtonB; //Read either A or B when released
        //} while (btnp == 1);

        //Task 6
        //Wait for all button to be pressed
        do {
            btnp = ButtonA&&ButtonB&&ButtonC&&ButtonD; //Read button A
        } while (btnp == 0);

        //Wait for noise to settle
        wait_us(10000);

        //Wait for all button to be released
        do {
            btnp = ButtonA&&ButtonB&&ButtonC&&ButtonD; //Read button A
        } while (btnp == 1);

        //Toggle the red LED
        redLED = !redLED;

        //Wait for noise to settle
        wait_us(10000);
    }
}
//task 2
//button A it turns on the red led  and when you press it again it turn it off