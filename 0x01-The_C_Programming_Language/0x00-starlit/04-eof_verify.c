#include <stdio.h>

/**
 * main - verify value of getchar() != EOF
 *
 * Description: prompts for input, read input
 * prints 1 for Ctrl -D or Ctrl -Z (program termination)
 * and 0 otherwise.
 *
 * Return: always 0 (success)
 */

int main(void)
{
	printf("Press any key...:\n");
	printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF);

	return (0);
}
