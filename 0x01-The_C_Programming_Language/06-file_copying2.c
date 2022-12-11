#include <stdio.h>

/**
 * main - file copying
 *
 * Description: copies its input to its output
 *
 * Return: always 0 (success)
 */

int main(void)
{
	int c;

	/**
	 * the brackets around c = getchar()
	 * assignment are necessary
	 * otherwise != will test the ralational
	 * test before the assignment
	 * c = getchar() != EOF
	 * is equivalent to c = (getchar() != EOF
	 */

	while ((c = getchar()) != EOF)
		putchar(c);

	return (0);
}
