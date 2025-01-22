#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void repeat_alpha(char *s)
{
	int i;
	int repeat;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			repeat = s[i] - 'A';
			while (repeat-- >= 0)// create repeat to loop decrement
			{
				ft_putchar(s[i]);
			}
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			repeat = s[i] - 'a';
			while (repeat-- >= 0)// create repeat to loop decrement
			{
				ft_putchar(s[i]);
			}
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
		repeat_alpha(av[1]);
	}
	ft_putchar('\n');
	return 0;
}

