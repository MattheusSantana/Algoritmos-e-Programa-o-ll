#include<stdio.h>

int main(){
	int v[10] = {5, 3, 17, 10, 84, 19, 6, 22, 9, 1};
	int i;

	
 	/*Testando a função desce não-recursiva*/
	int v2[10] = {26, 7, 14, 16, 8, 9, 11, 4, 12, 6};
	desce(10, v2, 1); // Descendo elemento da posição 1.

	for(i =0; i < 10; i++)
		printf("%d ",  v2[i]);
		printf("\n");
	
	/*Testando o heapSort com a função desce não-recursiva*/
	heapSort(10, v);

	for(i =0; i < 10; i++)
		printf("%d ",  v[i]);
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
	return (i * 2) +2;
}

/*Implementação não recursiva da função desce*/
void desce(int n, int v[], int i){
	int e;
	int d;
	int maior;
	int aux;
	do{
		e = esquerdo(i);
		d = direito(i);

		if(e < n && v[e] > v[i])	//Se e existe e se é maior que o pai.
			maior = e;
		else
			maior = i;
		if(d < n && v[d] > v[maior]) //Se d existe e se é maior que o maior.
			maior = d;

		if(maior != i){
			aux = v[maior];
			v[maior] = v[i];
			v[i] = aux;

			i = maior;
		}else{
			break;
		}

	}while(i == maior);
}

void constroi_maxHeap(int n, int v[]){
	int i;

	for(i = n/2 -1; i >= 0; i--)
		desce(n, v, i);
}

void heapSort(int n, int v[]){

	int maior;
	int i;

	constroi_maxHeap(n,v);

	for(i = n-1; i > 0; i--){
	maior = v[0];
	v[0] = v[n-1]; //pegando ultimo elemento e colocando na raiz.
	v[n-1] = maior; //Colocando o maior elemento no final.
	n = n-1;
	desce(n, v, 0); //Organizando o primeiro elemento para a posição devida.
}

}