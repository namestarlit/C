#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/**
 * main - using stdint.h sizes
 *
 * Return: 0 (success)
 */
int main(void)
{
	int16_t int16 = 12846;
	uint32_t uint32 = 4542358;

	printf(" %" PRId16 ", %" PRIu32 "\n", int16, uint32);

	return (0);
}
