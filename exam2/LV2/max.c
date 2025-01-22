/**
 * @param
 * unsigned int i = 0;
 * int max = tab[i] => store the current biggest int
 * 
 * @note
 * while (i < len) => Increment i to check if current > max (previously stored)
 */

int		max(int* tab, unsigned int len)
{
	unsigned int i = 0;
	int max;

	max = tab[i];//store the biggest int
	if (len == 0)
		return (0);
	while (i < len)
	{
		if (tab[i] > max) //move to check if new int > max
			max = tab[i];
		i++;
	}
	return (max);
}
// #include <stdio.h>
// int main()
// {
// 	int tab[5] = {-1, 3, -5, -8, -34};
// 	printf("%i\n", max(tab, 5));
// }