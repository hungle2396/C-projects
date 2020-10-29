#include <stdio.h>
#include <stdlib.h>

int main() {
    int character;

    printf("Please enter a character: ");

    scanf("%c", &character);

    if (character == '0' && character <= '9') {
        printf("Output: 1", &character);
    } else {
        printf("Output: 0", &character);
    }

    return 0;
}
