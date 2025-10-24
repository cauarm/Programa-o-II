#include <stdio.h>
#include <stdlib.h>

#define N 100

/*--------------------------------*/

void escreve_str(int *v, int n){

    int i;

    for(i=0;i<n;i++){
        printf(" %d ", v[i]);
    }
}

/*--------------------------------*/

int *separa(char str[], int *cont){

    *cont = 0;

    int i;
    int numero = 0;

    for(i=0;str[i]!='\0';i++){
        
        if(str[i]==','){
            (*cont)++;
        }
    }
    (*cont)++;

    int *numeros = (int *)malloc(*cont*sizeof(int));
    if(numeros==NULL){
        return NULL;
    }

    int k = 0;

    for(i=0;str[i]!='\0';i++){

        if(str[i]>='0' && str[i]<='9'){
            numero = numero * 10 + (str[i] - '0');
        }

        if(str[i]==','){
            numeros[k++] = numero;
            numero = 0;
        }
    }

    numeros[k] = numero;

    return numeros;
}

/*--------------------------------*/

int main(){

    int cont;
    char str[N] = "10,15,245,11,5,1243";

    int *separados = separa(str, &cont);

    if(separados!=NULL){
        escreve_str(separados,cont);
        free(separados);
    }else{
        printf("ERRO DE MEMORIA. \n");
    }
}

