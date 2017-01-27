/*Implementação da função quickSort para ordenar um vetor de registros*/
#include<stdio.h>

#define MAXT 100
#define MAXNOME 100


typedef struct {
	int p;
	char nome[MAXNOME + 1];
} tarefa;


int main (){
	int i;
	int n =10;
	tarefa tarefas[MAXT] = {
		{ -10, "Jogar Witcher 3" },
		{ 100, "Estudar para a prova de AlgProg II" },
		{ 50,  "Ler um livro" },
		{ 10,  "Dar banho no cachorro" },
		{ 30,  "Chutar o Windows do PC e instalar o Linux" },
		{ 70,  "Passear com as capivaras" },
		{ 40,  "Jogar RPG" },
		{ 20,  "Lavar os pratos" },
		{ 0,   "Dormir" },
		{ 80,  "Fazer a lista do URI" },
	};

	quickSort(0, n-1, tarefas);

	for(i =0; i < 10; i++)
		printf("%d %s\n", tarefas[i].p , tarefas[i].nome);



}


void quickSort(int p, int r, tarefa v[]){
	int q;
	if ( p < r){
			q = separa(p, r, v);
			quickSort(p, q, v);
			quickSort(q+1, r, v);
	}
}
int separa(int p, int r, tarefa v[]){
	int i = p-1;	//Começo do intervalo.
	int j = r+1;	//Fim do intervalo.
	int x = v[p].p; //Obtendo a prioridade
	tarefa aux; 
	
	while(1){
		do{
			j--;
		}while(v[j].p > x);
		
		do{
			i++;
		}while(v[i].p < x);
		
			if( i < j){
				aux = v[j];
				v[j] = v[i];
				v[i] = aux;
			}else{
				return j;
			}
	}
}