#include <stdio.h>

/*

Copies the string pointed to by str2 to str1. Copies up to and including the null character of str2. If str1 and str2 overlap the behavior is undefined. Returns the argument str1. 

it should be prototyped: 

char *my_strcpy(char *str1, char *str2);

*/

char *my_strcpy(char *str1, char *str2);

int main() {


    char string_One[] = "hello World";
    char string_Two[] = "This is Ucbi";

    printf("String One is: %s\n", string_One);

    printf("String Two is: %s\n", string_Two);

    my_strcpy(string_One, string_Two);

    printf("String One is now: %s\n", string_One);
    printf("String Two is now: %s\n", string_Two);

    return 0;
}

char *my_strcpy(char *str1, char *str2) {
    char temp; 
    int string_Length = 0;
    int i = 0;

    char *copied_String = NULL;
    copied_String = str2;

    while (*copied_String != '\0') {
        string_Length++;
        copied_String++;
    }

    // update the string length by 1
    copied_String = copied_String - string_Length;
    string_Length = string_Length + 1; // increment the size of string_length to include the character '\0'


    // start copying the string 2 to string 1
    while (i < string_Length) { // while i is lesser than the length of copied_String
        *str1 = *copied_String;

        str1++;
        copied_String++;
        i++;
    }

    // bring the string back to the original memory address
    str1 = str1 - string_Length;

    return str1;
}