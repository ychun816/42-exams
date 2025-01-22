#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);	
}

void rev_wstr(char *s)
{
	int i = 0;
	int start;
	int end;
	int flag;
	
	//count s len
	while (s[i])
		i++;
	//mark starts/ends:  loop rev i--
	while (i >= 0)
	{
		//skip space
		while ((s[i] == '\0' || s[i] == ' ' || s[i] == '\t'))
			i--;
		//mark word end
		end = i;
		//move i to word start
		while (s[i] != '\0' && (s[i] != '\0' && s[i] != ' ' && s[i] != '\t'))
			i--;
		//make word start
		start = i + 1;// Increment i to get the actual start index of the word, cuz end =i
		flag = start;
		//print words
		while (start <= end)
		{
			write(1, &s[start], 1);
			start++;
		}
		//print space if there's more to print
		if (flag != 0)//i>0 flag to check if == 0 -> not zero-> not at the end
			write(1, " ", 1);
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		rev_wstr(av[1]);
	}
	ft_putchar('\n');
}