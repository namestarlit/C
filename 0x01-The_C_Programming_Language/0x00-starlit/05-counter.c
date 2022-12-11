#include <stdio.h>

/**
 * main - counts blanks, tabs, and newlines
 *
 * Return: always 0 (seccess)
 */

int main(void)
{
	/**
	 * c = character
	 * b = blanks
	 * t = tabs
	 * l = newlines
	 */

	int c, b, t, l;

	b = t = l = 0;

	while ((c = getchar()) != EOF)
	{

		if (c == ' ')
			++b;

		if (c == '\t')
			++t;

		if (c == '\n')
			++l;
	}

	printf("-----------------------------------------------");
	printf("\n%d space(s)\n%d tab(s)\n%d line(s)\n", b, t, l);

	return (0);
}
