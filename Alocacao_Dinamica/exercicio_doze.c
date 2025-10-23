#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------------*/

struct motorista{

        char nome[51];
        int mat;
        int num_multas;
};

typedef struct motorista MOTORISTA;

/*-----------------------------------*/

MOTORISTA *le_motorista(int n){

    MOTORISTA *m = (MOTORISTA *)malloc(n*sizeof(MOTORISTA));

    int i;

    for(i=0;i<n;i++){
        printf("Digite o nome, matricula e numero de multas do motorista: \n");
        fflush(stdin);
        scanf("%s %d %d", m[i].nome, &m[i].mat, &m[i].num_multas);
    }

    return m;
}

/*-----------------------------------*/

void escreve_motorista(MOTORISTA *v, int n){

    int i;

    for(i=0;i<n;i++){
        printf("Nome: %s | Matricula: %d | Multas: %d\n", v[i].nome, v[i].mat, v[i].num_multas);
        printf("\n");
    }
}

/*-----------------------------------*/

MOTORISTA *piores_motoristas(MOTORISTA *m, int num_motoristas, int n){

    if(n>=num_motoristas){
        return NULL;
    }

    MOTORISTA *piores = (MOTORISTA *)malloc(n*sizeof(MOTORISTA));
    if(piores==NULL){
        return NULL;
    }

    int i, k = 0, j;
    MOTORISTA aux;

    for(i=0;i<num_motoristas;i++){
        for(j=i+1;j<num_motoristas - i;j++){
            if(m[i].num_multas<m[j].num_multas){
                aux = m[i];
                m[i] = m[j];
                m[j] = aux;
            }
        }
    }


    for(i=0;i<n;i++){
        piores[k++] = m[i];
    }

    return piores;
}

/*-----------------------------------*/

int main(){

    int num_moto, num_piores;

    printf("Digite quantos motorista sao: \n");
    scanf("%d", &num_moto);

    MOTORISTA *m = le_motorista(num_moto);

    printf("Digite quantos piores deseja ver: \n");
    scanf("%d", &num_piores);

    MOTORISTA *piores = piores_motoristas(m,num_moto,num_piores);

    if(piores!=NULL){
        escreve_motorista(piores,num_piores);
        free(m);
        free(piores);
    }else{
        printf("ERRO\n");
        free(m);
    }

}
