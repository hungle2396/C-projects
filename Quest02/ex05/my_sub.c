#include <stdio.h>

/*

Create a my_sub function which takes 2 parameters(nbr1 and nbr2) and returns a value. This value is the result of the substraction of nbr1 and nbr2 paramters.

*/

int my_sub(int a, int b);

int main() {

    int Number1 = 30;
    int Number2 = 35;
    int Result;

    Result = my_sub(Number1, Number2);

    printf("The result of substraction from number 1 and number 2 is %i\n", Result);

    return 0;
}

int my_sub(int a, int b) {

    int substraction_Result;

    substraction_Result = a - b;

    return substraction_Result;
}