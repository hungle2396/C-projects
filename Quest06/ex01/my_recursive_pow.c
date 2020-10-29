#include <stdio.h>
#include <stdlib.h>

/* 
Create a recursive function that returns the value of a power applied to a number. A power lowe than 0 returns 0. Overflows don't have to be handled.
*/

int my_recursive_pow(int nbr, int power);

int main() {
    int number = 2;
    int number_Power = 3;

    int result = my_recursive_pow(number, number_Power);

    printf("The result is %i\n", result);

    return 0;
}

int my_recursive_pow(int nbr, int power) {
    
    // return 0 if the power is 0 
    if (power == 0) {
        return 1;
    } else if (power == 1) { // Power of 1, is the number itself 3^1 = 3;
        return nbr;
    } else if (power > 1) {
        return (nbr * my_recursive_pow(nbr, power - 1));
    }
}