#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------------------------*/

struct aluno{

    char disciplina[8];
    char mat[10];
    float media_aluno;
};

typedef struct aluno ALUNO;

/*----------------------------*/

ALUNO *le_aluno(int n){

    ALUNO *a = (ALUNO *)malloc(n * sizeof(ALUNO));

    int i;

    for(i=0;i<n;i++){
        printf("Digite a disciplina, matricula e media do aluno: \n");
        scanf("%s %s %f", a[i].disciplina, a[i].mat, &a[i].media_aluno);
    }

    return a;
}

/*----------------------------*/

void escreve_aluno(ALUNO *v, int n){

    int i;

    for(i=0;i<n;i++){
        printf("Disciplina: %s | Aluno: %s | Media: %.2f\n", v[i].disciplina, v[i].mat, v[i].media_aluno);
        printf("\n");
    }
}

/*----------------------------*/

ALUNO *media(ALUNO *a, int num_alunos, char disc[10], float *media, int *qtd_alunos){
    *qtd_alunos = 0;
    int i, k = 0;

    for(i=0;i<num_alunos;i++){
        if(strcasecmp(a[i].disciplina, disc) == 0){
            *media += a[i].media_aluno;
            (*qtd_alunos)++;
        }
    }

    if(*qtd_alunos==0){
        *media = -1.0;
        return NULL;
    }

    *media/=*qtd_alunos;

    ALUNO *d = (ALUNO *)malloc(*qtd_alunos*sizeof(ALUNO));

    for(i=0;i<num_alunos;i++){
        if(strcasecmp(a[i].disciplina, disc) == 0){
            d[k++] = a[i];
        }
    }

    return d;
}

/*----------------------------*/

int main(){

    int qtd, num_alunos;
    float m = 0;
    char disc[10];

    printf("Digite a quantidade de alunos: \n");
    scanf("%d", &num_alunos);

    ALUNO *a = le_aluno(num_alunos);

    printf("Digite o nome da disciplina desejada: \n");
    fflush(stdin);
    fgets(disc,10,stdin);

    ALUNO *d = media(a,num_alunos,disc,&m,&qtd);

    if(d!=NULL){

        printf("Media da disciplina: %.2f\n", m);
        escreve_aluno(d, qtd);
        free(d);
    }else{
        printf("%d\n", m);
    }
}
