#include <stdio.h>
#include <stdlib.h>


void my_toupper_str(char* str) {

    int Character = 0;

    while (str[Character] != '\0') {
        if (str[Character] >= 'a' && str[Character] <= 'z') {
            str[Character] = str[Character] - 32;
        }
        Character++;
    }
}


int main() {

    /*
    char String[] = "AbCdEf G12";

    char newString[] = my_tolower_str(String);
    */

    char String[] = "sfsfsGAAF 12 g54~";

    printf("Input: %s\n", String);

    my_toupper_str(String);

    printf("Output: %s\n", String);

    return 0;
}