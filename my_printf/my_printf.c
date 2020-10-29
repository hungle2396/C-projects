#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include "Itoa.h"
#include "Utoa.h"
#include "helper_functions.h"

int my_printf(char * restrict format, ...);

int main(void) {

	int positive_Decimal = 300;
	int negative_Decimal = -300;
	unsigned int positive_Octal = 300;
	unsigned int negative_Octal = -300;
	unsigned int positive_Hex = 300;
	unsigned int negative_Hex = -300;
	char a_Character = 'E';
	char a_String[20] = "Senior Student";
    char *null_String = NULL;
	int *integer_Pointer1 = &positive_Decimal;
	int *integer_Pointer2 = &negative_Decimal;
	
	printf("%d\n", my_printf("Hello %s!\n", "QWASAR.IO"));
    // my_printf("Hello World!, this is Hung Le, I'm just trying to write a testing sentence!\n");
	// my_printf("Positive Decimal is %d\n", positive_Decimal);
	// my_printf("Negative Decimal is %d\n", negative_Decimal);
	// my_printf("Positive Octal is %o\n", positive_Octal);
	// my_printf("Negative Octal is %o\n", negative_Octal);
	// my_printf("Positive Hexadecimal is %x\n", positive_Hex);
	// my_printf("Negative Hexadecimal is %x\n", negative_Hex);
	// my_printf("This character is %c\n", a_Character);
    // my_printf("The first pointer is %p\n", integer_Pointer1);
	// my_printf("The second pointer is %p\n", integer_Pointer2);
	// my_printf("The string is %s\n", a_String);
    // my_printf("The NULL String is %s\n", null_String);
    // my_printf("Null String test 2 is %s\n", (char *)NULL);



	return 0;
}

int my_printf(char * restrict format, ...) {
	int i, j, string_Counter;
	int *pointer_j = &j;
	char *s;
	unsigned int Value;
	long pointer_Value;
	char *Result;
	char buffer[20];

	// 0. Calculate the string length and '%' counter for future dynamic malloc 
	string_Counter = my_strlen(format);

	Result = (char *) malloc(sizeof(char) * (string_Counter + 1));

	va_list arguments;

	va_start(arguments, format);

	// 1. Looping through each character in the first argument
	i = 0, j = 0;
	while (format[i] != '\0') {
		// 2. Check for the character '%'
		if (format[i] == '%') {
			// 3. Check for the next character after '%'
			i++;
			if (format[i] == 'd') { // 3.1 signed decimal (d)
				Value = va_arg(arguments, int);

				// Convert int to char string
				my_itoa(Value, buffer, 10);

				// copy/store the char data type to Result array
				my_strcpy(Result, buffer, pointer_j);
			} else if (format[i] == 'u') { // 3.2 unsigned decimal (u)
				Value = va_arg(arguments, unsigned int);

				my_utoa(Value, buffer, 10);

				my_strcpy(Result, buffer, pointer_j);
			} else if (format[i] == 'o') { // 3.3 unsigned octal (o)
				Value = va_arg(arguments, unsigned int);

				my_utoa(Value, buffer, 8);

				my_strcpy(Result, buffer, pointer_j);
			} else if (format[i] == 'x') { // 3.4 unsigned hexadecimal (x)
				Value = va_arg(arguments, unsigned int);

				my_utoa(Value, buffer, 16);

				my_strcpy(Result, buffer, pointer_j);
			} else if (format[i] == 'c') { // 3.5 convert int to unsigned char, char written (c)
				Result[j] = va_arg(arguments, int);
			} else if (format[i] == 's') { // 3.6 pointer to a string (s)
				s = va_arg(arguments, char *);

                if (s != NULL) { // If the string is not NULL
                    string_Counter = string_Counter + my_strlen(s);
                    Result = (char *) realloc(Result, sizeof(char) * string_Counter);
                } else {         // If the string is NULL
                    s = "(null)";
                    string_Counter = string_Counter + 6;
                }
                // realloc the dynamic memory for more space due to extra chars from string
                Result = (char *) realloc(Result, sizeof(char) * string_Counter);
				
				my_strcpy(Result, s, pointer_j);
			} else if (format[i] == 'p') { // 3.7 pointer printed in hexdecimal
				pointer_Value = va_arg(arguments, long);

				my_longtoa(pointer_Value, buffer, 16);

				my_strcpy(Result, buffer, pointer_j);
			}
		} else {
			// if it's just a regular character
			Result[j] = format[i];
		}
		i++;
		j++;
	}
	Result[j] = '\0';
	fwrite(Result, j, 1, stdout);
	va_end(arguments);

	free(Result);
	return j;
}
