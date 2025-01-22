/**
 * @param
 * int i = 0;
 * int last_word_start = 0;
 * 
 * @note
 * - First while (s[i])
 * - Then check if space && printable : if (s[i] == ' ' && s[i] >= '!' && s[i] <= '~')
 * - Mark last word start + Print last word : while (s[i] >= '!' && s[i] <= '~')
 * - use last_word_start -> mark the start of last word
 */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void last_word(char *s)
{
	int i = 0;
	int lastwd_start = 0;
	
	//check for space & printable character ('!'(33) - '~'(126))
	//mark start for last word
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] >= '!' && s[i + 1] <= '~')
		{
			lastwd_start = i + 1;
			i++;
		}
		i++;
	}
	//print last word
	while (s[lastwd_start] >= '!' && s[lastwd_start] <= '~')
	{
		ft_putchar(s[lastwd_start]);
		lastwd_start++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		last_word(av[1]);
	}
	ft_putchar('\n');
	return (0);
}