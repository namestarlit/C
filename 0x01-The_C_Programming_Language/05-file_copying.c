#include <stdio.h>

/**
 * main - file copying
 *
 * Description: copies it's input to its output
 *
 * Return: always 0 (success)
 */

int main(void)
{
	/**
	 * use int so it's big enough
	 * to hold EOF (end-of-file value)
	 * char cannot
	 */

	int c;

	/**
	 * getchar() - reads a character
	 * putchar() - prints a character
	 */

	c = getchar();

	while (c != EOF)
	{
		putchar (c);
		c = getchar();
	}

	return (0);
}
