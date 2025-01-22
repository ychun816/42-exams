#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void rev_print(char *s)
{
	int i;

	i = ft_strlen(s);
	while(i--)
	{
		ft_putchar(s[i]);
	}
}


int main(int ac, char *av[])
{
	if (ac == 2)
	{
		rev_print(av[1]);
	}
	ft_putchar('\n');
	return 0;
}