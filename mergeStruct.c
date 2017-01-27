/*Implementação da função mergeSort para uma struct */

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

	mergeSort(0, n, tarefas);

	for(i =0; i < 10; i++)
		printf("%d %s\n", tarefas[i].p , tarefas[i].nome);



}

void mergeSort(int p, int r, tarefa t[]){

	if(p < r-1){
		int q = (p + r)/2;
		mergeSort(p, q, t);
		mergeSort(q, r, t);
		intercala(p, q, r, t);
	}
}

int intercala(int p, int q, int r, tarefa v[]){
	int i = p;
	int j = q;
	tarefa w[r-p];
	int k =0;

		while(i < q && j < r){
				if(v[i].p < v[j].p){
					w[k] = v[i];
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

		for(i =p; i < r; i++)
			v[i] = w[i-p];
}