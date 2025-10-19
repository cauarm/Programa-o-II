#include <stdio.h>
#include <stdlib.h>

/*----------------------------------*/

int *fibonacci(int n){

    int *termos = (int *) malloc(n * sizeof(int));
    if(termos==NULL){
        return NULL;
    }
    int i;

    if(n>=1){
        termos[0] = 0;
    }
    if(n>=2){
        termos[1] = 1;
    }

    for(i=2;i<n;i++){
        termos[i] = termos[i-1] + termos[i-2];
    }

    return termos;
}

/*------------------------------------*/

int main(){

    int n, i;

    printf("Digite ate onde voce quer a fibonacci: \n");
    scanf("%d", &n);

    int *resultado = fibonacci(n);

    if(resultado!=NULL){
        for(i=0;i<n;i++){
            printf(" %d ", resultado[i]);
        }
        printf("\n");

        free(resultado);
    }else{
        printf("ERRO DE MEMORIA.\n");
    }

    return 0;
}