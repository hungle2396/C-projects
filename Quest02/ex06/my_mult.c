#include <stdio.h>

/*

Create a my_mult function which takes 2 parameters (nbr1 and nbr2) and returns a value. This value is the result of the multiplication of nbr1 and nbr2 parameters.

*/

int my_mult(int a, int b);

int main() {
    
    int Number1 = 0;
    int Number2 = 1;
    int Result;

    Result = my_mult(Number1, Number2);

    printf("The result of multiplying of Number 1 and Number 2 is %i\n", Result);

    return 0;
}

int my_mult(int a, int b) {

    int mult_Result;

    mult_Result = a * b;

    return mult_Result;
}