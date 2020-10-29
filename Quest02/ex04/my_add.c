#include <stdio.h>

/*

Create a my_add function which takes 2 paramters (nbr1 and nbr2) and return a value. This value is the result of the addtion of nbr1 and nbr2 parameters.

*/

int my_add(int a, int b);

int main() {

    int first_Number = 30;
    int second_Number = 20;

    int Result = my_add(first_Number, second_Number);

    printf("The result of adding number 1 and number 2 are %i\n", Result);

    return 0;
}

int my_add(int a, int b) {

    int result_of_Addition;

    result_of_Addition = a + b;

    return result_of_Addition;
}