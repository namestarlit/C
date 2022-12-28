#include <stdio.h>

/**
 * main - demonstrates format specifiers
 *
 * Return: 0 (success)
 */

int main(void)
{
	int i = 123;
	float f = 3.14159;
	double d = 5639.89000;
	char c = 'A';
	char str[] = "Hello, World!";

	printf("Character: %c\n", c);
	printf("Integer: %d\n", i);
	printf("Float: %.2f\n", f);
	printf("double: %.2lf\n", d);
	printf("String: %s\n", str);
	printf("Hexadecimal: %x\n", i);
	printf("Octal: %o\n", i);
	printf("Scientific notation: %e\n", d);
	printf("Shorter: %g\n", d);
	printf("Pointer address: %p\n", &str);
	
	return (0);
}
