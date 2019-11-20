#define MAX 20
#include <stdio.h>
#include <stdlib.h>


struct pilha
{
    char expressao[MAX];
    int topo;
    int base;
    int limite;
};
typedef struct pilha Pilha;

void reset(Pilha *pilha);
int push(Pilha *pilha, char i);
int full(Pilha *pilha);
int empty(Pilha *pilha);
int pop(Pilha *pilha,char i);
int main()
{
    int i;
    Pilha pilha,pilha_aux;
    char aux[10];
    reset(&pilha);
    reset(&pilha_aux);
    scanf("%s", aux);
    
    for(i = 0; i < strlen(aux); i++){
        if(aux[i] == '('){
        push(&pilha, aux[i]);
        }
        else if(aux[i] == ')'){
        push(&pilha_aux, aux[i]);
        }
    }
    if(pilha.topo == pilha_aux.topo){
        printf("Expressao Correta!");
    }
    else{
        printf("Expressao Incorreta!");
    }
   
        
       

    return 0;
}
void reset(Pilha *pilha)
{

    pilha->topo = 0;
    pilha->base = 0;
    pilha->limite = MAX;
}

int push(Pilha *pilha, char i)
{

    if (!full(pilha))
    {
        pilha->expressao[pilha->topo] = i;
        pilha->topo++;
        return 1;
    }
    else
    {
        return 0;
    }
}
int pop(Pilha *pilha,char i)
{

    if (!empty(pilha))
    {

        pilha->topo--;
        i = pilha->expressao[pilha->topo];
        return 1;
    }
    else
    {
        return 0;
    }
}

int full(Pilha *pilha)
{

    if (pilha->topo == MAX)
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