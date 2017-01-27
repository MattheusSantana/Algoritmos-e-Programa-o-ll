	/*HeapSort para um vetor minHeap*/
#include<stdio.h>

int main(){
	int v[8] = {1, 11, 2, 4, 6, 8, 9, 3};
	int i;

	//printf("Pai 	 ---->%d\n", pai(1));
	//printf("Esquerdo ---->%d\n", esquerdo(1));
	//printf("Direito  ---->%d\n", direito(1));

	//constroi_MinHeap(8, v);

	heapSort(8, v);
	

	for(i =0; i < 8; i++)
		printf("%d ", v[i]);
		printf("\n");

	return 0;
}
int pai(int i){
	return (i -1) /2;
}

int esquerdo(int i){
	return (i * 2) +1;
}
int direito(int i){
	return(i *2)+ 2;
}

void desce(int n, int v[], int i){
	int e = esquerdo(i);
	int d = direito(i);
	int menor;
	int aux;

	if(e < n && v[e] < v[i])	//Se e exite e se o filho da esquerda for menor do que o pai.
		menor = e;				//Guardando a posição de e.
	else
		menor = i; 

	if(d < n && v[d] < v[menor])
		menor = d;
	if(menor != i){				//Se o pai não for o menor
		aux = v[menor]; 	
		v[menor] = v[i];
		v[i] = aux;
		desce(n, v, menor);		// Chamando a função recursivamente 	

	}

}

void constroi_MinHeap(int n, int v[]){
	int i;

	for(i = n/2 -1; i > 0; i--)
		desce(n, v, i);
}

void heapSort(int n, int v[]){
		int w[n];				//Vetor auxiliar.
		int aux = n; 			//Guardando o tamanho original do arranjo.
		int k =0;				//índice do vetor w[].

		constroi_MinHeap(n, v); //Ordenando vetor segundo a propriedade minHeap.
		while(k < aux){
			w[k] = v[0];		//Pegando elemento de menor prioridade.
			v[0] = v[n-1]; 
			n = n-1;
			desce(n, v, 0);		//Reorganizando estrutura.
			k++;
		}

		for(k =0; k < aux; k++) 
			v[k] = w[k];		// Copiando novamente os elementos de w[] para v[], mas agora já ordenados..
}