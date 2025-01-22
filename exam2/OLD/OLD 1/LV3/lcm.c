unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int nb;
	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		nb = a;
	else
		nb = b;
	while (1)
	{
		if (nb % a == 0 && nb % b == 0)
			return (nb);
		++nb;
	}
}
#include <stdio.h>
int main(void)
{
    // Test cases
    printf("LCM of 4 and 6: %u\n", lcm(4, 6));  // Expected output: 12
    printf("LCM of 0 and 5: %u\n", lcm(0, 5));  // Expected output: 0 (LCM with 0 is 0)
    printf("LCM of 7 and 3: %u\n", lcm(7, 3));  // Expected output: 21
    printf("LCM of 10 and 15: %u\n", lcm(10, 15));  // Expected output: 30
    printf("LCM of 9 and 12: %u\n", lcm(9, 12));  // Expected output: 36
    printf("LCM of 1 and 1: %u\n", lcm(1, 1));  // Expected output: 1

    return 0;
}