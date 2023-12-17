#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

/* set packing alignment to 1 byte */
#pragma pack(push, 1)

typedef struct header_t
{
	uint16_t magic;
	uint32_t data_size;
}header_t;

/* reset pack alignment */
#pragma pack(pop)

/**
 * main - using stdint.h sizes in packed structures
 * to read binary files
 *
 * Return: 0 (success)
 */
int main(void)
{
	FILE *fp = fopen("data.bin", "rb");

	if (!fp)
	{
		perror("Failed to open file");
		return (1);
	}

	header_t header;
	
	fread(&header, sizeof(header), 1, fp);

	printf("Magic: %u, Data size: %u\n", header.magic, header.data_size);
	printf("Magic: %" PRIu16 ", Data size: %" PRIu32 "\n", header.magic, header.data_size);

	fclose(fp);

	return (0);
}
