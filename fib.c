#include<stdio.h>



int main(){
    int n; //Número de execuções do programa.
    int num; //Ńésimo termo.

    //Entre com o Número de execuções do programa.
    scanf("%d", &n);

    for(int i =0; i < n; i++){
        //Digite o termo desejado.
        scanf("%d", &num);

        //Chamando a função Fibonacci e imprimindo diretamente pela função.
        printf("%d ", Fib(num));
    }
    return 0;
}
//ESsa Função Calcula o n-ésimo termo da sequência de FIbonacci
int Fib(int i){

    //Se a entrada for menor que 3, retorn 1.
    if(i < 3){
        return 1;

    }else{ //Para entrada maior ou igual a 3, calcule a soma de n + n-1 + n-2.
        return  Fib(i-1) + Fib(i-2);
    }
}

