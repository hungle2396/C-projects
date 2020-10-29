#include <stdio.h>

/*
Reproduce the behavior of isspace() function. It returns 1 if the character sent as argument is a space (man isspace). It returns 0 otherwise.
*/

int my_isspace(char c);

int main() {
    
    int character;
    int result;

    printf("Please enter a character: ");

    scanf("%c", &character);

    result = my_isspace(character);

    printf("The result of %c is %i\n", character, result);

    return 0;
}

int my_isspace(char c) {

    if (c == ' ') {
        return 1;
    } else {
        return 0;
    }
}