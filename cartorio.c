#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <string.h> //biblioteca respons�vel pelas strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
    char arquivo[50];
	char cpf[50];
    char nome[50];
    char sobrenome[50];
    char cargo[50];
    //final da cria��o de vari�veis/string
    
    printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
    
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
        printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
	system("pause");
	
}

int deletar()
{
    char cpf[50];
    
    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
	   printf("O CPF digitado n�o existe.\n");
	   system("pause");
	}
    
}


int main()
{
	int opcao=0; //Definindo vari�veis
    int laco=1;

    for(laco=1;laco=1;)
   {
	
	  system("cls");//respons�vel por limpar a tela

      setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem

      printf("\t### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	  printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n"); 
	  printf("\t4 - Sair do sistema\n\n");
	  printf("Op��o: "); //fim do menu

	  scanf("%d", &opcao); //Armazenando a escolha do usu�rio

	  system("cls");
	  
	  
	  switch(opcao)//in�cio da sele��o do menu
     {
	    case 1:
        registro(); //chamada de fun��es
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
	      printf("Essa op��o n�o est� dispon�vel!\n");
	      system("pause");
	    break;
	 } //fim da sele��o

   }
}

