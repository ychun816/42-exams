/**
 * FUNCTON:
 * - strdup()
 * - gnl()
 * 
 * @param
 * STATIC CHAR buffer[BUFFER_SIZE] : 
 * - Static buffer to store chunks of data read from a file descriptor (fd)
 * - The read system call fills this buffer with up to BUFFER_SIZE bytes from the file at a time.
 * - The read function doesn’t always read the entire content of the file at once (especially for large files). 
 *   So, this buffer holds the portion of the file currently being processed until the function needs more data.
 * 
 * CHAR line[7000] : 
 * - This egular (non-static) array is used to store the line currently being read. 
 * - The function copies characters from buffer into line until it finds a newline (\n) or reaches the end of the buffer.
 * - Why 70000: The large size ensures that even very long lines can be stored without running out of space.
 * 
 * STATIC INT buffer_read : Static variable to keep track of how many bytes were read into the buffer
 * STATIC INT buffer_pos : Static variable to track the current position in the buffer
 * INT i;
 * 
 */

#include "get_next_line.h"

char *ft_strdup(char *s)
{
	int i = 0;
	char *res;

	while (s[i])
		i++;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *get_next_line(int fd)
{
	int i = 0;
	static char buf[BUFFER_SIZE];
	static int buf_rd;
	static int buf_pos;
	char line[7000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buf_pos >= buf_rd)
		{
			buf_rd = read(fd, buf, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_rd <= 0)
				break ;
		}
		line[i++] = buf[buf_pos++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

#include <stdio.h>
int main()
{
	int fd = open("./test.txt", BUFFER_SIZE);
	printf("%s", get_next_line(fd));
}
