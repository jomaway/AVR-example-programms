/* 
    Dies ist unser erstes C Programm 

    author: Jonas Malassa

    Mehrzeilige Kommentare sind kein Problem
*/

#include <stdio.h>  // Include für Standard Input und Output funktionen 

// C Funktion 
// Rückgabewert Name_der_funktion (Übergabeparameter) {}
int increment(int zahl) {
    return zahl + 1;
}

// Die main() funktion ist unser Einstiegspunkt in das Programm
int main() {

    // Etwas am Bildschirm ausgeben
    printf("Let's get started with C!");

    // Variablen vom Typ Integer anlegen
    int result;         
    int zahl = 7;

    // Funktion increment aufrufen und ergebnis in result variable speichern
    result = increment(zahl);
    // Result ausgeben
    printf("Ergebnis ist %d", result);
 

    return 0;  // Rückgabe ob Programm erfolgreich durchgelaufen ist. 0 -> alles OK.
}


