#include "mbed.h"
#include "myutils.hpp"

DigitalOut redLED(PC_2,0);
DigitalOut yellowLED(PC_3,0);
DigitalOut greenLED(PC_6,0);

int main()
{
    int grade=-1, hits=0;

    printf("\n\nPress Return to Start\n\n");

    //while (hits < 1) {                               //for task4
    while ( (hits < 1) || (grade>=100) || (grade<0) ) {//for task4

        //Clear out the serial port (keyboard)
        flushInputBuffer();
        //Prompt user
        printf("\nEnter grade (0..100)\n");
        //Read response
        hits = scanf("%d", &grade);
    }

    //Write results
    printf("scanf found %d hits\n",hits);
    printf("Grade entered = %d\n", grade);
    greenLED = 1;
    
    //Loop forever
    while (true);
}

//task 3
//50 50a 110 says "scanf found 1 hits" and say Grade entered
//xx it just repeats "Enter grade (0..100)"

//task 5
//xzy and 100 just repeats "Enter grade (0..100)"
//50 says "scanf found 1 hits" and say "Grade entered = 50"

//task 6
//couldn't find errors