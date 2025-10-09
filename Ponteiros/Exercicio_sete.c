#include <stdio.h>

#define N 100

/*--------------------------------------------------------*/

void doismaiores(char string[N], int *maior, int *segundo_maior){

    *maior = 0;
    *segundo_maior = 0;

    int i, num = 0;

    for(i=0;string[i]!='\0';i++){
        if(string[i]!='#'){
            num = num * 10 + (string[i] - '0');
        }else{
            if(num>*maior){
                *segundo_maior = *maior;
                *maior = num;
            }else{
                if(num>*segundo_maior){
                    *segundo_maior = num;
                }
            }
             num = 0;
        }
    }

    if(num>*maior){
        *segundo_maior = *maior;
        *maior = num;
    }else{
        if(num>*segundo_maior){
            *segundo_maior = num;
        }
    }
}

/*-------------------------------------------------------*/

int main(){

    char string[N] = "10#20#191#7#34";
    int maior, segundo_maior;

    doismaiores(string,&maior,&segundo_maior);

    printf("Maior numero: %d\n", maior);
    printf("Segundo maior: %d\n", segundo_maior);

    return 0;
}