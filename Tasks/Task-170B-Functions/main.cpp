#include "uop_msb.h"

// LED Bar Display
BusOut dataBits(LED_D0_PIN, LED_D1_PIN, LED_D2_PIN, LED_D3_PIN, LED_D4_PIN, LED_D5_PIN, LED_D6_PIN, LED_D7_PIN);
DigitalOut LED_BAR_OE(LED_BAR_OE_PIN,1);
DigitalOut LED_RED_LE(LED_RED_LE_PIN);
DigitalOut LED_GRN_LE(LED_GRN_LE_PIN);
DigitalOut LED_BLUE_LE(LED_BLUE_LE_PIN);

//Task 9
void setLatch(uint8_t dat, char col);
void led_init(uint8_t dat, bool enabled);

int main()
{
    printf("Functions demo\n");

    led_init(0x00, true);

    while (true) {

        //Update the red
        setLatch(0xFF,'r');

        //Update the green
        setLatch(0b10101010, 'g');

        //Update the blue
        setLatch(0b11001100, 'b');


        for (unsigned int n=0; n<10; n++) {
            //Enable all the LED BAR Latch Outputs
            LED_BAR_OE = 0;

            //Wait
            wait_us(500000);

            //Disable the latch outputs
            LED_BAR_OE = 1;

            //Wait
            wait_us(500000);            
        }

        //Spin forever
        while(true);

    }
}

//Task 6
void setLatch(uint8_t dat, char col)
{
    
    wait_us(1);
    dataBits = dat;    //Set the 8-bit data pattern
    wait_us(1);

    //cases for the colours
    switch (col)
    {   
        case 'b': //Blue Led
            LED_BLUE_LE  = 1;//on
            wait_us(10000);
            LED_BLUE_LE  = 0;//off
            break;

        case 'r': //Red Led
            LED_RED_LE  = 1;//on
            wait_us(10000);
            LED_RED_LE  = 0;//off
            break;

        case 'g': //green Led
            LED_GRN_LE  = 1;//on
            wait_us(10000);
            LED_GRN_LE  = 0;//off
            break;

    }
    wait_us(10000);
}

void led_init(uint8_t dat, bool enabled) //Task 6
{   

    //Disable the LED outputs
    unsigned int LED_BAR_OE = 1;

    //Set data to 0
    unsigned int dataBits = 0;

    //Give a little time
    wait_us(1);

    //Enable all latches
    unsigned int LED_RED_LE  = 1;
    unsigned int LED_GRN_LE  = 1;
    unsigned int LED_BLUE_LE  = 1;

    //Give a little time
    wait_us(1);

    //Enable all latches
    LED_RED_LE  = 0;
    LED_GRN_LE  = 0;
    LED_BLUE_LE  = 0;
}



//Task 8
//failed to run program and 4 errors are generated since the Led_init part of the codes are not defined but task 9 fixes the issue