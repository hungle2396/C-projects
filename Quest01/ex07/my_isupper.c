#include <stdio.h>

/*
Reproduce the behavior of issuper() function. It returns 1 if the character sent as argument is a upper-case letter(A to Z). It returns 0 otherwise.
*/

int my_isupper(char c);

int main() {
    
    int character;
    int result;

    printf("Please enter a character: ");

    scanf("%c", &character);

    result = my_isupper(character);

    printf("The result of %c is %i\n", character, result);

    return 0;
}

int my_isupper(char c) {

    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}