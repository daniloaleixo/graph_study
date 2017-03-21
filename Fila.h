
/* 

	Algoritmo de Fila baseado no site 
	do professor Paulo Feofiloff

	*/

#include<stdlib.h>
#include<stdio.h>

typedef struct cel {
   int         conteudo; 
   struct cel *prox;
} Celula;

typedef struct {
	Celula *fi;
} Fila;

Fila *inicializaFila();
int removeFI( Fila *fila);
Fila *insereFI( int y, Fila *fila);
void imprimeFI(Fila *fila);

