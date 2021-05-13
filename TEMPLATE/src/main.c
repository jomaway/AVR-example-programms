/**
 * Copyright (C) PlatformIO <contact@platformio.org>
 * See LICENSE for details.
 */

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5

int main(void)
{
    // SETUP PHASE
    // make the LED pin an output for PORTB5
    DDRB = 1 << LED_PIN;

    // MAIN LOOP 
    while (1)
    {
        _delay_ms(500);

        // toggle the LED
        PORTB ^= (1 << LED_PIN);
    }

    return 0;
}
