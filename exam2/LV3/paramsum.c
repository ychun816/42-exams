#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void putnb(int nb)
{
	if (nb >= 10)
		putnb(nb / 10);
	ft_putchar((nb % 10) + 48);
}

int main(int ac, char *av[])
{
	(void)av;
	putnb(ac - 1);
	ft_putchar('\n');
}