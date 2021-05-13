/**
 * Copyright (C) PlatformIO <contact@platformio.org>
 * See LICENSE for details.
 */

#include <avr/io.h>       // für Port und Register Definitionen
#include <util/delay.h>   // für funktion _delay_ms()

#define LED_PIN PD7     // LED ist an PIN PD7 angeschlossen
#define TASTER_PIN PD2  // Taster ist an PIN PD2 angeschlossen


int main(void)
{
    // SETUP PHASE
    // LED als Ausgang festlegen
    DDRD = (1 << LED_PIN);
    // Taster an PD2 als Eingang festlegen
    DDRD &= ~(1 << TASTER_PIN);
    // Internen Pullup für den Taster aktivieren
    PORTD |= (1 << TASTER_PIN);

    // ENLOSSCHLEIFE
    while (1)
    {
        // Abfrage ob der Taster gedrückt oder nicht gedrückt ist
        if(!(PIND & (1 << TASTER_PIN))) {
            // Taster gedrückt -> Eingang am TASTER_PIN ist LOW
            //  -> LED an -> setze Ausgang am LED_PIN auf HIGH
            PORTD |= (1 << LED_PIN);
            
        } else {
            // Taster nicht gedrückt -> Eingang am TASTER_PIN ist HIGH ->
            // -> LED aus -> setzte Ausgang am LED_PIN auf LOW
            PORTD &= ~(1 << LED_PIN);
        }
    }


    return 0;
}
