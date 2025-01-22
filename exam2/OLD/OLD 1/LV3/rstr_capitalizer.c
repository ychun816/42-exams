#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void rstr_capitalizer(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
		if ((s[i] >= 'a' && s[i] <= 'z') && (s[i + 1] == ' ' || s[i + 1] == '\t' || s[i + 1] == '\0'))
			s[i] = s[i] - 32;
		ft_putchar(s[i]);
		i++;
	}
}



int main(int ac, char *av[])
{
	if (ac == 2)
	{
		rstr_capitalizer(av[1]);
	}
	ft_putchar('\n');
}