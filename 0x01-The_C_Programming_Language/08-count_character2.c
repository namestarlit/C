#include <stdio.h>

/**
 * main - counts characters
 *
 * Return: always 0 (success)
 */

int main(void)
{
	/* use double to increase precison */

	double nc;

	/**
	 * The semicolon (;) below the loop
	 * is there to terminate the loop
	 * it serves as the body of the loop
	 */

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("\n%.f character(s)\n", nc);

	return (0);
}
