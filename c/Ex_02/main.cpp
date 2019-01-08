/*
Faça uma função que recebe, por parâmetro, a hora de inicio e a hora de 
término de um jogo, ambas subdivididas em 2 valores distintos: horas e minutos. 
A função deve retornar, a duração do jogo em minutos, 
considerando que o tempo máximo de duração de um jogo é de 24 horas 
e que o jogo pode começar em um dia e terminar no outro.
*/
#include "stdio.h"

bool Entrada(int *hora, int *minuto)
{
    printf("Hora (hh:mm): ");
    char sh[5];
    scanf("%s", sh);
    int h, m;
    h = (int)(sh[0] - '0') * 10 + (int)(sh[1] - '0');
    m = (int)(sh[3] - '0') * 10 + (int)(sh[4] - '0');
    if (h < 0 || h > 23)
    {
        printf("ERRO: Hora deve estar entre 0 e 23!\n");
        return false;
    }
    if (m < 0 || m > 59)
    {
        printf("ERRO: Minuto deve estar entre 0 e 59!\n");
        return false;
    }
    *hora = h;
    *minuto = m;
    return true;
}

int main()
{
    int h1 = 0, m1 = 0, h2 = 0, m2 = 0;
    if (!Entrada(&h1, &m1))
    {
        return 0;
    }
    if (!Entrada(&h2, &m2))
    {
        return 0;
    }
    int minutos1 = h1 * 60 + m1;
    int minutos2 = h2 * 60 + m2;
    int totalMinutos = 0;
    if (minutos1 > minutos2)
    {
        totalMinutos = (24 * 60) - minutos1 + minutos2;
    }
    else
    {
        totalMinutos = minutos2 - minutos1;
    }
    int tHora, tMinuto;
    tMinuto = totalMinutos % 60;
    tHora = (totalMinutos - tMinuto) / 60;
    printf("Duração do jogo = %d minutos = %d:%d\n", totalMinutos, tHora, tMinuto);

    return 0;
}