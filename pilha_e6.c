#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct pilha
{
    char *texto;
    int topo;
    int base;
} Pilha;
int main( )
{
Pilha pilha, pilha_aux;
int i = -1;
pilha.topo = 0;
pilha.base = 0;
pilha.texto = (char*)(malloc(sizeof(char)*i));
do{
i++;
pilha.texto = realloc(pilha.texto, sizeof(char)*(i+1));
scanf("%c", &pilha.texto[i]);
pilha.topo++;
}while(pilha.texto[i] != '.');

while(pilha.topo != -1){
if( pilha.texto[pilha.topo]!= '.')
printf("%c", pilha.texto[pilha.topo]);
pilha.topo--;

}


    return 0;
}
