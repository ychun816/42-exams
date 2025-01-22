/**
 * @note 
 * The program prints characters that are common between the two input strings, 
 * in the order they appear in the first string.
 * 
 * @note 
 * DECLARE unsigned char check[256] = {0};
 * MARK PRINTED CHARACTER AS : check[(int)s1[i]] = 1
 * USE BREAK => Stop further checking for this character in s2
 * 
 * @note
 * -> LOOP S1(SHORT STRING) FIRST
 * -> j = 0 inside first loop -> loop s2(long str) secondly
 */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void inter(char *s1, char *s2)
{
	unsigned char check[256] = {0};
	int i = 0;
	int j;

	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
			{
				if (check[(unsigned char)s1[i]] == 0)
				{
					ft_putchar(s1[i]);
					check[(unsigned char)s1[i]] = 1;
					break ; //stop further check for this character in s2
				}
			}
			j++;
		}
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 3)
	{
		inter(av[1], av[2]);
	}
	ft_putchar('\n');
	return (0);
}
