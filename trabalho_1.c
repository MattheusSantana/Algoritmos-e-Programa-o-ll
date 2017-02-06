/**************************************************
*
* Nome do estudante: Matheus Emmanoel Santana da Silva
* Trabalho 1
* Professor(a): Diego Rubert Padilha
*
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX_NOME 50
#define MAX_CAPIVARAS 50

/* Armazena informacoes de uma capivara */
typedef struct {
	char nome[MAX_NOME+1];
	int ultimo_peso; 		/* Ultimo peso registrado */
	int var_total; 			/* Variacao total de peso */
	int max_var_mensal; 	/* Maior variacao mensal encontrada */
	char nascimento[11];	/* Data de nascimento */
} capivara;

/* Armazena informacoes de uma familia de capivaras */
typedef struct {
	char nome[MAX_NOME+1];
	int num_capis; 					/* Quantidade de capivaras na familia */
	int num_meses; 					/* Meses registrados */
	capivara capis[MAX_CAPIVARAS]; 	/* Armazena as capivaras */
} familia;

/*Busca o nome de uma capivara em um vetor de capivaras e devolve a posição do registro dela*/
int buscar_Nome(char nome[MAX_NOME], int n, capivara capivaras[MAX_CAPIVARAS]);

/*Calcula a maior variação dentre todos as variações mensais*/
void calcula_max_var_mensal(capivara capivaras[MAX_CAPIVARAS], int i, int novo_peso);

/*Calcula a variação total de peso de uma capivara*/
void calcula_variacao_total(capivara capivaras[], int i);

/*Limpa o resgistro de todas capivaras registradas */
void limpa_registros(capivara capivaras[], int n);

/*Métodos de ordenação recursiva */
void mergeSort(int p, int r, capivara v[]);

/*Intercalação de elementos entre conjuntos de um determinado vetor */
void intercala(int p, int q, int r, capivara v[]);

/*Ordena os elementos de acordo com os critérios de desempate*/
int ordena_criterios(capivara capivaras[], int i, int j);

/*Calcula e devolve o nascimento de uma capivara em quantidade de dias */
int calcula_dias(char nascimento[]);

/*Calcula e devolve a menor palavra de acordo com a ordem lexicográfica*/
int ordem_lexicografica(capivara capivaras[], int i, int j);


int main(){
	int f =0;						//Quantidade de famílias.
	int n =0;						//Quantidade de capivaras da família.
	int lacos =0;					//Variável auxiliar que contará.
	int i =0, j =0;					//índices de iterações dos laços de repetição. 
	int posicao = 0;				//Armazena a posição da capivara no vetor de registros.
	int peso_Aux =0;				//Armazenará o novo peso da capivara.	
	char nome_Aux[MAX_NOME+1];		//Armazenará o nome da capivara no momento do cadastro do peso, para busca-la no registro de capivaras.
	char descricaoMes[MAX_NOME+1];	//Descrição sobre o mês.
	familia familias;				//Registro de uma familia de capivaras.
	
	/*Lendo a quantidade de famílias*/
	scanf("%d", &f);
	
	/*Lendo nome da família*/
	while(scanf(" %[^\n]%*c", familias.nome) != EOF){	
		/*Obtendo o número de capivaras.*/
		scanf("%d", &n);			
		/*Zerando todos os campos dos n registros.*/
		limpa_registros(familias.capis, n); 	

		/*Registrando os nome e as datas de nascimento das capivaras*/
		for(i = 0; i < n; i++){
			scanf(" %[^,]%*c", familias.capis[i].nome);				//Lendo o nome da capivara até a virgula.
			scanf(" %[^\n]%*c", familias.capis[i].nascimento);		//Lendo a data de nascimento da capivara até o '\n'.
		}

		/*Registrando os pesos das capivaras*/
		scanf("%d", &familias.num_meses); 							//Lendo a Quantidade de meses.
			for(i =0; i < familias.num_meses; i++){
				scanf(" %[^\n]%*c", descricaoMes); 					//Lendo o nome descritivo do mês.
					
					/*Lendo o nome das capivaras e cadastrando seus respectivos pesos.*/
					for(j =0; j < n; j++){ 				
						scanf(" %[^,]%*c", nome_Aux);				//Lendo nome até a virgula.
						scanf("%d", &peso_Aux); 					//Lendo o peso.

						/*Procurando a posição da capivara no vetor de registro.*/
						posicao = buscar_Nome(nome_Aux, n, familias.capis); 

						/*Caso seja o primeiro mes registre o peso dela na variação total.*/
						if(i ==0) 
							familias.capis[posicao].var_total = peso_Aux;
						/*A partir do segundo mês em diante verifique se a variação atual é maior do que a já registrada*/	
						if(i > 0)
							calcula_max_var_mensal(familias.capis, posicao, peso_Aux);	
						/*Registrando o peso mais recente da capivara.*/
						familias.capis[posicao].ultimo_peso = peso_Aux; 
						/*Caso seja o ultimo mês calcule a variação total*/	
						if(i == (familias.num_meses -1)) 
							calcula_variacao_total(familias.capis, posicao);
					}
				/*Limpando lixo de memória da variável auxiliar*/	
				strcpy(nome_Aux, ""); 		
			} //Fim de registros de pesos das capivaras. 
		
		/*Ordenando os registros de capivaras*/
		mergeSort(0, n, familias.capis);
		
		/*Quebra de linha a partir da segunda família*/
		if(lacos > 0)
			printf("\n");
		
		/*Imprimindo o nome da familia os registros de capivaras agora já ordenados*/
		printf("Familia %s - variacoes apos %d meses\n", familias.nome, familias.num_meses);	
			for (i = 0; i < n; i++){
				if(familias.capis[i].var_total >= 0)
				printf("%+04d, %s\n", familias.capis[i].var_total, familias.capis[i].nome);
				else
				printf("%04d, %s\n", familias.capis[i].var_total, familias.capis[i].nome);
			}
		
		/*Incrementando a contágem de famílias*/	
		lacos++;
	
		/*Caso a quantidade de laços seja igual a quantidade de famílias, finalize o programa.*/
		if(lacos==f)
			break;
	} //Fim cadastro de famílias
	return 0;	
} //Fim da função MAIN.

/*Essa função busca o nome de um capivara em um vetor de registros de capivaras e devolve a posição dessa capivara dentro do vetor.
  Recebe uma string nome[MAX_NOME], um inteiro n que representa a quantidade de registros existentes nesse vetor e o vetor de capivaras.
  Caso a capivara nãos seja encontrada a função irá retornar -1*/
int buscar_Nome(char nome[MAX_NOME], int n, capivara capivaras[MAX_CAPIVARAS]){
	int i; //índice de iterações do laço for.
	int posicao = -1; //Armazenará a posição a ser retornada.

	for(i =0; i < n; i++)
		if(strcmp(nome, capivaras[i].nome) == 0)
			posicao = i;
	
	return posicao;
}

/*Essa função calcula a maior variação de peso de uma capivara dentre os meses registrado
	Recebe um vetor de capivaras do tipo capivara, um inteiro i correspondente a posição da capivara nesse vetor
	e um inteiro novo_peso correspondente ao peso mais recente da capivara.
	O calculo da variação mensal é dado pela subtração do novo peso com o ultimo peso registrado.
	A função irá registrar a nova variação caso ela seja maior do que a maior variação já registrada.*/	
void calcula_max_var_mensal(capivara capivaras[MAX_CAPIVARAS], int i, int novo_peso){

	if(abs(novo_peso - capivaras[i].ultimo_peso) > capivaras[i].max_var_mensal)
		capivaras[i].max_var_mensal = novo_peso - capivaras[i].ultimo_peso;
	
}

/*Essa função calcula a variação total de peso de uma capivara.
  Recebe um vetor de capivaras  e um inteiro i correspondente a posição do registro da capivara dentro desse vetor.	
  O calculo da variação final é dado pela subtração do ultimo peso registrado com o primeiro peso registrado.*/
void calcula_variacao_total(capivara capivaras[], int i){
	capivaras[i].var_total = (capivaras[i].ultimo_peso - capivaras[i].var_total); 
}

/*Essa função limpa todos os campos de todos registro de capivaras.
  Recebe um vetor de capivaras e a quantidade de registro */
void limpa_registros(capivara capivaras[], int n){
	int i; //índice de iteração do laço for.
	for(i = 0; i < n; i++){
		strcpy(capivaras[i].nome, "");
		strcpy(capivaras[i].nascimento, "");
		capivaras[i].ultimo_peso = 0; 
		capivaras[i].max_var_mensal = 0; 
		capivaras[i].var_total = 0;
	}
}

/*Chamada recursiva da função de intercalação*/
void mergeSort(int p, int r, capivara v[]){
	
	if(p < r-1){
		int q = (p + r)/2;
		mergeSort(p, q, v);
		mergeSort(q, r, v);
		intercala(p, q, r, v);
	}
}

/* Recebe os vetores decrescentes v[p..q-1] e v[q..r-1]
e rearranja v[p..r-1] em ordem decrescente */
void intercala(int p, int q, int r, capivara v[]){
	int i =p; 			//Inicio do intervalo.
	int j =q; 			//Meio do intervalo.
	capivara w[r-p]; 	//Vetor auxiliar de capivaras.
	int k =0 ; 			//Indice de iteração dos laços.

		while(i < q && j < r){
			/*Caso a variação total de i seja maior, adicione i*/
			if(abs(v[i].var_total) > abs(v[j].var_total)){ //Se a max variação de i > j
				w[k] = v[i];
				i++;	
			/*Caso as variações sejam iguais, Ordene de acordo com os próximos critério*/	
			}else if(abs(v[i].var_total) == abs(v[j].var_total)){ 
					/*Chamando a função de critérios para ver qual elemento deve ser adicionado */
					if(ordena_criterios(v, i, j) == i){ //Adicionando i caso a função retorn i. 
						w[k] = v[i];
						i++;
					/*Adicionando j caso seja o maior*/
					}else{ 
						w[k] = v[j];
						j++;
					}	
			/*Caso contrário adicione j.*/
			}else{
				w[k] = v[j];
				j++;
			}
			k++;
		}
		/*Copiando os elementos que restáram após a intercalação*/
		while(i < q){
			w[k] = v[i];
			i++;
			k++;
		}
		/*Copiando os elementos que restáram após a intercalação*/
		while(j < r){
			w[k] = v[j];
			j++;
			k++;
		}		
		/*Adicionando novamente os elementos em v, mas agora já ordenados*/
		for(i = p; i < r; i++)
			v[i] = w[i-p];
}

/*Essa função calcula de acordo com os critérios de ordenação qual elemento deve ser adicionado primeiro
  Recebe um vetor de capivaras e dois inteiros i e j correspontes ás posições das duas capivaras no vetor.
  Caso haja empate em algum critério a função decidirá de acordo com os próximos critérios até haver desempate.
  Os critérios em ordem são:
  1° - Maior variação mensal.
  2° - Maior idade Idade.
  3° - Ordem lexicográfica.	
*/
int ordena_criterios(capivara capivaras[], int i, int j){
	/*Avaliando o primeiro critério*/
	if(abs(capivaras[i].max_var_mensal) > abs(capivaras[j].max_var_mensal)){
		return i;
	/*Avaliando pelo segundo critério caso haja empate */	
	}else if(abs(capivaras[i].max_var_mensal) == abs(capivaras[j].max_var_mensal)){ //Se a variação do mes for igual.
			if(calcula_dias(capivaras[i].nascimento) < calcula_dias(capivaras[j].nascimento))
				return i;
			/*Avaliando pelo terceiro critério caso haja empate*/
		    else if(calcula_dias(capivaras[i].nascimento) == calcula_dias(capivaras[j].nascimento))
			 	return ordem_lexicografica(capivaras, i, j);
			else
				return j;
	/*Retorne j caso seja maior*/
	}else{
		return j;
	}
}

/*Essa função calcula e retorna o número da data de nascimento em dias, de uma capivara
  Recebe uma string de data de nascimento no formato DD/MM/AAAA.
  Tranforma os dias, meses e anos em inteiros e soma.
  A transformação é dada pelo valor do caractere na tabela ascii - 48, que é o ínicio do intervalo dos caracteres númerais na tabela,
  de forma a obter o respectivo valor do caractere mas agora em inteiro. 	
*/
int calcula_dias(char nascimento[]){
	int dias =0;
	int mes  =0;
	int anos =0;

	dias = (nascimento[0] - 48)* 10; 
	dias += nascimento[1] - 48;

	mes = (nascimento[3] - 48) * 10;
	mes += (nascimento[4] - 48);
	mes = mes * 30;

	anos = 	(nascimento[6] - 48) * 1000;
	anos += (nascimento[7] - 48) * 100;
	anos += (nascimento[8] - 48) * 10;
	anos += (nascimento[9] - 48);
	anos = anos * 365;

	return  dias + mes + anos;
}

/*Essa função calcula e retorna qual é a menor palavra de acordo com a ordém lexicográfica
  Recebe um vetor de capivaras, e dois inteiros i e j correspondentes ás posições das capivaras dentro do vetor.
  */
int ordem_lexicografica(capivara capivaras[], int i, int j){
		/*Caso o nome de i seja igual que j, retorne i para manter a estabilidade na ordem, pois i veio primeiro*/
		if(strcmp(capivaras[i].nome, capivaras[j].nome) == 0)
			return i;

		/*Caso j seja menor*/
		else if(strcmp(capivaras[i].nome, capivaras[j].nome) > 0)
			return j;
		/*Caso i seja menor*/
		else
			return i;
}