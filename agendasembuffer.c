#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista{
char nome[30];
int telefone;
char endereco[30];
char estado[30];
int cep;
struct lista *prox;
};
typedef struct lista lista;
void inserir(lista *p);
void apagar(lista *p);
void listar(lista *p);
void buscar(lista *p);
int main( ){
lista *head;
head=(lista*)malloc(sizeof(lista));
head->prox = NULL;
int op;
for(;;){
printf("AGENDA\n");
printf("1)inserir\n");
printf("2)Apagar\n");
printf("3)Listar\n");
printf("4)Buscar\n");
printf("5)Sair\n");
scanf("%d",&op);
switch (op){
case 1:
inserir(head);
break;
case 2:
apagar(head);
break;
case 3:
listar(head);
break;
case 4:
buscar(head);
break;
case 5:
exit(0);
break;
}
}

    return 0;
}
void inserir(lista *p){
lista *busca, *nova;
char lixo;
for(busca = p; busca->prox != NULL ; busca= busca->prox);
nova = (lista *)malloc(sizeof(lista));
busca->prox = nova;
nova->prox = NULL;
printf("Informe o nome: \n");
scanf("%c", &lixo);
scanf("%[^\n]s", nova->nome);
printf("Informe o telefone: \n");
scanf("%d", &nova->telefone);
scanf("%c", &lixo);
printf("Informe o endereco: \n");
scanf("%[^\n]s", nova->endereco);
scanf("%c", &lixo);
printf("Informe o estado: \n");
scanf("%[^\n]s", nova->estado);
printf("Informe o CEP: \n");
scanf("%d", &nova->cep);

}
void apagar(lista *p){
lista *busca, *anterior;
char nome[30];
printf("Informe o nome que deseja excluir: ");
scanf("%s", nome);
for(busca=p->prox,anterior=p; busca != NULL; busca = busca->prox, anterior= anterior->prox ){
if(strcmp(nome, busca->nome)==0){
anterior->prox = busca->prox;
free(busca);
}
}
}
void listar(lista *p){
lista *i;
for(i=p->prox; i != NULL ; i=i->prox){
printf("Nome: %s\n", i->nome);
printf("Telefone: %d\n", i->telefone);
printf("Endereco: %s\n", i->endereco);
printf("Estado: %s\n", i->estado);
printf("CEP: %d\n", i->cep);

}
}
void buscar(lista *p){
	lista *i;
	char busca[30],lixo;
	int entrou=0;
	printf("Informe o nome que deseja buscar: ");
	scanf("%c", &lixo);
	scanf("%[^\n]s", busca);
	for(i=p->prox; i!=NULL; i=i->prox){
	if(strcmp(busca, i->nome)==0){
		printf("Nome: %s\n",i->nome);
		printf("Telefone: %d\n",i->telefone);
		printf("Endereco: %s\n", i->endereco);
		printf("Estado: %s\n", i->estado);
		printf("CEP: %d \n", i->cep);
		entrou++;
	}
}
	if(entrou==0){
		printf("Nome nao encontrado!\n");
	}
}
