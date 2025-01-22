#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void last_word(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	i--; //back to the pos before '\0'
	while (s[i] > ' ')//32
		i--;//loop back to check spaces -> skip
	i++; //move to the first character of the last word
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int main(int ac, char *av[])
{
	last_word(av[1]);
}