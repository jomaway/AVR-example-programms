/**
 * Copyright (C) PlatformIO <contact@platformio.org>
 * See LICENSE for details.
 * 
 *  Toogle a LED every second by using a Timer overflow interrupt
 *  Startwert berechnen 
 *  1s -> 49911
 *  0,5s -> 57723
 *  2s -> 34286 
 * 
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define LED_PIN PD4
#define LED_PIN2 PD7
#define TIMER1_START_VALUE 49911

volatile uint8_t zaehler = 0;  // zählervariable für den Timer0 (8-Bit)

int main(void)
{
    // SETUP PHASE
    // make the LED pin an output for PORTB5
    DDRD |= 1 << LED_PIN;
    DDRD |= 1 << LED_PIN2;

    // Prescaler für Timer 1 setzen
    TCCR1B |= ((1<<CS12) | (1 << CS10));
    TCCR1B &= ~(1<<CS11);

    // Startwert setzen
    TCNT1 = TIMER1_START_VALUE;

    // Interrupt für TIMER1 aktivieren
    TIMSK1 |= (1<<TOIE1);

    // Timer0 prescaler
    TCCR0B |= ((1<<CS02) | (1<<CS00));
    TCCR0B &= ~(1<<CS01);
    // Timer0 aktivieren
    TIMSK0 |= (1<<TOIE0);

    // Allgemeine Interrupts einschalten
    sei();

    // MAIN LOOP 
    while (1)
    {
        // do nothing here
        // Wenn der zaehler 61 ist dann ist eine Sekunde vorbei. 1s/0,016s
        if ( zaehler == 61){
            cli();
            PORTD ^= (1 << LED_PIN2);
            zaehler = 0;
            sei();
        }
    }

    return 0;
}


ISR(TIMER1_OVF_vect){
    cli();
    // toggle the LED
    PORTD ^= (1 << LED_PIN);
    // Startwert wieder setzten sonst würde der Zähler von 0 starten.
    TCNT1 = TIMER1_START_VALUE;
    sei();
}

ISR(TIMER0_OVF_vect) {
    // Wenn Timer0 OVerflow passiert mach irgendwas
    zaehler++;
}