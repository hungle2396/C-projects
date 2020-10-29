#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_iterative_pow(int nbr, int power);

int main() {
    int number = 2;
    int pow = 1;

    int result = my_iterative_pow(number, pow);

    printf("The Final result is %i\n", result);
    return 0;
}

int my_iterative_pow(int nbr, int power) {
    
    // counter for power
    int counter = 1;
    int constant_number = nbr;

    // if power is 0, then return 1
    if (power == 0) {
        return 1;
    }

    // if power is greater than 0
    while (counter < power) {
        
        nbr = nbr * constant_number;
        counter++;
    }

    return nbr;
}