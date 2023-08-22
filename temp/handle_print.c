#include "main.h"

/**
 * handle_print - Prints an arg
 * @fmt: Formatted string
 * @list: List of args
 * @indx: ind
 * @buffer: Buffer array
 * @flags: Calculates flags
 * @width: get width 
 * @precision: Precision
 * @size: Size 
 * Return: 1 or 2
 */
int handle_print(const char *ft, int *indx, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
int i, len = 0, printed_ch = -1;
	ft_t ft_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; ft_types[i].ft != '\0'; i++)
		if (ft[*indx] == ft_types[i].ft)
			return (ft_types[i].fnc(list, buffer, flags, width, precision, size));

	if (ft_types[i].ft == '\0')
	{
		if (ft[*indx] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (ft[*indx - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*indx);
			while (ft[*indx] != ' ' && ft[*indx] != '%')
				--(*indx);
			if (ft[*indx] == ' ')
				--(*indx);
			return (1);
		}
		len += write(1, &ft[*indx], 1);
		return (len);
	}
	return (printed_ch);
}
