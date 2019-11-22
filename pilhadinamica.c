#include <stdio.h>
#include <stdlib.h>

struct aluno
{
    char nome[15];
    int matricula;
};

struct pilha
{
    struct aluno aluno;
    struct pilha *prox;
};
typedef struct pilha Pilha;
typedef struct aluno Aluno;
void push(Pilha *pilha, Aluno *item);
int empty(Pilha *pilha);
Pilha *pop(Pilha *pilha);
void printStack(Pilha *head);
int main()
{
    int op;
    Pilha *head,*popi;
    Aluno aux;
    head = (Pilha*)malloc(sizeof(Pilha));
    popi = (Pilha*)malloc(sizeof(Pilha));
    head->prox = NULL;
    for (;;)
    {
        printf("0: Insere pessoa\n");
        printf("1: Deleta pessoa\n");
        printf("2: Limpa a pilha\n");
        printf("3: Lista na tela as pessoas\n");
        printf("4: Sair do programa\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Informe o nome do aluno:");
            scanf("%s", aux.nome);
            printf("Informe a matricula do aluno:");
            scanf("%d", &aux.matricula);
            push(head, &aux);
            
           
            break;
        case 1:
            if (popi = pop(head))
            {
                printf("%s\n",popi->aluno.nome);
                printf("Excluida com sucesso!\n");
                free(popi);
            }
            else
            {
                printf("Estrutura de dados vazia!\n");
            }
            break;
        case 2:
            do
            {

                popi = pop(head);
                free(popi);
            } while (!(empty(head)));
            printf("Estrutura limpa com sucesso!\n");

            break;
        case 3:
           printStack(head);
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
    }

    return 0;
}

void push(Pilha *pilha, Aluno *item)
{
    Pilha *novo,*aux;
    novo = (Pilha*)malloc(sizeof(Pilha));
    novo->aluno = *item;
    aux = pilha->prox;
    pilha->prox = novo;
    novo->prox = aux;
       
}
Pilha *pop(Pilha *pilha)
{
     Pilha *morto;
   if(pilha->prox == NULL){
       return NULL;
   }
   else{
       morto = pilha->prox;
       pilha->prox = morto->prox;
       return morto;
   }

   
}

int empty(Pilha *pilha)
{

    if (pilha->prox == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void printStack(Pilha *head){
        if(head->prox == NULL)
                printf("Pilha Vazia\n");

        Pilha *printer = head->prox;
        
        while(printer != NULL){
                printf("%s", printer->aluno.nome);
                printer = printer->prox;
        }
}