// /// METHOD A ///
#include <stdio.h>
#include <stdlib.h>

// int    ft_atoi_base(const char *str, int str_base)
// {
//     int    i;
//     int    sign;
//     int    result;

//     i = 0;
//     sign = 1;
//     result = 0;
//     if (str[i] == '-')
//     {
//         sign = -1;
//         i++;
//     }
//     while ((str[i] >= '0' && str[i] <= '9') ||( str[i] >= 'A' && str[i] <= 'F' )||( str[i] >= 'a' && str[i] <= 'f'))
//     {
//         result *= str_base;
//         if (str[i] >= '0' && str[i] <= '9')
//             result += str[i] - '0';
//         else if (str[i] >= 'A' && str[i] <= 'F')
//             result += str[i] - 'A' + 10;
//         else if (str[i] >= 'a' && str[i] <= 'f')
//             result += str[i] - 'a' + 10;
//         i++;
//     }
//     return (result * sign);
// }

// #include <stdio.h>
// int	main(void)
// {
// 	printf("Test 1: \"%s\" (base %d) -> %d\n", "10", 10, ft_atoi_base("10", 10));   // Decimal number in base 10
// 	printf("Test 2: \"%s\" (base %d) -> %d\n", "1010", 2, ft_atoi_base("1010", 2)); // Binary number in base 2
// 	printf("Test 3: \"%s\" (base %d) -> %d\n", "A", 16, ft_atoi_base("A", 16));     // Hexadecimal number in base 16
// 	printf("Test 4: \"%s\" (base %d) -> %d\n", "FF", 16, ft_atoi_base("FF", 16));   // Hexadecimal number in base 16
// 	printf("Test 5: \"%s\" (base %d) -> %d\n", "15", 8, ft_atoi_base("15", 8));     // Octal number in base 8
// 	return (0);
// }
// int main()
// {
//     printf("%d\n", ft_atoi_base("0", 16));
// }

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f'))
	{
		res = res * str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res = res + str[i] - 48;
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res + str[i] - 'a' + 10;
		i++;
	}
	return (sign *res);
}
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