#include <stdio.h>
#include <string.h>

/**
 * main - using strlen to find lenght of a string
 *
 * Return: 0 (success)
 */
int main(void)
{
	char str[] = "How long am I?";

	int i, len;

	len = strlen(str);

	for (i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}
	putchar('\n');
	printf("%d\n", len);

	return (0);
}
