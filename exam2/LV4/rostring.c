/**
 * 
 * @param
 * 
 * 
 */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void p_first_wd(char *s, int start, int end)
{
	while (start < end)
	{
		ft_putchar(s[start]);
		start++;
	}
}

int skip_space(char *s, int i)
{
	if (s[i] == ' ' || s[i] == '\t')
		i++;
	return (i);
}

void rostring(char *s)
{
	int i = 0;
	int wd_start = 0;
	int wd_end = 0;

	//skip space
	i = skip_space(s, i);
	//mark first word -start
	wd_start = i;
	//loop to mark first word -end
	while (s[i] != ' ' && s[i] != '\t')
		i++;
	wd_end = i;
	//print the rest
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			i = skip_space(s, i);
			if (s[i] != '\0') // If it's not the end of the string
				ft_putchar(' ');
		}
		else//not space
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	if (wd_start != wd_end)
        ft_putchar(' ');
	p_first_wd(s, wd_start, wd_end);
}

