#include <stdio.h>

/*

Create a my_string_formatting function which takes 3 parameters (firstname, lastname and age) and returns a string composed value. This value is the result of the addition of nbr1 and nbr2 parameters. Formatting should be: "Hello, my name is FIRSTNAME LASTNAME, I'm AGE."

*/

char *my_string_formatting(char *a, char *b, int c);

void tostring(char str[], int num);

int main() {

    char first_Name[128] = "Hung";
    char last_Name[128] = "Le";
    int year_Old = 23;

    char *Result = my_string_formatting(first_Name, last_Name, year_Old);

    printf("%s\n", Result);

    return 0;
}

char *my_string_formatting(char *a, char *b, int c) {

    char *greet_Message = "Hello, my name is ";
    char *space = " ";
    char *ending_Message = ", I'm ";
    char *period = ".";
    char Age[20];
    char first_Name[128]; 
    int i = 0;
    int j = 0;
    int counter = 0;

    // store the characters in a string to array first_Name
    while (a[j] != 0) {
        first_Name[j] = a[j];
        //printf("The current character stored in first_Name array is %c\n", first_Name[j]);
        j++;
    }

    first_Name[j] = 0;

    // convert integer to string 
    tostring(Age, c);

        
    // get the pointer from greet Message to get to end
    while (*greet_Message != 0) {
        // if the character is not NULL, go through the next memory address
        *a = *greet_Message;
        //printf("The current character being input in the string %c\n", *a);
        greet_Message++;
        a++;
        counter++;
    } 
    
    
    // inputting the first Name characters to the greet_Message string
    while (first_Name[i] != 0) {
        // add in the characters 
        *a = first_Name[i];
        //printf("The current character being input in the string %c\n", *a);
        // go to the next memory address to get the next character from first Name
        i++;
        // move to the next memory address of greet Message 
        a++;
        counter++;
    }

    i = 0;

    while (*space != 0) {
        *a = *space;
        //printf("The current character being input in the string %c\n", *a);
        space++;
        a++;
        counter++;
    }

    // inputting the last Name characters to the greet_Message string
    while (*b != 0) {
        *a = *b;
        //printf("The current character being input in the string %c\n", *a);
        b++;
        a++;
        counter++;
    }

    // inputting the ending message characters to the greet_Message string
    while (*ending_Message != 0) {
        *a = *ending_Message;
        //printf("The current character being input in the string %c\n", *a);
        ending_Message++;
        a++;
        counter++;
    } 

    // inputting the age characters to the greet Message
    while (Age[i] != 0) {
        *a = Age[i];
        //printf("The current character being input in the string %c\n", *a);
        a++;
        i++;
        counter++;
    }

    while (*period != 0) {
        *a = *period;
        //printf("The current character being input in the string %c\n", *a);
        a++;
        period++;
        counter++;
    }

    *a = '\0';

    a = a - counter;            
    return a;
}

void tostring(char *str, int num)
{
    int i, rem, len = 0, n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}