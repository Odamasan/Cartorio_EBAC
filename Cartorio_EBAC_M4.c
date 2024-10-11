#include <stdio.h> 	//entrada e sa�da de informa��es com o usu�rio e arquivos
#include <stdlib.h>  // aloca��o de espa�o de mem�ria	
#include <locale.h> // texto por regi�o


int registrar()
{
	char cpf[40]; //criando as vari�veis das informa��es pedidas
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF para registro: "); //inicio do cadastro
	scanf("%s", cpf);
	
	FILE *file; // criar o arquivo
	file = fopen(cpf, "w");  // fopen � como se eu estivesse acessando as propriedades do arquivo e definindo elas nos par�nteses
	fprintf(file,cpf);
	fclose(file);
	
	printf("Digite o nome para registro: ");
	scanf("%s",nome);
	
	file = fopen(cpf, "a"); // adicionando a informa��o nome ao arquivo
	fprintf(file,",%s",nome);
	fclose(file);
	
	printf("Digite o sobrenome para registro: ");
	scanf("%s",sobrenome);
	
	file = fopen(cpf,"a"); // adicionando a informa��o sobrenome ao arquivo
	fprintf(file,",%s",sobrenome);
	fclose(file);
	
	printf("Digite o cargo para registro: ");
	scanf("%s",cargo);
	
	file = fopen(cpf,"a"); // adicionando a informa��o cargo ao arquivo
	fprintf(file,",%s",cargo);
	fclose(file);
	
	printf("Cadastro concluido com sucesso \n"); //fim do cadastro
	
	system("pause");
}

int consultar()
{
	char cpf [40]; // criando vari�veis
	char conteudo [500];
	
	printf("Qual usu�rio deseja consultar? \n"); //coletando informa��o do usu�rio
	printf("Digite o CPF: ");
	scanf("%s",cpf); //armazenando na vari�vel
	
	FILE *file; //procurando arquivo para consultar o cpf
	file = fopen(cpf,"r");
	
	if (file == NULL) // caso o usu�rio n�o seja encontrado
	{
		printf("Usu�rio n�o encontrado");
	}
	
	else
	{
		while(fgets(conteudo,500,file) != NULL) //usasse fgets pois as vari�veis s�o pegas de uma em uma at� que n�o sobre nenhuma 
		{
			printf("Essas s�o as informa��es do usu�rio: %s \n\n",conteudo);
			
		}
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40]; //criando vari�vel
	
	printf("Qual usu�rio deseja deletar? \n"); //coletando informa��es do usu�rio
	printf("Digite CPF para deletar o usu�rio: ");
	scanf("%s",cpf); //armazenando em cpf
	
	FILE *file; //consultando arquivo com cpf
	file = fopen(cpf,"r");
	
	if (file == NULL) //caso n�o se ache nenhum arquivo com nome cpf
	{
		printf("Usu�rio n�o encontrado. \n");
		system("pause");
	}
	
	fclose(file); // fechar a procura de arquivo pois a vari�vel remove(x) � feita fora da procura
	
	remove(cpf); //removendo arquivo com nome cpf
	printf("Usu�rio deletado com sucesso! \n");
	system("pause");

}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem (Portugu�s)
	int opcao=0; //definindo vari�vel para opcao escolhida pelo usu�rio
	int x=1; //definindo vari�vel para looping do menu
	
	for(x=1;x=1;)
	{
		system("cls"); //limpar a tela de comandos do programa
		
		printf("---------Cart�rio EBAC--------- \n"); // in�cio do menu
		printf("*Escolha a op��o desejada do menu selecionando um n�mero:\n\n");
		printf("\t 1 - Registrar nomes. \n");
		printf("\t 2 - Consultar nomes. \n");
		printf("\t 3 - Deletar nomes. \n"); 
		printf("\t 4 - Sair do cart�rio. \n\n");
		printf("Digite a op��o desejada: "); //fim do menu
			
		
		scanf("%d",&opcao); //guarda o valor digitado pelo usu�rio e armazena na vari�vel indicada
	
		system("cls"); //limpar a tela de comandos do programa
		
		
		switch(opcao) //in�cio do fluxo de decis�es de acordo com o que o usu�rio escolher
		{
			case 1:
			registrar();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema EBAC");
			return 0;
			break;
			
			default:
			printf("ERROR! Escolha uma op��o entre 1,2, 3 ou 4 \n");
			system("pause");
			break;
		} //fim do fluxo de decis�es de acordo com o que o usu�rio escolher
	
 	}
}
