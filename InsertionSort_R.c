/* Programa: insertionSort.c
Programador: Matheus E. Santana da Silva
Data: 12/12/2016
	Estudo da forma normal e recursiva do método de ordenação por inserção insertionSort.
*/
#include<stdio.h>

int main() {
	
 	int v[5] = {5, 4, 3, 2, 1};
	int i;
	insertionSort_R(4, v); 
	
	for(i =0; i < 5; i++)
		printf("%d ", v[i]);
}

/*Essa função considera a primeiro elemento do intervalo como ordenado.
  Feito isso ela pega o próximo elemento do intervalo e insere no conjunto na sua respectiva posição*/
insertionSort(int n, int v[]){
	int i, j;					//Índices de iterações do laço.
	int x; 						//Armazena o elemento a ser ordenado.
	for(i = 1; i < n; i++){ 	//I = 1 pois a função considera a primeira posição do vetor comoo já ordenada.
		x = v[i];			
	
	//j = i +1. começa sempre uma posição após o conjunto ordenado.	
	//j <=0. J precisa ir até 0 pois o elemento x pode ser menor do que o elemento de v[0].
	//v[j] > x. Compara até achar um elemento que seja menor ou igual a x. pois adicionará x nessa posição.
	//j--. O índice decrementa pois a verificação é feita da direita para a esquerda.
		for(j = i -1; j >=0 && v[j] > x; j--)
			v[j+1] = v[j];		//Sobreescrevendo os elementos do vetor em uma posição á frente, de forma que sobre uma posição vaga, aonde x deve entrar.
			v[j+1] = x;			//Adiciona x na posição que sobrou.
	}
}

/*Função de Inserção de modo recursivo.
	Esta função considera o primeiro elemento do conjunto como ordenado
	Feito isto, a ordenação começa com x sendo o próximo elemento após o conjunto ja ordenado.
	A função calcula se x é menor que os elementos anteriores a ele.
	Sendo assim ela sobreescreve todos os elementos para uma posição para frente.
	Até que o laço dessa condição seja falsa, de modo que sobre uma posição vaga, aonde x será inserido.
	
*/
void insertionSort_R( int n, int v[]){
	
		 if(n > 0){
		 	int x;
		 	int j;
		insertionSort_R(n-1, v);
			x = v[n];
            for (j = n - 1; j >= 0 && v[j] > x; j--)
            v[j+1] = v[j];
        v[j+1] = x;	
		 }
    }
	
