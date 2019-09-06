#include <stdio.h>
#include <stdlib.h>

int main()
{
  float *v;
  int i;
 
  v = (float *)malloc(sizeof(float) * 10);
  
  for (i = 0; i < 10; i++)
  {
    printf("%p\n", (v + i));
  }
  
  return 0;
}