#include "StringOps.h"

FILE *leEntrada (char *nomeArquivo)
{
    FILE *entrada;
    /* depuraçao * printf("entrei leEntrada string: %s\n", nomeArquivo);*/
    entrada = fopen(nomeArquivo, "r");
    /* depuraçao * printf("entrada %p\n", entrada);*/
    if(entrada == NULL)
    {
        fprintf(stderr, "Nao consegui ler o arquivo!");
        exit(-1);
    }

    return entrada;

}

/*
  mallocSafe: testa o ponteiro devolvido por malloc
 */
void * mallocSafe (size_t n)
{
  void * pt;
  pt = malloc(n);
  if (pt == NULL) {
    printf("ERRO na alocacao de memoria.\n\n");
    exit(-1);
  }
  return pt;
}

