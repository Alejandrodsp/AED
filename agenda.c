#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *inserir(void *pBuffer);
void buscar(void *pBuffer, char *busca);
void listar(void *pBuffer);
void *apagar(void *pBuffer, char *busca);
int main()
{
  void *pBuffer;
  char *busca;
  pBuffer = malloc(sizeof(int) * 3); //1º numero de elementos, 2º controle repetição, 3º controle escolha
  *(int *)pBuffer = 0;
  for (;;)
  {
    printf("AGENDA ALEJANDRO\n");
    printf("1)Inserir\n");
    printf("2)Buscar\n");
    printf("3)Apagar\n");
    printf("4)Listar\n");
    printf("5)Sair\n");
    scanf("%d", (int *)(pBuffer + (2 * sizeof(int))));
    switch (*(int *)(pBuffer + (2 * sizeof(int))))
    {
    case 1:
      pBuffer = inserir(pBuffer);
      break;
    case 2:
      busca = (char *)malloc(sizeof(char) * 10);
      printf("Informe o nome que deseja buscar: ");
      scanf("%s", busca);
      buscar(pBuffer, busca);
      free(busca);
      break;
    case 3:
      busca = (char *)malloc(sizeof(char) * 10);
      printf("Informe o nome que deseja apagar: ");
      scanf("%s", busca);
      pBuffer = apagar(pBuffer, busca);
      free(busca);
      break;
    case 4:
      listar(pBuffer);
      break;
    case 5:
      free(pBuffer);
      exit(0);
      break;

    default:
      printf("Opcao invalida");
      break;
    }
  }
  return 0;
}
void *inserir(void *pBuffer)
{

  pBuffer = realloc(pBuffer, 12 + (14 * ((*(int *)pBuffer) + 1)));
  printf("Informe o nome: ");
  scanf("%s", (char *)(pBuffer + (12 + (*(int *)pBuffer) * 14)));
  printf("Informe o numero: ");
  scanf("%d", (int *)(pBuffer + (12 + (*(int *)pBuffer) * 14) + 10));
  *(int *)pBuffer = *(int *)pBuffer + 1;

  return pBuffer;
}
void buscar(void *pBuffer, char *busca)
{

  for (*(int *)(pBuffer + 4) = 0; *(int *)(pBuffer + 4) < *(int *)pBuffer; *(int *)(pBuffer + 4) = *(int *)(pBuffer + 4) + 1)
  {
    if (strcmp((pBuffer + (12 + (14 * *(int *)(pBuffer + 4)))), busca) == 0)
    {
      printf("Nome: %s\n", (char *)(pBuffer + (12 + (14 * *(int *)(pBuffer + 4)))));
      printf("Telefone: %d\n", *(int *)(pBuffer + (10 + 12 + (14 * *(int *)(pBuffer + 4)))));
    }
  }
}
void listar(void *pBuffer)
{

  for (*(int *)(pBuffer + 4) = 0; *(int *)(pBuffer + 4) < *(int *)pBuffer; *(int *)(pBuffer + 4) = *(int *)(pBuffer + 4) + 1)
  {
    printf("Nome: %s\n", (char *)(pBuffer + (12 + (14 * *(int *)(pBuffer + 4)))));
    printf("Telefone: %d\n", *(int *)(pBuffer + (10 + 12 + (14 * *(int *)(pBuffer + 4)))));
  }
}
void *apagar(void *pBuffer, char *busca)
{

  for (*(int *)(pBuffer + 4) = 0; strcmp((pBuffer + (12 + (14 * *(int *)(pBuffer + 4)))), busca) != 0; *(int *)(pBuffer + 4) = *(int *)(pBuffer + 4) + 1)
  {
  }
  for (*(int *)(pBuffer + 4) = *(int *)(pBuffer + 4); *(int *)(pBuffer + 4) < *(int *)pBuffer; *(int *)(pBuffer + 4) = *(int *)(pBuffer + 4) + 1)
  {
    strcpy((char *)(pBuffer + (12 + (14 * *(int *)(pBuffer + 4)))), (char *)(pBuffer + (12 + (14 * (1 + *(int *)(pBuffer + 4))))));
    *(int *)(pBuffer + (10 + 12 + (14 * *(int *)(pBuffer + 4)))) = *(int *)(pBuffer + (10 + 12 + (14 * (1 + *(int *)(pBuffer + 4)))));
  }
  *(int *)pBuffer = *(int *)pBuffer - 1;
  pBuffer = realloc(pBuffer, 12 + (14 * ((*(int *)pBuffer))));

  return pBuffer;
}
