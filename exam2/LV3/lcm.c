/**
 * @note lcm = Lowest Common Multiple 最小公倍数
 * @param 
 * unsigned int lcm = 0;
 * 
 * @note
 * 1. Check if a OR b == 0 => return (0)
 * 2. Initiate lcm => Pick the bigger one to start
 * 3. lcm % a == 0 && lcm % b == 0 
 *  
 */

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int lcm = 0;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		lcm = a;
	else
		lcm = b;
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return (lcm);
		lcm++;
	}
}
