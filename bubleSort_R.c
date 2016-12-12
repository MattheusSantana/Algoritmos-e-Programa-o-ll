/* Programa: bubleSort.c
Programador: Matheus E. Santana da Silva
Data: 12/12/2016
	Estudo da forma normal e recursiva do método de ordenação por trocas BubleSort.
*/


#include<stdio.h>

int main() {
	
	int v[5] = {5, 4, 3, 2, 1};
	int i;
	bubleSort_R(5, v); //(Passe n).
	//bubleSort(4, v); (Passe n-1).
	
	for(i =0; i < 5; i++)
		printf("%d ", v[i]);
}
/*Método de ordenação por trocas consecutivas.
  A cada iteração do laço, posiciona o elemento do vetor na sua respectiva posição
  analizando se esse elemento é maior do que o próximo, sucessivamente,
  de forma que o vetor fique ordenado em órdem crescente.
  Recebe um número inteiro n >= 0 e um vetor v de números inteiros
  com n elementos e rearranja o vetor v de modo que fique crescente */
void bubleSort(int n, int v[]) {
	int i, j;							//índices dos laços for.

	for(i =n-1; i > 0; i++) {			//Navegando o vetor v[].
		for(j = 0; j < n; j++) {		//Navegando o vetor v[] para cada elemento do vetor.
			if(v[j]> v[j+1]){			//Caso o elemento da vez seja maior do que o próximo elemento mais a direita.	
				v[j]   ^= v[j+1];		//Trocando os elementos usando o operador XOR.
				v[j+1] ^= v[j];
				v[j]   ^= v[j+1];	
				
			}
		}
	}
}


/*Ordenação por trocas de forma recursiva.
  Para cada chamada da função, o maior elemento
  do intervalo é posto na ultima posição do intervalo.
  o intervalo decresce a cada chamada da função desconsiderando os elementos já ordenados..	
*/
void bubleSort_R(int n, int v[]){
	int j;
	
	if(n <= 0){
		for(j =0; j < n; j++){
				if(v[j]> v[j+1]){
				v[j]   ^= v[j+1];
				v[j+1] ^= v[j];
				v[j]   ^= v[j+1];	
				
			}
		}
		bubleSort_R(n-1, v);
	}
}

