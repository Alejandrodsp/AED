#include <stdio.h>
#include <stdlib.h>
int *insertion(int *v, int n);
int *cria_vetor(int *v, int n);
void imprime_vetor(int *v, int n);
int main(){
int n,*v;
printf("Informe o numero de elementos: ");
scanf("%d", &n);
v = cria_vetor(v,n);
insertion(v,n);
imprime_vetor(v,n);
free(v);

    return 0;
}
int *cria_vetor(int *v, int n){
int i;
v = (int*)malloc(sizeof(int)*n);
printf("Informe os elementos: ");
for (i = 0; i < n; i++)
{
  scanf("%d", &v[i]);
}
    return v;
}
void imprime_vetor(int *v, int n){
int i;
printf("Vetor: ");
for (i = 0; i < n; i++)
{
  printf("%d ", v[i]);
}
}
int *insertion(int v[], int n){
int i,j,temp;

for(i = 1; i < n; i++){
temp = v[i];
j = i - 1;
while(j>=0 && v[j] > temp){
v[j+1]= v[j];
j--;
}
v[j+1] = temp;
}

}