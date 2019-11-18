#define MAX 5
#include <stdio.h>
#include <stdlib.h>
typedef struct aluno{
 char nome[20];
 int matricula;
}Aluno;
typedef struct fila{
Aluno alunos[MAX];
int topo;
int base;
int limite;
int quantidade;
}Fila;
void reset(Fila *fila);
int push(Fila *fila, Aluno *item);
int pop(Fila *fila, Aluno *item);
int full(Fila *fila);
int main (){
    int op, i;
    Fila fila, fila_aux;
    Aluno aux;
    char busca[15];
    reset(&fila);
    reset(&fila_aux);
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
            if (push(&fila, &aux))
            {
                printf("Inserido com sucesso!\n");
            }
            else
            {
                printf("Estrutura de dados cheia!\n");
            }
            break;
        case 1:
            if (pop(&fila, &aux))
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
            while (!(empty(&fila)))
            {
                pop(&fila, &aux);
                if (strcmp(aux.nome, busca) == 0)
                {
                    i++;
                    printf("Nome excluido com sucesso!\n");
                }
                if (i == 0)
                {
                    push(&fila_aux, &aux);
                }
            }
            while (!(empty(&fila_aux)))
            {
                pop(&fila_aux, &aux);
                push(&fila, &aux);
            };
            if (i == 0)
            {
                printf("Nome nao encontrado!\n");
            }
            break;
        case 3:
            do
            {

                pop(&fila, &aux);

            } while (!(empty(&fila)));
            printf("Estrutura limpa com sucesso!\n");

            break;
        case 4:
            if (empty(&fila))
            {
                printf("Estrutura de dados vazia!\n");
            }
            while (!(empty(&fila)))
            {
                pop(&fila, &aux);
                printf("Nome: %s, Matricula: %d\n", aux.nome, aux.matricula);
                push(&fila_aux, &aux);
            };
            while (!(empty(&fila_aux)))
            {
                pop(&fila_aux, &aux);
                push(&fila, &aux);
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
void reset(Fila *fila){
    
    fila->topo = 0;
    fila->base = 0;
    fila->limite = MAX; 
    fila->quantidade = 0;

}
int push(Fila *fila, Aluno *item){

if (!full(fila))
    {
        fila->alunos[fila->topo] = *item;
        fila->topo++;
        fila->quantidade++;
        return 1;
    }
    else
    {
        return 0;
    }

}
int pop(Fila *fila, Aluno *item)
{

    if (!empty(fila))
    {

        *item = fila->alunos[fila->base];
         fila->base++;
         fila->quantidade--;
        return 1;
    }
    else
    {
        return 0;
    }
}
int full(Fila *fila){

if (fila->quantidade == MAX)
    {

        return 1;
    }
    else
    {
        return 0;
    }

}
int empty(Fila *fila)
{

    if (fila->quantidade == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}