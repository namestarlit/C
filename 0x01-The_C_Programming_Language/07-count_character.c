#include <stdio.h>

/**
 * main - counts characters
 *
 * Return: always 0 (success)
 */

int main(void)
{
	/* use long for counter precision */
	/* use long for counter precision */


	long nc;

	nc = 0;

	while (getchar() != EOF)
	{
		++nc;
		printf("%ld\n", nc);
	}

	return (0);
}
