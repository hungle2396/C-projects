#include <stdio.h>

/* Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. The terminating null character is considered to be part of the string. Returns a pointer pointing to the last matching character, or null if no match was found. 

*/

char *my_strrchr(char *a, char b);

int main() {
    char string_A[] = "abc";
    char character_B = 'd';
    char *Result = my_strrchr(string_A, character_B);

    printf("The Result is: %s\n", Result);
     
    return 0;
}

char *my_strrchr(char *a, char b) {

    int  i = 0;
    int counter = 0;
    char* Result = NULL;
    
    while (a[i] != 0) {
        //printf("The current character is %c\n", a[i]);
        //i++;
        
        if (a[i] == b) {
            counter = i;
            printf("The current counter being stop is at %i and the character is %c\n", i, a[i]);
            i++;
        } else {
            printf("The current character is %c\n", a[i]);
            i++;
        }
    }

    if (a[i] == '\0' && counter == 0) {
        Result = NULL;
    } else if (a[i] == '\0' && counter != 0) {
        Result = a + counter;
    }

    printf("The final result string is %p\n", Result);

    return Result;
}