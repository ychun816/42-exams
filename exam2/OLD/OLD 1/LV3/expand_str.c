#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void expand_str(char *s)
{
	int i = 0;
	int space = 0; 
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			space = 1;
		if (s[i] != ' ' && s[i] != '\t')
		{
			if (space == 1)
				write(1, "   ", 3);
			write(1, &s[i], 1);	
			space = 0;
		}
		i++;
	}
}

int main(int ac, char *av[1])
{
	if (ac == 2)
		expand_str(av[1]);
	ft_putchar('\n');
	return (0);
}