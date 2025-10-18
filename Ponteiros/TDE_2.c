#include <stdio.h>

#define N 3 

/*-----------------------------------*/

struct piloto{
    char nome[51];
    char equipe[51];
    int pontuacao[22];
};

typedef struct piloto PILOTO;

/*-----------------------------------*/

void le_piloto(PILOTO v[N]){

    int i,j;

    for(i=0;i<N;i++){

        printf("Digite o nome do piloto: \n");
        getchar();
        fgets(v[i].nome, 51, stdin);
        printf("Digite o nome da equipe: \n");
        fgets(v[i].equipe, 51, stdin);
        for(j=0;j<22;j++){
            printf("Digite a pontuacao do piloto na prova %d: \n", j+1);
            scanf("%d", &v[i].pontuacao[j]);
        }
    }
}

/*-------------------------------------------*/

int soma_pontos(PILOTO piloto){

    int i, soma = 0;

    for(i=0;i<22;i++){
        soma += piloto.pontuacao[i];
    }

    return soma;
}


/*------------------------------------------*/

void calcula_classif(PILOTO v[N], PILOTO *campeao, PILOTO *vice){

    int soma = 0, i;
    *campeao = v[0];
    *vice = v[0];
    int pont_campeao = soma_pontos(*campeao);
    int pont_vice = soma_pontos(*vice);

    for(i=0;i<N;i++){

        int pont_atual = soma_pontos(v[i]);
        if(pont_atual>pont_campeao){
            *vice = *campeao;
            pont_vice = pont_campeao;
            *campeao = v[i];
            pont_campeao = pont_atual;
        }else if(pont_atual>pont_vice){
            *vice = v[i];
            pont_vice = pont_atual;
        }
    }
}

/*--------------------------------------------------*/

int main(){

    PILOTO v[N];
    PILOTO campeao, vice;

    le_piloto(v);
    calcula_classif(v, &campeao, &vice);

    printf(" - THE CHAMPIONS! -\n");
    printf("Piloto campeao: %s | Equipe: %s | Pontuacao: %d \n", campeao.nome, campeao.equipe, soma_pontos(campeao));
    printf("Vice Campeao: %s | Equipe: %s | Pontuacao: %d \n", vice.nome, vice.equipe, soma_pontos(vice));

    return 0;
}

