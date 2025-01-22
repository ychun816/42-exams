#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void str_capitalizer(char *s)
{
	int i = 0;
	while (s[++i])
	{
		//cap to low
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = s[i] + 32;
		//turn []low to cap
		if ((s[i] >= 'a' && s[i] <= 'z') && (s[i - 1] == ' ' || s[i - 1] == '\t'))
			s[i] = s[i] - 32;
		ft_putchar(s[i]);
		// i++;
	}
}


int main(int ac, char *av[])
{
	if (ac == 2)
	{
		str_capitalizer(av[1]);
	}
	ft_putchar('\n');
}