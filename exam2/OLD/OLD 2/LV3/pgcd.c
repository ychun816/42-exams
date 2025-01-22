#include <stdio.h>
#include <stdlib.h>
//最大公因数

// void ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

int pgcd(int n1, int n2)
{
	while (n1 != n2)
	{
		if (n1 > n2)
			n1 = n1 - n2;
		else
			n2 = n2 - n1;
	}
	return (n1);//// When nbr1 == nbr2, that's the GCD, so return it
}

int main(int ac, char *av[])
{
	if (ac == 3)
	{
		if (atoi(av[1]) > 0 && atoi(av[2]) > 0)
			printf("%d", pgcd(atoi(av[1]), atoi(av[2])));
	}
	printf("\n");
}