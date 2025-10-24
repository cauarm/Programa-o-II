#include <stdio.h>
#include <stdlib.h>

#define N 5

/*-----------------------*/

struct data{

    int dia, mes, ano;
};

typedef struct data DATA;

/*-----------------------*/

struct transacao{

    DATA data;
    float valor;
    char descricao[100];
};

typedef struct transacao TRANSACAO;

/*-----------------------*/

void escreve_trans(TRANSACAO *v, int n){

    printf("-------------------------------\n");
    int i;

    for(i=0;i<n;i++){
        printf("Data: %2d/%2d/%2d | Valor: %.2f | Descricao: %s\n", v[i].data.dia, v[i].data.mes, v[i].data.ano, v[i].valor, v[i].descricao);
        printf("\n");
    }
}

/*-----------------------*/

TRANSACAO *FiltroPorData(TRANSACAO *v, int n, DATA inicio, DATA fim, int *nt){

    TRANSACAO *seletos = (TRANSACAO *)malloc(n * sizeof(TRANSACAO));
    if(seletos==NULL){
        return NULL;
    }

    int inicial, final, atual;
    int i, k = 0;

    inicial = inicio.ano*10000+inicio.mes*100+inicio.dia;
    final = fim.ano*10000+fim.mes*100+fim.dia;

    for(i=0;i<n;i++){
        atual = v[i].data.ano*10000+v[i].data.mes*100+v[i].data.dia;

        if(atual>=inicial && atual<=final){
            seletos[k++] = v[i];
        }
    }

    *nt = k;
    seletos = (TRANSACAO *)realloc(seletos,k*sizeof(TRANSACAO));

    return seletos;
}

/*-----------------------*/

int main(){

    TRANSACAO transacoes[N] = {{{1, 10, 2024}, 10.0, "Pagamento de conta"},
		{{3, 10, 2024}, 30.0, "Transporte"},
		{{2, 10, 2024}, 20.0, "Compra de supermercado"},
		{{5, 10, 2024}, 50.0, "Lazer"},
		{{4, 10, 2024}, 40.0, "Jantar"}};
    DATA inicio={4, 10, 2024}, fim = {5, 10, 2024};
    int nt;

    escreve_trans(transacoes, N);

    TRANSACAO *seletos = FiltroPorData(transacoes,N,inicio,fim,&nt);

    if(seletos!=NULL){
        escreve_trans(seletos,nt);
        free(seletos);
    }else{
        printf("...");
    }
}