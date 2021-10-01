#include<stdio.h>
#include<inttypes.h>

const char *bit_rep[16] = {
    [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011",
    [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111",
    [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011",
    [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
};

void print_byte(uint8_t byte){
    printf("Dec: %2d, Hex: %2x, Oct: %2o, Bin: %s%s\n", byte, byte, byte, bit_rep[byte >> 4], bit_rep[byte & 0x0F]);
}

void print_all(){
    for(int i=0; i<=255; i++) {
	    print_byte(i);
    }
}

int main() {
	printf("Welcome to Bits and Bytes\n");

    print_all();

    return 0;
}
