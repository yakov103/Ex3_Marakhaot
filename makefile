all: stringProg

stringProg: main.o libUtils.a
	gcc -Wall -g -o stringProg main.o libUtils.a

main.o: main.c StringController.h
	gcc -Wall -g -c main.c

Utils.o: Utils.c StringController.h
	gcc -Wall -g -c Utils.c

libUtils.a: Utils.c StringController.h
	ar rcs libUtils.a Utils.o # list here all the files i want to become library

clean:
	rm -fr *.o *.a *.so stringProg