#include <stdio.h>
#include <stdlib.h>

#define N 3

/*-------------------------*/

struct data{

    int dia, mes, ano;
};

typedef struct data DATA;

/*-------------------------*/

struct cliente{

    int codigo;
    char nome[51];
    DATA nasc;
};

typedef struct cliente CLIENTE;

/*-------------------------*/

CLIENTE *maiores_de_idade(CLIENTE *v, int num_clientes, DATA atual, int *qtd_maiores){

    CLIENTE *maiores = (CLIENTE *)malloc(num_clientes * sizeof(CLIENTE));
    if(maiores==NULL){
        return NULL;
    }

    *qtd_maiores = 0;

    int k = 0, tem_maior = 0, i;

    for(i=0;i<num_clientes;i++){

        int idade = atual.ano - v[i].nasc.ano;

        if(atual.mes<v[i].nasc.mes || (atual.mes==v[i].nasc.mes) && atual.dia<v[i].nasc.dia){
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

/*-------------------------*/

void le_cliente(CLIENTE *v, int num_clientes){

    int i;

    for(i=0;i<num_clientes;i++){
        printf("Digite o codigo do cliente: \n");
        scanf("%d", &v[i].codigo);
        fflush(stdin);
        printf("Digite o nome do cliente: \n");
        fgets(v[i].nome, 51, stdin);
        printf("Digite a data de aniversario do cliente: \n");
        scanf("%d %d %d", &v[i].nasc.dia, &v[i].nasc.mes, &v[i].nasc.ano);
}
}

/*-------------------------*/

void escreve_clientes(CLIENTE *v, int num_clientes){

    int i;

    for(i=0;i<num_clientes;i++){

        printf("Nome: %s | Codigo: %d | Data de Aniversario: %d/%d/%d", v[i].nome, v[i].codigo, v[i].nasc.dia, v[i].nasc.mes, v[i].nasc.ano);

        printf("\n");
    }
}

/*-------------------------*/

int main(){

    CLIENTE v[N];
    int qtd_maiores;
    DATA atual;

    printf("Digite a data atual: \n");
    scanf("%d %d %d", &atual.dia, &atual.mes, &atual.ano);

    le_cliente(v, N);

    CLIENTE *maiores = maiores_de_idade(v, N, atual, &qtd_maiores);

    if(maiores!=NULL){
        escreve_clientes(maiores, qtd_maiores);

        free(maiores);
    }else{
        printf("Nao havia nenhum maior de idade. \n");
    }
    
}