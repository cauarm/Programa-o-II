#include <stdio.h>

/*-----------------------------------*/

int resto11(int soma){

    int resto = soma % 11;

    if(resto==0 || resto==1){
        return 0;
    }else{
        return 11 - resto;
    }
}

/*-------------------------------------*/

void calcula_digitos(char cpf[12], int *d1, int *d2){

    int i, soma1 = 0, m1 = 10;
    int soma2 = 0, m2 = 11; 
    int resto;

    for(i=0;cpf[i]!='\0';i++){
        if(cpf[i]>='0' && cpf[i]<='9'){
            soma1 += (cpf[i] - '0') * m1--;
            soma2 += (cpf[i] - '0') * m2--;
        }
    }

    *d1 = resto11(soma1);
    soma2 += (*d1 * 2);
    *d2 = resto11(soma2);
}

/*-----------------------------------------*/

int main(){

    char cpf[12] = "316.297.720";
    int d1, d2;

    calcula_digitos(cpf,&d1,&d2);

    printf("Primeiro digito: %d\n", d1);
    printf("Segundo digito: %d\n", d2);
}