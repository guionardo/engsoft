#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 5

struct tfila
{
    int dados[tamanho];
    int ini;
    int fim;
};

struct tfila fila;
int op;

void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    op = 1;
    fila.ini = 0;
    fila.fim = 0;
    while (op != 0)
    {
        system("cls");
        fila_mostrar();
        menu_mostrar();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fila_entrar();
            break;
        case 2:
            fila_sair();
            break;
        }
    }
    return 0;
};

void fila_entrar(){
    if (fila.fim==tamanho){
        printf("\nA fila está cheia, volte outro dia!\n\n");
        system("pause");
    } else {
        printf("\nDigite o valor a ser inserido: ");
        scanf("%d",&fila.dados[fila.fim]);
        fila.fim++;
    }
}

void fila_sair(){
    if (fila.ini==fila.fim){
        printf("\nFila vazia, mas logo aparece alguém!\n\n");
        system("pause");
    } else {
        int i;
        for(i=0;i<tamanho;i++){
            fila.dados[i]=fila.dados[i+1];
        }
        fila.dados[fila.fim]=0;
        fila.fim--;
    }
}

void fila_mostrar(){
    int i;
    printf("[  ");
    for(i=0;i<tamanho;i++)
    {
        printf("%d  ",fila.dados[i]);
    }
    printf("]\n\n");
}

void menu_mostrar(){
    printf("\nEscolha uma opção\n\n");
    printf("1 - Incluir na fila\n");
    printf("2 - Excluir da fila\n");
    printf("0 - Sair\n\n");
}