#include <stdlib.h>
//count nb len
int f_nblen(int nb)
{
	int len = 0;
	//nb==0
	if (nb == 0)
		return (1);
	//nb<0
	if (nb < 0)
	{
		nb = -nb;
		len++; // Count for the '-' sign
	}
	while (nb > 0)
	{
		nb = nb / 10;//count digits
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int nblen;
	char *result;
	long nb = nbr;// Use long to avoid overflow issues with -2147483648
	
	// Handle the edge case for the smallest integer
	if (nb == -2147483648)
		return ("-2147483648\0");
	// Count the length of the number
	nblen = f_nblen(nb);
	// Malloc for the result string
	result = (char *)malloc(sizeof(char) * (nblen + 1));
	if (!result)
		return (NULL);
	// Null-terminate the string!!
	result[nblen] = '\0';
	//handle nb == 0
	if (nbr == 0)//check if the original input value (nbr) is zero
	{
		result[0] = '0';
		return (result);
	}
	//handle nb < 0
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	// Fill the result string with digits
	while (nb)
	{
		result[--nblen] = (nb % 10) + 48;// Fill the string from the end
		nb = nb / 10;// Reduce the number
	}
	return (result);
}
#include <stdio.h>
int main(int ac, char *av[])
{
	printf("%s\n", ft_itoa(atoi(av[1])));
}