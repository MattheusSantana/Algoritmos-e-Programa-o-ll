#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

void troca(int *a, int *b); //Função de troca de elementos.
void bubblesort(int n, int v[]); //Função de ordenação por pares.
void selectionsort(int n, int v[]); //Função de ordenação por seleção.
void insertionsort(int n, int v[]); //Função de ordenação por inserção.
void copia_tmp(int n, int v[], int tmp[]); //Função que copia vetores temporariamento.


int main(void){
  int i, v[MAX], tmp[MAX];
  int n = MAX; //Número de elementos.
  clock_t inicio, fim; //Varíaveis que receberam os tempos de clock.

  /* initialize random seed:
  Passo 1: Sorteando numero aleatório */
  srand (time(NULL));

  //Passo 2: Populando vetor
  for (i = 0; i < n; i++)
    v[i] = rand();

  printf("%d elementos\n", n);


  /*Passo 3:
  Cópia temporária do vetor v[], para tmp[].
  Iniciando a contagem.
  Executando a função.
  Finalizando a contagem e calculando e imprimindo o tempo */

  copia_tmp(n, v,tmp);

  inicio = clock();
  bubblesort(n, tmp);
  fim = clock();
  printf("BUBBLE: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

  copia_tmp(n, v,tmp);

  //Recomeçando contagem e executando passo 3 para a função selectionSort.
  inicio = clock();
  selectionsort(n, tmp);
  fim = clock();
  printf("SELECTION: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

//Recomeçando contagem e executando passo 3 para a função selectionSort.
  copia_tmp(n, v,tmp);
  inicio = clock();
  insertionsort(n, tmp);
  fim = clock();
  printf("INSERTION: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

  return 0;
}
//Essa função realiza a troca de pares de elementos de um vetor em suas respectivas posições.
void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a =*b;
    *b = aux;
}

/*Método de ordenação por trocas consecutivas.
  A cada passo, posiciona o maior elemento de um subconjunto de
  elementos do vetor de entrada na sua localização correta neste vetor
  Recebe um número inteiro n >= 0 e um vetor v de números inteiros
  com n elementos e rearranja o vetor v de modo que fique crescente */
void bubblesort(int n, int v[]){
    int i, j;
    for (i = n - 1; i > 0; i--)
        for (j = 0; j < i; j++)
            if (v[j] > v[j+1])
        troca(&v[j], &v[j+1]);
        return;
}

/*Método de ordenação por seleção.
  Baseado na idéia de escolher um menor elemento do vetor,
  depois um segundo menor elemento e assim por diante
  Recebe um número inteiro n >= 0 e um vetor v de números inteiros
 com n elementos e rearranja o vetor v de modo que fique crescente */

void selectionsort(int n, int v[]){
    int i, j, min;

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i+1; j < n; j++)
            if (v[j] < v[min])
                min = j;
    troca(&v[i], &v[min]);

    }
    return;
}
/* Método de ordenação por inserção
    Considera um elemento de um conjunto como ordenado e adiciona o próximo
    elemento em sua nova posição de forma que o conjunto sempre se mantenha ordenado
    até o fim do conjunto.
    Recebe um número inteiro n >= 0 e um vetor v de números inteiros
    com n elementos e rearranja o vetor v de modo que fique crescente
*/
void insertionsort(int n, int v[]){
    int i, j, x;

    for (i = 1; i < n; i++){
        x = v[i];
            for (j = i - 1; j >= 0 && v[j] > x; j--)
            v[j+1] = v[j];
        v[j+1] = x;
    }
    return;
}

/*Essa função copia temporariamente os elementos do vetor
  já preenchido para um vetor temporário. */
void copia_tmp(int n, int v[], int tmp[]){
        for(int i =0; i < n; i++)
            tmp[i] = v[i];

}
