#define _POSIX_C_SOURCE 200809L

#include <inttypes.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

/*
Exercício 05 - Recursão e performance

1. Escreva um programa em C para calcular a SOMA de números de 1 até N.
2. O número deve ser informado pelo usuário e deve ser validado dentro da variação 1 a 100000.
3. Se o número não for válido, deve ser apresentada uma mensagem ao usuário e sair do programa.
4. Crie uma função para efetuar o cálculo usando um laço de repetição simples.
5. Crie uma função para efetuar o cálculo usando recursão.
6. Efetue o cálculo com as duas funções, registrando o tempo de execução de cada função.
7. Apresente o valor da soma
8. Apresente o tempo de execução de cada função.
*/

#define maximo 100000

// Armazena o tempo inical do cronômetro
long tempoInicial;

// Obtém o tempo atual em milisegundos
long TimeStamp()
{
    struct timespec spec;

    clock_gettime(CLOCK_REALTIME, &spec);

    return round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds
}

void IniciaCronometro()
{
    tempoInicial = TimeStamp();
}

void TerminaCronometro()
{
    printf("Tempo = %lu ms\n", (TimeStamp() - tempoInicial));
}

unsigned long Soma(int n)
{
    long r = 0;
    for (int i = 1; i <= n; i++)
    {
        r += i;
    }
    return r;
}

unsigned long SomaRecursao(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + SomaRecursao(n - 1);
}

int main()
{
    int numero = 0;
    printf("Digite um numero entre 1 e %d:", maximo);
    scanf("%d", &numero);
    if (numero < 1 || numero > maximo)
    {
        printf("Numero invalido!\n");
        return 0;
    }

    unsigned long resultado;
    IniciaCronometro();
    resultado = Soma(numero);

    TerminaCronometro();
    printf("Soma Simples: %lu\n", resultado);

    IniciaCronometro();
    resultado = SomaRecursao(numero);
    TerminaCronometro();
    printf("Soma por Recursão: %lu\n", resultado);

    return 0;
}
