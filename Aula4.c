#include <stdio.h>
#define MAX 100


/* Escreve um vetor contendo n elementos */
void escreve_vetor(int n, int v[MAX]);

/* Procura um elemento x em um vetor v ordenado contendo n elementos,
   devolvendo a posição onde x está ou deveria estar */
int busca_binaria_R(int esq, int dir, int v[MAX], int x);

/* Remove o elemento da posição k de um vetor v ordenado contendo n
   elementos, devolvendo o novo valor de n */
int remove_R(int n, int v[MAX], int k);

/* Insere recursivamente um elemento x na posição k do vetor v
   ordenado contendo n elementos, devolvendo o novo valor de n */
int insere_R(int n, int v[MAX], int k, int x);


int main(void)
{
  int x, k, n = 10, v[MAX] = {1,2,3,4,5,6,7,8,9,10};
  int op;
  int Indice;

  escreve_vetor(n,v);

  do {
    printf("\n\nOperações:\n");
    printf("\t1) Escrever o vetor ordenado\n");
    printf("\t2) Procurar elemento no vetor ordenado\n");
    printf("\t3) Inserir elemento no vetor ordenado\n");
    printf("\t4) Remover elemento no vetor ordenado\n");
    printf("\t5) Sair\n");
    printf("Digite a operação desejada: ");

    scanf("%d", &op);

    switch(op) {

    case 1:
      escreve_vetor(n, v);
      break;

    case 2:
      printf("Digite o elemento: ");
      scanf("%d", &x);
      /* buscar e testar se está ou não e escrever mensagem */
      Indice = busca_binaria_R(-1, n, v, x);
        if(v[Indice] == x)
        printf("O valor x está na posicao: %d", Indice);
      else{
        printf("O valor x está aproximadamente na posicao: %d", Indice);
      }
      break;

    case 3:
      printf("Digite o elemento: ");
      scanf("%d", &x);
      /* inserir */
      Indice = busca_binaria_R(-1, n, v, x);
          n = insere_R(n, v, Indice, x);
      break;

    case 4:
      printf("Digite o elemento: ");
      scanf("%d", &x);
      /* remover */
      Indice = busca_binaria_R(-1, n, v, x);
      if(v[Indice] == x)
        n = remove_R(n, v, Indice);

      break;

    case 5:
      printf("Até logo!\n");
      break;

    }

  } while (op != 5);

  return 0;
}


void escreve_vetor(int n, int v[MAX])
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", v[i]);
  printf("\n");
}

/* Recebe dois números inteiros esq e dir, um vetor de números
   inteiros crescente v[esq..dir] e um número inteiro x tais
   que v[esq] < x <= v[dir] e devolve um índice k em
   [esq+1, dir] tal que v[k-1] < x <= v[k] */
int busca_binaria_R(int esq, int dir, int v[MAX], int x)
{
  int meio;
  if (esq == dir - 1)
    return dir;
  else {
    meio = (esq + dir) / 2;
    if (v[meio] < x)
      return busca_binaria_R(meio, dir, v, x);
    else
      return busca_binaria_R(esq, meio, v, x);
  }
}

int remove_R(int n, int v[MAX], int k)
{
    if(k == n-1)
        return n-1;
    else{
        v[k] = v[k+1];
        return remove_R(n, v, k+1);

    }

  return n-1;

}

int insere_R(int n, int v[MAX], int k, int x)
{

    if(k == n){
        v[n] = x;
        return n+1;
    }else{
int aux;
    aux = v[k];
    v[k] = x;

    insere_R(n, v, k+1, aux);

    }

}
