#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100000

int main(){
    int i;
    int n = MAX;
    int v[MAX];
    int tmp[MAX]; //Vetor temporário.
    clock_t inicio, fim; //Váriaveis que armazenarão a contagem do tempo.

    //Passo 1. Sorteano semente.
    srand (time(NULL));

    //Passo 2. - Populando o vetor.
    for(i =0; i < n; i++)
        v[i] = rand();

    printf("%d elementos\n", n);

    copiaTmp(n, v, tmp);

    inicio = clock();
    mergeSort(0, n, v);
    fim = clock();
    printf("Merge: %g segundos\n", (fim - inicio) / (float) CLOCKS_PER_SEC);

    copiaTmp(n, v, tmp);
    inicio = clock();
    quickSort(0, n, tmp);
    fim = clock();
    printf("Quick: %g segundos\n", (fim - inicio) /(float) CLOCKS_PER_SEC);

    return 0;
}
void mergeSort(int p, int r, int v[]){

    int q;

    if(p < r-1){
        q = (p + r)/2;
        mergeSort(p, q, v);
        mergeSort(q, r, v);
        intercala(p, q, r, v);
    }

}

void intercala(int p, int q, int r, int v[]){
    int i, j, k, w[r-p];

    i =p;
    j =q;
    k =0;

    while(i < q && j < r){
        if(v[i] < v[j]){
            w[k] = v[j];
            i++;
        }else{
            w[k] = v[j];
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

    for(int i =p; i < r; i++)
        v[i] = w[i-p];
}


void quickSort(int p, int r, int v[]){
    int q;
    if (p < r){
        q = separa(p, r, v);
        quickSort(p, q, v);
        quickSort(q+1, r, v);
    }
}

int separa(int p, int r, int v[]){
    int x, i, j, aux;
    x = v[p];
    i = p - 1;
    j = r + 1;
    
    while (1){
        do{
            j--;
        }while (v[j] > x);
        
		do{
            i++;
        }while (v[i] < x);
        
		if (i < j){
			aux = v[j];
			v[j] = v[i];
			v[i] = aux;
		}else
            return j;
    }
}


void copiaTmp(int n, int v[], int tmp[]){
    for(int i =0; i < n; i++)
        tmp[i] = v[i];
}


