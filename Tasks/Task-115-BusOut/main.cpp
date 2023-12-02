#include "mbed.h"
#define WAIT_TIME_MS 1000 


// DigitalOut redLED(PC_2,1);
// DigitalOut yellowLED(PC_3,1);
// DigitalOut greenLED(PC_6,1);

//BusOut lights(PC_2, PC_3, PC_6);
BusOut lights(PC_2, PC_3, PC_6, PB_0, PB_7, PB_14);

int main()
{
    //All OFF
    lights = 0b000;

    while (true)
    {
        //int count = 7;//changed to count down from 7
        int count = 63;//changed to count down from 63 since it largest value (Task 7)
        while (count >= 0) //change so it stop when it hits 0
        {
            printf("count = %d\n", count);
            lights = count;
            wait_us(250000);//reduced time to 0.25s for task 7

            count = count - 1;//take away 1 so it counts down
        }
    }
}

//Task busout 3
//Green on when =4,5,6,7
//yellow on when =2,3,6,7
//red on when =1,3,5,7
//therefore binary table is (both tables they are the same)
//0   0   0   0
//1   0   0   1
//2   0   1   0
//3   0   1   1
//4   1   0   0
//5   1   0   1
//6   1   1   0
//7   1   1   1

//task 6 111111 to decimal is 63