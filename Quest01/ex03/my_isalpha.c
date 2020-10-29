#include <stdio.h>
#include <stdlib.h>

int main() {
    int character;

    printf("Please enter a character: ");
    
    // scan the user input
    scanf("%c", &character);

    if (character >= 'A' && character <= 'Z') {
        printf("Output: 1", &character);
    } else if (character >= 'a' && character <= 'z') {
        printf("Output: 1", &character);
    } else {
        printf("Output: 0", &character);
    }

    return 0;
}
