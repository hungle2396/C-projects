#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Write a function my_union that takes two strings and returns
- without doubles, the characters that appear in either one of the strings.
*/

char *my_union(char *param_1, char *param_2);
void my_strlen(char *String, int *Counting);

int main() {
    
    char string_One[128] = "ddf6vewg64f";
    char string_Two[128] = "gtwthgdwthdwfteewhrtag6h4ffdhsd";

    char *Result = my_union(string_One, string_Two);

    printf("%s\n", Result);
    
    return 0;
}

char *my_union(char *param_1, char *param_2) {
    int i = 0;
    int j = 0;
    int k;
    char temp_Character;
    int Counter = 0;
    int *pointer_Counter = &Counter;

    //1. count the length of characters in string one to put in malloc(string 1 + 2) later
    my_strlen(param_1, pointer_Counter);

    // 2. count the length of characters in string two to put in malloc(string 1 + 2) later
    my_strlen(param_2, pointer_Counter);

    // 3. Creating a malloc combined size from string 1 + 2 and null char at the end
    char *combined_String = (char *) malloc(Counter * sizeof(char) + 1);

    // 4. Add those characters in the combined_String malloc
    // 4.1 Add the characters from string 1 first
    i = 0;
    j = 0;
    while (param_1[i] != '\0') {
        combined_String[j] = param_1[i];
        i++;
        j++;
    }

    // 4.2 Add the characters from string 2 to combined String
    i = 0;
    while (param_2[i] != '\0') {
        combined_String[j] = param_2[i];
        i++;
        j++;
    }
    combined_String[j] = '\0';
    
    // 5. Going through each character in combine_String
    // 5.1 Check for duplicate
    // 5.2 duplicates will be replace with null
    i = 0, j = 0;
    // Going through each character in the string
    while (combined_String[i] != '\0') {
        //temp_Character = combined_String[i];
        j = i + 1;
        // find the duplicate characters
        while (combined_String[j] != '\0') {
            if (combined_String[j] == combined_String[i]) {
                //printf("The current duplicate char is %c\n", combined_String[j]);
                combined_String[j] = combined_String[j+1];
                k = j + 1;
                while (combined_String[k] == combined_String[i]) {
                    //printf("The next char is the same again is %c\n", combined_String[k]);
                    combined_String[j] = combined_String[k+1];
                    k++;
                }
                j++;
            } else {
                j++;
            }
        }
        i++;
    }

    return combined_String;
}

void my_strlen(char *String, int *Counting) {
    int i = 0;

    while (String[i] != '\0') {
        (*Counting)++;
        i++;
    }
}