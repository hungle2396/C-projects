#include <stdio.h>

/* reproduce the behavior of the function strncpy */

char *my_strncpy(char *a, char *b, int c);

int main() {

    char string_A[] = "";
    char string_B[] = "Hello There!";
    int count = 5;

    my_strncpy(string_A, string_B, count);

    printf("The copied string A is %s\n", string_A);
    printf("The copied string B is %s\n", string_B);
    return 0;
}

char *my_strncpy(char *a, char *b, int c) {
    int counter = 0;
    int i = 0;

    while (counter < c) {
        a[i] = b[i];
        printf("The current character in a[%i] is %c\n", i, a[i]);
        i++;
        counter++;
    }

    a[i] = '\0';
    return a;
}