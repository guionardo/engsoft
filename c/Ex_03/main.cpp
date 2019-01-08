/*
Problema_03
Fazer um programa para:
a.	declarar variáveis a, b, c, d do tipo int.
b.	declarar variáveis e, f, g, h do tipo float.
c.	declarar vetor v de 10 elementos do tipo char.
d.	declarar variável x do tipo int.
e.	criar um ponteiro apontando para o endereço de a.
f.	incrementar o ponteiro, mostrando o conteúdo do endereço apontado (em forma de número). 
    Caso o endereço coincida com o endereço de alguma outra variável, informar o fato.
*/

#include "stdio.h"

int a, b, c, d;

// Apesar do enunciado, não faz sentido estas variáveis abaixo
//float e, f, g, h;
//char v[10];
int x;

int *ponteiro_a;

int main()
{
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    /*  e = 0.1;
    f = 0.2;
    g = 0.3;
    h = 0.5;*/

    printf("a = %d\n", a);
    ponteiro_a = &a;
    printf("Ponteiro de a = %p\n", ponteiro_a);
    ++ponteiro_a;
    printf("Ponteiro incrementado = %p\n", ponteiro_a);
    printf("Valor da variável posicionada no ponteiro: %d", *ponteiro_a);

    // Variável usada apenas para mostrar a alteração de posição em relação as variáveis declaradas
    char variavel;
    variavel = ' ';
    if (ponteiro_a == &b)
    {
        variavel = 'b';
    }
    else if (ponteiro_a == &c)
    {
        variavel = 'c';
    }
    else if (ponteiro_a == &d)
    {
        variavel = 'd';
    }

    if (variavel != ' ')
    {
        printf("Ponteiro aponta agora para %c\n", variavel);
    }
    else
    {
        printf("O ponteiro não mudou de posição\n");
        // Esse bloco nunca vai ser executado
    }

    return 0;
}
