#include <stdio.h> //biblioteca de comunuca�ao com o usuario
#include <stdlib.h> //biblioteca de aloca�ao de memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao 
#include <string.h> // biblioteca responsavel por cuidar das string

int main() //fun�ao principal (todo codigo em C precisa de uma fun�ao principal)
{
	int opcao=0; //definindo variavel
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls"); //limpa tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
		
		printf("\t### CART�RIO EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o no menu:\n\n");
		printf("\t1 - Registar usu�rio\n");
		printf("\t2 - Consultar usu�rio\n");
		printf("\t3 - Deletar usu�rio\n");
		printf("\t4 - Sair do sistema\n\n");	
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //escolha do usuario
		
		system("cls"); //limpa tela
		
		switch(opcao) //inicio da selecao de opcoes 
		{
			case 1:
			registro(); //chama fun�ao registro
			break;
			
			case 2:
			consulta(); //chama fun�ao consulta
			break;
			
			case 3:
			deletar(); //chama fun�ao deletar
			break;
			
			case 4:
			printf("At� logo!\n\n");
			return 0;
			break;
			
			default:
				printf("\tOp��o inv�lida!\n\n");
				system("pause");
			break;		
		} //fim da selecao de opcoes 
	}
}

int registro() //fun��o de registro
{
	//criacao de variaveis/string
	char arquivo [40];
	char cpf[40];
	char nome[50];
	char sobrenome [50];
	char cargo [50];
	//fim da criacao de variaveis
	
	printf("\tRegistrar usu�rio\n\n");
	
	printf("Digite o CPF: "); //coletando informacao do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); //criar arquivo e "w" usado para escrever
	fprintf(file, cpf); //registra o valor da variavel no arquivo
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); // "a" usado para atualizar o arquivo ja criado
	fprintf(file, ", "); //insere "," ao fim do ultimo dado registrado no arquivo 
	fclose(file);
	
	printf("Digite o nome: "); //coletando informacao do usuario
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome); //registrando dado "nome" no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", "); //insere "," ao fim do ultimo dado registrado no arquivo
	fclose(file);
	
	printf("Digite o sobrenome: "); //coletando informacao do usuario
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome); //registrando dado "sobrenome" no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", "); //insere "," ao fim do ultimo dado registrado no arquivo
	fclose(file);
	
	printf("Digite o cargo: "); //coletando informacao do usuario
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo); //registrando dado "cargo" no arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", "); //insere "," ao fim do ultimo dado registrado no arquivo
	fclose(file);
	
	printf("\n");
	
	system("pause");
}

int consulta() //fun��o de consulta
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; //criacoo de variaveis
	char conteudo[200];
	
	printf("\tConsultar usu�rio\n\n");
	
	printf("Digite o CPF do usu�rio: "); //coletando informacao do usuario
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //tenta abrir o arquivo, "r" serve para ler arquivos
	
	if(file == NULL) //se o arquivo nao existir mostra na tela o texto abaixo
	{
		printf("\n");
		printf("Usu�rio n�o encontrado.\n");
		printf("\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //se o arquivo existir mostra na tela os dados contidos nesse arquivo
	{
		printf("\nDados do usu�rio:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //fecha o arquivo (sempre que um arquivo for aberto, � essencial usar a fun�ao fclose(file) para fecha-lo depois)	
	system("pause");
}

int deletar() //fun��o de deletar
{
	char cpf[40];
	
	printf("\tDeletar usu�rio\n\n");
	
	printf("Digite o CPF do usu�rio: "); //coletando informacao do usuario
	scanf("%s", cpf);
			
	FILE *file;
	file = fopen(cpf, "r"); //tenta abrir e ler o arquivo
	
	if(file == NULL) //se o arquivo nao existir mostra na tela o texto abaixo
	{
		printf("\nUsu�rio n�o localizado.\n\n");
	}
	else //se o arquivo exixtir
	{
		fclose(file); //fecha o arquivo
		remove (cpf); //exclui o arquivo
		printf("\nUsu�rio deletado com sucesso!\n\n"); //mostra esse texto na tela
	}

	system("pause");
}
