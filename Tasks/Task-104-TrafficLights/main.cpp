#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 

DigitalOut red(TRAF_RED1_PIN,1);         //Note the initial state
DigitalOut amber(TRAF_YEL1_PIN,0);
DigitalOut green(TRAF_GRN1_PIN,0);

LCD_16X2_DISPLAY lcd;

int main()
{
    lcd.puts("RED");
    wait_us(1000000);

    amber = 1;
    lcd.cls();
    lcd.puts("Amber");
    wait_us(1000000);

    green = 1;
    lcd.cls();
    lcd.puts("Green");    
    wait_us(1000000);

    lcd.cls();
    lcd.puts("TASK-104");



    //Task 5 and 6
    amber = 0;
    green = 0;
    red = 0;
    int count = 0;
    while (true)
    {
        red = !red; //turns on red
        wait_us(10000000); //waits 10s

        //flashes amber 4 times while leaving red on for a total of 2s then turning both off
        while (count < 8) {
            amber = !amber;
            wait_us (250000);
            count = count+1;
        }
        count = 0;
        red = !red;

        //turns on green waits 10s then turns it off
        green = !green;
        wait_us(10000000);
        green = !green;

        //flashes amber 4 times for a total of 2s
        while (count < 8) {
            amber = !amber;
            wait_us (250000);
            count = count+1;
        }
        count = 0;

        wait_us(WAIT_TIME_MS * 1000);
    }
}
