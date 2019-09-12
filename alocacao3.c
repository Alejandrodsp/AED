#include <stdio.h>
#include <stdlib.h>
int **cria(int m, int n);
void limpa(int **m, int n);
int main( )
{
int **matriz;
matriz = cria(3,3);
limpa(matriz,3);
    return 0;
}
int **cria(int m, int n){
  int i,j,**matriz;
matriz = (int**)malloc(sizeof(int*)*m);
for(i=0;i<m;i++){
  matriz[i]=(int*)malloc(sizeof(int)*n);
}

return matriz;
}
void limpa(int **matriz,int m){
int i;
for(i=0; i<m;i++){

    free(matriz[i]);
}
free(matriz);
}