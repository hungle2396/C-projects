#include <stdio.h>
#include <stdlib.h>

#include "my_ls.h"
/* Write a program called my_ls. Following the specifications of this man page.

1. my_ls -- list directory contents
2. my_ls [-Rat] [file ..]
3. For each operand that names a file of a type other than directory, my_ls displays its name as well as any requested, associated information. 
4. If no operands are given, the contents of the current directory are displayed. If more than one operand is given, non-directory operands are displayed first; directory and non-directory operands are sorted separately and in lexicographical order.

5. The following options are available:
-a Include directory entries whose names begin with a dot (.).
-t Sort by time modified (most recently modified first) before sorting the operands by lexicographical order.

6. Your code must be compiled with the flags -Wall -Wextra -Werror.

7. you must create a Makefile, and the ouput is the command itself
You can use:
malloc(3)
free(3)
printf(3)
open(2)
close(2)
lseek(2)
read(2)
write(2)
stat(2)
opendir(2)
closedir(2)
readdir(2)

8. You can NOT use:
Any functions / syscalls which does not appear in the previous list
Yes, it includes exit.

*/

int main(int ac, char **av) {
    //char **directory_Array = duplicateArgv(ac, av);
    
    Options *option = get_Option(ac, av);

    print_Option(option, ac, av);

    free(option);

    //freeDirectories(directory_Array);
    return 0;
}