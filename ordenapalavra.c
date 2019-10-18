#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *string, temp;
    int i, j;

    string = (char *)malloc(sizeof(char) * 20);

    printf("Informe a palavra: ");
    scanf("%s", string);

    for (i = 0; i < strlen(string) - 1; i++)
    {
        for (j = 0; j < strlen(string) - i - 1; j++)
        {

            if (string[j] > string[j + 1])
            {

                temp = string[j];
                string[j] = string[j + 1];
                string[j + 1] = temp;
            }
        }
    }
    printf("Palavra ordenada: %s", string);

    return 0;
}
