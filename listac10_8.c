#include <stdlib.h>
#include <stdio.h>
int main ( )
{
int *v,i;
v = (int*)calloc(1500,sizeof(int));
for(i=0;i<1500;i++){
    printf("%d",v[i]);
}    
for(i=0;i<1500;i++){
   v[i]=i;
}   
for(i=0;i<10;i++){
  printf("%d",v[i]);
}  
for(i=1490;i<1500;i++){
  printf("%d",v[i]);
}  

free(v);
    return 0;
}
