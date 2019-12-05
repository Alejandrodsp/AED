#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char nome[20];
    int telefone;
};

struct No
{
    struct aluno info;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;
typedef struct aluno Aluno;
void criarArvore(No **pRaiz);
void listar(No *pRaiz);
int insere(No **pRaiz, Aluno aux);
void buscar(No *pRaiz, Aluno aux);
void remover(No **pRaiz, Aluno aux);
void antecessor(No *p, No **pp);
void destruir(No *pRaiz);
int Altura(No *pRaiz);
int FB(No *pRaiz);
int EhArvoreArvl(No* pRaiz);
int Balanceamento(No **ppRaiz);
void RSE(No **ppRaiz);
void RSD(No **ppRaiz);
int BalancaEsquerda(No **ppRaiz);
int BalancaDireita(No **ppRaiz);


int main()
{
    int op;
    Aluno aux;
    No *raiz;
    criarArvore(&raiz);
    for (;;)
    {
        printf("1)Inserir\n");
        printf("2)Listar\n");
        printf("3)Buscar\n");
        printf("4)Excluir\n");
        printf("5)Sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Informe o nome: ");
            scanf("%s", aux.nome);
            printf("Informe o telefone: ");
            scanf("%d", &aux.telefone);
            insere(&raiz, aux);
            break;
        case 2:
            listar(raiz);
            break;
        case 3:
            printf("Informe o nome que deseja buscar: ");
            scanf("%s", aux.nome);
            buscar(raiz, aux);
            break;
        case 4:
            printf("Informe o nome que deseja excluir: ");
            scanf("%s", aux.nome);
            remover(&raiz, aux);
            break;
        case 5:
            if(EhArvoreArvl(raiz)){
                printf("AVL\n");
            }
            else{
                printf("Nao AVL\n");
            }
            destruir(raiz);
            exit(0);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
    return 0;
}
void criarArvore(No **pRaiz)
{
    *pRaiz = NULL;
}
int insere(No **pRaiz, Aluno aux)
{
    if (*pRaiz == NULL)
    {
        *pRaiz = (No *)malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->info = aux;
    }
    else if (strcmp(aux.nome, ((*pRaiz)->info.nome)) < 0)
    {
        if (insere(&((*pRaiz)->esquerda), aux))
        {
            if (Balanceamento(pRaiz))
                return 0;
            else
                return 1;
        }
    }
    else if (strcmp(aux.nome, ((*pRaiz)->info.nome)) > 0)
    {
        if (insere(&((*pRaiz)->direita), aux))
        {
            if(Balanceamento(pRaiz))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
    else
        return 0;
}

void listar(No *pRaiz)
{
    if (pRaiz != NULL)
    {
        listar(pRaiz->esquerda);
        printf("Nome: %s\n", pRaiz->info.nome);
        printf("Telefone: %d\n", pRaiz->info.telefone);
        listar(pRaiz->direita);
    }
}
void buscar(No *pRaiz, Aluno aux)
{

    if (pRaiz != NULL)
    {

        if (strcmp(aux.nome, pRaiz->info.nome) < 0)
        {
            buscar(pRaiz->esquerda, aux);
        }
        else if (strcmp(aux.nome, pRaiz->info.nome) > 0)
        {
            buscar(pRaiz->direita, aux);
        }
        else
        {
            printf("Nome: %s\n", pRaiz->info.nome);
            printf("Telefone: %d\n", pRaiz->info.telefone);
        }
    }
    else
    {
        printf("Sem dados!\n");
    }
}

void remover(No **pRaiz, Aluno aux)
{
    No *auxiliar;

    if (*pRaiz == NULL)
        return;

    if (strcmp(aux.nome, (*pRaiz)->info.nome) < 0)
    {
        remover(&(*pRaiz)->esquerda, aux);
        
        return;
    }

    if (strcmp(aux.nome, (*pRaiz)->info.nome) > 0)
    {
        remover(&(*pRaiz)->direita, aux);
        return;
    }

    if ((*pRaiz)->direita == NULL)
    {
        auxiliar = *pRaiz;
        *pRaiz = (*pRaiz)->esquerda;
        free(auxiliar);
        Balanceamento(pRaiz);
        return;
    }

    if ((*pRaiz)->esquerda != NULL)
    {
        antecessor(*pRaiz, &(*pRaiz)->esquerda);
        return;
    }

    auxiliar = *pRaiz;
    *pRaiz = (*pRaiz)->direita;
    free(auxiliar);
    Balanceamento(pRaiz);
             
}

void antecessor(No *p, No **pp)
{
    No *aux;

    if ((*pp)->direita != NULL)
    {
        antecessor(p, &(*pp)->direita);
        return;
    }

    p->info = (*pp)->info;
    aux = *pp;
    *pp = (*pp)->esquerda;
    free(aux);
}
void destruir(No *pRaiz)
{
    if (pRaiz != NULL)
    {
        destruir(pRaiz->esquerda);
        destruir(pRaiz->direita);
        free(pRaiz);
    }
    pRaiz = NULL;
}
int Altura(No *pRaiz)
{
    int iEsq, iDir;

    if (pRaiz == NULL)

        return 0;

    iEsq = Altura(pRaiz->esquerda);

    iDir = Altura(pRaiz->direita);

    if (iEsq > iDir)

        return iEsq + 1;

    else

        return iDir + 1;
}
int FB(No *pRaiz)

{

    if (pRaiz == NULL)
        return 0;

    return Altura(pRaiz->esquerda) - Altura(pRaiz->direita);
}
void RSE(No **ppRaiz)

{

    No *pAux;

    pAux = (*ppRaiz)->direita;

    (*ppRaiz)->direita = pAux->esquerda;

    pAux->esquerda = (*ppRaiz);

    (*ppRaiz) = pAux;
}

void RSD(No **ppRaiz)

{

    No *pAux;

    pAux = (*ppRaiz)->esquerda;

    (*ppRaiz)->esquerda = pAux->direita;

    pAux->direita = (*ppRaiz);

    (*ppRaiz) = pAux;
}
int BalancaEsquerda(No **ppRaiz)

{

    int fbe = FB((*ppRaiz)->esquerda);

    if (fbe > 0)

    {

        RSD(ppRaiz);

        return 1;
    }

    else if (fbe < 0)

    { /* Rotação Dupla Direita */

        RSE(&((*ppRaiz)->esquerda));

        RSD(ppRaiz); /* &(*ppRaiz) */

        return 1;
    }

    return 0;
}
int BalancaDireita(No **ppRaiz)

{

    int fbd = FB((*ppRaiz)->direita);

    if (fbd < 0)

    {

        RSE(ppRaiz);

        return 1;
    }

    else if (fbd > 0)

    { /* Rotação Dupla Esquerda */

        RSD(&((*ppRaiz)->direita));

        RSE(ppRaiz); /* &(*ppRaiz) */

        return 1;
    }

    return 0;
}
int Balanceamento(No **ppRaiz)

{

    int fb = FB(*ppRaiz);

    if (fb > 1)

        return BalancaEsquerda(ppRaiz);

    else if (fb < -1)

        return BalancaDireita(ppRaiz);

    else

        return 0;
}
int EhArvoreArvl(No* pRaiz)

{

int fb;

if (pRaiz == NULL)
return 1;

if (!EhArvoreArvl(pRaiz->esquerda))
return 0;

if (!EhArvoreArvl(pRaiz->direita))
return 0;

fb = FB (pRaiz);

if ( ( fb > 1 ) || ( fb < -1) )
return 0;

else
return 1;

}