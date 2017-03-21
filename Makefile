CC = gcc
CFLAGS = -Wall -ansi -pedantic -O2
LFLAGS = -lm
OUT = ep2
IN = ep2.c
OBJS = ep2.o StringOps.o Fila.o Pilha.o



all: $(OUT)

clean: 
	rm -f $(OBJS) $(OUT)

$(OUT): $(OBJS) 
	$(CC) $(OBJS) $(CFLAGS) -o $(OUT)


ep2.o: $(IN)
	$(CC) $(IN) $(CFLAGS) -c -o ep2.o

StringOps.o: StringOps.c
	$(CC) StringOps.c $(CFLAGS) -c -o StringOps.o
	
Fila.o: Fila.c
	$(CC) Fila.c $(CFLAGS) -c -o Fila.o

Pilha.o: Pilha.c
	$(CC) Pilha.c $(CFLAGS) -c -o Pilha.o



