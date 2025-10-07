#include <stdio.h>

/*----------------------------------*/

void trocar_valores(int *a, int *b){

    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

}

/*--------------------------------------*/

int main(){

    int a,b;

    printf("Digite um numero para A e um numero para B: \n");
    scanf("%d %d", &a, &b);

    trocar_valores(&a, &b);

    printf("Valores trocados: %d %d\n", a, b);
}