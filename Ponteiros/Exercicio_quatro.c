#include <stdio.h>

#define N 5

/*----------------------------------------*/

int maior_valor(int matriz[N][N], int *linha, int *coluna){

    int i,j, maior = 0;

    maior = matriz[0][0];
    *linha = 0;
    *coluna = 0;


    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(matriz[i][j]>maior){
                maior = matriz[i][j];
                *linha = i;
                *coluna = j;
            }
        }
    }

    return maior;
}

/*------------------------------------------*/

int main(){

    int matriz[N][N] ={
        {1, 2, 3, 4, 5}, 
        {6, 7, 8, 9, 10}, 
        {11, 12, 99, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int linha,coluna;

    printf("Maior valor da matriz: %d\n", maior_valor(matriz, &linha, &coluna));
    printf("Linha e coluna do valor: %d e %d\n", linha, coluna);
}