/**
 * FUNCTION:
 * - EASY atoi()
 * - EASY putnb()
 * - is_prime()
 * - add_prime_sum()
 * 
 * @note
 * 
 *  int is_prime(int nb)
	{
		int prime = 2;
		if (nb <= 1)
			return (0);
		while (prime * prime <= nb)
		{
			if (nb % prime == 0)
				return (0);//is prime
			prime++;
		}
		return (1);
	}
 * 
 * 
 */
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_atoi(char *s)
{
	int i = 0;
	int nb = 0;
	while (s[i])
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	return (nb);
}

void putnb(int nb)
{
	if (nb >= 10)
		putnb(nb / 10);
	ft_putchar((nb % 10) + 48);
}

int is_prime(int nb)
{
	int prime = 2;
	if (nb <= 1)
		return (0);
	while (prime * prime <= nb)
	{
		if (nb % prime == 0)
			return (0);//is prime
		prime++;
	}
	return (1);
}

void add_prime_sum(int nb)
{
	int sum = 0;
	while (nb)
	{
		if (is_prime(nb) == 1)
			sum = sum + nb;
		nb--;
	}
	putnb(sum);
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		add_prime_sum(ft_atoi(av[1]));
	}
	else
		putnb(0);
	ft_putchar('\n');
}