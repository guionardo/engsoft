/*
Problema 01

   Um pecuarista possui uma determinada quantia de bois, que possuem um identificador
   numérico (de 1 a n) cada um. 
   
   Faça um programa que: 

a.	receba o peso de cada boi, um por vez, e o armazene em um vetor. 
    Se o peso digitado for 0 significa que não há mais bois a serem digitados; 

b.	mostre a lista de todos os bois com seus identificadores e também os 
    identificadores do boi mais gordo e do boi mais magro. 
    Se houver dois ou mais bois mais gordos ou mais magros mostrar o de 
    menor identificador; 

c.	Faça o mesmo programa considerando que o número de bois é fixo e igual a dez.
*/
#include "stdio.h"
#define numeroBois 10

float pesos[numeroBois];
float menorPeso = 999999999,
      maiorPeso = 0;
int indiceMenorPeso,
    indiceMaiorPeso;

int main()
{
    int i;
    float p;
    bool naoPerguntaMais = false;

    for (i = 0; i < numeroBois; i++)
    {
        pesos[i] = 0;
        if (naoPerguntaMais)
        {
            continue;
        }
        printf("Boi #%d = ", (i + 1));
        scanf("%f", &p);
        if (p <= 0)
        {
            naoPerguntaMais = true;
            continue;
        }
        pesos[i] = p;
        if (p < menorPeso)
        {
            menorPeso = p;
            indiceMenorPeso = i;
        }

        if (p > maiorPeso)
        {
            maiorPeso = p;
            indiceMaiorPeso = i;
        }
    }

    printf("\nLista de bois\n\n");

    for (i = 0; i < numeroBois; i++)
    {
        if (pesos[i] == 0)
        {
            continue;
        }
        printf("Boi #%d = %f %s\n", (i + 1), pesos[i], (i == indiceMenorPeso ? "[MENOR]" : i == indiceMaiorPeso ? "[MAIOR]" : ""));
    }
    return 0;
}