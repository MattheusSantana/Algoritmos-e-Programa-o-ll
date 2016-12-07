/* Programa: buscaAeB.c
Programador: Matheus E. Santana da Silva
Data: 07/12/2016
	Esse Programa recebe um vetor de inteiros v[n], um inteiro x e procura dois elementos A e B, tal que A + B = X. Em tempo de execução log n.
*/

#include <stdio.h>

#define MAX 10000
int main (){
	int n;										//Tamanho do vetor.
	int v[MAX];									
	int x;										//Elemento a ser buscado.	
	int i, j;									//índice de iterações dos laços for.
	int b;
	int pos;
		scanf("%d", &n);						//Entre com o número de elementos.
		
		for(i =0; i < n; i++){					//Populando o primeiro intervalo do vetor.
			scanf("%d", &v[i]);					//Adcionando os elementos no intervalor v[0, n].
		}
	
		quickSort(0, n-1, v);
		
		scanf("%d", &x);						//Entre com o elemento a ser buscado.
		
		for(i =0; i < n; i++){					//pega cada elemento do vetor.
			b = x - v[i];  						//B é o valor que deve ser encontrado.	
		
			pos = buscaBinaria(n, v, b);		//Buscando a posição onde b deveria estar.
		
				if(b == v[pos]) {				//Se realmente for igual imprima B.	
					printf("A = %d e B = %d \n", v[i], b);
				}
		}
}	
		
		
		

void quickSort(int p, int r, int v[]){
	int q;
	if ( p < r){
			q = separa(p, r, v);
			quickSort(p, q, v);
			quickSort(q+1, r, v);
	}
}
int separa(int p, int r, int v[]){
	int i = p-1;	//Começo do intervalo.
	int j = r+1;	//Fim do intervalo.
	int x = v[p];
	int aux; 
	
	while(1){
		do{
			j--;
		}while(v[j] > x);
		
		do{
			i++;
		}while(v[i] < x);
		
			if( i < j){
				aux = v[j];
				v[j] = v[i];
				v[i] = aux;
			}else{
				return j;
			}
	}
}

/* Recebe dois números inteiros esq e dir, um vetor de números
   inteiros crescente v[esq..dir] e um número inteiro x tais
   que v[esq] < x <= v[dir] e devolve um índice k em
   [esq+1, dir] tal que v[k-1] < x <= v[k] */
int buscaBinaria(int n, int v[], int x){
	int esq = -1;								//Índice antes do ínicio do intervalo.
	int dir = n;								//Próxima posição depois do fim do intervalo.
	int meio;									//Recebe o meio do intervalo.
		
	while(esq < dir-1){							//Enquanto os índices não estiverem na mesma posição.
		meio = (dir + esq) /2;					//Atribuindo o meio do intervalo.
		if(v[meio] < x)							//Caso x esteja a direita do meio do intervalo.
			esq = meio;
		else
			dir = meio;							//Caso x esteja a esquerda do meio do intervalo.
	}
	return dir;									//Retorna posição mais apropiada do elemento x.
	
}
