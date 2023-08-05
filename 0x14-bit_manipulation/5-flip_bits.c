#include "main.h"

/**
 * flip_bits - sums the nmbr of bits to alter
 * to move from one nmbr to another
 * @n: first nmbr
 * @m: second nmbr
 * Return: nmbr of bits to alter
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
