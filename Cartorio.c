#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Inicio da criação de variáveis/string
	
	int opcao=0;
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Final da criação de variáveis/string
	printf("Você gostaria de seguir com o Registro de Nomes?\n\n"); //Evolutiva proposta para erro de digitação caso não queira cadastrar nomes
	printf("\t1 - Sim\n"); //Linhas de opções propostas
	printf("\t2 - Não\n\n");
	printf("Opção: "); //Definindo a validação da pergunta
		
	scanf("%d", &opcao); //Armazenamento da opção desejada na variável(opcao) proposta para evolutiva
	system("cls"); //Limpeza (troca) de tela
	
	if(opcao == 1)
	{
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string (usado para salvar o dado em uma string)
	printf("\n");
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string (cpf) no arquivo
	
	FILE *file; //Busca a função FILE e inicia o processo (*file) para criar o arquivo
	
	file = fopen(arquivo, "w"); //O "w" significa que vai criar o arquivo (write = escrever)
	fprintf(file,"CPF: "); //Escreve no arquivo "CPF: "
	fprintf(file,cpf); //Salva o dado escrito (cpf) no arquivo que foi gerado
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //O "a" significa que vai atualizar o arquivo
	fprintf(file,",\nNOME: "); //Atualiza o arquivo com uma virgula antes do "Nome: "
	fclose(file); //Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //Coleta o dado a ser digitado
	scanf("%s",nome); //Salva o dado da variável "nome" na string
	printf("\n");
	
	file = fopen(arquivo, "a"); //O "a" significa que vai abrir e atualizar com alguma informação
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
	fprintf(file, ".\n\n"); //Pula duas linhas (linha criada para estilização do código)
	fclose(file); //Fim do Registro de nomes
		
	system("pause");
	}
	
	else
	{
		printf("\nVoltando ao Menu Principal!\n\n");
		system("pause");
		system("cls"); //Fim da proposta de evolutiva
	}
	//Fim da função de Registro
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	int opcao=0; //Variável proposta para a evolutiva sugerida
	char cpf[40]; //Primary key
	char conteudo[200]; //String criada para utilização da função while
	
	printf("Você gostaria de seguir com a Consulta de Nomes?\n\n"); //Inicio da evolutiva
	printf("\t1 - Sim\n"); //Definindo a validação da pergunta
	printf("\t2 - Não\n\n");
	printf("Opção: ");
		
	scanf("%d", &opcao); //Armazenamento da opção na variável da evolutiva
	system("cls");
	
	if(opcao == 1)
	{	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //Salva o valor inserido na string "cpf"
	
	FILE *file;
	file = fopen(cpf,"r"); //Abre o arquivo com base na string cpf, o "r" significa que vai ler o arquivo (read = ler)
	
	//Validação de arquivo para consulta
	
	if(file == NULL) //Caso o arquivo não exista
	{
		printf("\nNão foi possível abrir o arquivo, não localizado!\n\n"); //Comunicação com o usuário
		system("pause");
	}
	
	if(file != NULL) //Caso o arquivo exista 
	{
		printf("\nEssas são as informações do usuário: \n\n");
		
	//O comando while é responsável pela repetição de um bloco de instruções enquanto uma condição for verdadeira.
		
		while(fgets(conteudo, 200, file) != NULL) //Enquanto(while) "fgets" estiver salvando na variável "conteudo" até 200 valores, repita o processo no arquivo / senão finalize o comando.
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
	
	printf("Você gostaria de seguir com a Exclusão de Nomes?\n\n"); //Inicio da evolutiva de validação
	printf("\t1 - Sim\n"); //Definindo a validação da pergunta
	printf("\t2 - Não\n\n");
	printf("Opção: ");
		
	scanf("%d", &escolha);
	system("cls");
	
	if(escolha == 1)
	{
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s",cpf);
	
		FILE *file;
		file = fopen(cpf,"r");
	
		if(file == NULL) //Validação para a inexistência do arquivo
		{
			printf("\nO usuário não se encontra no sistema!\n\n");
			fclose (file);
			system("pause");
		}
	
	else //Validação de existência do arquivo
	{
		fclose(file);
		FILE *file;
		file = fopen(cpf,"r");	
	
		if(file != NULL) //Inicio da Evolutiva de Confirmação para o usuário 
		{
			printf("\nEssas são as informações do usuário: \n\n");
		
			while(fgets(conteudo, 200, file) != NULL)
			{
				printf("%s", conteudo);
			}
			fclose(file);
			printf("_____________________________________________\n");
			printf("\nTem certeza de que quer excluir este usuário?\n\n");
			printf("\t1 - Sim\n"); //Definindo a validação da pergunta
			printf("\t2 - Não\n\n");
			printf("Opção: ");
		
			scanf("%d", &opcao); //Armazenando a escolha do usuário
			//Fim da Evolutiva de Confirmação para o usuário
			if(opcao == 1)
			{
				remove(cpf); //Comando de exclusão do arquivo "cpf" / gerado através FILE file* e armazeado pelo %s
				printf("\nUsuário deletado com sucesso!\n\n"); //Confirmação de exclusão dos dados
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
	} //Fim da Evolutiva de validação
}

int main() //Tela inicial do Usuário e função principal do código
{
	int opcao=0; //Definindo as variáveis
	int laco=1; //Definindo uma variável para realizar um "loop"

	for(laco=1;laco=1;) //Outra função igualmente ao "while" criada para utilização de um loop.
	{
		
		system("cls"); 
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nomes\n"); //O "\t" coloca um espaçamento à esquerda do código
		printf("\t2 - Consultar Nomes\n"); //O "\n" pula uma linha
		printf("\t3 - Deletar Nomes\n\n"); //Ambos "\t" e "\n\n" estão para estilização do código
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Responsável por limpar a tela
				
		switch(opcao) //Inicio da seleção do menu através do switch case (responsável por permitir executar um código diferente para cada condição)
		{
			case 1:
			registro(); //chamada da função de Registro dos dados
			break;
			
			case 2:
			consulta(); //chamada da função de Consulta dos dados
			break;
			
			case 3:
			deletar(); //chamada da função de exclusão dos dados
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} //Fim da seleção do menu
 
	}
}
