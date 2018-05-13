all: zad1.o clz.o
	gcc -o zad1 zad1.o clz.o -Wall -Wextra 

zad1.o: zad1.c
	gcc -Og -c -g zad1.c -Wall -Wextra

clz.o: clz.s
	gcc -c -g clz.s -Wall -Wextra

run:
	./zad1 12

clean:
	rm -f zad1.o clz.o zad1
