/* **********************************
*									*
*	EP2 - ESTRUTURA DE DADOS 		*
*									*
*	Prof. Andre Fujita 				*
*									*
*	Danilo Aleixo Gomes de Souza	*
*	n USP 7972370					*
*									*
*	Julio Cesar Seki				*
*	n USP 7991145 					*
*									*
********************************** */
#include<math.h>
#include<string.h>
#include"StringOps.h"
#include"Fila.h"
#include"Pilha.h"

#define TRUE 1
#define FALSE 0

/* Ponto onde guardaremos informaçoes dos vertices */
typedef struct ponto
    {
    int nVertice;
    int grauSaida;
    struct ponto *prox;
    } Ponto;

/* Prototipos das funcoes */
int numVertices(FILE *entrada, int *numeroArestas);
Ponto* montaGrafo(FILE *entrada, int tamanho);
void imprimeLista(Ponto *grafo, int nVertices, int *grauEntrada);
void gEntrada(int *grauEntrada, Ponto *grafo, int numeroVertices);
void BFS(Ponto *grafo, int tamanho, int r, int s);


int main(int argc, char **argv)
    {
    Ponto *grafo;
    FILE *entrada;
    int numeroVertices = 0, numeroArestas = 0,i;
    int *grauEntrada;
    int r, s;

    if(argc - 1 > 0)
        {
        entrada = leEntrada(argv[1]);
        numeroVertices = numVertices(entrada, &numeroArestas);
        grauEntrada = malloc(numeroVertices * sizeof(int));

        for(i=0; i<numeroVertices; i++) /*inicializando o vetor*/
            {
            grauEntrada[i] = 0;
            }

        grafo = montaGrafo(entrada, numeroVertices);

        /* Saidas */
        printf("\n");
        printf("Numero de vertices do grafo: %d\n",numeroVertices);
        printf("Numero de arestas do grafo: %d\n", numeroArestas);
        gEntrada(grauEntrada, grafo, numeroVertices);
        imprimeLista(grafo, numeroVertices, grauEntrada);
        printf("\n");

        /* Menor caminho */
        printf("Digite dois vertices:\n");
        if(scanf("%d %d", &r, &s))/*verifica se os vertices foram inseridos corretamente*/
            {
            if(r > numeroVertices || r < 0 || s > numeroVertices || s < 0)
                {
                printf("\nO Vertices inseridos sao invalidos\n");
                }
            else
                {
                BFS(grafo, numeroVertices, r, s);
                }
            }
        }
    else
        {
        printf("\n Modo de usar  ep2 <entrada> \n\n");
        }
    return 0;
    }

/* *************************************************************

					FUNÇOES AUXILIARES

	********************************************************** */


/* Na primeira leitura do arquivo de entrada
	percorremos em busca do maior vertice, para
	podermos posteriormente montar o vetor de vertices
	com o tamanho correto */
int numVertices(FILE *entrada, int *numeroArestas)
    {
    int maiorVertice = 0;
    int verticeSaida, verticeEntrada;
    int numArestas = 0;

    while(TRUE)
        {
        if((fscanf(entrada, "%d\t%d", &verticeSaida, &verticeEntrada)) != EOF)
            {
            numArestas++;

            /* procuramos o maior vertice do arquivo
            	para sabermos qual o tamanho do nosso
            	grafo                                */
            if(verticeSaida > maiorVertice)
                {
                maiorVertice = verticeSaida;
                }
            if(verticeEntrada > maiorVertice)
                {
                maiorVertice = verticeEntrada;
                }
            }
        else break;
        }

    *numeroArestas = numArestas;

    rewind(entrada); /*retornamos ao inicio do arquivo de entrada pois necessitamos ler novamente o arquivo para montar o grafo*/
    return maiorVertice + 1;
    }

/* Passamos o arquivo na segunda vez para agora montar o grafo */
Ponto* montaGrafo(FILE *entrada, int tamanho)
    {
    int verticeSaida, verticeEntrada, i;
    Ponto *grafo, *novoPonto, *temp, *aux;

    /* inicializamos o grafo e setamos suas informaçoes */
    grafo = mallocSafe(tamanho * sizeof(Ponto));
    for(i = 0; i < tamanho; i++)
        {
        grafo[i].nVertice = i;
        grafo[i].grauSaida = 0;
        grafo[i].prox = NULL;
        }

    /* colocamos as arestas no grafo 	*/
    while(TRUE)
        {
        if((fscanf(entrada, "%d\t%d", &verticeSaida, &verticeEntrada)) != EOF)
            {
            novoPonto = mallocSafe(sizeof(Ponto));
            novoPonto->nVertice = verticeEntrada;
            novoPonto->prox = NULL;

            /*comecamos a inserir os vertices ordenadamente na lista e incrementamos o grau de saida de cada um*/
            if(grafo[verticeSaida].prox == NULL) /*como a lista esta vazia basta inserir diretamente o novo elemento*/
                {
                grafo[verticeSaida].prox = novoPonto;
                grafo[verticeSaida].grauSaida = grafo[verticeSaida].grauSaida + 1;
                }
            else /*existem elementos na lista encadeada*/
                {
                temp = grafo[verticeSaida].prox;
                if(temp->nVertice <= novoPonto->nVertice)
                    {
                    while(temp->prox != NULL && temp->prox->nVertice <= novoPonto->nVertice)
                        {
                        temp = temp->prox;
                        }
                    if(temp->prox != NULL && temp->prox->nVertice > novoPonto->nVertice)/*insercao no meio da lista*/
                        {
                        novoPonto->prox = temp->prox;
                        temp->prox = novoPonto;
                        grafo[verticeSaida].grauSaida = grafo[verticeSaida].grauSaida + 1;
                        }
                    if(temp->prox == NULL) /*insercao no fim da lista*/
                        {
                        temp->prox = novoPonto;
                        grafo[verticeSaida].grauSaida = grafo[verticeSaida].grauSaida + 1;
                        }
                    }
                else /*insercao no comeco da lista*/
                    {
                    aux = grafo[verticeSaida].prox;
                    grafo[verticeSaida].prox = novoPonto;
                    novoPonto->prox = aux;
                    grafo[verticeSaida].grauSaida = grafo[verticeSaida].grauSaida + 1;
                    }

                }
            }
        else break;
        }
    return grafo;
    }


/* Usamos o principio da BFS(Breadth First Search) para percorrermos
	o grafo e acharmos a menor distancia entre dois pontos,
	para conseguirmos rastrear o percurso feito, usamos um vetor
	de pilhas que guardam os vertices que ja foram visitados */
void BFS(Ponto *grafo, int tamanho, int r, int s)
    {
    int *jaVisitei;
    int i, atual;
    Pilha **vetorPilhas;
    Fila *fila = inicializaFila();
    Ponto *aux;
    int acabou = FALSE;

    jaVisitei = mallocSafe(tamanho * sizeof(int));
    vetorPilhas = mallocSafe(tamanho * sizeof(Pilha *));

    for(i = 0; i < tamanho; i++) jaVisitei[i] = FALSE;
    for(i = 0; i < tamanho; i++) vetorPilhas[i] = inicializaPilha();

    /* O primeiro vertice a ser analisado
    	é aquele passado pela linha de comando */
    fila = insereFI(r, fila);
    empilha(r, vetorPilhas[r]);
    jaVisitei[r] = TRUE;

    /* Euquanto a fila possui elementos e o vertice final nao
    	foi encontrado ainda */
    while(fila->fi != fila->fi->prox && acabou == FALSE)
        {
        atual = removeFI(fila);

        /* Percorremos todos os vizinhos  */
        for(aux = &grafo[atual]; aux != NULL; aux = aux->prox)
            {
            /* Se o vertice nao foi visitado ainda colocamos ele na fila */
            if(jaVisitei[aux->nVertice] == FALSE)
                {
                fila = insereFI(aux->nVertice, fila);

                copiaPilha(vetorPilhas[atual], vetorPilhas[aux->nVertice]);
                empilha(aux->nVertice, vetorPilhas[aux->nVertice]);

                jaVisitei[aux->nVertice] = TRUE;
                }
            /* Caso acharmos o vertice procurado a interaçao termina e
            	imprimimos o percurso e o numero de passos */
            if(aux->nVertice == s)
                {
                printf("Lista de vertices percorridos: ");
                imprimePIInvertida(vetorPilhas[aux->nVertice]);
                printf("\nDistancia minima de r a s: %d passo(s) \n\n", numElemPilha(vetorPilhas[aux->nVertice]) - 1);
                acabou = TRUE;
                break;
                }
            }
        }
    if(acabou ==FALSE)
        {
        printf("\nNao existe um caminho possivel do vertice %d ate o vertice %d\n\nVertice", r, s);
        }
    }

/* A funçao verifica o grau de entrada para o vertices do grafo */
void gEntrada(int *grauEntrada, Ponto *grafo, int numeroVertices)
    {
    int i;
    Ponto *aux;
    for(i=0; i<numeroVertices; i++)
        {
        aux = grafo[i].prox;
        while(aux != NULL)
            {
            grauEntrada[aux->nVertice]++;
            aux = aux->prox;
            }
        }
    }

/*Funcao utilizada para imprimir o vetor de listas encadeadas */
void imprimeLista(Ponto *grafo, int nVertices, int *grauEntrada)
    {
    int i;
    Ponto *temp;
    printf("\n");
    printf("Lista de Adjacencia:\n");
    for(i=0; i<nVertices; i++)
        {
        temp = grafo[i].prox;
        printf("Vertice:%2d (Grau de saida: %2d)(Grau de entrada: %2d) ==> ",grafo[i].nVertice, grafo[i].grauSaida, grauEntrada[i]);
        if(temp==NULL)
            printf(" NULL");
        else
            {
            while(temp!=NULL)
                {
                printf("%2d ", temp->nVertice);
                temp = temp->prox;
                }
            }
        printf("\n");
        }
    }
