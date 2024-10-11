#include <stdio.h> 	//entrada e saída de informações com o usuário e arquivos
#include <stdlib.h>  // alocação de espaço de memória	
#include <locale.h> // texto por região


int registrar()
{
	char cpf[40]; //criando as variáveis das informações pedidas
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF para registro: "); //inicio do cadastro
	scanf("%s", cpf);
	
	FILE *file; // criar o arquivo
	file = fopen(cpf, "w");  // fopen é como se eu estivesse acessando as propriedades do arquivo e definindo elas nos parênteses
	fprintf(file,cpf);
	fclose(file);
	
	printf("Digite o nome para registro: ");
	scanf("%s",nome);
	
	file = fopen(cpf, "a"); // adicionando a informação nome ao arquivo
	fprintf(file,",%s",nome);
	fclose(file);
	
	printf("Digite o sobrenome para registro: ");
	scanf("%s",sobrenome);
	
	file = fopen(cpf,"a"); // adicionando a informação sobrenome ao arquivo
	fprintf(file,",%s",sobrenome);
	fclose(file);
	
	printf("Digite o cargo para registro: ");
	scanf("%s",cargo);
	
	file = fopen(cpf,"a"); // adicionando a informação cargo ao arquivo
	fprintf(file,",%s",cargo);
	fclose(file);
	
	printf("Cadastro concluido com sucesso \n"); //fim do cadastro
	
	system("pause");
}

int consultar()
{
	char cpf [40]; // criando variáveis
	char conteudo [500];
	
	printf("Qual usuário deseja consultar? \n"); //coletando informação do usuário
	printf("Digite o CPF: ");
	scanf("%s",cpf); //armazenando na variável
	
	FILE *file; //procurando arquivo para consultar o cpf
	file = fopen(cpf,"r");
	
	if (file == NULL) // caso o usuário não seja encontrado
	{
		printf("Usuário não encontrado");
	}
	
	else
	{
		while(fgets(conteudo,500,file) != NULL) //usasse fgets pois as variáveis são pegas de uma em uma até que não sobre nenhuma 
		{
			printf("Essas são as informações do usuário: %s \n\n",conteudo);
			
		}
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40]; //criando variável
	
	printf("Qual usuário deseja deletar? \n"); //coletando informações do usuário
	printf("Digite CPF para deletar o usuário: ");
	scanf("%s",cpf); //armazenando em cpf
	
	FILE *file; //consultando arquivo com cpf
	file = fopen(cpf,"r");
	
	if (file == NULL) //caso não se ache nenhum arquivo com nome cpf
	{
		printf("Usuário não encontrado. \n");
		system("pause");
	}
	
	fclose(file); // fechar a procura de arquivo pois a variável remove(x) é feita fora da procura
	
	remove(cpf); //removendo arquivo com nome cpf
	printf("Usuário deletado com sucesso! \n");
	system("pause");

}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem (Português)
	int opcao=0; //definindo variável para opcao escolhida pelo usuário
	int x=1; //definindo variável para looping do menu
	
	for(x=1;x=1;)
	{
		system("cls"); //limpar a tela de comandos do programa
		
		printf("---------Cartório EBAC--------- \n"); // início do menu
		printf("*Escolha a opção desejada do menu selecionando um número:\n\n");
		printf("\t 1 - Registrar nomes. \n");
		printf("\t 2 - Consultar nomes. \n");
		printf("\t 3 - Deletar nomes. \n"); 
		printf("\t 4 - Sair do cartório. \n\n");
		printf("Digite a opção desejada: "); //fim do menu
			
		
		scanf("%d",&opcao); //guarda o valor digitado pelo usuário e armazena na variável indicada
	
		system("cls"); //limpar a tela de comandos do programa
		
		
		switch(opcao) //início do fluxo de decisões de acordo com o que o usuário escolher
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
			printf("ERROR! Escolha uma opção entre 1,2, 3 ou 4 \n");
			system("pause");
			break;
		} //fim do fluxo de decisões de acordo com o que o usuário escolher
	
 	}
}
