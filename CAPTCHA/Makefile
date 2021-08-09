all:
	@gcc main.c funcoes.c -o trab -lm

main.o: main.c
	@gcc -c main.c

funcoes.o: funcoes.c
	@gcc -c funcoes.c

run:
	@./trab

clean:
	rm *.o

zip:
	zip -r trabalho.zip *.c Makefile
