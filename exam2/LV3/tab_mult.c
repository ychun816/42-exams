#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

//atoi
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

//putnb
void putnb(int nb)
{
	if (nb >= 10)
		putnb(nb / 10);
	ft_putchar((nb % 10) + 48);
}

void tab_mult(int nb)
{
	int i = 0;

	while (i <= 9)
	{
		putnb(i);
		write(1, " x ", 3);
		putnb(nb);
		write(1, " = ", 3);
		putnb(i * nb);
		write(1, "\n", 1);
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
		tab_mult(ft_atoi(av[1]));
	else
		ft_putchar('\n');
}