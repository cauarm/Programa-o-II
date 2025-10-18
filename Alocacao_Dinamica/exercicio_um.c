#include <stdio.h>
#include <stdlib.h>

/*----------------------------------*/

char *gerastr(int n, char c){

    char *str = (char *)malloc(n+1*sizeof(char));

    if(str==NULL){
        return NULL;
    }


    int i;

    for(i=0;i<n;i++){
        str[i] = c;
    }

    str[i] = '\0';

    return str;
}

/*----------------------------------*/

int main(){

    int n;
    char c;

    printf("Digite o caractere desejado: \n");
    scanf("%c", &c);

    printf("Digite quantas vezes deseja que ele seja repetido: \n");
    scanf("%d", &n);

    char *resultado = gerastr(n,c);

    printf("%s\n", resultado);

    return 0;
}