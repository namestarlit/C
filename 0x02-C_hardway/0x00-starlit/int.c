#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/**
 * main - stdint.h format specifiers
 *
 * Return: 0 (success)
 */
int main(void)
{
	int8_t i8 = -123;
	uint16_t ui16 = 45678;
	int32_t i32 = -2147483647;
	uint64_t ui64 = 18446744073709551615UL;

	printf("i8 = %" PRId8 "\n", i8);
	printf("ui16 = %" PRIu16 "\n", ui16);
	printf("i32 = %" PRId32 "\n", i32);
	printf("ui64 = %" PRIu64 "\n", ui64);

	return (0);
}
