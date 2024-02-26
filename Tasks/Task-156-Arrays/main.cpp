#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;

//Output
DigitalOut redLED(TRAF_RED1_PIN);
DigitalOut yellowLED(TRAF_YEL1_PIN);
DigitalOut greenLED(TRAF_GRN1_PIN);

//Analogue Inputs
AnalogIn ldr(AN_LDR_PIN);
Buzzer buzz;
double val = 0 ;//val is value

int main()
{
    unsigned short samples[100];

    for (unsigned int m=0; m<100; m++) {
        printf("%X ", samples[m]);
    }

    // Automatic headlamp 
    while (true) {

        for (unsigned int m=0; m<100; m++) {
            unsigned short ldrVal   = ldr.read_u16();
            samples[m] = ldrVal;
            val = val + ldrVal ;//Task 2
            wait_us(10000);          // 10ms
        }


        //Task 3
        // TASK a. Calculate the average value in samples
        int avrVal = val / 100 ;
        printf ("\nthe average is %X \n", avrVal ) ;
        printf ("in decimal it is %d \n", avrVal );
        // TASK b. Display to 1dp
        double avrVald = val / 100 ;
        printf ("with decimals it is %f\n", avrVald ) ;
        // TASK c. Switch green LED on when dark;
        if(avrVal > 35000 ){
            greenLED=1;
        }
        else{
            greenLED=0;
        }
        break;
    }  
}

//Task 2
//every time I run the program  a random array of number is printed
