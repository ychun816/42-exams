
// /// METHOD B ///  
int ft_isblank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		ft_isvalid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

int		ft_value_of(char c)///
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int result;
	int sign;

	result = 0;
	while (ft_isblank(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	(*str == '-' || *str == '+') ? ++str : 0;
	while (ft_isvalid(*str, str_base))
		result = result * str_base + ft_value_of(*str++);
	return (result * sign);
}

#include <stdio.h>
int	main(void)
{
	printf("Test 1: \"%s\" (base %d) -> %d\n", "10", 10, ft_atoi_base("10", 10));   // Decimal number in base 10
	printf("Test 2: \"%s\" (base %d) -> %d\n", "1010", 2, ft_atoi_base("1010", 2)); // Binary number in base 2
	printf("Test 3: \"%s\" (base %d) -> %d\n", "A", 16, ft_atoi_base("A", 16));     // Hexadecimal number in base 16
	printf("Test 4: \"%s\" (base %d) -> %d\n", "FF", 16, ft_atoi_base("FF", 16));   // Hexadecimal number in base 16
	printf("Test 5: \"%s\" (base %d) -> %d\n", "15", 8, ft_atoi_base("15", 8));     // Octal number in base 8
	return (0);
}
