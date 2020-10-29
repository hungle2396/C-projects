#include <stdio.h>
#include <stdlib.h>

void my_swap(int *a, int *b) {
    int a2;

    a2 = *a;

    *a = *b;
    *b = a2;  
}

int main() {

    int Number1 = 25;
    int Number2 = 30;
    int Number3 = 10;
    int Number4 = 20;
    

    printf("a = %i\n", Number1);
    printf("b = %i\n", Number2);
   
    my_swap(&Number1, &Number2);

    printf("a = %i\n", Number1);
    printf("b = %i\n", Number2);

    my_swap(&Number3, &Number4);

    printf("a = %i\n", Number3);
    printf("b = %i\n", Number4);

    return 0;
}