#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int f_atoi(char *s)
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

void print_hex(int nb)
{
	char hex_digits[] = "0123456789abcdef";

	if (nb >= 16)
		print_hex(nb / 16);
	ft_putchar(hex_digits[nb % 16]);
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		print_hex(f_atoi(av[1]));
	}
	ft_putchar('\n');
}