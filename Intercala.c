/* Programa: Intercala.c
Programador: Matheus E. Santana da Silva
Data: 01/12/2016
	Esse Programa ordena os elementos de um vetor de forma crescente usando o método de ordenação por intercalação.
*/

#include<stdio.h>


int main(){
	int v[10] = {1,0,3,2,4,6,4,3,2,1}; //Vetor não ordenado.
	
	//Passo 1. - Ordene o vetor.
	mergeSort(0, 10, v); 
	
	//Passo 2. - Imprima o vetor.
	for(int i =0; i < 10; i++)
		printf("%d ", v[i]);
	
}

/* Recebe um vetor v[p..r-1] e o rearranja em ordem crescente. 
	Condição de parada é para (p >= r -1).*/
void mergeSort(int p, int r, int v[]){
	int q;
	
	if(p < r-1){
		q = (p + r) /2;
		mergeSort(p, q, v); //Passando o primeiro intervalo vetor (p até q).
		mergeSort(q, r, v); //Passando o segundo intervalo do vetor (q até r).
		intercala(p, q, r, v); //Intercalando intervalos (p e q) e (q e r).
	}
}

/* Recebe os vetores crescentes v[p..q-1] e v[q..r-1]
e rearranja v[p..r-1] em ordem crescente e estável.*/
void intercala(int p, int q, int r, int v[]){
	int i, j, k, w[10];
	
	i = p;
	j = q;
	k = 0;
	
	//Passo 1. - Comparando elementos e trocando suas posições.
	while(i < q && j < r){
		//Caso o elemento do primeiro conjunto seja menor do que o elemento do segundo conjunto. 
		if(v[i] < v[j]){
			w[k] = v[i];
			i++;
			
		//Caso o elemento do segundo conjunto seja maior.
		}else{
			w[k] = v[j];
			j++;
		}
		k++;
	}
	
	//Passo 2. - copiando os intervalos restantes para o vetor w[].
	
	//Passo 2.1 - Copiando o primeiro intervalo (p, q-1).
	while(i < q){
		w[k] = v[i];
		i++;
		k++;
	}
	//Passo 2.2 - Copiando o primeiro intervalo (q, r-1).
	while(j < r){
		w[k] = v[j];
		j++;
		k++;
	}
	
	//Passo 3. - Copiando o vetor os elementos de w[] de volta para o vetor v[].
	for(i = p; i < r; i++)
	v[i] = w[i-p];
}
