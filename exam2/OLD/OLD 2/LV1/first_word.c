
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void first_word(char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' | s[i] == '\t')
		i++;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
	{
		ft_putchar(s[i]);
		i++;
	}
}


int main(int ac, char *av[])
{
	if (ac == 2)
	{
		first_word(av[1]);
	}
	ft_putchar('\n');
	return 0;
}