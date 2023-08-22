#include "main.h"

/**
 * get_precision - gets the precision
 * @format: formatted string 
 * @indx: index
 * @list: list of args
 *
 * Return: Precision
 */
int get_precision(const char *format, int *indx, va_list list)
{
	int current_indx = *indx + 1;
	int p = -1;

	if (format[current_indx] != '.')
		return (p);

	p = 0;

	for (current_indx += 1; format[current_indx] != '\0'; current_indx++)
	{
		if (is_digit(format[current_indx]))
		{
			p *= 10;
			p += format[current_indx] - '0';
		}
		else if (format[current_indx] == '*')
		{
			current_indx++;
			p = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*indx = current_indx - 1;

	return (p);
}
