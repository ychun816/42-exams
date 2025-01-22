
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void inter(char *s1, char *s2)
{
	int check[256] = {0};
	int i = 0;
	int j = 0;
	
	// looping over the whole first string
	// comparing against every character in the second string
	while (s2[i])
	{
		j = 0;
		while (s1[j])
		{
			if (s2[i] == s1[j] && check[(int)s1[j]] == 0)
			{
				ft_putchar(s1[j]);
				check[(int)s1[j]] = 1;//mark as printed
			}
			j++;
		}
		i++;
	}
}

int main(int ac, char *av[1])
{
	if (ac == 3)
	{
		inter(av[1], av[2]);
	}
	ft_putchar('\n');
	return (0);
}