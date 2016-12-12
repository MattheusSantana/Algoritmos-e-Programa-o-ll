/* Programa: insertionSort.c
Programador: Matheus E. Santana da Silva
Data: 12/12/2016
	Estudo da forma normal e recursiva do m�todo de ordena��o por inser��o insertionSort.
*/
#include<stdio.h>

int main() {
	
 	int v[5] = {5, 4, 3, 2, 1};
	int i;
	insertionSort_R(4, v); 
	
	for(i =0; i < 5; i++)
		printf("%d ", v[i]);
}

/*Essa fun��o considera a primeiro elemento do intervalo como ordenado.
  Feito isso ela pega o pr�ximo elemento do intervalo e insere no conjunto na sua respectiva posi��o*/
insertionSort(int n, int v[]){
	int i, j;					//�ndices de itera��es do la�o.
	int x; 						//Armazena o elemento a ser ordenado.
	for(i = 1; i < n; i++){ 	//I = 1 pois a fun��o considera a primeira posi��o do vetor comoo j� ordenada.
		x = v[i];			
	
	//j = i +1. come�a sempre uma posi��o ap�s o conjunto ordenado.	
	//j <=0. J precisa ir at� 0 pois o elemento x pode ser menor do que o elemento de v[0].
	//v[j] > x. Compara at� achar um elemento que seja menor ou igual a x. pois adicionar� x nessa posi��o.
	//j--. O �ndice decrementa pois a verifica��o � feita da direita para a esquerda.
		for(j = i -1; j >=0 && v[j] > x; j--)
			v[j+1] = v[j];		//Sobreescrevendo os elementos do vetor em uma posi��o � frente, de forma que sobre uma posi��o vaga, aonde x deve entrar.
			v[j+1] = x;			//Adiciona x na posi��o que sobrou.
	}
}

/*Fun��o de Inser��o de modo recursivo.
	Esta fun��o considera o primeiro elemento do conjunto como ordenado
	Feito isto, a ordena��o come�a com x sendo o pr�ximo elemento ap�s o conjunto ja ordenado.
	A fun��o calcula se x � menor que os elementos anteriores a ele.
	Sendo assim ela sobreescreve todos os elementos para uma posi��o para frente.
	At� que o la�o dessa condi��o seja falsa, de modo que sobre uma posi��o vaga, aonde x ser� inserido.
	
*/
void insertionSort_R( int n, int v[]){
	
		 if(n > 0){
		 	int x;
		 	int j;
		insertionSort_R(n-1, v);
			x = v[n];
            for (j = n - 1; j >= 0 && v[j] > x; j--)
            v[j+1] = v[j];
        v[j+1] = x;	
		 }
    }
	
