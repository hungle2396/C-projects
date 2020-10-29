CC=gcc
OUTPUT=my_ls

all: ${OUTPUT}

${OUTPUT}: main.o get_Option.o print_Option.o
	${CC} get_Option.o print_Option.o main.o -o ${OUTPUT}

get_Option.o: get_Option.c 
	${CC} -c get_Option.c 

print_Option.o: print_Option.c
	${CC} -c print_Option.c

main.o: main.c 
	${CC} ${CC_OUTPUT} -c main.c

clean:
	rm *.o ${OUTPUT}