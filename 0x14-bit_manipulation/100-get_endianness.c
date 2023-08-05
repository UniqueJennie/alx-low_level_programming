#include "main.h"

/**
 * get_endianness - asses if its a big or small endian
 * Return: 0 for big, 1 for small
 */
int get_endianness()
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
