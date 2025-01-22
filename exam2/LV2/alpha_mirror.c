/**
 * @note
 * MIRROR : [HEAD] + [END] - [CURRENT ALPHA]
 * s[i] = 'A' + 'Z' - s[i];
 * s[i] = 'a' + 'z' - s[i];
 */
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void alpha_mirror(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = 'A' + 'Z' - s[i];
		else if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = 'a' + 'z' - s[i];
		ft_putchar(s[i]);
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		alpha_mirror(av[1]);
	}
	ft_putchar('\n');
}