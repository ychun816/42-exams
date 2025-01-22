#include <stdlib.h>

int *ft_range(int start, int end)
{
    int rangelen;
    int i;
    int *array;

    // Calculate the range length, including both start and end
    if (start <= end)
        rangelen = end - start + 1;  // Length for increasing order
    else
        rangelen = start - end + 1;  // Length for decreasing order

    // Allocate memory for the array
    array = (int *)malloc(sizeof(int) * rangelen);
    if (!array)  // Check if malloc failed
        return (NULL);

    // Fill the array with values based on the relationship between start and end
    i = 0;
    while (i < rangelen)
    {
        if (start <= end)
            array[i] = start + i;  // Incrementing order
        else
            array[i] = start - i;  // Decrementing order
        i++;
    }

    return (array);  // Return the filled array
}

#include <stdio.h>
int main()
{
	int *result;
	int i = 0;
	int len = 3;

	result = ft_range(-1, 2);
	
	while ( i <= 3)//can't write result[i] => result[i] checks non-zero! not suitable for int array!!
	{
		printf("%d | ", result[i]);
		i++;
	}
}