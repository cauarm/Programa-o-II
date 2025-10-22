#include <stdio.h>
#include <stdlib.h>

#define N 5

/*---------------------*/

int *uniao(int *x1, int *x2, int n1, int n2, int *qtd){

    int t = n1+n2;

    int *x3 = (int *)malloc(t * sizeof(int));
    if(x3==NULL){
        return NULL;
    }

    int i,j,m,k,ja_existe;

    k = 0;

    for(i=0;i<n1;i++){

        ja_existe = 0;

        for(m=0;m<k && !ja_existe;m++){
            if(x3[m]==x1[i]){
                ja_existe = 1;
                break;
            }
        }

        if(!ja_existe){
            x3[k++] = x1[i];
        }
    }

    for(j=0;j<n2;j++){

        ja_existe = 0;

        for(m=0;m<k && !ja_existe;m++){
            if(x3[m]==x2[j]){
                ja_existe = 1;
                break;
            }
        }

        if(!ja_existe){
            x3[k++] = x2[j];
        }
    }

    x3 = (int *)realloc(x3,k*sizeof(int));
    *qtd = k;

    return x3;
}

/*---------------------*/

void escreve(int *v, int n){

    int i;

    printf("---- UNIAO ----\n");
    for(i=0;i<n;i++){
        printf(" %d ", v[i]);
    }
}

/*---------------------*/

int main(){

    int x1[N] = {1,3,5,6,7};
    int x2[N] = {1,3,4,6,8};
    int qtd;

    int *x3 = uniao(x1,x2,N,N,&qtd);

    if(x3!=NULL){
        escreve(x3, qtd);

        free(x3);
    }else{
        printf("ERRO DE MEMORIA.");
    }
}
