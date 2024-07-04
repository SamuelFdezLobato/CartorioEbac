#include <stdio.h>  // biblioteca de comunicacion com o usuario 
#include <stdlib.h> // biblioteca de aloçao de espacio de memoria 
#include <locale.h> // biblioteca de alocaçoes de texto por region 
#include <string.h> // biblioteca responsavel por cuidar das string

int registro () // funcao responsavel por cadastrar os usuarios no sistema
{
	// inicio de criacao de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criacao de variaveis/string
	
	printf("digite o cpf a ser cadastrado:  "); // coletando informacao do usuario 
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");

	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado:");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado!. \n");
	}
	
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas sao as informacoes do usuario: ");
			printf("%s",conteudo);
			printf("\n\n");
		}
		
		system("pause");
	
}

int deletar ()
{
	char cpf[40];
	
	printf("digite o cpf do usuario a ser deletado: ");
	scanf("%s",cpf);
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL)
	{
		printf("o usuario nao se encontra no sistema!.\n");
		system("pause");
	}
	
}
int main()
{
	int opcao=0;   // definindo variaveis
	int laco=1;
	for(laco=1;laco=1;)
	{
	
		system("cls"); // responsavel por limpar a tela 
		
		setlocale(LC_ALL, "Portuguese");  // definindo a linguagem
	
		printf("### Cartorio da EBAC ###\n\n"); // inicio do menu 
		printf ("Escolha a opçao desejada do menu: \n\n");
		printf("\t1 - registrar nomes \n");
		printf("\t2 - consultar nomes \n");
		printf("\t3 - deletar nomes \n\n"); 
		printf("opcao: ");  // fim do menu 
		scanf("%d",&opcao); //  armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao) //da selecao do menu
		{
			case 1:
			registro();	//chamada de funcoes
			break;
			
			case 2:
			consulta();
			break;
			
			
			case 3:
			deletar();
			break;
			
			
			
			default:
			printf("essa opçao nao esta disponivel\n");
			system("pause");
			break;
		}
	
	
	  }	
	}

