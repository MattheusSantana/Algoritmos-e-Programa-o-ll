/* Programa: selectionSort.c
Programador: Matheus E. Santana da Silva
Data: 12/12/2016
	Estudo da forma normal e recursiva do método de ordenação por seleção selectionSort.
*/

#include<stdio.h>

int main() {
	
	int v[5] = {5, 4, 3, 2, 1};
	int i;
	// selectionSort_R(4, v); (Passe n-1).
		selectionSort(5, v); // (Passe n).  
	for(i =0; i < 5; i++)
		printf("%d ", v[i]);
}

/*Essa função considera o elemento da primeira posição do intervalo como sendo o maior elemento
  Feito isso ela navega o vetor procurando o menor elemento, para efetuar a troca de posições entre eles.
  De forma que os maiores elementos sempre fiquem mais a direita e os menores mais a esqueda.
  Ordenando o vetor em ordem crescente.
*/
void selectionSort(int n, int v[]){
	int i, j;
	int min;
	int aux;
	
	for(i =0; i < n-1; i++){
		min = i; 					//Considera i como menor elemento.
		
		for(j = i+1; j < n; j++)	//Procura o elemento menor ou igual ao elemento da posição i.
			if(v[j] < v[min])		//Caso seja menor que v[i].
				min = j; 			//Pega a posição desse menor elemento.
	
		aux  = v[i];				//Trocando os elementos de posição.		
		v[i] = v[min];			
		v[min] = aux;		
			
	}
}

/* Esta função considera a ultima posição v[n], como a posição do maior elemento (max) do intervalo.
   Feito isso, ela procura o maior elemento do intervalo v[i até n-1], desconsiderando a posição de n.
   Depois de ter encontrado o maior elemento desse intervalo reduzido, ela troca o novo maior com n.
   De forma que o maior elemento sempre fique mais a direita e o vetor fique em ordem crescente.
*/
void selectionSort_R(int n, int v[]){
	int i;
	int aux;
	int max = n;					//Considera v[n], como maior elemento do vetor.
	
	if(n>0){
	
	for(i = 0; i < n-1; i++)		//Navega o vetor v[].
		if(v[i] > v[max])			//Compara os elementos de forma a pegar o maior do intervalo.
			max = i;				//Armazena a posição do maior elemento.
		
		aux  = v[n];				//Trocando os elementos de posição de forma		
		v[n] = v[max];				//que o maior elemento sempre fique na ultima posição
		v[max] = aux;				//mais a esquerda.
	
		selectionSort_R(n-1, v); 	//Desconsidera a ultima posição do intervalo, pois esta já está ordenada.
	}
}
