/*
Curso: Engenharia de Software
Disciplina: Estrutura de Dados 1 ()
Atividade MAPA de Estrutura de Dados 1
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
int proximaSenha = 1;

// Última senha gerada
int ultimaSenha = 0;

// Mensagem para ser apresentada
char mensagem[40];

void mostrarFila()
{

	printf("[Anterior] [Atual] [Proxima]\n");

	if (proximaSenha > 2)
	{
		printf("    %03d   ", proximaSenha - 2);
	}
	else
	{
		printf("          ");
	}

	if (proximaSenha > 1)
	{
		printf("   %03d   ", proximaSenha - 1);
	}
	else
	{
		printf("         ");
	}

	if (proximaSenha <= ultimaSenha)
	{
		printf("   %03d   ", proximaSenha);
	}
	else
	{
		printf("         ");
	}

	for (int i = proximaSenha + 1; i <= ultimaSenha; i++)
	{
		printf("  %03d", i);
	}
	printf("\n%s\n\n", mensagem);
}

void pedirSenha()
{
	if (ultimaSenha - proximaSenha + 1 < tamanhoFila)
	{
		ultimaSenha++;
		strcpy(mensagem, "");
	}
	else
	{
		strcpy(mensagem, "A fila ja esta completa, tente novamente mais tarde.");
	}
}

void chamarCliente()
{
	if (proximaSenha <= ultimaSenha)
	{
		strcpy(mensagem, "");

		proximaSenha++;
	}
	else
	{
		strcpy(mensagem, "A fila esta vazia");
	}
}

int main(int argc, char *argv[])
{
	int opcao = 1;
	proximaSenha = 1;
	ultimaSenha = 0;
	while (opcao != 0)
	{
		system("CLS");		
		printf("****************************************\n");
		printf("* SISTEMA DE SENHAS DO ACOUGUE DO JOSE *\n");
		printf("****************************************\n");

		mostrarFila();

		printf("1. Retirar uma senha para o atendimento\n");
		if (proximaSenha <= ultimaSenha)
		{
			printf("2. Chamada da proxima senha\n");
		}
		printf("0. SAIR\n");

		scanf("%d", &opcao);
		switch (opcao)
		{
		case 1:
			pedirSenha();
			break;
		case 2:
			chamarCliente();
			break;
		case 0:
			if (proximaSenha <= ultimaSenha)
			{
				strcpy(mensagem, "Ainda existem clientes na fila");
				opcao = -1;
			}
			break;
		}
	}

	return 0;
}
