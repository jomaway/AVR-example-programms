/**
 * Copyright (C) PlatformIO <contact@platformio.org>
 * See LICENSE for details.
 */
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#include "lcd_definitions.h"
#include <lcd.h>
#include <stdlib.h>

// LCD Controller defines
#define LCD_CONTROLLER_KS0073 0 // Use 0 for HD44780 controller, change to 1 for displays with KS0073 controller. 

int main(void)
{
    // SETUP PHASE
    lcd_init(LCD_DISP_ON);
    lcd_clrscr();

    lcd_puts("Count till 255");

    lcd_gotoxy(0,1);

    uint8_t counter = 0;
    // MAIN LOOP 
    while (1)
    {
        counter++;
        if (!counter) {
            lcd_gotoxy(0,1);
            lcd_puts("   "); // clear second row 
        }
        lcd_gotoxy(0,1);
        char text[4];
        itoa(counter, text,10);
        lcd_puts(text);
        _delay_ms(1000);
    }

    return 0;
}
