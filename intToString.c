#include <stdlib.h>

/**
 * getInt - Gets a character pointer to a new string containing an integer.
 * @num: Number to convert to a string.
 *
 * Return: Character pointer to the newly created string. NULL if malloc fails.
 */
char *getInt(int num)
{
	unsigned int temp;
	int length = 0;
	long numLong = 0;
	char *result;

	temp = getAbsoluteValue(num);
	length = getNumBaseLength(temp, 10);

	if (num < 0 || numLong < 0)
		length++; /* negative sign */

	result = malloc(length + 1); /* Create a new string */
	if (!result)
		return (NULL);

	fillNumBaseBuffer(temp, 10, result, length);
	if (num < 0 || numLong < 0)
		result[0] = '-';

	return (result);
}

/**
 * getAbsoluteValue - Gets the absolute value of an integer.
 * @num: Integer to get the absolute value of.
 *
 * Return: Unsigned integer absolute value of num.
 */
unsigned int getAbsoluteValue(int num)
{
	if (num < 0)
		return (-(unsigned int)num);
	return ((unsigned int)num);
}

/**
 * getNumBaseLength - Gets the length of buffer needed for an unsigned integer.
 * @num: Number to get the length needed for.
 * @base: Base of the number representation used by the buffer.
 *
 * Return: Integer containing the length of the buffer needed (doesn't contain null byte).
 */
int getNumBaseLength(unsigned int num, unsigned int base)
{
	int length = 1; /* All numbers contain at least one digit */

	while (num > base - 1)
	{
		length++;
		num /= base;
	}
	return (length);
}

/**
 * fillNumBaseBuffer - Fills the buffer with correct numbers up to base 36.
 * @num: Number to convert to string given the base.
 * @base: Base of the number used in the conversion, only works up to base 36.
 * @buffer: Buffer to fill with the result of the conversion.
 * @bufferSize: Size of the buffer in bytes.
 *
 * Return: Always void.
 */
void fillNumBaseBuffer(unsigned int num, unsigned int base, char *buffer, int bufferSize)
{
	int remainder, i = bufferSize - 1;

	buffer[bufferSize] = '\0';

	while (i >= 0)
	{
		remainder = num % base;

		if (remainder > 9) /* Return lowercase ASCII value representation */
			buffer[i] = remainder + 87; /* 10 will be 'a', 11 = 'b', ... */
		else
			buffer[i] = remainder + '0';

		num /= base;
		i--;
	}
}
