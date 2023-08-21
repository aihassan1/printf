#include "main.h"

/**
 * is_printable - checks if char is printable
 * @c: Char to be checked
 *
 * Return: 1 if c is printable, 0 is not
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal
 * @buff: Array 
 * @in: Index 
 * @ascii_c: ASSCI
 * Return: Always 3
 */
int append_hexa_code(char ascii_c, char buff[], int in)
{
	char maping_into[] = "0123456789ABCDEF";
	if (ascii_c < 0)
		ascii_c *= -1;

	buff[in++] = '\\';
	buff[in++] = 'x';

	buff[in++] = maping_into[ascii_c / 16];
	buff[in] = maping_into[ascii_c % 16];

	return (3);
}

/**
 * is_digit - checks if char is digit
 * @c: Char to be checked
 *
 * Return: 1 if c is a digit, 0 not digit
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number 
 * @numb: Number cast
 * @size: Number to be casted
 *
 * Return: Casted value
 */
long int convert_size_number(long int numb, int size)
{
	if (size == SIZE_LONG)
		return (numb);
	else if (size == SIZE_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * convert_size_unsgnd - Casts a number
 * @numb1: Number to cast
 * @size: Number type to cast
 *
 * Return: Casted value 
 */
long int convert_size_unsgnd(unsigned long int numb1, int size)
{
	if (size == SIZE_LONG)
		return (numb1);
	else if (size == SIZE_SHORT)
		return ((unsigned short)numb1);

	return ((unsigned int)numb1);
}
