/* Programa: SomaElementos.c
Programador: Matheus E. Santana da Silva
Data: 06/12/2016
	Esse Programa recebe um vetor de inteiros v[n], um inteiro x e procura dois elementos A e B, tal que A + B = X. Em tempo de execução log n.
*/

#include<stdio.h>

#define MAX 10000

int main(){
	int n;										//Tamanho do vetor.
	int v[MAX];									
	int x;										//Elemento a ser buscado.	
	int i, j;									//índice de iterações dos laços for.
	
	
		scanf("%d", &n);						//Entre com o número de elementos.
		
		for(i =0; i < n; i++){					//Populando o primeiro intervalo do vetor.
			scanf("%d", &v[i]);					//Adcionando os elementos no intervalor v[0, n].
		}
		
		scanf("%d", &x);						//Entre com o elemento a ser pesquisado.
			i =0;
			for(j =n; j < n*2; j++){			//Percorrento o segundo intervalo v[n, n*2].	
					v[j] = x - v[i]; 			//Adicionando os respectivos B elementos tal que v[A] + B = x no segundo intervalo vetor.
					i++;
			}
		
		mergeSort(0, n*2, v);					//Ordenando vetor me ordem crescente.
	
	
		for(i =0; i < n*2; i++){				//Imprimindo o elementos a e b.
			if(v[i] == v[i+1])					//Caso os elementos repitam.	
				printf("%d ", v[i]);			//Imprima o elemento.				
			
		}
		return 0;
}

/* Recebe um vetor v[p..r-1] e o rearranja em ordem crescente. 
	Condição de parada é para (p >= r -1).*/
void mergeSort(int p, int r, int v[]){
	int q;										//Recebe uma posição x entre o ínicio e o fim do intervalo.
	 
	if(p < r-1){								//Enquanto a diferença entre os intervalos forem maiores do que zero.
		q = (p + r)/2;							//Atribuindo o meio do intervalo.
		mergeSort(p, q, v);						//Chamando a função recursivamente e dividindo conjunto em intervalos menores v[p, q].	
		mergeSort(q, r, v);						//Chamando a função recursivamente e dividindo conjunto em intervalos menores v[q, r].
		intercala(p, q, r, v);					//Ordenando os intervalos.
	}
}

/* Recebe os vetores crescentes v[p..q-1] e v[q..r-1]
e rearranja v[p..r-1] em ordem crescente e estável.*/
void intercala(int p, int q, int r, int v[]){
	int i = p;							//Ínicio do intervalo.
	int j = q;							//Fim do intervalo.
	int k =0;							//Índice do vetor w.
	int w[r-p];							//Vetor temporário.
	
	

		while(i < q && j < r){			//Percorrendo os intervalos [i, q], [q, r].
			
			if(v[i] < v[j]){			//Caso o elemento do primeiro intervalo seja menor. 
				w[k] = v[i]; 			//copie para o novo vetor w[].
				i++;
			}else{						//Caso contrário.
				w[k] = v[j];			//Copie o elemento do segundo 
				j++;
			}
			k++;						//Incrementando a posição do vetor w[].
		}
		
		while(i < q){					//Copiando os elementos restantes do intervalo [i, q], para o vetor w[].
			w[k] = v[i];
			i++;
			k++;
		}
		while(j < r){					//Copiando os elementos restantes do intervalo [q, r], para o vetor w[].
			w[k] = v[j];				
			j++;
			k++;
		}
		
		for(i = p; i < r; i++)			//Copiando os intervalos já ajustados de volta para o vetor de origem v[].
			v[i] = w[i-p];				//Adicionando elemento no intervalo v[i, r].	
}


