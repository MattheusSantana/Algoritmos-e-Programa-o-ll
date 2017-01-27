#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAXT 100
#define MAXNOME 100


typedef struct {
	int p;
	char nome[MAXNOME + 1];
} tarefa;


/* Troca duas tarefas */
void troca(tarefa *a, tarefa *b);

/* Obtém o pai de um nó */
int pai(int i);

/* Obtém o filho esquerdo de um nó */
int esquerdo(int i);

/* Obtém o filho direito de um nó */
int direito(int i);

/* Desce um nó */
void desce(int n, tarefa S[], int i);

/* Sobe um nó */
void sobe(int n, tarefa S[], int i);

/* Dado um vetor, constrói uma max-heap */
void constroi_max_heap(int n, tarefa S[]);

/* Devolve a tarefa de maior prioridade */
tarefa consulta_maxima(tarefa S[]);

/* Extrai e devolve a tarefa de maior prioridade (caso não exista, devolve uma tarefa com prioridade INT_MIN */
tarefa extrai_maxima(int *n, tarefa S[]);

/* Insere uma nova tarefa na heap */
void insere_heap(int *n, tarefa S[], tarefa t);

/* Altera a prioridade de uma tarefa */
void altera_prioridade(int n, tarefa S[], int i, int p);

/* Remove um elemento qualquer da heap */
void remove_heap(int *n, tarefa S[], int i);

/* Escreve tarefa */
void escreve_tarefa(tarefa t);

/* Escreve as tarefas de um vetor */
void escreve_vetor(int n, tarefa S[]);


int main(void)
{
	int i, n, op, p;
	tarefa t;
	
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
	
	n = 10; // Atualizar esse valor caso a quantidade de tarefas da inicialização mude

	heapSort(n, tarefas);
	constroi_max_heap(n, tarefas);
	escreve_vetor(n, tarefas);

	do {
		printf("\n\nOperações:\n");
		printf("\t1) Escrever vetor (heap)\n");
		printf("\t2) Exibir tarefa de maior prioridade\n");
		printf("\t3) Remover tarefa de maior prioridade\n");
		printf("\t4) Inserir uma nova tarefa\n");
		printf("\t5) Alterar prioridade de uma tarefa qualquer\n");
		printf("\t6) Remover uma tarefa qualquer (!!!)\n");
		printf("\t7) Sair\n");
		printf("Digite a operação desejada: ");

		scanf("%d", &op);

		switch(op) {

		case 1:
			escreve_vetor(n, tarefas);
			break;
		
		case 2:
			/* ENTENDA O CÓDIGO A SEGUIR ANTES DE UTILIZÁ-LO */
			
			if (n > 0) {
				putchar('\n');
				escreve_tarefa(consulta_maxima(tarefas));
			}
			else
				printf("\nNao ha tarefas!\n");
	
			break;
		
		case 3:
			/* ENTENDA O CÓDIGO A SEGUIR ANTES DE UTILIZÁ-LO */
			
			t = extrai_maxima(&n, tarefas);
			if (t.p == INT_MIN)
				printf("\nNão ha tarefas!\n");
			else {
				printf("\nTarefa removida: ");
				escreve_tarefa(t);
			}
			
			break;
			
		case 4:
			printf("Digite a prioridade seguida do nome: ");
			scanf("%d %[^\n]%*c", &t.p, t.nome);
			/* CHAME A FUNÇÃO DE INSERÇÃO */
					insere_heap(&n, tarefas, t);
			break;

		case 5:
			printf("Digite o indice e a nova prioridade: ");
			scanf("%d%d", &i, &p);
			/* CHAME A FUNÇÃO DE ALTERAÇÃO */
			altera_prioridade(n, tarefas, i, p);
			break;

		case 6:
			printf("Digite o indice: ");
			scanf("%d", &i);
			/* CHAME A FUNÇÃO DE REMOÇÃO */
			remove_heap(&n, tarefas, i);
			break;
			
		case 7:
			printf("Até logo!\n");
			break;

		}
		
	} while (op != 7);
	


	return 0;
}



void troca(tarefa *a, tarefa *b)
{
	tarefa aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int pai(int i)
{
	return (i - 1) / 2;
}

int esquerdo(int i)
{
	return 2 * (i + 1) - 1;
}

int direito(int i)
{
	return 2 * (i + 1);
}

void constroi_max_heap(int n, tarefa S[])
{
	int i;
	for (i = n/2 - 1; i >= 0; i--)
		desce(n, S, i);
}

void desce(int n, tarefa S[], int i)
{
	int e, d, maior;
	e = esquerdo(i);
	d = direito(i);
	if (e < n && S[e].p > S[i].p)
		 maior = e;
	else
		maior = i;
	if (d < n && S[d].p > S[maior].p)
		maior = d;
	if (maior != i) {
		troca(&S[i], &S[maior]);
		desce(n, S, maior);
	}
}

void sobe(int n, tarefa S[], int i)
{
	/* IMPLEMENTE */
		tarefa aux;

		while( S[pai(i)].p < S[i].p  ){ //Enquanto a prioridade de i for maior do que a prioridade do pai.
				 aux.p = S[pai(i)].p;	// Copiando prioridade do pai.
				 strcpy(aux.nome, S[pai(i)].nome); //Copiando nome do pai.
				 
				 S[pai(i)].p = S[i].p;	//Subindo prioridade do filho.
				 strcpy(S[pai(i)].nome, S[i].nome); //Subindo nome do filho.

				 S[i].p = aux.p;	//Descendo prioridade do pai.
				 strcpy(S[i].nome, aux.nome);   //Descendo nome do pai.

			i = pai(i);		//Atualizando o valor de i.  
		}
}

tarefa consulta_maxima(tarefa S[])
{
	return S[0];
}

tarefa extrai_maxima(int *n, tarefa S[])
{
	tarefa t;
	if(*n > 0){  
			/* IMPLEMENTE */
		//Copiando o elemento a ser extraído, para retorná-lo.
		t.p = S[0].p;
		strcpy(t.nome, S[0].nome);  
		
		S[0].p = S[*n-1].p;		//Colocando prioridade na raiz.
		
		strcpy(S[0].nome, S[*n-1].nome); 
		*n = *n-1;
	return t;
}else{
			t.p = INT_MIN;
	return t;
}
}

void insere_heap(int *n, tarefa S[], tarefa t)
{
	S[*n].p = t.p;		//Inserindo prioridade na ultima posição do vetor.
	strcpy(S[*n].nome, t.nome);   //Inserindo o nome da prioridade na ultima posição do vetor.
	*n = *n + 1;		//Incrementando n em mais uma unidade.
	sobe(*n, S, *n - 1);//Organizando prioridade inserida.
}

void altera_prioridade(int n, tarefa S[], int i, int p)
{
			/* IMPLEMENTE */
			 //Alterando a prioridade.
			if(p > S[i].p){  //Caso a nova prioridade seja menor do que a antiga.          
				S[i].p = p;
				sobe(n, S, i);      
			}else{            //Caso a nova prioridade seja maior do que a antiga.    
				S[i].p = p;
				desce(n, S, i);
			 }
}

void remove_heap(int *n, tarefa S[], int i)
{
	/* IMPLEMENTE */

		if(i > *n)
			printf("Prioridade não existe.\n");
		else{
			S[i].p = S[*n-1].p; //Sobreescrevendo a prioridade do elemento a ser removido.
			strcpy(S[i].nome, S[*n-1].nome); //Sobreescrevendo o nome da prioridade a ser removida.
			*n = *n-1;
			desce(*n, S, i); //Reorganizando o elemento na heap.
		}
}

void heapSort(int n, tarefa t[]){
	int i;
	tarefa maior;

		constroi_max_heap(n, t);
	for(i =n-1; i > 0; i-- ){
		maior = t[0]; // pegando a raiz;
		t[0] = t[i]; //Pegando o ultimo elemento.
		t[i] = maior;
		n = n-1;
		desce(n, t, 0); //Ordenado o elemento da raiz.

	}
}

void escreve_tarefa(tarefa t)
{
	printf("%-4d\t%s\n", t.p, t.nome);
}

void escreve_vetor(int n, tarefa S[])
{
	int i;
	printf("\nIndice\tPrio\tNome\n");
	for (i = 0; i < n; i++) {
		printf("%d\t", i);
		escreve_tarefa(S[i]);
	}
	printf("\n");
}