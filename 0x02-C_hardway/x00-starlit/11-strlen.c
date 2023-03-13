#include <stdio.h>

/**
 * _strlen - gets length of a string
 * @str: string argument
 *
 * Return: len (string lenght)
 */
size_t _strlen(const char *str)
{
	size_t len;

	while (str[len])
		len++;

	return (len);
}

/**
 * main - _strlen at work
 *
 * Return: 0 (success)
 */
int main(void)
{
	char str[] = "Paul";

	printf("lenght of string %s: %lu\n", str, _strlen(str));
	printf("sizeof %s: %lu\n", str, sizeof(str));

	return (0);
}
