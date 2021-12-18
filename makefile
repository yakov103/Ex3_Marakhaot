all: stringProg

stringProg: main.o libUtilsD.so
	gcc -Wall -g -o stringProg main.o libUtilsD.so

main.o: main.c StringController.h
	gcc -Wall -g -c main.c


libUtilsD.so: Utils.c StringController.h
	gcc -Wall -g -fPIC -shared -o libUtilsD.so Utils.c -lm

clean:
	rm -fr *.o *.a *.so stringProg

