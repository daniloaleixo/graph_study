# Estudo de grafos

## Introdução
Projeto realizado para a matéria de Estrutura de Dados - Desenvolver alguns algoritmos básicos de grafos.

## Enunciado
A estrutura de dados a ser usado neste EP consiste em armazenar os vértices num vetor, e as arestas em listas simplesmente encadeadas como mostra a figura acima. 
Seu EP deve ler um grafo de um arquivo de entrada e imprimir na tela: 
1. número de vértices do grafo 
2. número de arestas do grafo 
3. o grau de saída (número de arestas que saem) de cada vértice 
4. o grau de entrada (número de arestas que entram) de cada vértice 
5. a lista dos vértices que saem de cada vértice em ordem crescente 
Cada linha do arquivo de entrada descreve uma aresta do grafo, ou seja, o vértice de saída, uma tabulação, e o vértice de entrada([vérticeinicial][tab] [vértice final]). Em seguida,o usuário deve ser capaz de inserir, pelo teclado,os números de dois vértices (r, s), e o programa deve imprimir na tela, se existe algum caminho do vértice r ao s. Em caso positivo, deve imprimir a distância(a distância de r a s é onúmero de arestas de um caminho mínimo de r a s) entre os vértices e o percurso (lista de vértices percorridos na ordem do percurso de r a s ). 

## Execução
Para executar basta compilar o programa com o Makefile
```sh
make
```
E depois executar o programa para verificação de conectividade 
  ```sh
  ep2 <arquivo de entrada>
  ```
