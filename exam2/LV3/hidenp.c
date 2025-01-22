/**
 * @note
 * put "return ;" after print '1' :
 * after finding all characters of find in s and printing '1', 
 * the program would continue looping through the rest of s unnecessarily, 
 * even though the result has already been determined.
 */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void hidenp(char *find, char *s)
{
	int i = 0;
	int j = 0;
	while (s[i])
	{
		if (s[i] == find[j])
			j++;
		if (find[j] == '\0')
		{
			ft_putchar('1');
			return ;//stop the loop!! (like wdmatch, but wdmatch would print whole string)
		}
		i++;
	}
	ft_putchar('0');
}

int main(int ac, char *av[])
{
	if (ac == 3)
	{
		hidenp(av[1], av[2]);
	}
	ft_putchar('\n');
}