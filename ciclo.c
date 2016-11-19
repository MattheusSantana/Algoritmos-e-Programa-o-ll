#include<stdio.h>

int main(){
    int n; //Número de execuções do programa.
    int num;

    //Entre com o Número de execuções do programa.
    scanf("%d", &n);

    for(int i =0; i < n; i++){
        //Digite o termo desejado.
        scanf("%d", &num);

        //CHamando a função do Ciclo e imprimindo o numero de ciclos.
        printf("\nO número total de ciclos é = %d  ", ciclo(num));

    }
    return 0;
}
/*  Considere o seguinte processo para gerar uma seqüência de números. Comece com um
inteiro n. Se n é par, divida por 2. Se n é ímpar, multiplique por 3 e some 1. Repita esse
processo com o novo valor de n, terminando quando n = 1. Por exemplo, a seqüência de
números a seguir é gerada para n = 22:
22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
É conjecturado que esse processo termina com n = 1 para todo inteiro n > 0. Para uma
entrada n, o comprimento do ciclo de n é o número de elementos gerados na seqüência.
No exemplo acima, o comprimento do ciclo de 22 é 16.
*/
int ciclo(int n){
    int contador =1; //ESsa variável armazenará o número de ciclos.

    //Para n =1 imprima e retorne 1.
    if(n ==1 ){
    printf("1 ");
    return 1;


    }else{
        //n /2, se n for par.
        if(n%2 ==0){
        //Imprimindo o valor de N para cada execução da função.
        printf("%d ", n);
        //Incrementando contador para cada número de execuçoes da função.
       return contador + ciclo(n/2);

        //n*3 +1, se n for ímpar.
        }else{
        //Imprimindo o valor de N para cada execução da função.
        printf("%d ", n);
        //Incrementando contador para cada número de execuçoes da função
        return contador + ciclo(n*3+1);
        }
    }
}
