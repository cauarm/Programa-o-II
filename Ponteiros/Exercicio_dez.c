#include <stdio.h>

#define N 3

/*----------------------------------------*/

struct candidato{

    char nome[50];
    float pont;
};

typedef struct candidato CANDIDATO;

/*------------------------------------------*/

void le_candidato(CANDIDATO v[N]){

    int i;

    for(i=0;i<N;i++){
        printf("Digite o nome do candidato: \n");
        getchar();
        fgets(v[i].nome, 50, stdin);
        printf("Digite a pontuacao do candidato: \n");
        scanf("%f", &v[i].pont);
    }
}

/*-------------------------------------------------*/

void maiores_pontuadores(CANDIDATO v[N], CANDIDATO *c1, CANDIDATO *c2){

    int i;

    *c1 = v[0];
    *c2 = v[0];


    for(i=0;i<N;i++){
        if(v[i].pont>c1->pont){
            *c2 = *c1;
            *c1 = v[i];
        }else if(v[i].pont>c2->pont){
            *c2 = v[i];
        }
    }
}

/*--------------------------------------------------------*/

int main(){

    CANDIDATO v[N];
    CANDIDATO c1, c2;

    le_candidato(v);
    maiores_pontuadores(v, &c1, &c2);

    printf(" - MAIORES PONTUADORES -\n");
    printf("Maior pontuador:\n");
    printf("Nome: %s | Pontuacao: %.2f\n", c1.nome, c1.pont);
    printf("Segundo maior: \n");
    printf("Nome: %s | Pontuacao: %.2f\n", c2.nome, c2.pont);
}