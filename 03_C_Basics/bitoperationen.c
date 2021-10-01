#include <stdio.h>
#include <stdint.h>

int main()
{
    /* 
        23 = 0001 0111 
        9  = 0000 1001
        ----------------------
        &  = 0000 0001  (1)
        |  = 0001 1111  (31)
        ^  = 0001 1110  (30)
    */

    uint8_t a = 23, b = 9, c;

    c = a & b;
    printf("a&b = %d \n",c);
    printf("a|b = %d \n",a|b);
    printf("a^b = %d \n",a^b);

    a = ~a;
    b = ~b;
    c = ~c;

    printf("~a %i \n",a);
    printf("~b %i \n",b);
    printf("~c %i \n",c);

    /*
        Setze bit3 auf 0:

          1001 1100
        & 1111 0111 
        ------------
          1001 0100

        Setze bit1 auf 1:

         1001 1100
       | 0000 0010
        ------------
         1001 1110

        Invertiere bit5: 
        
         1001 1100
       ^ 0010 0000
        ------------
         1011 1100
    */ 
                    // b7 b6 b5 b4 b3 b2 b1 b0
    uint8_t port = 0b10011100; 
    // bit7 soll invertiert werden, 
    // bit4 soll auf 0 gesetzt werden und 
    // bit0 soll auf 1 gesetzt werden
    
    port = port ^ 0b10000000;  // 10011100 ^ 10000000 = 00011100 (28)  
    port = port & 0b11101111;  // 00011100 & 11101111 = 00001100 (12)
    port = port | 0b00000001;  // 00001100 | 00000001 = 00001101 (13)

    // -> Ergebnis: 0000 1101 (13)
    printf("Ergebnis: %d\n", port);

    (1 << 0);  // 0000 0001
    (1 << 1);  // 0000 0010
    (1 << 2);  // 0000 0100   ~(1 << 2) = 1111 1011
    (1 << 5);  // 0010 0000

    port = port | (1 << 5);  // Setze bit5 auf 1;
    port = port | (1 << 3);  // Setze bit3 auf 1;

    port = port & ~(1 << 2);   // Setze bit2 auf 0;



    return 0;
}
