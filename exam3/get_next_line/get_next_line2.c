#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
    while(*s)
    {
        if(*s == (char)c)
            return((char *)s);
        s++;
    }
    return(NULL);
}

size_t ft_strlen(const char *str)
{
    size_t i = 0;

    while(str[i])
        i++;
    return(i);
}

void ft_strcpy(char *dst, const char *src)
{
    while(*src)
        *dst++ = *src++;
    *dst = '\0';
}

char *ft_strdup(const char *src)
{
    size_t len = ft_strlen(src) + 1;
    char *dst = malloc(len);

    if(dst == NULL)
        return(NULL);
    ft_strcpy(dst, src);
    return(dst);
}

char *ft_strjoin(char *s1, const char *s2)
{
    size_t s1len = ft_strlen(s1);
    size_t s2len = ft_strlen(s2);
    char *join = malloc((s1len + s2len + 1));

    if(!s1 || !s2)
        return(NULL);
    if(!join)
        return(NULL);
    ft_strcpy(join, s1);
    ft_strcpy((join + s1len), s2);
    free(s1);
    return(join);
}

char    *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char *line;
    char *newline;
    int countread;
    int to_copy;

    line = ft_strdup(buf);
    while(!(newline = ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)))
    {
        buf[countread] = '\0';
        line = ft_strjoin(line, buf);
    }
    if(ft_strlen(line) == 0)
        return(free(line), NULL);

    if(newline != NULL)
    {
        to_copy = newline - line + 1;
        ft_strcpy(buf, newline + 1);
    }
    else
    {
        to_copy = ft_strlen(line);
        buf[0] = '\0';
    }
    line[to_copy] = '\0';
    return(line);
}

#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    int fd = open("file", O_RDONLY);
    char *line = get_next_line(fd);

    while(line)
    {
        printf("%s", line);
        line = get_next_line(fd);
        if(!line)
            break;
    }
    printf("%s", line);
}