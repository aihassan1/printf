#include "main.h"

/**
 * get_size - gets size to cast args
 * @format: formatted string
 * @idx: list args
 *
 * Return: size
 */
int get_size(const char *format, int *idx)
{
	int size = 0;
    	int current_idx = *idx + 1;

	if (format[current_idx] == 'l')
		size = SIZE_LONG;
	else if (format[current_idx] == 'h')
		size = SIZE_SHORT;

	if (size == 0)
		*idx = current_idx - 1;
	else
		*idx = current_idx;

	return (size);
}
