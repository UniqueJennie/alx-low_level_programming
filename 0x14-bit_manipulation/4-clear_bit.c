#include "main.h"

/**
 * clear_bit - arrays the worth of a stated bit to 0
 * @n: pointer to the nmbr to alter
 * @index: index of the bit to remove
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
