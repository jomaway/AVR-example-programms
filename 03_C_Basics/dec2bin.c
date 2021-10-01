#include <stdio.h>
#include <inttypes.h>  // uint8_t, uint16_t, int8_t


#define NR_OF_BITS  16
const int nr_of_bits = 16;  // variable die nicht änderbar ist.


#define MAX_VALUE 255

#define MAX_8BIT_VALUE MAX_VALUE


void func(int dec, int bits){
    for (int i = bits-1; i>=0;i--){
        int z = dec >> i;
        if (z & 1){
            printf("1");
        }else {
            printf("0");
        }
    }
    printf("\n");
}

void dec2binMod(uint8_t dec){
    char rest[8];

    for(int i=7; i>=0; i--)  {
        if(dec % 2){
            rest[i] = '1';   // printf("1");
        } else {
            rest[i] = '0';   // printf("0");
        }
        dec = dec / 2;
    }

    printf("Dualzahl = %s",rest);
}



int main()
{

    int dezimalzahl = 1223;
    printf("Dezimalzahl = %d\n", dezimalzahl);

    dec2binMod(dezimalzahl);

    //dec2bin(dezimalzahl, NR_OF_BITS);

    
    // printf("Define BITS: %d",255);

    return 0;
}

int add(int a, int b) { return a+b; }