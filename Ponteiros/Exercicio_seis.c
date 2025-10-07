#include <stdio.h>

#define N 15

/*-------------------------------------------*/

int eh_primo(int numero){

    int i;

    if(numero<=1) return 0;
    if(numero==2) return 1;

    for(i=2; i * i <= numero;i++){
        if(numero%i == 0){
            return 0;
        }
    }

    return 1;
}

/*----------------------------------------------------*/

void menor_primo(int matriz[N][N], int *primo, int *linha, int *coluna){
    int numero, i,j;
    int menor_primo;

    menor_primo = 999999;
    *primo = -1;
    *linha = -1;
    *coluna = -1;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            numero = matriz[i][j];
            if(eh_primo(numero)){
                if(numero<menor_primo){
                    menor_primo = numero;
                    *linha = i;
                    *coluna = j;
                    *primo = numero;
                }
            }
        }
    }
}

/*----------------------------------------------------------------------*/

int main(){

    int matriz[N][N];
    int primo,linha,coluna;
    int i,j;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("Digite um valor da matriz: \n");
            scanf("%d", &matriz[i][j]);
        }
    }

    menor_primo(matriz, &primo, &linha, &coluna);

    if(linha!=-1 && coluna!=-1){
        printf("Menor valor primo: %d\n", primo);
        printf("Linha e coluna desse valor: %d e %d", linha, coluna);
    }else{
        printf("Primo: %d | Linha: %d | Coluna: %d - Nao haviam primos. \n", primo,linha,coluna);
    }
}



