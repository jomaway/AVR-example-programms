/**
 * Copyright (C) PlatformIO <contact@platformio.org>
 * See LICENSE for details.
 */

#include <avr/io.h>
#include <util/delay.h>

#define LED_PB1_GREEN PB1
#define LED_PC3_RED PC3
#define LED_PD2_YELLOW PD2

int main(void)
{
    // SETUP PHASE
    // set the LED pins as output
    DDRB |= (1 << LED_PB1_GREEN);   // sets the green LED on PB1 as output
    DDRC |= (1 << LED_PC3_RED);     // sets the red LED on PC3 as output
    DDRD |= (1 << LED_PD2_YELLOW);  // sets the yellow LED on PD2 as output

    // ENDLOSSCHLEIFE
    while (1)
    {
        /* 
            Die grüne LED an PORTB soll doppelt so schnell blinken, wie die anderen beiden 
            -> Daher toggeln wir die Grüne LED pro Schleifendurchlauf 2x
            -> die anderen beiden nur 1x
            -> dazwischen schalten wir jeweils eine Pause von 250 ms
        */

        // toggle the green LED
        PORTB ^= (1 << LED_PB1_GREEN);
        _delay_ms(250);
        
        // toggle the green LED
        PORTB ^= (1 << LED_PB1_GREEN);
        // toggle the red LED
        PORTC ^= (1 << LED_PC3_RED);
        // togle the yellow LED
        PORTD ^= (1 << LED_PD2_YELLOW);
        _delay_ms(250);

    }

    return 0;
}
