/**
 * @param
 * unsigned char res = 0;
 * int i = 8;
 * 
 */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char res = 0;
	int i = 8;

	while (i--)
	{
		res = res << 1;//move a space for the rightest(8th) position for next command
		res = res | (octet & 1); //take combinition of res + octet
		octet = octet >> 1;//shift to right by one to process
	}
	return (res);
}

/*
Example

octet = 13 (binary 00001101):

Initial State: res = 00000000, octet = 00001101

    Iteration 1:
        res = 00000000 << 1 = 00000000
        res = 00000000 | (00001101 & 1) = 00000000 | 1 = 00000001
        octet = 00001101 >> 1 = 00000110

    Iteration 2:
        res = 00000001 << 1 = 00000010
        res = 00000010 | (00000110 & 1) = 00000010 | 0 = 00000010
        octet = 00000110 >> 1 = 00000011

    Iteration 3:
        res = 00000010 << 1 = 00000100
        res = 00000100 | (00000011 & 1) = 00000100 | 1 = 00000101
        octet = 00000011 >> 1 = 00000001

    Iteration 4:
        res = 00000101 << 1 = 00001010
        res = 00001010 | (00000001 & 1) = 00001010 | 1 = 00001011
        octet = 00000001 >> 1 = 00000000

    Iterations 5-8:
        octet becomes 0, and the subsequent iterations will not add any more bits to res.
*/

