/**
 * @note
 * STRUCTURE LIKE PUT_NBR!!
 * 
 * FUNCTION:
 * - EASY ft_atoi() -> no skip space / no negative sign
 * - void print_hex(int nb)
 * 
 * @param
 * char hex[] = "0123456789abcdf"
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

void print_hex(int nb)
{
	char hex[] = "0123456789abcdef";

	if (nb >= 16)
		print_hex(nb / 16);
	ft_putchar(hex[nb % 16]);
}

int main(int ac, char *av[])
{
	if (ac == 2)
		print_hex(ft_atoi(av[1]));
	ft_putchar('\n');
}




