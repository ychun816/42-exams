int		max(int* tab, unsigned int len)
{
	int max;
	int i = 0;
	// int count = 0;
	if (len > 0)
	{
		max = tab[i];
		while (i < len)//count < len tab[i]
		{
			if (tab[i] > max)
			{
				max = tab[i];
			}
			i++;
			// count++;
		}
		return (max);
	}
	return (0);
}
#include <stdio.h>
int main()
{
	int arr[5] = {-3, -4, -89, -70000, -500};
	printf("%i\n", max(arr, 5));
}