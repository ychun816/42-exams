/**
 * FUNCTION:
 * (1) Finds First Match: 
 * finds the first character in s1 that is also in s2.
 * 
 * (2) Returns Pointer: 
 * It returns a pointer to that character in s1 if found; 
 * otherwise, it returns NULL.
 * 
 * @note
 * !!! Return POINTER!! 
 * 
 * @note
 * - Check !s1 || !s2 => return (0)
 * - While (s1[i])
 * - While (s2[j]) => If (s2[j] == s1[i])
 * 
 * @return 
 * return (char *)(s1 + i); !!!
 * return (NULL);
 */

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j;

	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i])
				return (char *)(s1 + i); // Return pointer to the matching character in s1
			j++;
		}
		i++;
	}
	return (NULL);// No match found, return NULL
}