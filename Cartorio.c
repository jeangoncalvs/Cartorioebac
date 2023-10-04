#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inicio da cria��o de vari�veis/string
	
	int opcao=0;
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Final da cria��o de vari�veis/string
	printf("Voc� gostaria de seguir com o Registro de Nomes?\n\n"); //Evolutiva proposta para erro de digita��o caso n�o queira cadastrar nomes
	printf("\t1 - Sim\n"); //Linhas de op��es propostas
	printf("\t2 - N�o\n\n");
	printf("Op��o: "); //Definindo a valida��o da pergunta
		
	scanf("%d", &opcao); //Armazenamento da op��o desejada na vari�vel(opcao) proposta para evolutiva
	system("cls"); //Limpeza (troca) de tela
	
	if(opcao == 1)
	{
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string (usado para salvar o dado em uma string)
	printf("\n");
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string (cpf) no arquivo
	
	FILE *file; //Busca a fun��o FILE e inicia o processo (*file) para criar o arquivo
	
	file = fopen(arquivo, "w"); //O "w" significa que vai criar o arquivo (write = escrever)
	fprintf(file,"CPF: "); //Escreve no arquivo "CPF: "
	fprintf(file,cpf); //Salva o dado escrito (cpf) no arquivo que foi gerado
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //O "a" significa que vai atualizar o arquivo
	fprintf(file,",\nNOME: "); //Atualiza o arquivo com uma virgula antes do "Nome: "
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coleta o dado a ser digitado
	scanf("%s",nome); //Salva o dado da vari�vel "nome" na string
	printf("\n");
	
	file = fopen(arquivo, "a"); //O "a" significa que vai abrir e atualizar com alguma informa��o
	fprintf(file,nome); //Atualiza o arquivo com o dado inserido
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo com o intuito de atualiza-lo
	fprintf(file,",\nSOBRENOME: "); //Atualiza o arquivo com uma virgula
	fclose(file); //Fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //Busca o dado a ser inserido
	scanf("%s", sobrenome); //Salva o dado da string
	printf("\n");
	
	file = fopen(arquivo, "a"); //Abre o arquivo e atualiza
	fprintf(file,sobrenome); //Salva o dado da string "sobrenome" no arquivo gerado
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",\nCARGO: "); //Atualiza o arquivo gerado com uma virgula
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	printf("\n\n");
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, ".\n\n"); //Pula duas linhas (linha criada para estiliza��o do c�digo)
	fclose(file); //Fim do Registro de nomes
		
	system("pause");
	}
	
	else
	{
		printf("\nVoltando ao Menu Principal!\n\n");
		system("pause");
		system("cls"); //Fim da proposta de evolutiva
	}
	//Fim da fun��o de Registro
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	int opcao=0; //Vari�vel proposta para a evolutiva sugerida
	char cpf[40]; //Primary key
	char conteudo[200]; //String criada para utiliza��o da fun��o while
	
	printf("Voc� gostaria de seguir com a Consulta de Nomes?\n\n"); //Inicio da evolutiva
	printf("\t1 - Sim\n"); //Definindo a valida��o da pergunta
	printf("\t2 - N�o\n\n");
	printf("Op��o: ");
		
	scanf("%d", &opcao); //Armazenamento da op��o na vari�vel da evolutiva
	system("cls");
	
	if(opcao == 1)
	{	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //Salva o valor inserido na string "cpf"
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo com base na string cpf, o "r" significa que vai ler o arquivo (read = ler)
	
	//Valida��o de arquivo para consulta
	
	if(file == NULL) //Caso o arquivo n�o exista
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n\n"); //Comunica��o com o usu�rio
		system("pause");
	}
	
	if(file != NULL) //Caso o arquivo exista 
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		
	//O comando while � respons�vel pela repeti��o de um bloco de instru��es enquanto uma condi��o for verdadeira.
		
		while(fgets(conteudo, 200, file) != NULL) //Enquanto(while) "fgets" estiver salvando na vari�vel "conteudo" at� 200 valores, repita o processo no arquivo / sen�o finalize o comando.
		{
			printf("%s", conteudo); //Salva e exibe o valor inserido da string conteudo
		}
		system("pause");
		fclose(file); //Fecha o arquivo
	}
	
	}	
	else
	{
		printf("\nVoltando ao Menu Principal!\n\n");
		system("pause");
		system("cls"); //fim da evolutiva
	}
}

int deletar()
{
	int escolha=1;
	char conteudo[200];
	int opcao=0;
	char cpf[40];
	
	printf("Voc� gostaria de seguir com a Exclus�o de Nomes?\n\n"); //Inicio da evolutiva de valida��o
	printf("\t1 - Sim\n"); //Definindo a valida��o da pergunta
	printf("\t2 - N�o\n\n");
	printf("Op��o: ");
		
	scanf("%d", &escolha);
	system("cls");
	
	if(escolha == 1)
	{
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s",cpf);
	
		FILE *file;
		file = fopen(cpf,"r");
	
		if(file == NULL) //Valida��o para a inexist�ncia do arquivo
		{
			printf("\nO usu�rio n�o se encontra no sistema!\n\n");
			fclose (file);
			system("pause");
		}
	
	else //Valida��o de exist�ncia do arquivo
	{
		fclose(file);
		FILE *file;
		file = fopen(cpf,"r");	
	
		if(file != NULL) //Inicio da Evolutiva de Confirma��o para o usu�rio 
		{
			printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		
			while(fgets(conteudo, 200, file) != NULL)
			{
				printf("%s", conteudo);
			}
			fclose(file);
			printf("_____________________________________________\n");
			printf("\nTem certeza de que quer excluir este usu�rio?\n\n");
			printf("\t1 - Sim\n"); //Definindo a valida��o da pergunta
			printf("\t2 - N�o\n\n");
			printf("Op��o: ");
		
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
			//Fim da Evolutiva de Confirma��o para o usu�rio
			if(opcao == 1)
			{
				remove(cpf); //Comando de exclus�o do arquivo "cpf" / gerado atrav�s FILE file* e armazeado pelo %s
				printf("\nUsu�rio deletado com sucesso!\n\n"); //Confirma��o de exclus�o dos dados
				system("pause");
			}
		else
		{
			printf("\nVoltando ao Menu Principal!\n\n");
			system("pause");
			system("cls");
		}
		}
	}
	}
	else
	{
		printf("\nVoltando ao Menu Principal!\n\n");
		system("pause");
		system("cls");
	} //Fim da Evolutiva de valida��o
}

int main() //Tela inicial do Usu�rio e fun��o principal do c�digo
{
	int opcao=0; //Definindo as vari�veis
	int laco=1; //Definindo uma vari�vel para realizar um "loop"

	for(laco=1;laco=1;) //Outra fun��o igualmente ao "while" criada para utiliza��o de um loop.
	{
		
		system("cls"); 
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n"); //O "\t" coloca um espa�amento � esquerda do c�digo
		printf("\t2 - Consultar Nomes\n"); //O "\n" pula uma linha
		printf("\t3 - Deletar Nomes\n\n"); //Ambos "\t" e "\n\n" est�o para estiliza��o do c�digo
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
				
		switch(opcao) //Inicio da sele��o do menu atrav�s do switch case (respons�vel por permitir executar um c�digo diferente para cada condi��o)
		{
			case 1:
			registro(); //chamada da fun��o de Registro dos dados
			break;
			
			case 2:
			consulta(); //chamada da fun��o de Consulta dos dados
			break;
			
			case 3:
			deletar(); //chamada da fun��o de exclus�o dos dados
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} //Fim da sele��o do menu
 
	}
}
