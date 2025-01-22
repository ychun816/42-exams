/**
 * @note 
 * Takes two strings and prints all the unique characters that appear in either one of the strings, 
 * without any duplicates. 
 * It does this in the order the characters appear in the input.
 * 
 * @note
 * SEPERATELY PROCESS s1 & s2: First s1; Then s2
 * 
 * @note
 * Create : unsigned char check[256] = {0}
 * 
 */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_union(char *s1, char *s2)
{
	unsigned char check[256] = {0};
	int i = 0;
	int j = 0;

	//first str
	while (s1[i])
	{
		if (check[(unsigned int)s1[i]] == 0)
		{
			ft_putchar(s1[i]);
			check[(unsigned int)s1[i]] = 1;
		}
		i++;
	}
	//second str
	while (s2[j])
	{
		if (check[(unsigned int)s2[j]] == 0)
		{
			ft_putchar(s2[j]);
			check[(unsigned int)s2[j]] = 1;
		}
		j++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 3)
	{
		ft_union(av[1], av[2]);
	}
	ft_putchar('\n');
}