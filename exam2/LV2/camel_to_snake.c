/**
 * @note
 * !!! Cap to Low => No need to print out
 * 
 * 		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
			ft_putchar('_');
		}
			ft_putchar(s[i]);
 * 
 * 
 */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void camel_to_snake(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
			ft_putchar('_');
		}
			ft_putchar(s[i]);
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		camel_to_snake(av[1]);
	}
	write(1, "\n", 1);
	return 0;
}