#include <stdio.h>

// Verificador de Título Eleitoral

/*----------------------------------------------*/

int resto11(int soma){

    int resto = soma % 11;

    if(resto==10){
        return 0;
    }

    return resto;
}

/*--------------------------------------------*/

void titulo_de_eleitor(char str[13], int *d1, int *d2){

    int soma1 = 0, mult1 = 2;
    int soma2 = 0, mult2 = 7;
    int i;

    for(i=0;i<8;i++){
        if(str[i]>='0' && str[i]<='9'){
            soma1+= (str[i] - '0') * mult1++;
        }
    }

    for(i=8;i<10;i++){
        soma2+= (str[i] - '0') *mult2++;
    }

    *d1 = resto11(soma1);
    soma2+= *d1 * 9;
    *d2 = resto11(soma2);
}

/*--------------------------------------------------*/

int main(){
    char titulo[13];  // 12 dígitos + '\0'
    int d1, d2;
    
    printf("Digite o título eleitoral (12 dígitos): ");
    scanf("%s", titulo);
    
    titulo_de_eleitor(titulo, &d1, &d2);
    
    printf("\nTítulo informado: %s\n", titulo);
    printf("Dígito verificador 1 (calculado): %d\n", d1);
    printf("Dígito verificador 2 (calculado): %d\n", d2);
    
    return 0;
}