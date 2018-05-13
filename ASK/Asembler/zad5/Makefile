all: zad5.o mulf.o
	gcc -o zad5 zad5.o mulf.o -Wall -Wextra 

zad5.o: zad5.c
	gcc -Og -c -g zad5.c -Wall -Wextra

clz.o: clz.s
	gcc -c -g mulf.s -Wall -Wextra

clean:
	rm -f zad5.o mulf.o zad5
