#include <stdio.h>
#include <stdlib.h>

/*--------------------------------------*/

int eh_primo(int numero){

    if(numero<=1){
        return 0;
    }

    if(numero==2){
        return 1;
    }

    int i;

    for(i=2;i*i<=numero;i++){
        if(numero%i==0){
            return 0;
        }
    }

    return 1;
}

/*--------------------------------------*/

int *primos(int n){

    int *num_primos = (int *) malloc(n * sizeof(int));
    if(num_primos==NULL){
        return NULL;
    }

    int contador_primos = 0;
    int numero = 2;

    while(contador_primos<n){
        if(eh_primo(numero)){
            num_primos[contador_primos++] = numero;
        }

        numero++;
    }

    return num_primos;
}

/*--------------------------------------*/

int main(){

    int n, i;

    printf("Digite quantos numeros primos deseja ver: \n");
    scanf("%d", &n);

    int *resultado = primos(n);

    if(resultado!=NULL){
        for(i=0;i<n;i++){
            printf(" %d ", resultado[i]);
        }

        printf("\n");
        free(resultado);
    }else{
        printf("ERRO DE MEMORIA.");
    }

        return 0;
}