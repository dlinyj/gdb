# Makefile for Hello World project
#
all: var

var: var.o print_count.o
	gcc -o  var -g var.o print_count.o

print_count.o: print_count.c print_count.h
	gcc -c -g print_count.c

var.o: var.c print_count.h
	gcc -c -g var.c

clean:
	rm -f *.o var
