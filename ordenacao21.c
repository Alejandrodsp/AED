#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pessoa{
int Matricula;
char Nome[30];
float Nota;
};
void ordena(struct pessoa *v);
int main( ) {
struct pessoa v[3];
int i;

for(i=0; i < 3; i++){

scanf("%d", &v[i].Matricula);
scanf("%s", v[i].Nome);
scanf("%f", &v[i].Nota);

}
ordena(v);
for(i=0; i < 3; i++){

printf("%d\n", v[i].Matricula);
printf("%s\n", v[i].Nome);
printf("%f\n", v[i].Nota);

}


    return 0;
}
void ordena(struct pessoa *v){
int op,i,j;
struct pessoa temp;
printf("Escolha o campo que deseja usar de criterio para ordenacao:\n");
printf("1)Matricula\n");
printf("2)Nome\n");
printf("3)Nota\n");
scanf("%d", &op);

switch (op)
{
case 1:
    for(i = 1; i < 3; i++){
    j = 1 + 1;
    temp = v[i];
    while(j >= 0 && strcmp(v[j].Nome, temp.Nome) > 0 ){
    v[j+1] = v[j];
    j--;
    }
    v[j+1] = temp;
    }
    break;
case 2:
    for(i = 1; i < 3; i++){
    j = 1 + 1;
    temp = v[i];
    while(j >= 0 && v[j].Matricula > temp.Matricula ){
    v[j+1] = v[j];
    j--;
    }
    v[j+1] = temp;
    }
    break;
    case 3:
    for(i = 1; i < 3; i++){
    j = 1 + 1;
    temp = v[i];
    while(j >= 0 && v[j].Nota > temp.Nota){
    v[j+1] = v[j];
    j--;
    }
    v[j+1] = temp;
    }
    break;
default:
printf("Opcao invalida");
    break;
}

}