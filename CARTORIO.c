#include <stdio.h> //biblioteca de comunucaçao com o usuario
#include <stdlib.h> //biblioteca de alocaçao de memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao 
#include <string.h> // biblioteca responsavel por cuidar das string

int main() //funçao principal (todo codigo em C precisa de uma funçao principal)
{
	int opcao=0; //definindo variavel
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls"); //limpa tela
	
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem 
		
		printf("\t### CARTÓRIO EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção no menu:\n\n");
		printf("\t1 - Registar usuário\n");
		printf("\t2 - Consultar usuário\n");
		printf("\t3 - Deletar usuário\n");
		printf("\t4 - Sair do sistema\n\n");	
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //escolha do usuario
		
		system("cls"); //limpa tela
		
		switch(opcao) //inicio da selecao de opcoes 
		{
			case 1:
			registro(); //chama funçao registro
			break;
			
			case 2:
			consulta(); //chama funçao consulta
			break;
			
			case 3:
			deletar(); //chama funçao deletar
			break;
			
			case 4:
			printf("Até logo!\n\n");
			return 0;
			break;
			
			default:
				printf("\tOpção inválida!\n\n");
				system("pause");
			break;		
		} //fim da selecao de opcoes 
	}
}

int registro() //função de registro
{
	//criacao de variaveis/string
	char arquivo [40];
	char cpf[40];
	char nome[50];
	char sobrenome [50];
	char cargo [50];
	//fim da criacao de variaveis
	
	printf("\tRegistrar usuário\n\n");
	
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

int consulta() //função de consulta
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; //criacoo de variaveis
	char conteudo[200];
	
	printf("\tConsultar usuário\n\n");
	
	printf("Digite o CPF do usuário: "); //coletando informacao do usuario
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //tenta abrir o arquivo, "r" serve para ler arquivos
	
	if(file == NULL) //se o arquivo nao existir mostra na tela o texto abaixo
	{
		printf("\n");
		printf("Usuário não encontrado.\n");
		printf("\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL) //se o arquivo existir mostra na tela os dados contidos nesse arquivo
	{
		printf("\nDados do usuário:\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file); //fecha o arquivo (sempre que um arquivo for aberto, é essencial usar a funçao fclose(file) para fecha-lo depois)	
	system("pause");
}

int deletar() //função de deletar
{
	char cpf[40];
	
	printf("\tDeletar usuário\n\n");
	
	printf("Digite o CPF do usuário: "); //coletando informacao do usuario
	scanf("%s", cpf);
			
	FILE *file;
	file = fopen(cpf, "r"); //tenta abrir e ler o arquivo
	
	if(file == NULL) //se o arquivo nao existir mostra na tela o texto abaixo
	{
		printf("\nUsuário não localizado.\n\n");
	}
	else //se o arquivo exixtir
	{
		fclose(file); //fecha o arquivo
		remove (cpf); //exclui o arquivo
		printf("\nUsuário deletado com sucesso!\n\n"); //mostra esse texto na tela
	}

	system("pause");
}
