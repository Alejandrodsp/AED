#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2);
int main()
{
    int *v1, *v2, *v3, n1, n2, i;
    
    printf("Informe o tamanho do v1: ");
    scanf("%d", &n1);
  
    printf("Informe o tamanho do v2: ");
    scanf("%d", &n2);
   
    v1 = (int *)malloc(sizeof(int) * n1);
    v2 = (int *)malloc(sizeof(int) * n2);
   
    printf("Digite os elementos do v1: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &v1[i]);
    }
    printf("Digite os elementos do v2: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &v2[i]);
    }
    v3 = uniao(v1, n1, v2, n2);
    printf("V3: ");
    for (i = 0; i < (n1 + n2); i++)
    {
        printf("%d ", v3[i]);
    }
    free(v1);
    free(v2);
    free(v3);
    
    return 0;
}
int *uniao(int *v1, int n1, int *v2, int n2)
{
    int *v3, i, j = 0;

    v3 = (int *)malloc(sizeof(int) * (n1 + n2));
    for (i = 0; i < (n1 + n2); i++)
    {
        if (i < n1)
        {
            v3[i] = v1[i];
        }
        else
        {
            v3[i] = v2[j];
            j++;
        }
    }

    return v3;
}