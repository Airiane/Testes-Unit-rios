#include <stdio.h>
#include <string.h>

struct cadastro
{
    char nome[200];
    int id;
};

int le_cliente (struct cadastro cliente[40], int controle);

main()
{
 	struct cadastro cliente[50];
	int i=0, Op, a, cont=0, id2, z;
	char resp, nome2[50];
	do {
		printf("\n1 - Cadastrar Novo Cliente ");
        printf("\n2 - Procurar por nome ");
       	printf("\n3 - Alterar Cliente ");
       	printf("\n4 - Listar ");
       	printf("\n5 - Sair ");
       	printf(" \nSelecione uma opcao por favor:");
       	scanf("%d", &Op);
       	if(Op>5 || Op<1){
       		printf("\nErro!");
       		printf("\nOpcao invalida.");
       	}
       	switch(Op)
		{
			case 1: 
				cont=le_cliente(cliente, cont);
				break;
			case 2:
				fflush(stdin);
				printf("\nDigite o nome: ");
				gets(nome2);
				for(a=0;a<cont;a++){
					if(strcmp(nome2, cliente[a].nome)==0){
					printf("\nNome: %s ",cliente[a].nome);
					fflush(stdin);
					printf("\nCodigo: %d", cliente[a].id);	
					}
					else
					printf("\nCliente nao cadastrado.");
				}
				break;
			case 3:
				printf("\nDigite o codigo do cliente que deseja alterar: ");
				scanf("%d", &id2);
				fflush(stdin);
				for(z=0;z<cont;z++){
					if(id2==cliente[z].id){
						fflush(stdin);
						printf("\nNome: ");
						gets(cliente[z].nome);
						fflush(stdin);		
						}		
					else
						printf("\nCodigo nao cadastrado.");
				}
				break;
			case 4: 
				if(cont==0){
					printf("\nNenhum cliente cadastrado.");
				}
				else{
				for(i=0;i<cont;i++){
					printf("\nNome: %s ",cliente[i].nome);
					printf("\nCodigo: %d", cliente[i].id);
				}
			}
				break;
		}
	}while(Op!=5);
}
int le_cliente (struct cadastro cliente[100], int controle)
{
	int x;
	char resp;
	do{
		fflush(stdin);
		printf("\nDigite o codigo: ");
		scanf("%d", &cliente[x].id);
		fflush(stdin);
		printf("\nNome: ");
		gets(cliente[x].nome);
		fflush(stdin);
		printf("\nDeseja incluir outro? (S/N)");
		scanf("%c", &resp);
		fflush(stdin);
		x++;
		controle++;
	}while(resp=='s' || resp=='S');
	return controle;
}
