/**
 * @param
 * int i = 0;
 * int space_flag = 0;
 * 
 * @note
 * 1. Skip spaces : while (s[i] == ' ' || s[i] == '\t'), i++
 * 2. While (s[i]), 
 *    2-1 First set space flag = 1 to spaces
 * 	  2-2 Check non-space character, put one space before the start of a word
 * 
 * 		if (s[i] != ' ' && s[i] != '\t')
		{
			if (space == 1)
			{
				ft_putchar(' ');
				space = 0;
			}
			ft_putchar(s[i]);
		}
 * 
 * 
 */
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void epur_str(char *s)
{
	int i = 0;
	int space = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			space = 1;
		if (s[i] != ' ' && s[i] != '\t')
		{
			if (space == 1)
			{
				ft_putchar(' ');//the one space before the first character of a word inside the str
				space = 0;
			}
			ft_putchar(s[i]);
		}
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		epur_str(av[1]);
	}
	ft_putchar('\n');
}

/*
Why can space flag be 1 during a non-space character?

-> It is because space flag retains the value from the previous space(s) encountered 
   until the next non-space character is processed.
-> When a non-space character is encountered after spaces, 
   the function checks flg, finds it 1, 
   prints a space (to separate words), 
   and then resets space flag to 0, to signify that we are now in a non-space section.
*/