#include <stdio.h>

#define N 1000

char *ultimo_nome(char *nome_completo){

    int i, ult = 0;

    for(i=0;nome_completo[i]!='\0';i++){
        if(nome_completo[i] == ' '){
            ult = i;
        }
    }

    return &nome_completo[ult+1];
}M

int main(){

    char nome_completo[N];

    printf("Digite seu nome completo: \n");
    fgets(nome_completo,N,stdin);

    char *sobrenome = ultimo_nome(nome_completo);

    printf("Seu sobrenome: %s\n", sobrenome);

    return 0;
}