#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, absNumber;
    printf("Please enter a number: ");

    // scan the user input number
    scanf("%d", &number);

    absNumber = abs(number);

    printf("Output: %d\n", absNumber);
    
    return 0;
}