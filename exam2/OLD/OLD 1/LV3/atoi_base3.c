
////METHOD B////
//covert to lower case
char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

//get digit
// Returns the digit value of the character 'c' in the base 'digits_in_base'.
// If the character is a valid digit in the given base, it returns the numeric value.
// Otherwise, it returns -1 to indicate an invalid digit.
int get_digit(char c, int digits_in_base)
{
	int max_digit;

	// Calculate the maximum valid character for the given base.
	// If base is 10 or less, 'max_digit' is the maximum numeric character ('0' - '9').
	if (digits_in_base <= 10)//10digits: 0123456789 
		max_digit = digits_in_base - 1 + 48;//digits_in_base - 1 gives us 9 for base 10 => change numeric value to character 
	else
		max_digit = digits_in_base - 10 -1 + 'a';//get the character aftr 0123456789
	//-10 accounts for the numeric digits 0-9
	//-1 gives the highest valid alphabetic digit
	//Adding 'a' converts this into the corresponding character.
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');// Convert character to its value (e.g., 'a' becomes 10).
	else
		return (-1);// Return -1 if the character is not valid in the given base.
}

//atoi base
int ft_atoi_base(char *s, int s_base)
{
	int i;
	int digit;
	int sign;
	int result;

	i = 0;
	result = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((digit = get_digit(to_lower(s[i]), s_base)) >= 0)
	{
		result = result *s_base;//shifts the current result left by multiplying it by the base, making room for the next digit.
		result = result + (digit * sign);//dds the current digit (accounting for the sign, if it's negative) to the result.
		i++;
	}
	return (result);
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