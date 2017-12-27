main: main.o
	gcc lamport_bakery.o -pthread -Wall -Werror -o lamport_bakery

main.o: lamport_bakery.c
	gcc -c lamport_bakery.c

run: 
	./lamport_bakery 1 2
