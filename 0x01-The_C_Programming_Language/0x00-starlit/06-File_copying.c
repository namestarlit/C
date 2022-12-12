#include <stdio.h>

/**
 * main - replaces replaces mutiple blanks with a single blank
 *
 * Return: always 0 (success)
 */

int main(void)
{
	/**
	 * c = character
	 * prev_c = previous character
	 */

	char c;
	char prev_c;

	prev_c = 0;

	while ((c = getchar()) != EOF)
	{
		/**
		 * Either the previous character
		 * or the next character is
		 * equal to space, read character
		 */

		if (c != ' ' || prev_c != ' ')
		{
			prev_c = c;
			putchar(c);
		}
	}

	return (0);
}
