#include <stdio.h>

#define N 100

/*----------------------------------------*/

struct letra{

    char letra;
    int ocorrencias;
};

typedef struct letra LETRA;

/*------------------------------------------*/

void caracteres_mais_frequentes(char str[N], LETRA *mais, LETRA *segundo_mais){

    int i;
    int contagem[26] = {0};

    for(i=0;str[i]!='\0';i++){
        if(str[i]>='a' && str[i]<='z'){
            int index = str[i] - 'a';
            contagem[index]++; 
        }
    }

    mais->letra = 'a';
    mais->ocorrencias = 0;
    segundo_mais->letra = 'a';
    segundo_mais->ocorrencias = 0;

    for(i=0;i<26;i++){
        char letra_atual = 'a' + i;
        int freq_atual = contagem[i];

        if(freq_atual>mais->ocorrencias){
            *segundo_mais = *mais;
            mais->letra = letra_atual;
            mais->ocorrencias = freq_atual;
        }else if(freq_atual==mais->ocorrencias && letra_atual<mais->letra){
            *segundo_mais = *mais;
            mais->letra = letra_atual;
            mais->ocorrencias = freq_atual;
        }else if(freq_atual > segundo_mais->ocorrencias){
            segundo_mais->letra = letra_atual;
            segundo_mais->ocorrencias = freq_atual;
        }else if(freq_atual==segundo_mais->ocorrencias && letra_atual<segundo_mais->letra){
            segundo_mais->letra = letra_atual;
            segundo_mais->ocorrencias = freq_atual;
        }
    }
}

/*----------------------------------------------*/

int main(){
    char str[N] = "aabbbccde";
    LETRA mais, segundo_mais;

    caracteres_mais_frequentes(str, &mais, &segundo_mais);

    printf("Letra que mais aparece: %c (%d vezes) | Segundo letra: %c (%d vezes) \n",mais.letra, mais.ocorrencias, segundo_mais.letra, segundo_mais.ocorrencias);
}