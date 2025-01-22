#include <unistd.h>

/**
 * @param
 * unsigned char bit;
 * int i = 8;
 * 
 * @note
 * - while (i--)
 * - bit = (octet >> i & 1) + 48;
 * 
 * @note
 * If the result of the right shift was 1, 
 * & 1 returns 1, indicating that the original bit was 1. 
 * 
 * If the result was 0, & 1 returns 0, indicating that the original bit was 0.
 */

void	print_bits(unsigned char octet)
{
	unsigned char bit = 0;
	int i = 8;

	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
}
