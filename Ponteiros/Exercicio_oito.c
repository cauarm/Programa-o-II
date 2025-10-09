#include <stdio.h>

#define N 5

/*------------------------------------*/

struct alunos{

    char nome[50];
    float nota1, nota2, nota3, media;
};

typedef struct alunos ALUNOS;

/*------------------------------------*/
void escreve_aluno(ALUNOS v[N]){

    int i;
    
    for(i=0;i<N;i++){
    printf("Digite o nome do aluno: ");
    fgets(v[i].nome, 50, stdin);
    printf("Digite as notas deste aluno: ");
    scanf("%f %f %f", &v[i].nota1, &v[i].nota2, &v[i].nota3);
    fflush(stdin);
    }
}
/*------------------------------------------*/
void calcula_media(ALUNOS v[N]){
    int i;
    for(i=0;i<N;i++){
        v[i].media = (v[i].nota1 + v[i].nota2 + v[i].nota3 ) / 3; 
    }
}
/*------------------------------------------*/
void menor_maior_medias(ALUNOS v[N], ALUNOS *menor, ALUNOS *maior){

    int i;
    *menor = v[0];
    *maior = v[0];

    for(i=0;i<N;i++){
        if(v[i].media > maior -> media){
            *maior = v[i];
        }
        if(v[i].media < menor -> media){
            *menor = v[i];
        }
    }
}
/*-----------------------------------------------*/

int main(){

    ALUNOS menor, maior;
    ALUNOS v[N];

    escreve_aluno(v);
    printf("\n");
    calcula_media(v);
    menor_maior_medias(v, &menor, &maior);

    printf("Aluno com maior media: %s\n", maior.nome);
    printf("Media do aluno: %.2f\n", maior.media);
    printf("--------------------------------------\n");
    printf("Aluno com menor media: %s", menor.nome);
    printf("Media do aluno: %.2f\n", menor.media);
    
}
