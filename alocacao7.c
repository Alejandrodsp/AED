#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int *valores_entre(int *v, int n, int min, int max, int *qtd);
int main()
{
    int *v_min_max, *v;
    int n = 10, q = 0, min, max, i;

    v = (int *)malloc(sizeof(int) * 10);
    for (i = 0; i < n; i++)
    {
        v[i] = 10 + i;
        printf("%d ", v[i]);
    }
    printf("Informe os valor min e max: \n");
    scanf("%d %d", &min, &max);
    v_min_max = valores_entre(v, n, min, max, &q);
    if (v_min_max != NULL)
    {
        for (i = 0; i < q; i++)
        {
            printf("%d ", v_min_max[i]);
        }
    }
    else
    {
        printf("Nenhum numero do vetor esta entre os valores min e max!\n");
    }
    free(v);
    free(v_min_max);

    return 0;
}
int *valores_entre(int *v, int n, int min, int max, int *qtd)
{
    int i, *vetor, j = 0;
    for (i = 0; i < n; i++)
    {
        if (v[i] > min && v[i] < max)
        {
            (*qtd)++;
        }
    }
    if ((*qtd) > 0)
    {
        vetor = (int *)malloc(sizeof(int) * (*qtd));
        for (i = 0; i < n; i++)
        {
            if (v[i] > min && v[i] < max)
            {
                vetor[j] = v[i];
                j++;
            }
        }
        return vetor;
    }
    else
    {
        return NULL;
    }
}