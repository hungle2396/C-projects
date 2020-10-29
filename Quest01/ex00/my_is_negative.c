#include <stdio.h>

int main() {
    int number;

    printf("Please enter a number: ");
    
    // scan the number
    scanf("%d", &number);

    if (number > 0) 
        printf("1", number);
    else if (number < 0)
        printf("0", number);
    else if (number == '\0')
        printf("0", number);

    return 0;
}