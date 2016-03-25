#include <string.h>
#include <stdlib.h>

#include "rpi-gpio.h"
#include "rpi-systimer.h"

/** GPIO Register set */
volatile unsigned int* gpio = (unsigned int*)GPIO_BASE;

/** Main function - we'll never return from here */
void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags )
{
    int brightness = 255;
    int speed = 16;
    int up = 0;

    /* Write 1 to the GPIO init nibble in the Function Select GPIO peripheral register to enable
       the LED pin an output */
    gpio[LED_GPFSEL] |= ( 1 << LED_GPFBIT );

    /* Never exit as there is no OS to exit to! */
    while(1)
    {
        if( brightness > 0 )
        {
            /* Set the GPIO16 output high ( Turn OK LED off )*/
            LED_OFF();

            /* Wait half a second */
            RPI_WaitMicroSeconds( brightness );
        }

        if( ( 255 - brightness ) >= 0 )
        {
            /* Set the GPIO16 output low ( Turn OK LED on )*/
            LED_ON();

            /* Wait half a second */
            RPI_WaitMicroSeconds( 255 - brightness );
        }

        speed--;
        if( speed == 0 )
        {
            speed = 16;

            if( up )
            {
                if( brightness < 255 )
                    brightness++;

                if( brightness == 255 )
                    up = 0;
            }
            else
            {
                if( brightness )
                    brightness--;

                if( brightness == 0 )
                    up = 1;
            }
        }
    }
}
