#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pilha
{
    char palavra[10];
    int topo;
    int base;
} Pilha;
int main()
{
    Pilha pilha, pilha_aux;

    scanf("%s", pilha.palavra);
    pilha.topo = strlen(pilha.palavra);
    pilha.base = 0;
    pilha_aux.topo = 0;
    pilha_aux.base = 0;

    while (pilha.topo != 0)
    {

        pilha_aux.palavra[pilha_aux.topo] = pilha.palavra[pilha.topo];
        pilha.topo--;
        pilha_aux.topo++;
    }

    pilha_aux.palavra[pilha_aux.topo - 1] = '\0';

    if (strcmp(pilha_aux.palavra, pilha.palavra) == 0)
    {
        printf("Palindromo\n");
    }
    else
    {
        printf("Nao é palindromo\n");
    }

    return 0;
}
