all: zad4.o fibonacci.o
	gcc -o zad4 zad4.o fibonacci.o -Wall -Wextra 

zad4.o: zad4.c
	gcc -Og -c -g zad4.c -Wall -Wextra

clz.o: clz.s
	gcc -c -g fibonacci.s -Wall -Wextra

clean:
	rm -f zad4.o fibonacci.o zad4
