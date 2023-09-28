// You need this to use the Module Support Board
#include "uop_msb.h"
using namespace uop_msb;

#define WAIT_TIME_MS 500 
DigitalOut greenLED(TRAF_GRN1_PIN);
Buzzer buzz;
Buttons buttons;

// TIP: (I suggest you read this!)
//
// Press the black reset button to restart the code (and stop the sound)
// Otherwise, the noise can be "distracting" :)

int main()
{
    //Wait for the BLUE button to be pressed (otherwise this becomes super annoying!)
    while (buttons.BlueButton == 0);
    
    //Repeat everything "forever" (until the power is removed or the chip is reset)
    //plays the mosrse code with Modify the code to repeatedly play a major scale (C,D,E,F,G,A,B,C).(task 6) but instead of each not playing for 250ms it follows the morese timing
    while (true)
    {
        //S Morse code part
        //On for 500ms
        //dot morse code part
        greenLED = 1; //on led
        buzz.playTone("C");// plays the tone C
        wait_us(WAIT_TIME_MS * 150);  //150ms
        greenLED = 0; //off led
        buzz.rest(); //off buzzer
        wait_us(WAIT_TIME_MS * 150);  //150ms

        greenLED = 1; //on led
        buzz.playTone("D");// plays the tone D
        wait_us(WAIT_TIME_MS * 150);  //150ms
        greenLED = 0; //off led
        buzz.rest();//off buzzer
        wait_us(WAIT_TIME_MS * 150);  //150ms

        greenLED = 1; //on led
        buzz.playTone("E");// plays the tone E
        wait_us(WAIT_TIME_MS * 150);  //150ms
        greenLED = 0; //off led
        buzz.rest();//off buzzer
        wait_us(WAIT_TIME_MS * 450);  //450ms

        greenLED = 1; //on led
        buzz.playTone("F");// plays the tone F
        wait_us(WAIT_TIME_MS * 450);  //450ms
        greenLED = 0; //off led
        buzz.rest();//off buzzer
        wait_us(WAIT_TIME_MS * 150);  //150ms

        greenLED = 1; //on led
        buzz.playTone("G");// plays the tone G
        wait_us(WAIT_TIME_MS * 450);  //450ms
        greenLED = 0; //off led
        buzz.rest();//off buzzer
        wait_us(WAIT_TIME_MS * 150);  //150ms

        greenLED = 1; //on led
        buzz.playTone("A", Buzzer::HIGHER_OCTAVE);// plays the tone A on a higher octave
        wait_us(WAIT_TIME_MS * 450);  //450ms
        greenLED = 0; //off led
        buzz.rest();//off buzzer
        wait_us(WAIT_TIME_MS * 450);  //450ms

        greenLED = 1; //on led
        buzz.playTone("B", Buzzer::HIGHER_OCTAVE);// plays the tone B on a higher octave
        wait_us(WAIT_TIME_MS * 150);  //150ms
        greenLED = 0; //off led
        buzz.rest();//off buzzer
        wait_us(WAIT_TIME_MS * 150);  //150ms

        greenLED = 1; //on led
        buzz.playTone("C", Buzzer::HIGHER_OCTAVE);// plays the tone C on a higher octave
        wait_us(WAIT_TIME_MS * 150);  //150ms
        greenLED = 0; //off led
        buzz.rest();//off buzzer
        wait_us(WAIT_TIME_MS * 150);  //150ms

        greenLED = 1; //on led
        buzz.playTone("D", Buzzer::HIGHER_OCTAVE);// plays the tone D on a higher octave
        wait_us(WAIT_TIME_MS * 150);  //150ms
        greenLED = 0; //off led
        buzz.rest();//off buzzer
        wait_us(WAIT_TIME_MS * 900);  //900ms for the next sos sequence


    }
}