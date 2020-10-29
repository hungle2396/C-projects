#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#include "Itoa.h"
#include "Utoa.h"
#include "helper_functions.h"

char *my_utoa(unsigned int Number, char *String, int base_Number) {
	int i = 0; 

	// 1. Return the string if the number is 0
	if (Number == 0) {
		printf("The number is 0\n");
		String[i] = '0';
		String[i + 1] = '\0';
		return String;
	}

	// 3. Modulo the number backward while loop
	while (Number != 0) {
		int Remainder; 
		Remainder = Number % base_Number; // find the remainder
		 
		if (Remainder > 9) {
			// Convert number to Letter (for number bigger than 9)
			String[i] = (Remainder - 10) + 97;
		} else {
			String[i] = Remainder + 48;
		} 

		Number = Number / base_Number;
		i++;
	}

	String[i] = '\0';

	String = my_strrev(String);

	return String;
}

char *my_longtoa(long Number, char *String, int base_Number) {
	// num = 1234
	// String[10]
	// base = 10
	int i = 0; 

	// 1. Return the string if the number is 0
	if (Number == 0) {
		//printf("The number is 0\n");
		String[i] = '0';
		String[i + 1] = '\0';
		return String;
	}

	// 3. Modulo the number backward while loop
	while (Number != 0) {
		int Remainder; 
		Remainder = Number % base_Number; // find the remainder
		 
		if (Remainder > 9) {
			// Convert number to Letter (for number bigger than 9)
			String[i] = (Remainder - 10) + 97;
		} else {
			String[i] = Remainder + 48;
		} 

		//printf("%c\n", String[i]);
		
		Number = Number / base_Number;
		i++;
	}
	
    // add in x to the string
	String[i] = 'x';
    i++;

    // add in 0 to the string
    String[i] = '0';
    i++;

	String[i] = '\0';

	String = my_strrev(String);

	return String;
}