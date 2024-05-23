#include <stdlib.h>
#include <stdio.h>

int main()
{
	int nbrs[500];
	int candidate;
	int i = 0;
	int j;
	int aux = 1;

	while (i < 500)
	{
		nbrs[i++] = -1;
	}
	i = 0;
	while (i < 500)
	{
		candidate = rand();
		j = -1;
		while (nbrs[++j] != -1)
		{
			if (nbrs[j] == candidate)
				aux = 0;
		}
		if (aux)
		{
			nbrs[i] = candidate;
			i++;
		}
		aux = 1;
	}
	i = -1;
	while (++i < 500)
	{
		printf("%d ", nbrs[i]);
	}
}
