/*
 * Program to display the input status of a GPIO.
 * Board used : OrangePi Zero 2w
 * Prerequisites : 
 *   - WiringOP, http://www.orangepi.org/orangepiwiki/index.php/Orange_Pi_Zero_2W#How_to_install_wiringOP
 */

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>

#include <wiringPi.h>


#define GPIO_PIN 27

void setup()
{
    pinMode(GPIO_PIN, INPUT);
}

void loop()
{
    int pinValue = digitalRead(GPIO_PIN);

    printf("GPIO %d : %d\n", GPIO_PIN, pinValue);
    delay(500);
}

int main()
{
    printf("~~~ GPIO pin status ~~~\n");

    if (geteuid() != 0)
    {
        fprintf(stderr, "\n Error: Program should be run as root.\n");
        exit(1);
    }

    if (wiringPiSetup() == -1) {
        printf("WiringPi setup failed!\n");
        exit(1);
    }

    setup();

    for (;;)
        loop();

    return 0;
}