#include <stdio.h>

/* Create a my_capitalize function. Which takes a string as parameter and returns the capitalized version of it.
*/

char *my_capitalize(char *a);

int main() {

    char String[128] = "abc dEf !H1"; 

    printf("%s\n", String);

    char *Result = my_capitalize(String);  
    
    printf("%s\n", Result);
    return 0;
}


char *my_capitalize(char *a) {
    
    int i = 0;
    char Space = ' ';
    int Capitalized = 0;
    
    while (a[i] != 0) {
        // the character is the space, reset Capitalized back to 0 to capitalize the next character
        if (a[i] == Space) {
            Capitalized = 0;
            i++;            
        } else {
            // 1) First character is already capitalized
            if (Capitalized == 0 && (a[i] >= 'A' && a[i] <= 'Z')) {
                //printf("The first character is already capitalized %c\n", a[i]);
                i++;
                Capitalized++;
            }
            // 2) First character that need to be capitalized after the space
            else if (Capitalized == 0 && (a[i] >= 'a' && a[i] <= 'z')) {
                //printf("The current character that need to be capitalized %c\n", a[i]);
                // capitalize the character if it's between or equal 'a' and 'z'
                a[i] = a[i] - 32;
                //printf("The current capitalized character is %c\n", a[i]);
                // go to next character
                i++;
                Capitalized++;
            // 3) First character that don't need to be capitalized      
            } else if (Capitalized == 0 && (a[i] < 'a' && a[i] > 'z')) {
                //printf("The current first character that don't need to be capitalized is %c\n", a[i]);
                i++;
                Capitalized++;
            // 4) Characters that needs to be down-case if already capitalized
            } else if (Capitalized != 0 && (a[i] >= 'A' && a[i] <= 'Z')) {
                //printf("The current character after capitalized character is %c\n", a[i]);
                a[i] = a[i] + 32;
                //printf("The current character after capitalized character being down-case is %c\n", a[i]);
                i++;
            // 5) Every other characters that need to be keep the same
            } else {
                //printf("Normal characters %c\n", a[i]);
                i++;
                Capitalized++;
            }
        }
    }

    return a;
}