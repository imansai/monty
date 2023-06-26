#include <stdlib.h>


char *getInt(int num);
unsigned int getAbsoluteValue(int);
int getNumBaseLength(unsigned int num, unsigned int base);
void fillNumBaseBuffer(unsigned int num, unsigned int base,
               char *buff, int buff_size);


/**
 * getInt - gets a character pointer to new string containing int
 * @num: number to convert to string
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *getInt(int num)
{
    unsigned int temp;
    int length = 0;
    long num_l = 0;
    char *ret;


    temp = getAbsoluteValue(num);
    length = getNumBaseLength(temp, 10);


    if (num < 0 || num_l < 0)
        length++; /* negative sign */
    ret = malloc(length + 1); /* create new string */
    if (!ret)
        return (NULL);


    fillNumBaseBuffer(temp, 10, ret, length);
    if (num < 0 || num_l < 0)
        ret[0] = '-';


    return (ret);
}


/**
 * getAbsoluteValue - gets the absolute value of an integer
 * @i: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int getAbsoluteValue(int i)
{
    if (i < 0)
        return (-(unsigned int)i);
    return ((unsigned int)i);
}


/**
 * getNumBaseLength - gets length of buffer needed
 * @num: number to get length needed for
 * @base: base of number used by buffer
 *
 * Return: integer containing length of buffer
 */
int getNumBaseLength(unsigned int num, unsigned int base)
{
    int len = 1; /* all numbers contain at least one digit */


    while (num > base - 1)
    {
        len++;
        num /= base;
    }
    return (len);
}


/**
 * fillNumBaseBuffer - fills buffer with correct number up to base 36
 * @num: number to convert to string
 * @base: base of number used in conversion up to base 36
 * @buff: buffer to fill with result of conversion
 * @buff_size: buffer size in bytes
 *
 * Return: always void.
 */
void fillNumBaseBuffer(unsigned int num, unsigned int base,
            char *buff, int buff_size)
{
    int rem, i = buff_size - 1;


    buff[buff_size] = '\0';
    while (i >= 0)
    {
        rem = num % base;
        if (rem > 9) /* return lowercase ascii val representation */
            buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
        else
            buff[i] = rem + '0';
        num /= base;
        i--;
    }
}
