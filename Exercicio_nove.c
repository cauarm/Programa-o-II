#include <stdio.h>
#include <math.h>

#define N 3

/*-------------------------------*/

struct ponto{
    int x,y;
};

typedef struct ponto PONTO;

/*-------------------------------*/

void le_pontos(PONTO v[N]){
    int i;
    for(i=0;i<N;i++){
        printf("Digite o ponto X e Y: \n");
        scanf("%d %d", &v[i].x, &v[i].y);
    }
}

/*-----------------------------------*/

void calc_dist(PONTO v[N], PONTO *ponto1, PONTO *ponto2){

    int i, j;
    float distancia_x = 0, distancia_y = 0, distancia = 0;
    float maior_distancia = 0;

    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            distancia_x = v[i].x - v[j].x;
            distancia_y = v[i].y - v[j].y;
            distancia = sqrt((distancia_x * distancia_x) + (distancia_y * distancia_y));

            if(distancia>maior_distancia){
                maior_distancia = distancia;
                *ponto1 = v[i];
                *ponto2 = v[j];
            }
        }
    }
}

/*--------------------------------------------------*/

int main(){

    PONTO v[N];
    PONTO ponto1, ponto2;

    le_pontos(v);
    calc_dist(v, &ponto1, &ponto2);

    printf("Dois pontos com maior distancia: \n");
    printf("Ponto 1: (%.2f , %.2f)\n", ponto1.x, ponto1.y);
    printf("Ponto 2: (%.2f , %.2f)\n", ponto2.x, ponto2.y);

    return 0;
}


