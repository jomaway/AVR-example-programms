/**
 * Copyright (C) PlatformIO <contact@platformio.org>
 * See LICENSE for details.
 */

#include <avr/io.h>       // für Port und Register Definitionen
#include <util/delay.h>   // für funktion _delay_ms()

#define LED_PIN PD7         // LED ist an PIN PD7 angeschlossen
#define TASTER_PIN PD2      // Taster ist an PIN PD2 angeschlossen

#define LED_OFF 0           // Definiere LED_OFF als 0
#define LED_ON 1            // Definiere LED_ON als 1

#define TASTER_PRESSED 0    // Definiere TASTER_PRESSED als 0
#define TASTER_RELEASED 1   // Definiere TASTER_RELEASED als 1

int main(void)
{
    // SETUP PHASE
    uint8_t led_state = LED_OFF;                // Variable für den aktuellen LED status
    uint8_t taster_state = TASTER_RELEASED;     // Variable zum speichern des Taster Zustands

    // LED als Ausgang festlegen
    DDRD = (1 << LED_PIN);
    // Taster an PD2 als Eingang festlegen
    DDRD &= ~(1 << TASTER_PIN);
    // Internen Pullup für den Taster aktivieren
    PORTD |= (1 << TASTER_PIN);

    // ENLOSSCHLEIFE
    while (1)
    {
        // Überprüge den Eingang am TASTER_PIN
        if(!(PIND & (1 << TASTER_PIN))) {
            // Eingang LOW -> Taster gedrückt -> change taster_state

            taster_state = TASTER_PRESSED;  // speicher aktuellen Tasterzustand
            _delay_ms(50);  // Taster entprellen
        } else {
            // Eingang HIGH -> Taster nicht gedrückt ->
            // Überprüge vorherigen taster zustand
            if (taster_state == TASTER_PRESSED){
                // Steigende Flanke -> change led_state
                led_state = !led_state;     // led_state = LED_ON falls vorher LED_OFF und andersrum 
            }        
            
            taster_state = TASTER_RELEASED; // speicher aktuellen Tasterzustand
            _delay_ms(50); // Taster entprellen
        }

        // Überprüfe LED status
        if (led_state == LED_ON) {
            //  -> lasse die LED blinken
            PORTD |= (1 << LED_PIN);
            _delay_ms(500);
            PORTD ^= (1 << LED_PIN);
            _delay_ms(500);
        } else {
            // -> schalte LED aus
            PORTD &= ~(1 << LED_PIN);
        }
    }

    return 0;
}
