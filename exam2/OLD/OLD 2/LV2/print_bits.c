void	print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;
	while (i--)
	{
		bit = (octet >> i & 1) + 48;//change char to ascii value
		write(1, &bit, 1);
	}
}

unsigned char bit
int i = 8;

while (i--)
{
	bit = (octet >> i & 1) + 48;
	write
}
