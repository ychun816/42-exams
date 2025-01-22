#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int f_atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int nb = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		s[i]++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + (s[i] - 48);
		i++;
	}
	return (nb *sign);
}

void putnb(int nb)
{
	if (nb >= 10)
		putnb(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void tab_mult(int nb)
{
	int i = 1;
	while (i <= 9)
	{
		putnb(i);
		ft_putstr(" x ");
		putnb(nb);
		ft_putstr(" = ");
		putnb(nb * i);
		ft_putchar('\n');
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac != 2)
		ft_putchar('\n');
	else
	{
		tab_mult(f_atoi(av[1]));
	}
}