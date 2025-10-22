#include <stdio.h>
#include <stdlib.h>

#define N 5

struct naonulo{

    int valor;
    int linha;
    int coluna;
};

typedef struct naonulo NAONULO;

/*---------------------------------*/

NAONULO *valores_nao_nulos(int mat[N][N], int *qtd_nao_nulo){

    int t = N * N;

    NAONULO *num_nao_nulo = (NAONULO *)malloc(t * sizeof(NAONULO));
    if(num_nao_nulo==NULL){
        return NULL;
    }

    int i,j,k, foi = 0;

    k = 0;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(mat[i][j]!=0){
                num_nao_nulo[k].valor = mat[i][j];
                num_nao_nulo[k].linha = i;
                num_nao_nulo[k++].coluna = j;
                foi = 1;
            }
        }
    }

    num_nao_nulo = (NAONULO *)realloc(num_nao_nulo,k*sizeof(NAONULO));
    *qtd_nao_nulo = k;

    if(foi){
        return num_nao_nulo;
    }else{
        return NULL;
    }
}

/*---------------------------------*/

void escreve(NAONULO *v, int n){

    int i;

    for(i=0;i<n;i++){
        printf(" Valor: %d | Linha: %d | Coluna: %d \n", v[i].valor, v[i].linha, v[i].coluna);
    }
}

/*---------------------------------*/

int main(){

    int matriz[N][N] = {
        {0, 0, 3, 0, 0},
        {0, 5, 0, 0, 0},
        {0, 0, 0, 7, 0},
        {2, 0, 0, 0, 9},
        {0, 0, 4, 0, 0}
    };

    int qtd_nao_nulo;

    NAONULO *resultado = valores_nao_nulos(matriz,&qtd_nao_nulo);

    if(resultado!=NULL){
        escreve(resultado, qtd_nao_nulo);

        free(resultado);
    }else{
        printf("Nenhum numero diferente de 0 encontrado.\n");
    }
}


