/* Programa: bubleSort.c
Programador: Matheus E. Santana da Silva
Data: 12/12/2016
	Estudo da forma normal e recursiva do m�todo de ordena��o por trocas BubleSort.
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
/*M�todo de ordena��o por trocas consecutivas.
  A cada itera��o do la�o, posiciona o elemento do vetor na sua respectiva posi��o
  analizando se esse elemento � maior do que o pr�ximo, sucessivamente,
  de forma que o vetor fique ordenado em �rdem crescente.
  Recebe um n�mero inteiro n >= 0 e um vetor v de n�meros inteiros
  com n elementos e rearranja o vetor v de modo que fique crescente */
void bubleSort(int n, int v[]) {
	int i, j;							//�ndices dos la�os for.

	for(i =n-1; i > 0; i++) {			//Navegando o vetor v[].
		for(j = 0; j < n; j++) {		//Navegando o vetor v[] para cada elemento do vetor.
			if(v[j]> v[j+1]){			//Caso o elemento da vez seja maior do que o pr�ximo elemento mais a direita.	
				v[j]   ^= v[j+1];		//Trocando os elementos usando o operador XOR.
				v[j+1] ^= v[j];
				v[j]   ^= v[j+1];	
				
			}
		}
	}
}


/*Ordena��o por trocas de forma recursiva.
  Para cada chamada da fun��o, o maior elemento
  do intervalo � posto na ultima posi��o do intervalo.
  o intervalo decresce a cada chamada da fun��o desconsiderando os elementos j� ordenados..	
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

