#include <stdio.h>
#include <stdbool.h>

#define even_Message "I have an even number of arguments."
#define odd_Message "I have an odd number of arguments."

char *my_define(int param_1);

int main(int argc) {
    
    printf("The number of argc is %i\n", argc);
    char *Result = my_define(argc);

    printf("%s\n", Result);
    return 0;
}

char *my_define(int param_1) {

    if (param_1 % 2 == 0) {
        //printf("The answer is even\n");
        return even_Message;
    } else {
        //printf("The result is false\n");
        return odd_Message;
    }
}