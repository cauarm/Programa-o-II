#include <stdio.h>
#include <stdlib.h>

#define N 3


/*--------------------------*/

struct ponto{

    float x,y;

};

typedef struct ponto PONTO;

/*--------------------------*/

PONTO *filtra_pontos(PONTO *p, int n_pontos, float x1, float y1, float x2, float y2, int *qtd){

    PONTO *pontos = (PONTO *)malloc(n_pontos * sizeof(PONTO));
    if(pontos==NULL){
        return NULL;
    }

    int i,k = 0;
    int teve_ponto = 0;

    for(i=0;i<n_pontos;i++){

        if(x1<=p[i].x && p[i].x<x2 && y1<=p[i].y && p[i].y<y2){
            pontos[k] = p[i];
            k++;
            teve_ponto = 1;
        }
    }

    pontos = (PONTO *)realloc(pontos,k*sizeof(PONTO));
    *qtd = k;

    if(teve_ponto){
        return pontos;
    }else{
        free(pontos);
        return NULL;
    }
}

/*--------------------------*/

void le_pontos(PONTO *v, int n){

    int i;

    for(i=0;i<n;i++){

        printf("Digite seu ponto x e y: \n");
        scanf("%f %f", &v[i].x, &v[i].y);
    }
}

/*--------------------------*/

void escreve_pontos(PONTO *v, int n){

    int i;

    for(i=0;i<n;i++){

        printf(" %.2f | %.2f \n", v[i].x, v[i].y);
    }
}

/*--------------------------*/

int main(){

    PONTO v[N];
    int qtd_pontos;
    float x1,y1,x2,y2;
    int i;

    printf("Digite seu x1 e y1: \n");
    scanf("%f %f", &x1, &y1);

    printf("Digite seu x2 e y2: \n");
    scanf("%f %f", &x2, &y2);

    le_pontos(v, N);

    PONTO *ponto_ret = filtra_pontos(v, N, x1,y1,x2,y2,&qtd_pontos);

    if(ponto_ret!=NULL){
        escreve_pontos(ponto_ret, qtd_pontos);

        free(ponto_ret);
    }else{
        printf("Nao houveram pontos dentro do retangulo. \n");
    }
}
