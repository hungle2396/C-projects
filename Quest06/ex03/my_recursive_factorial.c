#include <stdio.h>
#include <stdlib.h>

/* 
Create a recursive function that returns the factorial of the number given as a parameter. If there's an error, the function should return 0.
*/

int my_recursive_factorial(int nbr);

int main() {
    
    int number = 5;

    int result = my_recursive_factorial(number);

    printf("The result of factorial %i is %i\n", number, result);

    return 0;
}

int my_recursive_factorial(int nbr) {

    int copied_number = nbr;
    
    if (nbr == 1) {
        return nbr;
    } else if (nbr > 1) { 
        return (copied_number * my_recursive_factorial(copied_number - 1));
    } else {
        return 1;
    }
}