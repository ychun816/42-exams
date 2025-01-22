#include <stdio.h>
#include <stdlib.h>

void fprime(int nb)
{
	int prime = 2;

	if (nb == 1)
	{
		// printf("1");
		return ;
	}
	while (prime <= nb)
	{
		if (nb % prime == 0)
		{
			printf("%i", prime);
			if (nb == prime)
				break;
			printf("*");
			nb = nb / prime;//reduce number and keep checking until number becomes 1. This allows you to find all prime factors, including repeated factors.
			prime = 1;
		}
		prime++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		fprime(atoi(av[1]));
	}
	printf("\n");
}