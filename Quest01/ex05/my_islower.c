#include <stdio.h>

/*
Reproduce the behavior of islower() function. It returns 1 if the character sent as argument is a lower letter (a to z). It returns otherwise.
*/

int my_islower(char c);

int main() {
    
    int character;
    int result;

    printf("Please enter a character: ");

    scanf("%c", &character);

    result = my_islower(character);

    printf("The result of %c is %i\n", character, result);

    return 0;
}

int my_islower(char c) {

    if (c >= 'a' && c <= 'z') {
        return 1;
    } else {
        return 0;
    }
}