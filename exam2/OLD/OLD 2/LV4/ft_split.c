#include <stdlib.h>

// char *ft_strncpy(char *s1, char *s2, int n)
// {
// 	int i = -1;

// 	while (++i < n && s2[i])
// 		s1[i] = s2[i];
// 	s1[i] = '\0';
// 	return (s1);
// }

// char	**ft_split(char *str)
// {
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	int wc = 0;
	
// 	while (str[i])
// 	{
// 		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
// 			i++;
// 		if (str[i])
// 			wc++;
// 		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
// 			i++;
// 	}
	
// 	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
// 	i = 0;
	
// 	while (str[i])
// 	{
// 		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
// 			i++;
// 		j = i;
// 		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
// 			i++;
// 		if (i > j)
// 		{
// 			out[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
// 			ft_strncpy(out[k++], &str[j], i - j);
// 		}
// 	}
// 	out[k] = NULL;
// 	return (out);
// }



//strncpy
char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

//split
char    **ft_split(char *str)
{
	int i = 0;
	int wd_start = 0;
	int r_i = 0;
	int wd_count = 0;
	char **res;
	
	////count word: count how many words in a str
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		wd_start = i;
		
		// If we find a non-delimiter character, we have found a word
		if (str[i])
			wd_count++;
		// Skip over the word until we find another delimiter
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}

	//malloc: allocate space 
	res = (char **)malloc(sizeof(char *) * (wd_count + 1)); //+ 1 for a NULL terminator
	if (!res)
		return (NULL);
	
	// Extract each word and copy it into the 'res' array
	i = 0; // Reset i to start from the beginning of the string
	while (str[i])
	{
		// Skip over delimiters (spaces, tabs, newlines)
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		// Mark the start of the word
		wd_start = i;
		// Move i to the end of the current word (next delimiter or end of string)
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		// If we found a word (i > j), allocate memory and copy the word into 'out'
		if (i > wd_start)//i should always be ahead of wd_start (i always greater than wd_start; if not, it's end of the word)
		{
			res[r_i] = (char *)malloc(sizeof(char) * (i - wd_start + 1));
			ft_strncpy(res[r_i++], &str[wd_start], i - wd_start);
			//wd_start is used as the start index of the word, and once the word is copied, there’s no need to increment wd_start
		}
	}
	res[r_i] = NULL;//// Null-terminate the array of words
	return (res);

}
#include <stdio.h>
int main() {
    char *test_str = "  Hello   world 42!  "; // Test input string
    char **result;                          // Array to hold the split strings
    int i = 0;

    // Call ft_split to split the test string
    result = ft_split(test_str);

    // Print the results
    while (result[i] != NULL) { // Loop through the results until NULL
        printf("Word %d: '%s'\n", i + 1, result[i]); // Print each word
        free(result[i]); // Free the allocated memory for each word
        i++;
    }

    free(result); // Free the array of pointers
    return 0;
}