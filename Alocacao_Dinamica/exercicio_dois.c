#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*------------------------------------*/

char *aleatoria(int n){

    char *str = (char *) malloc((n+1) * sizeof(char)); 
    if(str==NULL){
        return NULL;
    }
    int i;

    for(i=0;i<n;i++){

        int tipo = rand() % 3;
        switch(tipo){
            case 0: str[i] = 'A' + (rand() % 26);
            break;
            case 1: str[i] = 'a' + (rand() % 26);
            break;
            case 2: str[i] = '0' + (rand() % 10);
            break;
        }
    }

    str[i] = '\0';

    return str;
}

/*-------------------------------------------*/

int main(){

    srand(time(NULL));
    int n;

    printf("Digite quantos digitos tera sua chave: \n");
    scanf("%d", &n);

    char *chave = aleatoria(n);

    if(chave!=NULL){
        printf("Chave aleatoria: %s\n", chave);
    }else{
        printf("ERRO\n");
    }

    return 0;
}