#include "Fila.h"

Fila *inicializaFila()
{
	Celula *fi = malloc(sizeof(Celula));
	Fila *fila = malloc(sizeof(Fila));
	fi->prox = fi;
	fila->fi = fi;
	return fila;
}

int removeFI( Fila *fila) {
   int x;
   Celula *p, *fi = fila->fi;
   if(fi != fi->prox)
   {

   		p = fi->prox; 
	   	x = p->conteudo;
	   	fi->prox = p->prox;
	   	free( p);
	   	return x;  
   } else {
   	printf("ultimo elemento pilha\n");
   	return 0;
   }
   
}

Fila *insereFI( int y, Fila *fila) {
   Celula *nova, *fi = fila->fi;
   nova = malloc( sizeof (Celula));
   nova->prox = fi->prox;
   fi->prox = nova;
   fi->conteudo = y;
   fila->fi = nova;
   return fila;
}

void imprimeFI(Fila *fila)
{
	Celula *p;
	p = fila->fi->prox;
	while(p != fila->fi)
	{
		printf(" %d ", p->conteudo);
		p = p->prox;
	}
	printf("\n");
}
