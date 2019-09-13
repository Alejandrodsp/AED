#include <stdio.h>
#include <stdlib.h>
void min_max(int *v, int *min, int *max);
int main()
{
    int *v, min, max, n = 10, i;
    v = (int *)malloc(sizeof(int) * n);
    printf("Vetor: ");
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        v[i] = rand() % 100;
        printf("%d ", v[i]);
    }
    printf("\n");
    min_max(v, &min, &max);
    printf("Valor minimo do vetor: %d", min);
    printf("Valor maximo do vetor: %d", max);
    return 0;
}
void min_max(int *v, int *min, int *max)
{
    int i;
    *min = v[0];
    *max = v[0];
    for (i = 0; i < 10; i++)
    {
        if (v[i] > *max)
        {
            *max = v[i];
        }
        if (v[i] < *min)
        {
            *min = v[i];
        }
    }
}