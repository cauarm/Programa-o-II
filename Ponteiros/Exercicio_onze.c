#include <stdio.h>

#define N 10

/*-----------------------------------------*/

void mais_vezes(int v[N], int *valor, int *vezes){

    int i,j;
    int cont = 0;
    int maior_vezes_rep = 0;
    int num_mais_freq = v[0];

    for(i=0;i<N;i++){
        cont = 0;
        for(j=0;j<N;j++){
            if(v[i]==v[j]){
                cont++;
            }
        }

        if(cont>maior_vezes_rep || (cont==maior_vezes_rep && v[i]>num_mais_freq)){
            maior_vezes_rep = cont;
            num_mais_freq = v[i];
        }
    }

    *valor = num_mais_freq;
    *vezes = maior_vezes_rep;
}

/*-----------------------------------------------*/

int main(){

    int v[N] = {1,2,2,2,3,4,5,7,2,2};
    int valor,vezes;

    mais_vezes(v, &valor, &vezes);

    printf("Valor mais repetido: %d | Vezes repetidas: %d\n", valor, vezes);
}