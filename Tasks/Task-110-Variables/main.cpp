#include "uop_msb.h"
using namespace uop_msb;

Buzzer buzz;

PortOut LED_PORTE(PortE, LED_MASK);

DigitalOut LED_BAR_OE(LED_BAR_OE_PIN,1);      //Off by default
DigitalOut LED_DIGIT_OE(LED_DIGIT_OE_PIN,1);   //Off by default

DigitalOut LED_D1_LE(LED_D1_LE_PIN,0);
DigitalOut LED_D2_LE(LED_D2_LE_PIN,0);
DigitalOut LED_RED_LE(LED_RED_LE_PIN,0);
DigitalOut LED_GRN_LE(LED_GRN_LE_PIN,0);
DigitalOut LED_BLUE_LE(LED_BLUE_LE_PIN,0);

DigitalIn BlueButton(USER_BUTTON);

BusOut ledData(LED_D0_PIN, LED_D1_PIN, LED_D2_PIN, LED_D3_PIN, LED_D4_PIN, LED_D5_PIN, LED_D6_PIN, LED_D7_PIN);


int main()
{
    printf ("///////////////////////////");
    printf("\nTASK-110\n");

    //Printing variables Task 1
    // Integer
    int count = 10;
    printf("count = %d\n", count);
    //Printing variables Task 2
    // Add one to count
    count = count + 2;
    printf("New value of count = %d\n", count);


    //Task ASCII characters and char 1-3
    // Char
    char character;
    character = 65;
    printf("The character %c has the ASCII code %d\n", character, character);
    character = 'A';
    printf("The character %c has the ASCII code %d\n", character, character);
    character = 'Z';
    printf("The character %c has the ASCII code %d\n", character, character);
    character = 'a';
    printf("The character %c has the ASCII code %d\n", character, character);
    character = 'z';
    printf("The character %c has the ASCII code %d\n", character, character);
    character = '0';
    printf("The character %c has the ASCII code %d\n", character, character);
    character = '9';
    printf("The character %c has the ASCII code %d\n", character, character);

    //task Integers
    // Short
    //unsigned short shortCount = 32766; //task 4
    int shortCount = 32766; //task 6,7 when changed to int doesn't print properly as it would only print when %d instead of %hd as well if changed to %d it prints 32768
    printf("The value of shortCount is %d\n", shortCount);//changed %hd to %d
    shortCount = shortCount + 2;// task1+2 it prints -32768
    printf("add 1 and shortCount is %d\n", shortCount); //changed %hd to %d

    // Long long task
    long long NN = 0x12345678ABCD0001LL; //Literal in HEX
    printf("A very large number %d\n", NN);//changed %lld to d for task andit still print -1
    printf("A very large number in hex %llX\n", NN);

    // unsigned
    // unsigned type task
    short p = 1; //16 bit change to signed for task
    printf("unsigned int p = %u\n", p);// this when %u it shows 1
    p = p - 2;
    printf("Subtract 2. Now unsigned int p = %u\n", p);// this when %u it shows 65535
    // when changed to unsign and %d the first one shows 1 and the second shows 4294967295


    //Floating Point Variables task
    // float 
    float pi_float = 3.1415926536;
    printf("The value of pi is approximately %.10f\n", pi_float);

    // double
    //double pi_double = 3.1415926536l;
    double pi_double = 3.14159265358979323846l;
    printf("The value of pi is approximately %.20lf\n", pi_double);
    //task 2 the first one isn't accurat but double is
    //task 4it isn't too accurate only up to 3.141592653589793 and not after that


    // Data type sizes (in bytes)
    printf("Size of a char is %d bytes\n", sizeof(unsigned char));
    printf("Size of a short is %d bytes\n", sizeof(unsigned short));
    printf("Size of a int is %d bytes\n", sizeof(unsigned int));
    printf("Size of a long is %d bytes\n", sizeof(unsigned long));
    printf("Size of a long long is %d bytes\n", sizeof(unsigned long long));
    printf("Size of a float is %d bytes\n", sizeof(float));
    printf("Size of a double is %d bytes\n", sizeof(double));
    //changed all changable signed to unsigned

    //Constant Strings Task 1
    printf("tree");

    // Stop
    while (true);   
}