#include <stdio.h>
#include <stdlib.h>

/*
Create an iterated function that returns a number. This number is the result of a factorial operation based on the number given as a parameter.

if there's an error, the function should return 0.
*/

int my_iterative_factorial(int nbr);

int main() {
    int number = 8;

    int result = my_iterative_factorial(number);

    printf("The factorial of %i is %i\n", number, result);
    return 0;
}

int my_iterative_factorial(int nbr) {
    int copied_Number = nbr;
    int new_Result = nbr;
    int next_Number;
    
    while (nbr != 1) {
        copied_Number = copied_Number - 1;
        new_Result = new_Result * copied_Number;
        nbr--;
    }
    
    return new_Result;
}