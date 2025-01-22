#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void putnb(int nb)
{
	if (nb > 9)
	{
		putnb(nb / 10);
		putnb(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void fizzbuzz(int nb)
{
	while (nb <= 100)
	{
		if (nb % 3 == 0)
			ft_putstr("fizz\n");
		else if (nb % 5 == 0) 
			ft_putstr("buzz\n");
		else if (nb % 3 == 0 && nb % 5 == 0)
			ft_putstr("fizzbuzz\n");
		else
		{
			putnb(nb);
			ft_putchar('\n');
		}
		nb++;
	}

}


int main()
{
	fizzbuzz(0);
	return 0;
}