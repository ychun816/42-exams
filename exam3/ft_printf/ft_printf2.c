#include <unistd.h>
#include <stdarg.h>

void    put_string(char *string, int *length)
{
    if (!string)
        string = "(null)";
    while (*string)
        *length += write(1, string++, 1);
}

void    put_digit(long long int number, int base, int *length)
{
    char    *hexadecimal = "0123456789abcdef";

    if (number < 0)
    {
        number *= -1;
        *length += write(1, "-", 1);
    }
    if (number >= base)
        put_digit((number / base), base, length);
    *length += write(1, &hexadecimal[number % base], 1);
}

int    ft_printf(const char *format, ...)
{
    int length = 0;

    va_list    pointer;
    va_start(pointer, format);

    while (*format)
    {
        if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
        {
            format++;
            if (*format == 's')
                put_string(va_arg(pointer, char *), &length);
            else if (*format == 'd')
                put_digit((long long int)va_arg(pointer, int), 10, &length);
            else if (*format == 'x')
                put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
        }
        else
            length += write(1, format, 1);
        format++;
    }
    return (va_end(pointer), length);
}

#include <stdio.h>
int main(void)
{
	ft_printf("%s! toto\n", "SuUuup");
	ft_printf("%s is harder. But would win %d points\n", "The version 2", 100);
	ft_printf("Hexdecimal is %s!!! like why input %d becomes %x? u know what: %s\n", "complicated", 255, 255, "Je m'en fous!");
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

/* ==== TEST MAIN B ====
int main(void)
{
    int len;

    // Testing string output
    len = ft_printf("Hello, %s!\n", "world");
    ft_printf("Printed %d characters.\n\n", len); // Expected: 13 (Hello, world!\n)

    // Testing integer output
    len = ft_printf("Number: %d\n", 42);
    ft_printf("Printed %d characters.\n\n", len); // Expected: 11 (Number: 42\n)

    // Testing negative integer output
    len = ft_printf("Negative Number: %d\n", -12345);
    ft_printf("Printed %d characters.\n\n", len); // Expected: 20 (Negative Number: -12345\n)

    // Testing hexadecimal output
    len = ft_printf("Hex: %x\n", 255);
    ft_printf("Printed %d characters.\n\n", len); // Expected: 9 (Hex: ff\n)

    // Testing null string
    len = ft_printf("Null string: %s\n", NULL);
    ft_printf("Printed %d characters.\n\n", len); // Expected: 17 (Null string: (null)\n)

    return 0;
}
*/
