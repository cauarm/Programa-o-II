#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------*/

int *interseccao(int *x1, int *x2, int n1, int n2, int *qtd){

    int i,j,k,m;

    *qtd = 0;

    int ja_apareceu;

    for(i=0;i<n1;i++){

        ja_apareceu = 0;

        for(m=0;m<i && !ja_apareceu;m++){
            if(x1[m]==x1[i]){
                ja_apareceu = 1;
                break;
            }
        }

        if(!ja_apareceu){
            for(j=0;j<n2 && !ja_apareceu;j++){
                if(x1[i]==x2[j]){
                    ja_apareceu = 1;
                    (*qtd)++;
                }
            }
        }
    }

    int *x3 = (int *) malloc((*qtd) * sizeof(int));
    if(x3==NULL){
        return NULL;
    }

    k= 0;

    for(i=0;i<n1;i++){

        ja_apareceu = 0;

        for(m=0;m<k && !ja_apareceu;m++){
            if(x3[m]==x1[i]){
                ja_apareceu = 1;
                break;
            }
        }

        if(!ja_apareceu){
            for(j=0;j<n2 && !ja_apareceu;j++){
                if(x1[i]==x2[j]){
                    ja_apareceu = 1;
                    x3[k++] = x1[i];
                }
            }
        }
    }

    return x3;
}

/*---------------------------------------*/

void escreve(int *vet, int n){

    int i;

    printf("------ INTERSECCAO ------ \n");

    for(i=0;i<n;i++){
        printf(" %d ", vet[i]);
    }

    printf("\n");
}
/*---------------------------------------*/

int main(){

    int x1[5] = {1,3,5,6,7};
    int x2[5] = {1,3,4,6,8};
    int qtd;

    int *x3 = interseccao(x1,x2,5,5,&qtd);

    if(x3!=NULL){
        escreve(x3, qtd);

        free(x3);
    }else{
        printf("ERRO DE MEMORIA.");
    }

    return 0;
}