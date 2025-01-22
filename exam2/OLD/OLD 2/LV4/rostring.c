
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void p_first_word(char *s, int start, int end)
{
	while (start < end)
	{
		write(1, &s[start], 1);
		start++;
	}
}

int skip_space(char *s, int i)
{
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

void rostring(char *s)
{
	int i = 0;
	int fword_start;
	int fword_end;
	// Skip leading spaces
	i = skip_space(s, i);
	// Find the first word's start and end
	fword_start = i;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
		i++;
	fword_end = i;
	// Skip spaces after the first word
	i = skip_space(s, i);
	//check if s[i] not empty (not the end of string)
	//Print the rest of the words after the first
	// if (s[i] != '\0')
	// {
		while (s[i])
		{
			if (s[i] == ' ' || s[i] == '\t')//skip space too!!
			{
				i = skip_space(s, i);
				if (s[i] != '\0')// If it's not the end of the string
					ft_putchar (' ');
			}
			else //not space
			{
				ft_putchar (s[i]);
				i++;
			}
			// i++;
		}
		if (fword_start != fword_end)// If there were more words, add a space before appending the first word at the end
			ft_putchar (' ');// a space needs to be added before appending the first word at the end
	// }
	// Print the first word at the end
	p_first_word(s, fword_start, fword_end);
}

int main(int ac, char *av[])
{
	if (ac > 1)
	{
		rostring(av[1]);
	}
	ft_putchar('\n');
	return 0;
}