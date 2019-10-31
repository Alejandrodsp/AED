#include <stdio.h>
#include <stdlib.h>

struct aluno
{
    char nome[15];
    int matricula;
};

struct pilha
{
    struct aluno alunos[10];
    int topo;
    int base;
    int limite;
};
typedef struct pilha Pilha;
typedef struct aluno Aluno;
void reset(Pilha *pilha);
int push(Pilha *pilha, Aluno *item);
int full(Pilha *pilha);
int empty(Pilha *pilha);
int pop(Pilha *pilha, Aluno *item);
int main()
{
    int op, i;
    Pilha pilha, pilha_aux;
    Aluno aux;
    char busca[15];
    reset(&pilha);
    reset(&pilha_aux);
    for (;;)
    {
        printf("0: Insere pessoa\n");
        printf("1: Deleta pessoa do topo\n");
        printf("2: Deleta pessoa por nome\n");
        printf("3: Limpa a pilha\n");
        printf("4: Lista na tela as pessoas\n");
        printf("5: Sair do programa\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Informe o nome do aluno:");
            scanf("%s", aux.nome);
            printf("Informe a matricula do aluno:");
            scanf("%d", &aux.matricula);
            if (push(&pilha, &aux))
            {
                printf("Inserido com sucesso!\n");
            }
            else
            {
                printf("Estrutura de dados cheia!\n");
            }
            break;
        case 1:
            if (pop(&pilha, &aux))
            {

                printf("Excluida com sucesso!\n");
            }
            else
            {
                printf("Estrutura de dados vazia!\n");
            }
            break;
        case 2:
            printf("Informe o nome que deseja excluir: ");
            scanf("%s", busca);
            i = 0;
            while (!(empty(&pilha)))
            {
                pop(&pilha, &aux);
                if (strcmp(aux.nome, busca) == 0)
                {
                    i++;
                    printf("Nome excluido com sucesso!\n");
                }
                if (i == 0)
                {
                    push(&pilha_aux, &aux);
                }
            }
            while (!(empty(&pilha_aux)))
            {
                pop(&pilha_aux, &aux);
                push(&pilha, &aux);
            };
            if (i == 0)
            {
                printf("Nome nao encontrado!\n");
            }
            break;
        case 3:
            do
            {

                pop(&pilha, &aux);

            } while (!(empty(&pilha)));
            printf("Estrutura limpa com sucesso!\n");

            break;
        case 4:
            if (empty(&pilha))
            {
                printf("Estrutura de dados vazia!\n");
            }
            while (!(empty(&pilha)))
            {
                pop(&pilha, &aux);
                printf("Nome: %s, Matricula: %d\n", aux.nome, aux.matricula);
                push(&pilha_aux, &aux);
            };
            while (!(empty(&pilha_aux)))
            {
                pop(&pilha_aux, &aux);
                push(&pilha, &aux);
            };
            break;
        case 5:
            exit(0);
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
    }

    return 0;
}
void reset(Pilha *pilha)
{

    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = 10;
}

int push(Pilha *pilha, Aluno *item)
{

    if (!full(pilha))
    {
        pilha->alunos[pilha->topo] = *item;
        pilha->topo++;
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop(Pilha *pilha, Aluno *item)
{

    if (!empty(pilha))
    {

        pilha->topo--;
        *item = pilha->alunos[pilha->topo];
        return 1;
    }
    else
    {
        return 0;
    }
}

int full(Pilha *pilha)
{

    if (pilha->topo == 10)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}
int empty(Pilha *pilha)
{

    if (pilha->topo == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}