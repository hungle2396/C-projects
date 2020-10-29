CC = gcc
CC_OPT = -g3 -fsanitize=address -Wall -Wextra -Werror
OUTPUT = my_printf

all: ${OUTPUT}

${OUTPUT}: helper_functions.o Itoa.o Utoa.o my_printf.o
	${CC} helper_functions.o Itoa.o Utoa.o my_printf.o -o ${OUTPUT}

helper_functions.o: helper_functions.c helper_functions.h Itoa.h Utoa.h
	${CC} -c helper_functions.c
	
Itoa.o:	Itoa.c helper_functions.h Itoa.h Utoa.h
	${CC} -c Itoa.c

Utoa.o:	Utoa.c helper_functions.h Itoa.h Utoa.h
	${CC} -c Utoa.c
	
my_printf.o: my_printf.c helper_functions.h Itoa.h Utoa.h
	${CC} -c my_printf.c 
	
clean:
	rm *.o ${OUTPUT}