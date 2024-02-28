#include "uop_msb.h"
#include <chrono>
using namespace uop_msb;

AnalogIn pot(AN_POT_PIN);
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut dispBackLight(LCD_BKL_PIN);
LCD_16X2_DISPLAY disp;

extern int getAverageDelay(double alpha);

int main()
{
    //Update display
    disp.cls();
    disp.printf("Timers");
    dispBackLight = 1;

    //Implement a delay (BLOCKING)
    Timer tmr;
    tmr.start();
    while (tmr.elapsed_time() < 2s);

    //Update display
    disp.locate(1, 0);
    disp.printf("Turn the POT");

    //Implement another delay (BLOCKING)
    tmr.reset();
    while (tmr.elapsed_time() < 2s);

    //Get initial delay value
    float Ton = pot;

    // Now we use Timer in WITHOUT BLOCKING

    typedef enum {OFF, ON} LCD_STATE;
    LCD_STATE state = ON;

    while(true) {
        
        switch (state)
        {
            case ON:
                if (tmr.elapsed_time() > (Ton*1ms)) { //tmr<Ton
                    state = OFF;
                    dispBackLight = 0; // Backlight = 0
                }
                break;

            case OFF:
                if (tmr.elapsed_time()>=1ms) { //tmr<Tp
                    state = ON;
                    dispBackLight = 1; //backlight = 1
                    Ton = pot; //ton = pot
                    tmr.reset();
                }
                break;
        }

    }

}

//Task 2
//It changes the brightness of the lcd screen

//Task 3
//Very minor flickering

//Task4
//on the code