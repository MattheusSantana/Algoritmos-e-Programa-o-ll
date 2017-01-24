#include<stdio.h>
#include<limits.h>

#define MAX 10

int main(){
	int v[MAX] = {26, 7, 14 ,16, 8, 9, 11, 4, 12, 6};
	int i;

	//constroi_MaxHeap(MAX, v);	//Reorganizando o vetor de acordo com a propriedade max-heap.

	/*Chamando a função pai*/
	//	printf("Pai ----> %d\n", pai(7));
	
	/*Testando a função esquerdo*/
	//printf("Filho esquerdo ----> %d\n", esquerdo(2));
	
	/*Testando a função direito*/
	//printf("Filho direito ----> %d\n", direito(2));
	

	/* Chamando a função para ordenar a árvore cuja posição 1 não satisfaz a propriedade max-heap. */
		//int v2[MAX] = {26, 7, 14 ,16, 8, 9, 11, 4, 12, 6};	
		//desce(MAX, v2, 1);
		//for(i =0; i < MAX; i++)
		//printf("arvore ordenada ----> %d \n", v2[i]);			

	/* Testando a função constrói max-heap*/
		//int v3[MAX] = {9, 4, 8, 6, 26, 16, 14, 18, 12, 11};
		//constroi_MaxHeap(MAX, v3);
		//for(i =0; i < MAX; i++)
		//printf("arvore ordenada ----> %d \n", v3[i]);
	
	/* Testando a função Altera_MaxHeap inserindo o elemento 3 na posição 1*/
		//int v4[MAX] = {26, 3, 14, 16, 8, 9, 11, 4, 12, 6};
		//altera_MaxHeap(MAX, v4, 1);

	/*Testando a função extrai_maxima*/
		//Ordenando a árvore por prioridade max-heap.
		//constroi_MaxHeap(MAX, v);
		//Extraíndo elemento de maior prioridade e imprimindo o valor e a árvore re-organizada.	
		//int n = 10;
		//printf("Elemento extraido ----> %d\n", extrai_Maxima(&n, v));
		//for(i =0; i < MAX-1; i++)
		//printf("arvore ordenada ----> %d \n", v[i]);

	/*Testando a função aumenta_prioridade*/
		//aumenta_prioridade(MAX, v, 10, 5);	//Aumentando a prioridade do valor 9, para 10.
		//for(i =0; i < MAX; i++)
		//printf("arvore ordenada ----> %d \n", v[i]);
	
	/*Testando a função insere_lista*/
		//int n = 10;
		//insere_lista(&n, v, 10);	//Inserindo a prioridade 10 no vetor
		//for(i =0; i < MAX; i++)
		//printf("arvore ordenada ----> %d \n", v[i]);
	
		heapSort(MAX, v);
		for(i =0; i < MAX; i++)
		printf("arvore ordenada ----> %d \n", v[i]);
	

	return 0;
}


int pai(int i){
	if(i == 0)				//Caso esteja na raiz.
		return 0;			//Retorne a própria raiz.
	else
		return (i -1) /2;		//Retornando o nó pai.
}

int esquerdo(int i){
	return 2* (i+1) -1;
}

int direito(int i){
	return 2 * (i+1); 
}

void desce(int n, int v[MAX], int i){
	int e = esquerdo(i);		//Obtendo filho da esquerda.
	int d = direito(i);			//Obterndo filho da direita.
	int maior;		

	if(e < n && v[e] > v[i])	//Se o filho da esquerda existe, e se o filho é maior que o pai.
		maior = e;
	else
		maior = i;
	if(d < n && v[d] > v[maior])//Se o filho da direita existe e é maior do que o maior.
		maior = d;
	if(maior != i){				//Caso o maior dos elementos não seja o próprio pai.	
		troca(&v[i], &v[maior]);//Trocando os elementos de posição.   
		desce(n, v, maior);		//Chamando a função recursivamente, passando o maior como i de forma que ele desça até a sua posição correta.
	}
}
int troca(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;	
}

void constroi_MaxHeap(int n, int v[]){
	int i;
	for(i = n/2 -1; i >= 0; i--)//Começando do ultimo elemento da penultima linha da árvore e indo até a raiz.
		desce(n, v, i);			//Organizando o elemento da vez de forma a satisfazer a propriedade max heap.
}

void altera_MaxHeap(int n, int v[], int i){
	if(v[i] < v[esquerdo(i)] || v[i] < v[direito(i)])	//Caso o elemento inserido seja menor do que seus filhos.
		desce(n, v, i);			//Desça esse elemento.

	if(v[i] > v[pai(i)])		//Caso o elemento em i seja maior do que o elemento pai em i.
		sobe(i);		//Subindo esse elemento.		
}

void sobe(int n, int v[], int i){
		while(v[pai(i)] < v[i]){	//Enquanto o elemento é maior do que o elemento pai.
		troca(&v[i], &v[pai(i)]);	//Troque.
			i = pai(i);			//Atualizando o valor de i para verificar novamente. 		
	}
}

void consulta_Maxima(int v[]){
	return v[0];
}	

/* Recebe um número inteiro n > 0 e uma lista de max-prioridades
V e remove e devolve o valor da maior prioridade em V */
int extrai_Maxima(int *n, int v[]){
	int maior;

	if(*n > 0){
		maior = v[0];		//Obtendo o valor da raiz.
		v[0] = v[*n-1]; 		//colocando o ultimo valor do max heap na raiz.
		*n = *n-1;	
		desce(*n, v, 0);		//Chamando a função desce para reorganizar o vetor.
		return maior;	 
	}else
		return INT_MIN; 

}

void aumenta_prioridade(int n, int v[], int p, int i){
	if(p < v[i])		//Caso a nova prioridade seja menor do que a prioridade que ja está la.
		printf("ERRO: nova prioridade e menor que da celula\n");	
	else{
		v[i] = p;
		sobe(n, v, i);
	}

}

/* Recebe um número inteiro n > 0, uma lista de max-prioridades S e uma prioridade
p e devolve a lista de max-prioridades com a nova prioridade */

void insere_lista(int *n, int v[], int p){
	v[*n] = p; //Inserindo a nova prioridade na ultima posição do vetor.
	*n = *n+1; //Aumentando o tamanho do vetor em mais uma unidade.
	sobe(*n, v, *n-1);	//Chamando a função sobe para organizar o elemento inserido na sua posição correta.
}

void heapSort(int n, int v[]){
	constroi_MaxHeap(n, v);		//Organizando elementos com prioridade max heap.
	int i;
	for(i = n-1; i >0; i--){	//Navegando o vetor de forma decrescente.
		troca(&v[0], &v[i]);	//Colocando elemento de maior prioridade na ultima posição do vetor.
		n--;					//Desconsiderando o ultimo elemento pois este já está ordenado.
		desce(n, v, 0);			//Descendo elemento e reorganizando o arranjo.		
	}

}
