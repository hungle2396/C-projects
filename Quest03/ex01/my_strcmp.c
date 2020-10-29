#include <stdio.h>

/* Compare the string pointed to by str1 to the string pointed to by str2. Returns zero if str1 and str2 are equal. Return less than zero or greaer than zero if str1 is less than or greater than str2 respectively.

*/

int my_strcmp(char *_str1_, char *_str2_); // declare the function

int main(void) {
    char string_One[6] = "Hellc";
    char string_Two[6] = "Helld";
    int result;

    printf("String One pointer: %p\n", string_One);
    printf("String Two pointer: %p\n", string_Two);

    result = my_strcmp(string_One, string_Two);

    if (result == 0) {
        printf("The strings have the same value. so result is = %i\n", result);
    } else if (result > 0) {
        printf("Output: String 1 is greater than string 2, so result is %i\n", result);
    } else if (result < 0) {
        printf("The string 1 is lesser than string 2, so result is %i\n", result);
    }
} 


int my_strcmp(char *_str1_, char *_str2_) { // make statements inside the function

    while(*_str1_ != '\0' || *_str2_ != '\0') {

        if (*_str1_ == '\0' && *_str2_ == '\0') { // if string1 = '/0' and string2 = '/0'
            return 0;                             // return 0 
        } else if (*_str1_ == '\0' && *_str2_ != '\0') { // if string1 = '/0' and string2 = 'B'
            return -1;                                   
        } else if (*_str1_ != '\0' && *_str2_ == '\0') {  // if string1 = 'B' and string2 = '/0'
            return 1;                           // return 1 bc string1 is higher
        } else if (*_str1_ == *_str2_) {
            _str1_++;
            _str2_++;
        } else if (*_str1_ > *_str2_) {
            return 1;
        } else if (*_str1_ < *_str2_) {
            return -1;
        }
    }
}