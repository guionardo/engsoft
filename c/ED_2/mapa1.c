// MAPA Estrutura de dados 2
// Autor: Guionardo Furlan
// Versão: 1.0 - 24/05/2018
// Código disponível em https://github.com/guionardo/engsoft_c/tree/master/ED_2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Estrutura para registro do nodo
struct Elemento
{
    int Id;         // Indice do elemento
    int Valor;      // Valor do elemento
    char Dado[1];   // Dado do elemento (número ou operação matemática)
    int Processado; // Flag indicativa que o nó já foi processado e seu valor foi calculado

    struct Elemento *nEsquerdo; // Nó esquerdo
    struct Elemento *nDireito;  // Nó direito
    struct Elemento *nPai;      // Nó pai (usado apenas para controlar o nível)
    int Nivel;
};

//
// Elemento raiz da árvore binária
struct Elemento *Raiz = NULL;

// Número de elementos da árvore
int nElementos = 0;

// Nível (usada para identação dos resultados de cálculos na função ValorNo)
int nNivel = 0;

//
// Função para criação de um nodo
struct Elemento *CriaNodo(char *Dado, struct Elemento *Pai)
{

    struct Elemento *elm = malloc(sizeof(struct Elemento));
    if (elm == NULL)
    {
        printf("ERRO NA ALOCAÇÃO DE MEMÓRIA!\n");
        return NULL;
    }
    nElementos++;
    elm->Id = nElementos;
    elm->Valor = 0;
    strcpy(elm->Dado, " ");
    elm->Dado[0] = Dado[0];
    elm->Processado = 0;
    elm->nEsquerdo = NULL;
    elm->nDireito = NULL;
    elm->nPai = Pai;
    elm->Nivel = 0;

    printf("Nodo #%d [%s] ", elm->Id, elm->Dado);
    if (Pai == NULL)
    {
        printf("(RAIZ)\n");
        elm->Nivel = 1;
    }
    else
    {
        printf("(Pai = %d)\n", Pai->Id);
        elm->Nivel = Pai->Nivel + 1;
    }

    return elm;
}

//
// Método para liberação dos ponteiros criados
void LiberaPonteiros(struct Elemento *no)
{
    if (no == NULL)
    {
        return;
    }
    //printf("%p ", no);
    if (no->nEsquerdo != NULL)
    {
        LiberaPonteiros(no->nEsquerdo);
        no->nEsquerdo = NULL;
    }
    if (no->nDireito != NULL)
    {
        LiberaPonteiros(no->nDireito);
        no->nDireito = NULL;
    }
    free(no);
}

//
// Método para montagem da árvore binária
void MontaArvore()
{
    printf("# Montando arvore...\n");
    nElementos = 0;
    Raiz = CriaNodo("+", NULL);
    Raiz->nEsquerdo = CriaNodo("*", Raiz);
    Raiz->nDireito = CriaNodo("5", Raiz);
    Raiz->nEsquerdo->nEsquerdo = CriaNodo("-", Raiz->nEsquerdo);
    Raiz->nEsquerdo->nDireito = CriaNodo("+", Raiz->nEsquerdo);
    Raiz->nEsquerdo->nEsquerdo->nEsquerdo = CriaNodo("6", Raiz->nEsquerdo->nEsquerdo);
    Raiz->nEsquerdo->nEsquerdo->nDireito = CriaNodo("3", Raiz->nEsquerdo->nEsquerdo);
    Raiz->nEsquerdo->nDireito->nEsquerdo = CriaNodo("4", Raiz->nEsquerdo->nDireito);
    Raiz->nEsquerdo->nDireito->nDireito = CriaNodo("1", Raiz->nEsquerdo->nDireito);

    printf("%d elementos criados\n\n", nElementos);
}

//
// Função para cálculo do valor do nodo, com uso de recursividade para percorrer a árvore binária
int ValorNo(struct Elemento *no)
{
    if (no == NULL)
    {
        return 0;
    }

    printf("%*sNodo %d [%s] ", nNivel * 2, "", no->Id, no->Dado);
    if (no->Processado == 0)
    {
        short n = (short)no->Dado[0];
        printf("(%d) ", n);
        // Testa de o dado do nó é um número
        if (n >= 48 && n <= 57) // 48 = 0, 57 = 9 na tabela ASCII
        {
            no->Valor = (short)no->Dado[0] - 48;
            no->Processado = 1;
            printf("Valor = %d\n", no->Valor);
        }
        else
        {
            printf("\n");
            nNivel++;
            // Obtém o valor dos nodos filhos, recursivamente
            int valorEsquerdo = ValorNo(no->nEsquerdo);
            int valorDireito = ValorNo(no->nDireito);
            nNivel--;
            // Verifica a operação matemática e efetua o cálculo
            switch (n)
            {
            case 43: // '+':
                no->Valor = valorEsquerdo + valorDireito;
                no->Processado = 1;
                printf("Valor (Nodo %d) = %d + %d = %d\n", no->Id, valorEsquerdo, valorDireito, no->Valor);
                break;
            case 45: //'-':
                no->Valor = valorEsquerdo - valorDireito;
                no->Processado = 1;
                printf("Valor (Nodo %d) = %d - %d = %d\n", no->Id, valorEsquerdo, valorDireito, no->Valor);
                break;
            case 42: //'*':
                no->Valor = valorEsquerdo * valorDireito;
                no->Processado = 1;
                printf("Valor (Nodo %d) = %d * %d = %d\n", no->Id, valorEsquerdo, valorDireito, no->Valor);
                break;
            case 47: // '/':
                if (valorDireito != 0)
                {
                    no->Valor = valorEsquerdo / valorDireito;
                }
                else
                {
                    no->Valor = 0;
                }
                printf("Valor (Nodo %d) = %d / %d = %d\n", no->Id, valorEsquerdo, valorDireito, no->Valor);
                no->Processado = 1;
                break;
            default:
                printf("ERRO DADO INVALIDO [%s]\n", no->Dado[0]);
                break;
            }
        }
    }
    else
    {
        printf("Nodo previamente processado. Valor = %d\n", no->Valor);
    }
    return no->Valor;
}

//
// Método principal
int main()
{
    printf("**********************************************************\n");
    printf("* CALCULO DE EXPRESSOES MATEMATICAS COM ARVORES BINARIAS *\n");
    printf("* UNICESUMAR - ESOFT - ESTRUTURAS DE DADOS II            *\n");
    printf("* ALUNO: GUIONARDO FURLAN                   RA:1650466-5 *\n");
    printf("**********************************************************\n");
    MontaArvore();
    printf("# Calculando...\n\n");
    int Calculo = ValorNo(Raiz);
    printf("\n# Resultado: %d\n\n", Calculo);
    LiberaPonteiros(Raiz);
    return Calculo;
}
