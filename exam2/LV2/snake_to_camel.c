/**
 * @note 
 * !!! When find '_' => Increment i by one, then print / else -> print the rest
 * 
 * 		if (s[i] == '_')
		{
			i++;
			ft_putchar(s[i] - 32);
		}
		else
			ft_putchar(s[i]);
 */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void snake_to_camel(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] == '_')
		{
			i++;
			ft_putchar(s[i] - 32);
		}
		else
			ft_putchar(s[i]);
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		snake_to_camel(av[1]);
	}
	write(1, "\n", 1);
	return 0;
}