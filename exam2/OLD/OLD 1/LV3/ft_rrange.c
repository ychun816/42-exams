#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int rangelen;
	int i;
	int *arr;

	if (start <= end)
		rangelen = end - start + 1;
	else
		rangelen = start - end + 1;
	arr = (int *)malloc(sizeof(int) * rangelen);
	if (!arr)
		return 0;
	i = 0;
	while (i < rangelen)
	{
		if (start <= end)
			arr[i] = end - i; 
		else
			arr[i] = end + i;
		i++;
	}
	return (arr);
}
#include <stdio.h>
int main()
{
	int *res;
	int i;

	res = ft_rrange(0, 0);
	while (i < 1)
	{
		printf("%d | ", res[i]);
		i++;
	}
}