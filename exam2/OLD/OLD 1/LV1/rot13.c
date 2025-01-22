#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void rot13(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'M' || s[i] >= 'a' && s[i] <= 'm')
			ft_putchar((s[i] + 13));
		else if (s[i] >= 'N' && s[i] <= 'Z' || s[i] >= 'n' && s[i] <= 'z')
			ft_putchar((s[i] - 13));
		else
			ft_putchar(s[i]);
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		rot13(av[1]);
	}
	ft_putchar('\n');
	return 0;
}

ft_strcspn()

int i = 0;
int j = 0;
while (s[i])
{
	j = 0;
	while (s2[i])
		if ()
}