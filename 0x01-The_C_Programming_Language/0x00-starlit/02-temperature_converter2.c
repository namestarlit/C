#include <stdio.h>

/**
 * main - prints Fahrenheit-Celsius Table in reverse
 *
 * Description: using for loop
 *
 * Return: always 0 (success)
 */

int main(void)
{
	int fahr;

	printf("Fahrenheit-Celsius Table\n");

	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d %6.2f\n", fahr, (5.0 / 9.0) * (fahr - 32));

	return (0);
}
