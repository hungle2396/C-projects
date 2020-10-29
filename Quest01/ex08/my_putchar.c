#include <stdio.h>

/*
Create a function that displays the character send as argument.
*/

void my_putchar(char c);

int main() {
    
    char character;

    printf("Please enter a character: ");

    scanf("%c", &character);

    my_putchar(character);

    return 0;
}

void my_putchar(char c) {

    printf("%c", c);

}