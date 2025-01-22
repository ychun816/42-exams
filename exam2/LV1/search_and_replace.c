/**
 * @note Remember to check: 
 * if (av[2][1] == '\0' && av[3][1] == '\0')
 */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void search_and_replace(char *s, char find, char replace)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == find)
			s[i] = replace;
		ft_putchar(s[i]);
		i++;
	}
}


int main(int ac, char *av[])
{
	if (ac == 4)
	{
		if (av[2][1] == '\0' && av[3][1] == '\0')
			search_and_replace(av[1], av[2][0], av[3][0]);
	}
	ft_putchar('\n');
}