/**************************************************
*
* Nome do(a) estudante: Matheus Emmanoel Santana da Silva.
* Trabalho 2
* Professor(a): Diego Rubert Padilha.
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEICULOS 5
#define NUM_PILHAS 3

/* Armazena informacoes de um veiculo estacionado em uma pilha */
typedef struct cel {
char placa[9];
struct cel *prox;
}veiculo;

/* Armazena informacoes de uma pilha */
typedef struct {
int veiculos; /* Quantidade de veiculos estacionados */
veiculo *topo; /* Topo da pilha */
}pilha;

/* Armazena informacoes do estacionamento */
typedef struct {
char data[11];
pilha P[NUM_PILHAS]; /* Armazena as pilhas P0, P1, ..., NUM_PILHAS-1 */
}estacionamento;

/*Seleciona qual pilha que o veículo deve ser estacionado.*/
int seleciona_pilha(estacionamento E); 											
/*Estaciona o veículo na pilha.*/
void empilha_enc_C(char placa[], veiculo *topo); 								
/*Aloca as pilhas ao começo de cada dia.*/
void cria_pilha(estacionamento E);										
/*Procura e retona a pilha em que o veículo está estacionado.*/
int busca_veiculo(char placa[], estacionamento E);									
/*Remove o veículo da pilha.*/
int busca_remove(char placa [], veiculo *t, veiculo *fila, veiculo **fim_fila); 
/*Imprime os veículos referente a pilha.*/
void imprime(veiculo *topo); 
/*Fila auxiliar para a remoção dos veículos.*/
void enfileira_enc_c(veiculo *fila, veiculo **fim_fila, char placa[]); 			
/*Reorganiza os veículos da fila de volta para a pilha.*/
void re_empilha(veiculo *topo, veiculo *fila, veiculo **fim_fila); 
/*Desempilha todos os veículos ao fim de cada dia.*/
int desempilha(estacionamento E); 

/*Recebe um arquivo de entrada*/
int main(int argc, char *argv[]){
	int c; 							//Número de casos de teste.
	int i, j;						//índices dos laços de repetições.
	char placa_aux[9];				//Armazena a placa.
	char nome_pilha[3];				//Nome da pilha.
	char operacao;					//Armazenará a operação a ser efetuada.
	int resultado_busca =0;			//armazenará o índice da pilha em que o carro está.
	int resultado_remocao =0;		//armazenará o resultado da remoção do veículo.
	int pos_pilha =1;				//Armazenará o inteiro correspondente á posição da pilha no vetor na struct estacionamento.
	estacionamento Estacionamento;	//Nova Intância de estacionamento. 
	FILE *ptarq;					//Ponteiro para o arquivo de entrada.

	/*Abrindo o arquivo de entrada.*/
	ptarq = fopen(argv[1], "r"); 

	/*Lendo a quantidade de casos de teste*/
	fscanf(ptarq, "%d", &c);
	
	/*Lendo as entradas*/
	for(i =0; i < c; i++){
		/*Imprimindo uma quebra de linha partir do segundo caso de teste.*/
		if(i > 0){
			printf("\n");
		}

		/*Zerando a quantidade de veiculos no estacionamento*/
		Estacionamento.P[0].veiculos =0;
		Estacionamento.P[1].veiculos =0;
		Estacionamento.P[2].veiculos =0;
		
		/*instanciando a fila auxiliar*/
		veiculo *fila = (veiculo *) malloc(sizeof(veiculo));
		fila->prox = NULL;
		veiculo *fim_fila = fila; 

		/*Criando pilhas vazias com cabeça.*/
		for(j =0; j < NUM_PILHAS; j++){	
			Estacionamento.P[j].topo = (veiculo *) malloc(sizeof(veiculo));
			Estacionamento.P[j].topo->prox = NULL;
		}

		/*Lenda e imprimindo a Data*/	
		fscanf(ptarq, " %s", Estacionamento.data);
		printf("%s\n", Estacionamento.data);
		
		/*Lendo a operação requisitada.*/

		fscanf(ptarq, " %c", &operacao);

		/*Enquanto a operação for diferente de 'F' (Operação final do dia). Efetue as outras operações*/
		while(operacao != 'F'){

			/*Caso a operação seja 'E' estacionar veiculo*/
			if(operacao == 'E'){
				/*Lendo a placa.*/
				fscanf(ptarq, " %s", placa_aux);			
				/*Verificando se tem vagas nas pilhas.*/							
				pos_pilha = seleciona_pilha(Estacionamento);
			
				/*Caso tenha vaga, estacione o veiculo na pilha retornada.*/
				if(pos_pilha != -1){ 
					/*Empilhando o carro na pilha.*/
					empilha_enc_C(placa_aux, Estacionamento.P[pos_pilha].topo);
					/*Imprimindo a mensagem de saída.*/
					printf("E %s\n", Estacionamento.P[pos_pilha].topo->prox->placa);
					/*Incrementando a quantidade de veiculos na pilha.*/
					Estacionamento.P[pos_pilha].veiculos++; 
				}
				/*Caso as pilhas estejam todas cheias.*/	
				if(pos_pilha == -1){
					/*Imprimindo a mensagem de saída.*/
					printf("C %s\n", placa_aux); 
				}
			}

			/*Caso a aoperação solicitada seja de remoção de veiculo*/
			if(operacao == 'S'){
			
			/*Lendo a placa solicitada.*/
			fscanf(ptarq, " %s", placa_aux); 
				/*Procurando o veiculo nas pilhas.*/
				resultado_busca = busca_veiculo(placa_aux, Estacionamento);
				/*Caso o veiculo não seja encontrada*/
				if(resultado_busca == -1){
					/*Imprimindo mensagem de saída.*/
					printf("N %s\n", placa_aux); 
				}

				/*Caso o veiculo seja encontrado*/
				if(resultado_busca != -1){
					/*Efetuando a remoção do veiculo.*/
					resultado_remocao = busca_remove(placa_aux, Estacionamento.P[resultado_busca].topo, fila, &fim_fila);
					/*Se a remoçao foi bem feita*/
					/*Imprima a placa do veículo removido e re-empilhe os outros veículos de volta.*/
					/*Decremente a quantidade de veículos da pilha.*/
					if(resultado_remocao == 1){
						printf("S %s\n", placa_aux);										
						re_empilha(Estacionamento.P[resultado_busca].topo, fila, &fim_fila);
						Estacionamento.P[resultado_busca].veiculos--;						
					}
				}
			}
			/*Caso a operação seja a solicitação de impressão.*/
			if(operacao == 'I'){
				/*Lendo qual pilha deve ser imprimida.*/
				fscanf(ptarq, "%s", nome_pilha);  
				/*Caso seja a pilha (P0)*/	
				if(strcmp(nome_pilha,"P0") == 0){
					printf("P0:");
					imprime(Estacionamento.P[0].topo);
				}
				/*Caso seja a pilha (P1)*/
				if(strcmp(nome_pilha,"P1") == 0){
					printf("P1:");
					imprime(Estacionamento.P[1].topo);
				}
				/*Caso seja a pilha (P2)*/
				if(strcmp(nome_pilha,"P2") == 0){
					printf("P2:");
					imprime(Estacionamento.P[2].topo);
				}
			}
				operacao = fgetc(ptarq);	
			/*Lendo a próxima operação*/	
			fscanf(ptarq, "%c", &operacao);	
		}

		/*Caso a operação solicitada seja 'F' encerrar o dia, desempilhe os veículos caso tenha e imprima a mensagem de saída. */
		if(operacao == 'F'){
			desempilha(Estacionamento); 
			printf("F\n");
		}
		/*Limpando a data.*/
		strcpy(Estacionamento.data, "");
	}
	/*Fechando o arquivo de entrada.*/
	fclose(ptarq);

	return 0;
}

/*Essa função recebe um ponteiro topo para uma pilha de veículos e imprime todas as placas dos veículos.
  Caso não tenha veículos a função imprimirá uma quebra de linha.*/
void imprime(veiculo *topo){
	/*Caso a pilha não esteja vazia*/
	if(topo->prox != NULL){
	veiculo *p = topo->prox;

	while(p->prox != NULL){
		printf("%s,", p->placa);
		p = p->prox;
	}
	printf("%s\n", p->placa);
	}else{
	printf("\n");
	}
}

/*Essa função verifica e retorna qual pilha do estacionamento tem a quantidade menor de veículos. 
  Caso as pilhas tenham a mesma quantidade de veículos a função retornará -1.*/
int seleciona_pilha(estacionamento E){
	int menor = 0; //Armazena o índice da pilha.
	int i; //índice de iteração do laço.

	/*Navegando pilha por pilha e verificando a quantidade de veículos delas*/
	for(i =0; i < NUM_PILHAS; i++)
		if(E.P[i].veiculos < E.P[menor].veiculos)
			menor = i;
	/*Caso a pilha esteja cheia*/	
	if(E.P[menor].veiculos == 5){
		return -1;
	}	
	return menor;		
}

/* Recebe um elemento e uma pilha t e insere no topo da pilha t */
void empilha_enc_C(char placa[], veiculo *topo){
	veiculo *nova;
	nova = (veiculo *) malloc(sizeof(veiculo));
	strcpy(nova->placa,placa);
	nova->prox = topo->prox;
	topo->prox = nova;
}

/*Essa função recebe uma placa de um veículo e um estacionamento e verifica se o respectivo veículo se encontra em uma das pilhas.
  Caso encontre a função devolve o índice da pilha em que o veículo se encontra, caso contrário a função retorna -1.*/
int busca_veiculo(char placa[], estacionamento E){
	int i = -1;
	veiculo *p;
	//Caso todas as pilhas estejam vazias.
	if(E.P[0].topo->prox == NULL && E.P[1].topo->prox == NULL && E.P[2].topo->prox == NULL){
		return -1;
	}

	/*Navegando pelas pilhas de veículos.*/
	for(i =0; i < NUM_PILHAS; i++){ 
		/*Apontando  o ponteiro p para o topo da pilha da vez.*/
		p = E.P[i].topo->prox; 
		/*Procure enquanto não achar a placa ou chegar no ultimo elemento*/
		for(; p != NULL && (strcmp(placa, p->placa) != 0); p = p->prox);

		/*Caso tenha encontrado a placa.*/
		if(p != NULL){
		if(strcmp(placa, p->placa) == 0)
			return i; 	
		}
	}
	/*Caso onão tenha encontrado a placa em nenhuma das pilhas.*/
	return -1;
}

/* Recebe uma pilha t e uma placa de um veículo que já se encontra nessa pilha,
   um ponteiro para o ínicio e outro para o fim da fila.
   A função insere os veículos numa fila auxiliar enquanto procura pelos respectivo veículo.
   A função remove o veículo o mesmo é achado.*/ 
int busca_remove(char placa[], veiculo *t, veiculo *fila, veiculo **fim_fila){
	veiculo *p;
	/*Caso a pilha não esteja vazia*/
	if (t->prox != NULL){
		/*Apontando para o primeiro elemento da pilha.*/
		p = t->prox;  

		/*Enquanto ã função não encontrar a placa, os veiculos são colocados em uma fila auxiliar.*/
		while(strcmp(p->placa, placa) != 0){
			enfileira_enc_c(fila, fim_fila, p->placa);	//Colocando o veiculo na fila auxiliar. 
			t->prox = p->prox;							//Apontando a cabeça para o próximo veiculo.
			free(p);									//removendo o veiculo da pilha.
			p = t->prox;
		}
		/*Removendo o veículo da pilha.*/
		t->prox = p->prox;
		free(p); 

		return 1;  
	}else{  
		return -1; 
	}

}

/*Essa função enfileira os veículos numa fila auxiliar no momento da remoção dos veículo na pilha.
  Recebe um ponteiro para o ínicio da fila e outro para o fim e o veículo a ser enfileirado.*/
void enfileira_enc_c(veiculo *fila, veiculo **fim_fila, char placa[]){
	veiculo *nova;
	nova = (veiculo *) malloc(sizeof(veiculo));
	strcpy(nova->placa, placa);
	nova->prox = NULL;
	(*fim_fila)->prox = nova;
	*fim_fila = nova;
	//printf("Aloquei na fila o veiculo -> %s\n", nova->placa);
}

/*Essa função re-empilha os veículos que estão da fila auxiliar, devolvendo-os de volta para a pilha após o momento da remoção.
  Recebe três ponteiros, um para o topo da pilha, outro para o ínicio da fila auxiliar e outro para o fim da fila.*/
void re_empilha(veiculo *topo, veiculo *fila, veiculo **fim_fila){
	/*Apontando para o primeiro veiculo da fila.*/
	veiculo *p = fila->prox; 
	
	/*Caso a fila não esteja vazia.*/
	while(p != NULL){
		/*Impilhando carro na pilha.*/
		empilha_enc_C(p->placa, topo);
		fila->prox = p->prox;	//Apontando para o segundo elemento da fila.
		free(p);				//Removendo o primeiro veiculo da fila.
		p = fila->prox;			//Apontando p para o novo primeiro elemento da fila.

		/*Caso o chegue ao fim da fila, aponto o ponteiro do final para a cabeça.*/
		if(fila->prox == NULL)
			*fim_fila = fila;
	}
}

/*Essa função recebe um estacionamento E e desempilha todos os carros de suas pilhas.*/
int desempilha(estacionamento E){
	veiculo *p;	//Apontará para o topo da pilha.
	int i;		//Índice de iteração do laço de repetição.
	
	/*Navegando pelas pilhas do estacionamento.*/
	for(i =0; i < NUM_PILHAS; i++){
		/*Caso não pilha esteja vazia*/
		if(E.P[i].topo->prox != NULL){
			p = E.P[i].topo->prox;
			/*Navegue até o ultimo elemento.*/
			while(p->prox != NULL){
				E.P[i].topo->prox = p->prox;	//Apontando o topo para o 2° elemento da pilha.
				free(p);						//Removendo o elemento da pilha.
				p = E.P[i].topo->prox;			//Apontado o ponteiro auxiliar para o novo 1° elemento da pilha.
			}
			/*Limpando o ultimo elemento da pilha.*/
			free(p);
		}
	}
	return -1;
}