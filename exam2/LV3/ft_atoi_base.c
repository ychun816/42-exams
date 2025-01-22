/**
 * @param
 * int i = 0;
 * int sign = 1;
 * int res = 0;
 * 
 * @note
 * STRUCTURE LIKE ATOI (10-base) :
 * 
 * 1. Skip space :  (== ' ' || >= 9 && <= 13)
 * 2. Handle Negative : if (str[i] == '-') => sign = -1 ; i++;(move one space)
 * 3. Handle ('0' ~ '9') / ('A' ~ 'F') / ('a' ~ 'f')
 * 
 * 	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f'))
	{
		res = res * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res = res + (str[i] - 48);
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = + str[i] - 'a' + 10;
		i++;
	}
 * 
 */

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int res = 0;
	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	//0-9, A-F, a-f
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f'))
	{
		res = res * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res = res + (str[i] - 48);
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = + str[i] - 'a' + 10;
		i++;
	}
	return (res *sign);
}
#include <stdio.h>
int main()
{
	printf("%i\n", ft_atoi_base("-10", 10));
	printf("\n");
	printf("%i\n", ft_atoi_base("1010", 2));
	printf("\n");
	printf("%i\n", ft_atoi_base("  -15", 8));
	printf("\n");
	printf("%i\n", ft_atoi_base("A", 16));
	printf("%i\n", ft_atoi_base("b", 16));
	printf("%i\n", ft_atoi_base("20", 16));
	printf("\n");
	printf("Binary (base 2) '1010' -> %d\n", ft_atoi_base("1010", 2));  // Expected output: 10
    printf("Octal (base 8) '24' -> %d\n", ft_atoi_base("24", 8));      // Expected output: 20
    printf("Decimal (base 10) '-42' -> %d\n", ft_atoi_base("-42", 10)); // Expected output: -42
    printf("Hexadecimal (base 16) '1A' -> %d\n", ft_atoi_base("1A", 16)); // Expected output: 26
    printf("Hexadecimal (base 16) 'FF' -> %d\n", ft_atoi_base("FF", 16)); // Expected output: 255
}

/*
#include <stdio.h>
int main()
{
	printf("%i\n", ft_atoi_base("10", 10));
	printf("%i\n", ft_atoi_base("10", 2));
	printf("%i\n", ft_atoi_base("10", 8));
	printf("%i\n", ft_atoi_base("10", 16));

	printf("Test 1: \"%s\" (base %d) -> %d\n", "10", 10, ft_atoi_base("10", 10));   // Decimal number in base 10
	printf("Test 2: \"%s\" (base %d) -> %d\n", "1010", 2, ft_atoi_base("1010", 2)); // Binary number in base 2
	printf("Test 3: \"%s\" (base %d) -> %d\n", "A", 16, ft_atoi_base("a", 16));     // Hexadecimal number in base 16
	printf("Test 4: \"%s\" (base %d) -> %d\n", "FF", 16, ft_atoi_base("FF", 16));   // Hexadecimal number in base 16
	printf("Test 5: \"%s\" (base %d) -> %d\n", "15", 8, ft_atoi_base("15", 8));     // Octal number in base 8

}
*/