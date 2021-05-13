/**
 * Copyright (C) PlatformIO <contact@platformio.org>
 * See LICENSE for details.
 */

#include <avr/io.h>         // für Port und Register Definitionen
#include <avr/interrupt.h>  // für die verwendung von Interrupts
#include <util/delay.h>     // für funktion _delay_ms()

#define LED_PIN PB5         // LED ist an PIN PD7 angeschlossen
#define TASTER_PIN PD2      // Taster ist an PIN PD2 angeschlossen

#define LED_OFF 0           // Definiere LED_OFF als 0
#define LED_ON 1            // Definiere LED_ON als 1

#define TASTER_PRESSED 0    // Definiere TASTER_PRESSED als 0
#define TASTER_RELEASED 1   // Definiere TASTER_RELEASED als 1

// Globale Variablen 
volatile uint8_t led_state = LED_ON;           
volatile uint8_t taster_state = TASTER_RELEASED; 

int main(void)
{
    // SETUP PHASE

    // LED als Ausgang festlegen
    DDRB = (1 << LED_PIN);
    // Taster an PD2 als Eingang festlegen
    DDRD &= ~(1 << TASTER_PIN);
    // Internen Pullup für den Taster aktivieren
    PORTD |= (1 << TASTER_PIN);

    // Externen Interrupt INT0 konfigurieren  -> wenn low soll Interrupt auslösen -> 0
    EICRA = 0; 
    // INT0 aktivieren 
    EIMSK = (1 << INT0);
    // Alle Interrupts global aktivieren
    sei(); 

    // ENLOSSCHLEIFE
    while (1)
    {
        // Überprüfe LED status
        if (led_state == LED_ON) {
            //  -> lasse die LED blinken
            PORTB ^= (1 << LED_PIN);
            _delay_ms(1000);
        } else {
            // -> schalte LED aus
            PORTB &= ~(1 << LED_PIN);
        }
    }

    return 0;
}

/* Interrupt Service Routine für INT0 -> externer Interrupt an PD2 -> HIER der Taster */
ISR(INT0_vect) {
    // atomaren Variablenzugriff gewährleisten -> Interrupts global deaktivieren
    cli();

    if (taster_state == TASTER_PRESSED)
    {
        // change led_state
        
        led_state = !led_state;
        taster_state = TASTER_RELEASED;
    } else {
        taster_state = TASTER_PRESSED;
    }
    _delay_ms(100);  // Taster entprellen
    

    // globe Interrupts wieder aktivieren
    sei();
}