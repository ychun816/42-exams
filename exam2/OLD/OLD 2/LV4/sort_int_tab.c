void	sort_int_tab(int *tab, unsigned int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

// void	sort_int_tab(int *tab, unsigned int size)
// {
// 	unsigned int	i = 0;
// 	int	temp;

// 	while (i < (size - 1))
// 	{
// 		if (tab[i] > tab[i + 1])
// 		{
// 			temp = tab[i];
// 			tab[i] = tab[i+ 1];
// 			tab[i + 1] = temp;
// 			i = 0;
// 		}
// 		else
// 			i++;
// 	}
// }

#include <stdio.h>

int	main(void)
{
	int i = 0;

	int tab[7] = {3, 2, -23, 0, 500, 9, -30};
	while (i < 7)
	{
		printf("%i | ", tab[i]);
		i++;
	}
	sort_int_tab(tab, 7);
	printf("\n");
	i = 0;
	while (i < 7)
	{
		printf("%i | ", tab[i]);
		i++;
	}
}