a.out: main.o batallanaval.o
	gcc main.o batallanaval.o

main.o: main.c
	gcc -c main.c

batallanaval.o: batallanaval.c
	gcc -c batallanaval.c

run: a.out
	./a.out
clean: 
	rm a.out *.o
