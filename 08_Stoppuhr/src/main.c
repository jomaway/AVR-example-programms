/**
 * Copyright (C) PlatformIO <contact@platformio.org>
 * See LICENSE for details.
 */
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define LCD_CONTROLLER_KS0073 0

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"

#define TRUE 1
#define FALSE 0

#define TASTER_PAUSE_PIN PD2
#define TASTER_RESET_PIN PD3

#define TIMER1_START_VALUE 49911

#define RESET(counter) (counter = 0)  // Macro to reset the counter to zero.

volatile uint64_t counter = 0;
volatile uint8_t changed = FALSE;


void timer_init(){
    // konfigure Timer1 for counting seconds
    TCCR1B |= ((1 << CS12) | (1 << CS10));
    // Set start value for TIMER1
    TCNT1 = TIMER1_START_VALUE;
    // Activate Timer1 
    TIMSK1 |= (1 <<TOIE1);
}

void taster_init(){
    // Set Port Pins as INPUT
    DDRD &= ~((1 << TASTER_PAUSE_PIN) | (1 << TASTER_RESET_PIN));
    // Set internal PULLUPs
    PORTD |= ((1 << TASTER_PAUSE_PIN) | (1 << TASTER_RESET_PIN));
}

void update_display(const char* text) {
    lcd_gotoxy(0, 1);
    lcd_puts(text);
}

int main(void)
{
    // SETUP PHASE    
    timer_init();
    taster_init();
    
    lcd_init(LCD_DISP_ON);
    lcd_clrscr();
    sei();

    char textvalue[16];

    lcd_puts("RUNNING ...");

    // MAIN LOOP 
    while (1)
    {
        // Check if taster is pressed
        if(!(PIND & (1 << TASTER_PAUSE_PIN))) {
            TIMSK1 &= ~(1 << TOIE1);  // Wenn taster gedrückt schalte interrupt aus.
        } else {
            TIMSK1 |= (1 << TOIE1);  // Wenn taster offen schalte interrupt ein.
        }

        if(!(PIND & (1 << TASTER_RESET_PIN))) {
            ATOMIC_BLOCK(ATOMIC_FORCEON){
                counter = 0; // RESET(counter); // counter = 0;
            }
            lcd_gotoxy(0,1);            // lcd_clrscr();
            lcd_puts("        ");       // lcd_puts("RUNNING ...");
            changed = TRUE;
        }

        if (changed) {
            cli();
            itoa(counter, textvalue, 10);  // convert counter to a asciistring and save to textvalue
            sei();
            lcd_gotoxy(0, 1);
            lcd_puts(textvalue);
            changed = FALSE; 
        }
        //_delay_ms(100);
    }
    

    return 0;
}

ISR(TIMER1_OVF_vect){
    counter++;
    TCNT1 = TIMER1_START_VALUE;
    changed = TRUE;
}