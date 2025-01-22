#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void epur_str(char *s)
{
	int i = 0;
	int space_flag = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			space_flag = 1;
		if (!(s[i] == ' ' || s[i] == '\t'))// If the current character is not a space or tab
		{
			if (space_flag == 1)//// If a space or tab was encountered before this character, print a single space
				write(1, " ", 1);
			space_flag = 0;
			write(1, &s[i], 1);
		}
		i++;
	}
}

int main(int ac, char *av[1])
{
	if (ac == 2)
		epur_str(av[1]);
	ft_putchar('\n');
	return (0);
}