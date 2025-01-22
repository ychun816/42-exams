
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void f_union(char *s1, char *s2)
{
	int i = 0;
	int check[256] = {0};
	while (s1[i++])
		check[(int)s1[i]] = 1;
	i = 0;
	while (s2[i++])
		check[(int)s2[i]] = 1;
	i = 0;
	while (s1[i])
	{
		if (check[(int)s1[i]] == 1)
		{
			ft_putchar(s1[i]);
			check[(int)s1[i]] = 0;
		}
		i++;
	}
	i = 0;
	while (s2[i])
	{
		if (check[(int)s2[i]] == 1)
		{
			ft_putchar(s2[i]);
			check[(int)s2[i]] = 0;
		}
		i++;
	}

}

int main(int ac, char *av[])
{
	if (ac == 3)
	{
		f_union(av[1], av[2]);
	}
	ft_putchar('\n');
	return (0);
}