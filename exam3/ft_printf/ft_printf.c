#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

//print_s_char
int ft_putstr(char *s)
{
	int i = 0;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

//putnb
int putnb(int nb)
{
	long ln = (long)nb;
	int count = 0;
	
	if (ln == 0)
	{
		count += ft_putchar('0');
	}
	if (ln < 0)
	{
		count += ft_putchar('-');
		ln = -ln;
	}
	if (ln > 9)
		count += putnb(ln / 10);
	count += ft_putchar((ln % 10) + 48);
	return (count); //ft_nblen(ln)
}
//puthex
int puthex(unsigned int n)
{
	int i = 0;
	int count = 0;

	if (n >= 16)
	{
		count += puthex(n / 16);
		count += puthex(n % 16);	
	}
	else
	{
		if (n < 10)
			count += ft_putchar(n + 48);
		else
			count += ft_putchar(n - 10 + 'a');
	}
	return (count);
}

//check type
int check_type(const char type, va_list args)
{
	int count = 0;
	
	if (type == 's') //print string
		count += ft_putstr(va_arg(args, char *));
	if (type == 'd') //put nb
		count += putnb(va_arg(args, int));
	if (type == 'x') // puthex 
		count += puthex(va_arg(args, unsigned int));
	return (count);
}

//printf
int ft_printf(const char *s, ...)
{
	int i = 0;
	int count = 0;
	va_list args;

	va_start(args, s);// Initializes the argument list 'args'
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += check_type(s[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
int main(void)
{
	ft_printf("yolo! %s\n", "toto");
	ft_printf("%s I'm happy! I passed exam with %d points\n", "today", 100);
	ft_printf("Hexdecimal is %s!!! like why input %d becomes %x ? I think : %s\n", "complicated", 255, 255, "C'est fou!");
	printf("\n");
	printf("=============================================================\n");
	printf("\n");
	printf(" ||| REAL : %d | FT : %d", printf("hello"), ft_printf("hello"));
	printf("\n");
	printf(" ||| REAL : %d | FT : %d", printf("%s", "hello"), ft_printf("%s", "hello"));
	printf("\n");
	printf(" ||| REAL : %d | FT : %d", printf("%d", 42), ft_printf("%d", 42));
	printf("\n");
	printf(" ||| REAL : %d | FT : %d", printf("%d", -424), ft_printf("%d", -424));
	printf("\n");
	printf(" ||| REAL : %d | FT : %d", printf("%x", 0), ft_printf("%x", 0));
	printf("\n");
	printf(" ||| REAL : %d | FT : %d", printf("%x", 255), ft_printf("%x", 255));
	printf("\n");
	printf("\n");
    return 0;
}

/* === EXTRA FUNCTIONS ===
// ft_nblen
int ft_nblen(int n)
{
	int len = 0;
	long ln = (long)n;

	if (ln == 0)
		len = 1;
	if (ln < 0)
	{
		len += 1;
		ln = -ln;
	}
	if (ln > 0)
	{
		ln = ln / 10;
		len++;
	}
	return (len);
}


// ft_hexlen
int ft_hexlen(unsigned int n)
{
	int len = 0;

	if (n == 0)
		return (1);
	if (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

*/
