all: stringProg

stringProg: main.o Utils.o
	gcc -Wall -g -o stringProg main.o Utils.o

main.o: main.c StringController.h
	gcc -Wall -g -c main.c

Utils.o: Utils.c StringController.h
	gcc -Wall -g -c Utils.c

clean:
	rm -f *.o *.a stringProg