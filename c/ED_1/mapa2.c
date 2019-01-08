// Atividade MAPA para a disciplina Estrutura de Dados 1
// Segunda versão, usando fila
// Aluno: Guionardo Furlan
// Curso: Engenharia de Software - Unicesumar - 2018
/*
José é o proprietário de um açougue em sua cidade, o estabelecimento possui um grande fluxo de pessoas.
José não está conseguindo controlar a fila de clientes que está se formando para o atendimento,
muitos dos clientes estão reclamando que não está sendo respeitado a ordem de chegada para serem atendidos.
Sendo assim José solicitou a você um software que resolva o problema.


Depois de uma análise foi definido que o software deverá ter duas funcionalidades:
- Retirar uma senha para o atendimento.
- Chamada da próxima senha no painel para atendimento.

Com base nestas informações, você deverá desenvolver um programa em linguagem C que atenda as funcionalidades:
- Retirada de nova senha pelo cliente.
- Atendente chamar o próximo número da fila.
- Sair

Funcionalidade e restrições do programa:
- A cada nova iteração deve-se apresentar na tela a composição da fila.
- Ao ser chamado um número para atendimento, no painel deve-se apresentar a senha anterior, atual e a próxima.
- A funcionalidade Sair, só poderá ser executada se a todas as senhas de atendimento já foram chamadas.
- A fila deve ter no máximo 10 pessoas, caso a fila esteja completa apresentar uma mensagem que “A fila já está completa, tente novamente mais tarde.”
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanhoFila 10

// Próxima senha a ser chamada
int senhaAtual = 0;

// Mensagem para ser apresentada
char mensagem[40];

struct Fila {
	int numeros[tamanhoFila];	// vetor para conter a fila
	int tamanho;				// número de senhas na fila
	int ultimo;					// última senha adicionada
};

struct Fila fila;

void InicializarFila(){
	for(int i=0;i<tamanhoFila;i++){
		fila.numeros[i] = 0;		
	}
	fila.tamanho = 0;
	fila.ultimo = 0;
}

// Adiciona uma senha a fila
// Retorna o número da senha em caso de sucesso, ou 0 em caso de fila completa
int pushSenha(){
	if (fila.tamanho == tamanhoFila) {
		strcpy(mensagem, "A fila ja esta completa, tente novamente mais tarde.");		
		return 0;
	} else {
		fila.numeros[fila.tamanho] = fila.ultimo + 1;
		fila.ultimo++;
		fila.tamanho++;
		return fila.ultimo;
	}
}

// Retorna a próxima senha da fila
// 0 se a fila estiver vazia
int popSenha(){
	if (fila.tamanho == 0) {
		strcpy(mensagem, "A fila esta vazia");
		return 0;
	} else {
		senhaAtual = fila.numeros[0];
		// reloca as senhas
		for(int i=0;i<tamanhoFila-1;i++){
			fila.numeros[i] = fila.numeros[i+1];
		}
		fila.numeros[tamanhoFila-1]=0;
		fila.tamanho--;		
		return senhaAtual;
	}
}

void mostrarFila()
{

printf("DBG: ");
for(int i=0;i<tamanhoFila;i++){
	printf("%03d ",fila.numeros[i]);
}
printf("\n");

	printf("[Anterior] [Atual] [Proxima]\n");

	if (senhaAtual > 1)
	{
		printf("    %03d   ", senhaAtual-1);
	}
	else
	{
		if (fila.tamanho==0 && fila.ultimo>0){
			printf("    %03d   ", fila.ultimo);
		} else {
				printf("          ");
						}
	}

	if (senhaAtual > 0)
	{
		printf("   %03d   ", senhaAtual);
	}
	else
	{
		printf("         ");
	}

	if (fila.numeros[1] > 0)
	{
		printf("   %03d   ", fila.numeros[1]);
	}
	else
	{
		printf("         ");
	}

	for (int i = (senhaAtual==0?1:2); i < tamanhoFila; i++)
	{
		if (fila.numeros[i]>0){
			printf("  %03d", fila.numeros[i]);			
		}		
	}
	printf("\n%s\n\n", mensagem);
}

int main(int argc, char *argv[])
{
	int opcao = 1;	
	while (opcao != 0)
	{
		system("CLS");		
		printf("****************************************\n");
		printf("* SISTEMA DE SENHAS DO ACOUGUE DO JOSE *\n");
		printf("****************************************\n");

		mostrarFila();

		printf("1. Retirar uma senha para o atendimento\n");
		
		if (fila.numeros[1] > 0)		
		{
			printf("2. Chamada da proxima senha\n");
		}
		if (fila.tamanho == 0) {
			printf("0. SAIR\n");	
		}
		

		scanf("%d", &opcao);
		switch (opcao)
		{
		case 1:
			pushSenha();
			//pedirSenha();
			break;
		case 2:
			popSenha();
			//chamarCliente();
			break;
		case 0:
			
			if (fila.tamanho>0)
			{
				strcpy(mensagem, "Ainda existem clientes na fila");
			//	opcao = -1;
			}
			break;
		}
	}

	return 0;
}
