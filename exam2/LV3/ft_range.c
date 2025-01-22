/**
 * @param
 * int i = 0;
 * int len = 0;
 * int *array = (int *)malloc(sizeof(int) * (len + 1)) -> !! PLUS ONE for '\0'
 * 
 * @note
 * 1. Check start OR end is bigger? => LENGTH = [Bigger] - [Smaller]
 * 2. while (i <= len) => Check start/end which is bigger?
 * 
 * 	while (i <= len)
	{
		if (start <= end)
			arr[i] = start + i;
		else
			arr[i] = start - i;
		i++;
	}
 * 
 */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int len = 0;
	int i = 0;
	int *arr;

	//check start/end
	if (start <= end)
		len = end - start;
	else
		len = start - end;
	arr = (int *)malloc(sizeof(int) * (len + 1));
	if (!arr)
		return (NULL);
	while (i <= len)
	{
		if (start <= end)
			arr[i] = start + i;
		else
			arr[i] = start - i;
		i++;
	}
	return (arr);
}
// #include <stdio.h>
// int main ()
// {
// 	int i = 0;
// 	int *res = ft_range(3, -5);
// 	while (i < 8)
// 	{
// 		printf("%d | ", res[i]);
// 		i++;
// 	}
// }