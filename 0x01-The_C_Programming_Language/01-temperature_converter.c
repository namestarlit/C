#include <stdio.h>

/**
 * main - prints Fahrenheit-Celsius table
 * fahr: for fahr = 0, 20, ..., 300
 *
 * Return: always 0 (success)
 */

int main(void)
{
	int fahr, celsius;
	int lower, upper, step;

	/**
	 * lower: lower limit of temperature scale
	 * upper: upper limit
	 * step: step size
	 */

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	while (fahr <= upper)
	{
		/**
		 * multiply by five first then divede by 9
		 * otherwise / will truncate any fractional part
		 * hence you 5/9 will result to zero
		 */

		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
	return (0);
}
