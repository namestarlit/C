#include <stdio.h>

/**
 * main - counts lines
 *
 * Return: always 0 (success)
 */

int main(void)
{
	int c, nl;

	nl = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')
		{
			++nl;
		}
	}
	printf("\n%d line(s)\n", nl);

	return (0);
}

