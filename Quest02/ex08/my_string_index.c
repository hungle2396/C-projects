#include <stdio.h>

/* Create a my_string_index function which takes 2 parameters(haystack and needle) and locates the first occurrence of the string needle in the string haytstack and returns the index position.
*/

int my_string_index(char *a, char *b);

int main() {
    
    // Create array that has the input
    char string_One[128] = "Hello World!";
    char string_Two[128] = "W";
    int Result = my_string_index(string_One, string_Two);

    printf("The result is %i\n", Result);

    return 0;
}

int my_string_index(char *a, char *b) {
    int i = 0;
    int j = 0;
    int index_Number;
    // going through each chacter in pointer a and compared those chars to the first character in pointer b
    while (a[i] != 0) {     // string a = aaaaaa'/0'     string b = b     a[i] != b[j] a[i] = a; b[j] = f 
    
        if (a[i] != b[j]) {
            i++;
        } else {
            index_Number = i;
            return index_Number;
        }
    }

    // if pointer a can't find any character similar to pointer b
    if (a[i] == 0 && index_Number != i) {
        return -1;
    }
}