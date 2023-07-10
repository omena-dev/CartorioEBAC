#include <locale.h> //biblioteca de alocação de texto por região
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <string.h> //biblioteca responsável pelas strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
    char arquivo[50];
	char cpf[50];
    char nome[50];
    char sobrenome[50];
    char cargo[50];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //responsável por copiar os valores das strings
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e w significa write = escrever
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[50];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
	system("pause");
	
}

int deletar()
{
    char cpf[50];
    
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
	   printf("O CPF digitado não existe.\n");
	   system("pause");
	}
    
}


int main()
{
	int opcao=0; //Definindo variáveis
    int laco=1;

    for(laco=1;laco=1;)
   {
	
	  system("cls");//responsável por limpar a tela

      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

      printf("\t### Cartório da EBAC ###\n\n"); //Início do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n"); 
	  printf("\t4 - Sair do sistema\n\n");
	  printf("Opção: "); //fim do menu

	  scanf("%d", &opcao); //Armazenando a escolha do usuário

	  system("cls");
	  
	  
	  switch(opcao)//início da seleção do menu
     {
	    case 1:
        registro(); //chamada de funções
        break;
        
		case 2:
	    consulta();
	    break;

		case 3:
        deletar();
	    break;
	    
	    case 4:
	    printf("Obrigado por utilizar o sistema!\n");
	    return 0;
	    break;

		default:
	      printf("Essa opção não está disponível!\n");
	      system("pause");
	    break;
	 } //fim da seleção

   }
}

