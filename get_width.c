#include "main.h"

/**
 * get_width - Calculates the width 
 * @format: Formatted string 
 * @idx: Index of the current character
 * @list: List of args
 *
 * Return: The calculated width.
 */
int get_width(const char *format, int *idx, va_list list)
{
	int current_index;
	int width = 0;
	current_index = *idx + 1;

	for (; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		
			width =  width * 10 + (format[current_index] - '0');
		
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(list, int);
			break;
		}
		else	
			break;
	}

	*idx = current_index - 1;

	return (width);
}
