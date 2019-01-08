#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Constantes
#define tamanho 5

// Estrutura da pilha
struct tpilha{
    int dados[tamanho];
    int ini;
    int fim;
};

// Variáveis globais
struct tpilha pilha;
int op;

// Prototipação
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();

// Função principal
int main(){
    setlocale(LC_ALL,"Portuguese");
    op=1;
    pilha.ini = 0;
    pilha.fim = 0;
    while (op!=0){
        system("CLS");
        pilha_mostrar();
        menu_mostrar();
        scanf("%d",&op);
        switch(op){
            case 1:
            pilha_entrar();
            break;
            case 2:
            pilha_sair();
            break;            
        }
    }
    return 0;
}

// Adicionar um elemento no final da pilha
void pilha_entrar(){
    if (pilha.fim==tamanho)
    {
        printf("\nA pilha está cheia, impossível empilhar!\n\n");
        system("pause");
    } else {
        printf("\nDigite o valor a ser empilhado: ");
        scanf("%d",&pilha.dados[pilha.fim]);
        pilha.fim++;
    }
}

// Retirar o último elemento da pilha
void pilha_sair(){
if(pilha.ini==pilha.fim){
    printf("\nA pilha está vazia, impossível desempilhar!\n\n");
    system("pause");
} else {
    pilha.dados[pilha.fim-1]=0;
    pilha.fim--;
}
}

// Mostrar o conteúdo da pilha
void pilha_mostrar(){
    int i;
    printf("[  ");
    for(i=0;i<tamanho;i++){
        printf("%d  ",pilha.dados[i]);
    }
    printf("]\n\n");
}

// Mostrar o menu de opções
void menu_mostrar(){
printf("\nEscolha uma opção:\n");
printf("1 - Incluir na pilha\n");
printf("2 - Excluir da pilha\n");
printf("0 - Sair\n\n");
}
