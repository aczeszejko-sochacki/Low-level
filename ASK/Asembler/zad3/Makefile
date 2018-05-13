all: zad3.o insert_sort.o
	gcc -o zad3 zad3.o insert_sort.o -Wall -Wextra 

zad1.o: zad1.c
	gcc -Og -c -g zad3.c -Wall -Wextra

clz.o: clz.s
	gcc -c -g insert_sort.s -Wall -Wextra

clean:
	rm -f zad3.o insert_sort.o zad3
