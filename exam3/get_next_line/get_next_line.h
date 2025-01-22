#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#define BUFFER_SIZE 42

char *ft_strdup(char *s);
char *get_next_line(int fd);

#endif