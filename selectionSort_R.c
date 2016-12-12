/* Programa: selectionSort.c
Programador: Matheus E. Santana da Silva
Data: 12/12/2016
	Estudo da forma normal e recursiva do m�todo de ordena��o por sele��o selectionSort.
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

/*Essa fun��o considera o elemento da primeira posi��o do intervalo como sendo o maior elemento
  Feito isso ela navega o vetor procurando o menor elemento, para efetuar a troca de posi��es entre eles.
  De forma que os maiores elementos sempre fiquem mais a direita e os menores mais a esqueda.
  Ordenando o vetor em ordem crescente.
*/
void selectionSort(int n, int v[]){
	int i, j;
	int min;
	int aux;
	
	for(i =0; i < n-1; i++){
		min = i; 					//Considera i como menor elemento.
		
		for(j = i+1; j < n; j++)	//Procura o elemento menor ou igual ao elemento da posi��o i.
			if(v[j] < v[min])		//Caso seja menor que v[i].
				min = j; 			//Pega a posi��o desse menor elemento.
	
		aux  = v[i];				//Trocando os elementos de posi��o.		
		v[i] = v[min];			
		v[min] = aux;		
			
	}
}

/* Esta fun��o considera a ultima posi��o v[n], como a posi��o do maior elemento (max) do intervalo.
   Feito isso, ela procura o maior elemento do intervalo v[i at� n-1], desconsiderando a posi��o de n.
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
			max = i;				//Armazena a posi��o do maior elemento.
		
		aux  = v[n];				//Trocando os elementos de posi��o de forma		
		v[n] = v[max];				//que o maior elemento sempre fique na ultima posi��o
		v[max] = aux;				//mais a esquerda.
	
		selectionSort_R(n-1, v); 	//Desconsidera a ultima posi��o do intervalo, pois esta j� est� ordenada.
	}
}
