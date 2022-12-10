#include <stdio.h>

/**
 * main - prints Fahrenheit-Celsius table
 * fahr: for fahr = 0, 20, ..., 300; floating-point version
 *
 * Return: always 0 (success)
 */

int main(void)
{
	float fahr, celsius;
	float lower, upper, step;

	/**
	 * lower: lower limit of temperature scale
	 * upper: upper limit
	 * step: step size
	 */

	lower = 0;
	upper = 300;
	step = 20;


	printf("Fahrenheit-Celsius Table\n");

	fahr = lower;

	while (fahr <= upper)
	{
		/**
		 * %3.0f - print at least 3 digits without the decimal part
		 * %6.1f - print at least 6 digits with 1 decimal point
		 */

		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}

	return (0);
}
