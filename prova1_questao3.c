#include <stdio.h>

int quantosMenores(int *pN, unsigned int n);

int main( )
{
	int v[] = {3, 9, 4, 6, 7, 5};
	int n = 6, c;

	c = quantosMenores(v, n);

	printf("%d", c);

	return 0;
}
int quantosMenores(int *pN, unsigned int n)
{
	int i, c = 0;
	
	for (i = 0; i < n - 1; i++)
	{
		if (pN[i] > pN[i + 1])
		{
			c++;
		}
		else if ((pN[i] > pN[i + 2]) && (i < n - 2))
		{
			c++;
		}
		else if ((pN[i] > pN[i + 3]) && (i < n - 3))
		{
			c++;
		}
		else if ((pN[i] > pN[i + 4]) && (i < n - 4))
		{
			c++;
		}
		else if ((pN[i] > pN[i + 5]) && (i < n - 5))
		{
			c++;
		}
	}
	
	return c;
}
