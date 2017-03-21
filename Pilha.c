#include "Pilha.h"

Pilha *inicializaPilha()
{
	Celula2 *tp = malloc(sizeof(Celula2));
	Pilha *pilha = malloc(sizeof(Pilha));
	tp->prox = NULL;
	pilha->topo = tp;
	return pilha;
}

void empilha(int y, Pilha *pilha)
{
	   Celula2 *nova,  *tp = pilha->topo;
	   nova = malloc(sizeof(Celula2));
	   nova->conteudo = y;
	   nova->prox  = tp->prox;
	   tp->prox = nova;
	   pilha->topo = tp;
}

int desempilha(Pilha *pilha)
{
   int x;
   Celula2 *p, *tp = pilha->topo;
   p = tp->prox;
   x = p->conteudo;
   tp->prox = p->prox;
   free( p);
   return x; 
}

void imprimePI(Pilha *pilha)
{
	Celula2 *p;
	p = pilha->topo->prox;
	while(p != NULL)
	{
		printf(" %d ", p->conteudo);
		p = p->prox;
	}
	printf("\n");
}


void imprimePIInvertida(Pilha *pilha)
{
	Celula2 *p, *tp = malloc(sizeof(Celula2));
	Pilha *aux = malloc(sizeof(Pilha));
	
	/* Inicializamos a pilha auxiliar */
	tp->prox = NULL;
	aux->topo = tp;


	p = pilha->topo->prox;
	while(p != NULL)
	{
		empilha(p->conteudo, aux);
		p = p->prox;
	}
	/* agora imprimimos a pilha invertida */
	p = aux->topo->prox;
	while(p != NULL)
	{
		if(p->prox == NULL)
		{
			printf(" %d ", p->conteudo);
		}else {
			printf(" %d ->", p->conteudo);
		}
		p = p->prox;
	}
	printf("\n");
}

void copiaPilha(Pilha *i, Pilha *j)
{
	/*printf("Copia PIlha\n");
	printf("PILHA; dentro do copia: ");
	imprimePI(i);*/
	Celula2 *p = i->topo->prox, *tp = malloc(sizeof(Celula2));
	Pilha *aux = malloc(sizeof(Pilha));

	/* Inicializamos a pilha auxiliar */
	tp->prox = NULL;
	aux->topo = tp;

	while(p != NULL)
	{
		empilha(p->conteudo, aux);
		p = p->prox;
	}

	p = aux->topo->prox;
	while(p != NULL)
	{
		empilha(p->conteudo, j);
		p = p->prox;
	}
}


int numElemPilha(Pilha *i)
{
	int cont = 0;
	Celula2 *p = i->topo->prox;
	while(p != NULL)
	{
		cont++;
		p = p->prox;
	}
	return cont;
}
