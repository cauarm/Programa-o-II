#include <stdio.h>
#include <stdlib.h>

#define N 5

/*------------------------*/

struct data{

    int dia, mes, ano;
};

typedef struct data DATA;

/*------------------------*/

struct cliente{

    int codigo;
    char nome[51];
    DATA nasc;

};

typedef struct cliente CLIENTE;

/*------------------------*/

CLIENTE *maior_de_idade(CLIENTE *v, int num_clientes, DATA atual, int *qtd_maiores){

    CLIENTE *maiores = (CLIENTE *)malloc(num_clientes * sizeof(CLIENTE));
    if(maiores==NULL){
        return NULL;
    }

    *qtd_maiores = 0;

    int i,tem_maior = 0, k = 0;

    for(i=0;i<num_clientes;i++){
        int idade = atual.ano - v[i].nasc.ano;

        if(v[i].nasc.mes<atual.mes || (v[i].nasc.mes==atual.mes) && v[i].nasc.dia<atual.dia){
            idade--;
        }

        if(idade>=18){
            maiores[k++] = v[i];
            tem_maior = 1;
        }
    }

    maiores = (CLIENTE *)realloc(maiores,k*sizeof(CLIENTE));
    *qtd_maiores = k;

    if(tem_maior){
        return maiores;
    }else{
        return NULL;
    }
}

/*------------------------*/

void le_cliente(CLIENTE *v, int n){

    int i;

    for(i=0;i<n;i++){
        printf("Digite o codigo do cliente: \n");
        scanf("%d", &v[i].codigo);
        fflush(stdin);
        printf("Diga o nome do cliente: \n");
        fgets(v[i].nome,51,stdin);
        printf("Digite a data de aniversario do cliente: \n");
        scanf("%d %d %d", &v[i].nasc.dia, &v[i].nasc.mes, &v[i].nasc.ano);
    }
}

/*------------------------*/

void escreve_cliente(CLIENTE *v, int n){

    int i;

    for(i=0;i<n;i++){
        printf("Nome: %s | Codigo: %d | Data de nascimento: %d/%d/%d\n", v[i].nome, v[i].codigo, v[i].nasc.dia, v[i].nasc.mes, v[i].nasc.ano);
        printf("\n");
    }
}

/*------------------------*/

int main(){

    CLIENTE v[N];
    DATA atual;
    int qtd_maiores;

    printf("Digite a data atual: \n");
    scanf("%d %d %d", &atual.dia, &atual.mes, &atual.ano);

    le_cliente(v, N);

    CLIENTE *maior_idade = maior_de_idade(v,N,atual,&qtd_maiores);

    if(maior_idade!=NULL){

        escreve_cliente(maior_idade, qtd_maiores);

        free(maior_idade);
    }else{
        printf("Nao tivemos maiores de idade.\n");
    }
}

