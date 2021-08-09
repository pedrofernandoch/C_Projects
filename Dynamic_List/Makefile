BINARY=trab
SOURCES=dyn_list_simple.c main.c
CC=gcc
INCLUDES=.

all:
	$(CC) -o $(BINARY) $(SOURCES) -I$(INCLUDES)

debug:
	$(CC) -g -o $(BINARY) $(SOURCES) -I$(INCLUDES)

profiler:
	$(CC) -pg -o $(BINARY) $(SOURCES) -I$(INCLUDES)

run:
	./$(BINARY)

clean:
	rm *.o

zip:
	zip -r trabalho.zip *.c *.h Makefile
