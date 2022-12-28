#include <stdio.h>

/**
 * main - demonstarates escape codes
 *
 * Return: 0 (success)
 */

int main(void)
{
	puts("Alert: \a");
	puts("Backspace: Hello\bWorld");
	puts("Form feed: Hello\fWorld");
	puts("Newline: Hello\nWorld");
	puts("Carriage Return: Hello\rWorld");
	puts("Horizontal Tab: Hello\tWorld");
	puts("Vertical Tab: Hello\vworld");
	puts("Backslash: Hello\\world");
	puts("Single Quote: Hello \'World\'");
	puts("Double Quote: Hello \"World\"");
	puts("Question Mark: Hello\? World");
	puts("Octal Number: Hello\012World");
	puts("Hexadecimal Number: Hello\x0aWorld");

	return (0);
}
