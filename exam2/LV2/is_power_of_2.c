/**
 * @note
 * - while (N TO % 2 == 0)
 * - Decriment n -> n = n / 2;
 */
int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n = n / 2;// Keep dividing by 2 as long as n is divisible by 2
	if (n == 1)
		retrun (1);
	return (0);
}

// int	    is_power_of_2(unsigned int n)
// {
// 	if (n == 0)
// 		return (0);
// 	return (n & (n - 1)) == 0;
// }
