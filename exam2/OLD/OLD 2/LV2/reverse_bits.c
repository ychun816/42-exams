unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char result = 0;
	int i = 8;
	while (i--)
	{
		result = result << 1;//for the second loop(first loop results: 1)-> creating space for the next bit you are about to extract from octet
		result = result | (octet & 1);//result
		octet = octet >> 1;//allowing you to access the next bit
	}
	return (result);
}
/*
01101001 (octet)
00000001 (1)
--------
00000001 (octet & 1)

===================

00000000 (result)
00000001 (octet & 1)
--------
00000001 result | (octet & 1)

*/


