/* Programa: insertionSort.c
Programador: Matheus E. Santana da Silva
Data: 32/12/2016
	Estudo dos métodos elementares de ordenação de forma recursiva do método .
*/
#include<stdio.h>

#define MAX 5
int main(){
	int i;
	int v[MAX] = {5, 4, 3, 2, 1};
	
	
	insertionSort_R(MAX -1, v);
	//selectionSort_R(MAX -1, v);
	//bubleSort_R(MAX -1, v);
	//quickSort_R(0, MAX-1, v);
	//mergeSort_R(0, MAX , v);
	
	for(i =0; i < MAX; i++)
		printf("%d ", v[i]);
		
		return 0;
}
void insertionSort_R(int n, int v[]){
	
	if(n > 0){
		int j, x;
		x = v[n];		
		insertionSort_R(n-1, v);
		
		for(j = n-1; j >= 0 && v[j]  >x; j--)
			v[j+1] = v[j];
			v[j+1] = x;
	}
}
void selectionSort_R(int n, int v[]){
	
	if(n > 0){
		int i;
		int aux;
		int max = n;
		
		for(i =0; i < n-1; i++)
			if(v[i] > v[max])
			max = i;
		
		aux = v[n];
		v[n] = v[max];
		v[max] = aux;
		selectionSort_R(n-1, v);
		
	}
}
void bubleSort_R(int n, int v[]){
	
	if(n>0){
		int i;
		int aux;
		for(i =0; i < n; i++){
			if(v[i] > v[i+1])
			aux = v[i];
			v[i] = v[i+1];
			v[i+1] = aux;
		}
		
		bubleSort_R(n-1, v);	
	}
}
void quickSort_R(int p, int r, int v[]){
	
	
	if(p < r){
	int q;
	
		q = separa(p, r, v);
		quickSort_R(p, q, v);
		quickSort_R(q+1, r, v);	
	}
}
int separa(int p, int r, int v[]){
	int i = p-1;
	int j = r+1;
	int x = v[p];
	int aux;
	
	while(1){
		do{
			j--;
		}while(v[j] > x);
		
		do{
			i++;
		}while(v[i] < x);
		
		if(i < j){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}else{
			return j;
		}
	}
	
}
void mergeSort_R(int p, int r, int v[]){
	
	if(p < r-1){
		int q = (p + r)/2;
		mergeSort_R(p, q, v);
		mergeSort_R(q, r, v);
		intercala(p, q, r, v);	
	}
}
void intercala(int p, int q, int r, int v[]){
	int i = p;
	int j = q;
	int k =0;
	int w[r-p];
	
		while( i < q && j < r){
			if(v[i] < v[j]){
				w[k] = v[i];
				i++;
			}else{
				w[k]= v[j];
				j++;
			}
			k++;
		}
		
		while(i < q){
			w[k] = v[i];
			i++;
			k++;
		}
		while(j < r){
			w[k] = v[j];
			j++;
			k++;
		}
		
		for(i = p; i < r; i++)
			v[i] = w[i-p];
}
