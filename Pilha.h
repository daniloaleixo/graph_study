#include<stdlib.h>
#include<stdio.h>

typedef struct cel2 {
   int         conteudo; 
   struct cel2 *prox;
} Celula2;

typedef struct {
	Celula2 *topo;
} Pilha;

Pilha *inicializaPilha();
int desempilha(Pilha *pilha);
void empilha(int y, Pilha *pilha);
void imprimePI(Pilha *pilha);
void imprimePIInvertida(Pilha *pilha);
void copiaPilha(Pilha *i, Pilha *j);
int numElemPilha(Pilha *i);

