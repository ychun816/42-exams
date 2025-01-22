/**
 * FUNCTIONS:
 * - ft_nlben
 * - itoa
 * 
 * @param
 * For itoa():
 * int len = 0; len = ft_nblen()
 * long lnb = 0;
 * char *res = (char *)malloc(sizeof(char) * (len + 1));
 * 
 * 
 */
#include <stdlib.h>

//nblen
int ft_nblen(int nb)
{
	int len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len++);
}

//itoa
char *ft_itoa(int nbr)
{
	int len = 0;
	long lnb = 0;
	char *res;

	if (nbr == -2147483648)
		return (-2147483648);
	lnb = nbr;//use long int to calculate
	len = ft_nblen(lnb);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len--] = '\0';//null terminate! 
	//nb == 0
	if (lnb == 0)
	{
		res[0] = '0';
		return (res);
	}
	//nb < 0
	if (lnb < 0)
	{
		res[0] = '-';
		lnb = -lnb;
	}
	//nb > 0
	while (lnb > 0)
	{
		res[len--] = (lnb % 10) + 48; // Convert digit to character
		lnb = lnb / 10;
	}
	return (res);
}

#include <stdio.h>
int main()
{
	printf("%s\n", ft_itoa(3));
	printf("%s\n", ft_itoa(-3));
	printf("%s\n", ft_itoa(42));
}