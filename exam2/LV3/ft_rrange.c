/**
 * @param
 * int i = 0;
 * int len = start - end || end - start;
 * int *array = (int *)malloc(sizeof(int) * (len + 1));
 * 
 * @note
 * OPPOSITE FROM FT_RANGE : end - i || end + i
 * (FT_RANGE : start - i || start + i)
 * 
 * 	while (i < len)
	{
		if (start <= end)
			arr[i] = end - i;
		else
			arr[i] = end + i;
		i++;
	}
 * 
 */
#include <stdlib.h>
int     *ft_rrange(int start, int end)
{
	int i = 0;
	int len = 0;
	int *arr;
	if (start <= end)
		len = end - start;
	else
		len = start - end;
	arr = (int *)malloc(sizeof(int) * (len + 1));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		if (start <= end)
			arr[i] = end - i;
		else
			arr[i] = end + i;
		i++;
	}
	return (arr);
}
// #include <stdio.h>
// int main ()
// {
// 	int i = 0;
// 	int *res = ft_rrange(3, -5);
// 	while (i < 8)
// 	{
// 		printf("%d | ", res[i]);
// 		i++;
// 	}
// }