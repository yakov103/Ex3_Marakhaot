# makefile with dynamic library

all: stringProg

stringProg: main.o libUtilsD.so
	gcc -Wall -g -o stringProg main.o libUtilsD.so

main.o: main.c StringController.h
	gcc -Wall -g -c main.c

#Utils.o: Utils.c StringController.h
#	gcc -Wall -g -c Utils.c

libUtilsD.so: Utils.c StringController.h
	gcc -Wall -g -fPIC -shared -o libUtilsD.so Utils.c -lc

clean:
	rm -fr *.o *.a *.so stringProg


# makefile with archive

#all: stringProg
#
#stringProg: main.o libUtils.a
#	gcc -Wall -g -o stringProg main.o libUtils.a
#
#main.o: main.c StringController.h
#	gcc -Wall -g -c main.c
#
#Utils.o: Utils.c StringController.h
#	gcc -Wall -g -c Utils.c
#
#libUtils.a: Utils.c StringController.h
#	ar rcs libUtils.a Utils.o # list here all the files i want to become library
#
#clean:
#	rm -fr *.o *.a *.so stringProg


# ar rcs libUtils.a Utils.o
# ar rcs  # ar - archive - c create replacement insert the file members
#into the archive - s will write an object file index into the archive
# gcc =shared Utils.o -o libUtils.so -fPIC # position independent Code

# good makefile cz it is generic

#CC := gcc
#CFLAGS := -Wall -g
#
#objs := main.o Utils.o
#target := stringProg
#
#all: $(target)
#
#deps := $(patsubst %.o,%.d,$(objs))
#-include $(deps)
#DEPFLAGS = -MMD -MF $(@:.o=.d)
#
#stringProg: $(objs)
#	$(CC) $(CFLAGS) -o $@ $^
#
#%.o: %.c
#	$(CC) $(CFLAGS) -c $< $(DEPFLAGS)
#
#clean:
#	rm -f $(target) $(objs) $(deps)




# old but good makefile

#all: stringProg
#
#stringProg: main.o Utils.o
#	gcc -Wall -g -o stringProg main.o Utils.o
#
#main.o: main.c StringController.h
#	gcc -Wall -g -c main.c
#
#Utils.o: Utils.c StringController.h
#	gcc -Wall -g -c Utils.c
#
#clean:
#	rm -f *.o *.a stringProg



# bad not working

# main.c StringController.h
#          	gcc -Wall -c main.c
#
#
#
#
#all:stringProg
#
#stringProg: main.o StringController.h utilslib.a
#	gcc -Wall -g -o stringProg main.o utilslib.a
#
#main.o: main.c
#	gcc -Wall -g -c main.c StringController.h
#
#util.o: Utils.c StringController.h
#
#utilslib.a: Utils.c
#	ar -rcs utilslib.a Utils.c StringController.h
#
#.PHONY = all clean
#
#clean:
#	rm -rf *.o *.a stringProg
