#include "mbed.h"

PortOut lights(PortC, 0b0000000001001100);

int main()
{
    //All OFF
    lights = 0;

    while (true)
    {   
        //since red is 0b0000000000000100
        //yellow is 0b0000000000001000
        //and green is 0b0000000001000000
        //therefore
        lights = 0b0000000000001100;//red and yellow light on
        wait_us(1000000);
        lights = 0b0000000001001000;//yellow and green on
        wait_us(1000000);
        lights = 0b0000000001000100;//green and red on
        wait_us(1000000);                
    }
}
