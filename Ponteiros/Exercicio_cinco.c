#include <stdio.h>

#define N 5

/*----------------------------------*/

int minimax(int matriz[N][N], int *linha_minimax, int *coluna_minimax){

    int i,j, maior = 0, minimax_numero = 0;
    *linha_minimax = 0;
    *coluna_minimax = 0;

    minimax_numero = matriz[0][0];
    maior = matriz[0][0];

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(matriz[i][j]>maior){
                maior = matriz[i][j];
                *linha_minimax = i;
            }
        }
    }

    for(j=0;j<N;j++){
        if(matriz[*linha_minimax][j] < minimax_numero){
            minimax_numero = matriz[*linha_minimax][j];
            *coluna_minimax = j;
        }
    }

    return minimax_numero;
}

/*---------------------------------------------------*/

int main(){

int matriz[N][N] = {
    {4,  8,  2,  7,  5},
    {1, 15,  3,  2,  9},
    {6, 14, 11, 12, 10},
    {5,  9,  8,  4,  3},
    {7,  2,  6,  5,  1}
    };
int linha_minimax, coluna_minimax;

printf("O numero minimax: %d\n", minimax(matriz,&linha_minimax,&coluna_minimax));
printf("Linha e coluna: %d e %d", linha_minimax, coluna_minimax);

}

