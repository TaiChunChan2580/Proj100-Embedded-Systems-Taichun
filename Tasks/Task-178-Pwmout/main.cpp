#include "uop_msb.h"
#include <chrono>
using namespace uop_msb;
extern int getAverageDelay(double alpha);

AnalogIn pot(AN_POT_PIN);
DigitalOut redLED(TRAF_RED1_PIN);
LCD_16X2_DISPLAY disp;
PwmOut dispBackLight(LCD_BKL_PIN);

//Task 4
DigitalOut led1(LED1);

//Task 5
AnalogIn ldr(AN_LDR_PIN);

int main()
{
    //Configure the PWM for the backlight 
    dispBackLight.period(0.001f);   // 1ms
    dispBackLight.write(1.0);       // 100% duty

    //Update display
    disp.cls();
    disp.printf("PwmOut");

    //Implement a delay (BLOCKING)
    wait_us(2000000);

    //Update display
    disp.locate(1, 0);
    disp.printf("Turn the POT");

    //Implement another delay (BLOCKING)
    wait_us(2000000);

    //Timer for the pot
    Timer tmr;
    tmr.start();

    //Task 6 to iniitate value
    float u = pot;
    int count = 0;

    while(true) {
        
        //Once every 100ms, re-read the POT and update the duty
        if (tmr.elapsed_time() >= 250ms) {
            u = pot;              // Every 250ms, read the pot... 
            dispBackLight.write(u);     // ... and update the brightness.
            led1.write(u);//Task 5
            tmr.reset();
        }
        
        
        
        //Other non-blocking code could go here

        //Task 5 measures the ldr value and prints it
        unsigned short ldrv = ldr.read_u16();
        printf("Light Dependant Resistor: %d\n", ldrv);
        
        //Task 6
        if (tmr.elapsed_time() >= 250ms) {
            count = count + 1;//wait it it counts 4 ticks so 4x of 250ms
            if (count == 3){
                disp.cls();
                disp.locate(0, 0);
                unsigned short potv = pot.read_u16();// reads the value of the pot
                disp.printf("Pot value: %X ", potv);//print pot value on lcd screen
                count = 0;//resets counter so it can repeat the loop
            }
        }
    }
}

//Task 2
//the change in the lcd brightness is very choppy


