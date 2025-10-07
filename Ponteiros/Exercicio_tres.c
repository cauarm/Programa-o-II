#include <stdio.h>

/*---------------------------------------------*/

void calc_hora(int h1, int m1, int minutos_somados, int *h2, int *m2){

    int minutos_totais = (h1 * 60 + m1 + minutos_somados) % 1440;

    *h2 = minutos_totais/60;
    *m2 = minutos_totais%60;
}

/*---------------------------------------------*/

int main(){

    int h1,m1,minutos_somados;
    int h2, m2;

    printf("Digite um horario (com hora e minuto): ");
    scanf("%d %d", &h1, &m1);

    printf("Digite a quantidade de minutos a ser somado: ");
    scanf("%d", &minutos_somados);

    calc_hora(h1,m1,minutos_somados,&h2,&m2);

    printf("O horário informado mais os minutos: %d:%d + %d minutos\n", h1,m1,minutos_somados);
    printf("Horário atualizado: %d:%d\n", h2,m2);
}