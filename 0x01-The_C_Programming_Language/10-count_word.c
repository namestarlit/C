#include <stdio.h>

/* inside a word */
#define IN 1
/* outside a word */
#define OUT 0

/**
 * main - counts lines, words, and characters in iput
 *
 * Return: always 0 (success)
 */

int main(void)
{
	int c, nl, nw, nc, state;

	state = OUT;

	nl = nw = nc = 0;

	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
		{
			++nl;
		}
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
		printf("%d line(s)\n%d word(s)\n%d character(s)\n", nl, nw, nc);

		return (0);
}
