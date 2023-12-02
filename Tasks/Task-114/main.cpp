//task General Purpose Input Output (GPIO)
//task3 red led is PC_2,1
//task3 yellow led is PC_3,1
//task3 green led is PC_6,1

#include "mbed.h"
DigitalOut red(PC_2,1);
DigitalOut yellow(PC_3,1);
DigitalOut green(PC_6,1);


int main()
{
    //power on test for all 3 leds
    red = 1;
    yellow = 1;
    green = 1;
    wait_us (2000000);// test for 2s
    red = 0;
    yellow = 0;
    green = 0;

    //the trafficlight sequence where each stage lasts 2s and repeats
    while (true) {
        //red light on for 2s
        red = 1;
        wait_us (2000000);

        //red and yellow light on for 2s
        yellow = 1;
        wait_us (2000000);

        //only green light on for 2s(turns off red and yellow)
        red = 0;
        yellow = 0;
        green = 1;
        wait_us (2000000);

        //turns off green and yellow flashes 4 times
        green = 0 ;
        int count = 0;
        while (count < 3){
            yellow = 1 ;
            wait_us (500000);
            yellow = 0;
            wait_us (500000);
            count = count + 1;
        }

    }
}