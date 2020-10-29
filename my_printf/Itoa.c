#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#include "Utoa.h"
#include "Itoa.h"
#include "helper_functions.h"

char *my_itoa(int Number, char *String, int base_Number) {
	int i = 0;
	bool is_Negative = false;

	// 1. Return the string if the number is 0
	if (Number == 0) {
		String[i] = '0';
		String[i + 1] = '\0';
		return String;
	}

	// 2. Check if the number is negative
	// 2.1 If it is, Check for base 10 
	if (Number < 0 && base_Number < 11) {
		// 2.2 turn is_Negative to true, and switch it to positive #
		is_Negative = true;
		Number = Number * (-1);
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
	
	if (is_Negative == true) {
		String[i] = '-';
		i++;
	}

	String[i] = '\0';

	String = my_strrev(String);

	return String;
}

