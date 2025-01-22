int	    is_power_of_2(unsigned int n)
{
	int nb = 1;
	while (nb <= n)
	{
		if (nb == n)
			return (1);//is pwer of 2
		nb = nb * 2;
	}
	reutn (0);	
}
//If at any point test becomes equal to n, that means n is a power of 2, because test is always a power of 2 (from multiplying by 2 in each iteration).