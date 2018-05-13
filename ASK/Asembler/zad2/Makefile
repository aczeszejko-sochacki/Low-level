all: zad2.o lcm_gcd.o
	gcc -o zad2 zad2.o lcm_gcd.o -Wall -Wextra 

zad1.o: zad1.c
	gcc -Og -c -g zad2.c -Wall -Wextra

clz.o: clz.s
	gcc -c -g lcm_gcd.s -Wall -Wextra

clean:
	rm -f zad2.o lcm_gcd.o zad2
