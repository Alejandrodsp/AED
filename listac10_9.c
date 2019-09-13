#include <stdlib.h>
#include <stdio.h>
int main()
{
    int *v, i = 0;
    v = (int *)malloc(sizeof(int));
    scanf("%d", &v[i]);
    i++;
    do
    {
        v = realloc(v, sizeof(int) * (i + 1));
        scanf("%d", &v[i - 1]);
        i++;
    } while (v[i - 2] != -1);
    free(v);
    return 0;
}
