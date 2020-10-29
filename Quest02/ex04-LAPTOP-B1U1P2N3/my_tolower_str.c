#include <stdio.h>
#include <stdlib.h>


void my_tolower_str(char* str) {

    int Character = 0;

    while (str[Character] != '\0') {
        if (str[Character] >= 'A' && str[Character] <= 'Z') {
            str[Character] = str[Character] + 32;
        }
        Character++;
    }
}


int main() {

    /*
    char String[] = "AbCdEf G12";

    char newString[] = my_tolower_str(String);
    */

    char String[] = "ABCDEfgG 12";

    printf("Input: %s\n", String);

    my_tolower_str(String);

    printf("Output: %s\n", String);

    return 0;
}