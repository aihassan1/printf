#include "main.h"

/**
 * handle_write_char - Print string
 * @c: char 
 * @buffer: Buffer array 
 * @flags: active flags
 * @width: width
 * @precision: precision spec
 * @size: Size spec
 *
 * Return: Number char (int)
 */
int write_char(char c, char buffer[], int flags, int width,
 int precision, int size)
{ 
	int x = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FLAG_0)
		pad = '0';

	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer[BUFF_SIZE - x - 2] = pad;

		if (flags & FLAG_MINUS)
			return (write(1, &buffer[0], 1) + write(1,
			 &buffer[BUFF_SIZE - x - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) 
			+ write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints string
 * @is_negative: int
 * @indx: char 
 * @buffer: Buffer array
 * @flags:  active flags
 * @width: width
 * @precision: precision spec
 * @size: Size spec
 *
 * Return: Number of char (int)
 */
int write_num(int is_negative, int indx, char buffer[], int flags, int width,
 int precision, int size)
{
	int len = BUFF_SIZE - indx - 1;
	char pad = ' ', ex_c = 0;

	UNUSED(size);

	if ((flags & FLAG_0) && !(flags & FLAG_MINUS))
		pad = '0';
	if (is_negative)
		ex_c = '-';
	else if (flags & FLAG_PLUS)
		ex_c = '+';
	else if (flags & FLAG_SPACE)
		ex_c = ' ';

	return (write_num1(indx, buffer, flags, width, precision, len, pad, ex_c));
}

/**
 * write_num - Write a number using a bufffer
 * @indx: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @len: Number length
 * @pad: Pading char
 * @ex_c: Extra char
 *
 * Return: Number of chars (int)
 */
int write_num(int indx, char buffer[], int flags, int width, int prec, 
int len, char pad, char ex_c)
{
	int x, pad_str = 1;

	if (prec == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0' && width == 0)
		return (0);
	if (prec == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		buffer[indx] = pad = ' '; 
	if (prec > 0 && prec < len)
		pad = ' ';
	while (prec > len)
		buffer[--indx] = '0', len++;
	if (ex_c != 0)
		len++;

	if (width > len)
	{
		for (x = 1; x < width - len + 1; x++)
			buffer[x] = pad;
		buffer[x] = '\0';
		if (flags & FLAG_MINUS && pad == ' ')
		{
			if (ex_c)
				buffer[--indx] = ex_c;
			return (write(1, &buffer[indx], len) + write(1, &buffer[1], x - 1));
		}
		else if (!(flags & FLAG_MINUS) && pad == ' ')
		{
			if (ex_c)
				buffer[--indx] = ex_c;

			return (write(1, &buffer[1], x - 1) + write(1, &buffer[indx], len));
		}
		else if (!(flags & FLAG_MINUS) && pad == '0')
		{
			if (ex_c)
				buffer[--pad_str] = ex_c;
			return (write(1, &buffer[pad_str], x - pad_str) + 
			write(1, &buffer[indx], len - (1 - pad_str)));
		}
	}
	if (ex_c)
		buffer[--indx] = ex_c;
	return (write(1, &buffer[indx], len));
}

/**
 * write_unsgnd - write unsigned num
 * @is_negative: Number if the num is neg
 * @indx: Index 
 * @buffer: Array 
 * 
 * @flags: Flags spec
 * @width: Width spec
 * @precision: Precision spec
 * @size: Size spec
 *
 * Return: Number of char (int)
 */
int write_unsignd(int is_negative, int indx, char buffer[], int flags,
 int width, int precision, int size)
{
	int len = BUFF_SIZE - indx - 1, i = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && indx == BUFF_SIZE - 2 && buffer[indx] == '0')
		return (0); 

	if (precision > 0 && precision < len)
		pad = ' ';

	while (precision > len)
	{
		buffer[--indx] = '0';
		len++;
	}

	if ((flags & FLAG_0) && !(flags & FLAG_MINUS))
		pad = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = pad;

		buffer[i] = '\0';

		if (flags & FLAG_MINUS) 
		{
			return (write(1, &buffer[indx], len) + write(1, &buffer[0], i));
		}
		else 
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[indx], len));
		}
	}

	return (write(1, &buffer[indx], len));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Array
 * @indx: int
 * @ext: Char2
 * @pad_st: Index2
 *
 * Return: Number of written chars.
 */
int write_pointer(char buffer[], int indx, int len, int width, int flags,
 char pad, char ext, int pad_st)
{
	int x;

	if (width > len)
	{
		for (x = 3; x < width - len + 3; x++)
			buffer[x] = pad;
		buffer[x] = '\0';
		if (flags & FLAG_MINUS && pad == ' ')
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';
			if (ext)
				buffer[--indx] = ext;
			return (write(1, &buffer[indx], len) + write(1, &buffer[3], x - 3));
		}
		else if (!(flags & FLAG_MINUS) && pad == ' ')
		{
			buffer[--indx] = 'x';

			buffer[--indx] = '0';
			if (ext)
				buffer[--indx] = ext;
			return (write(1, &buffer[3], x - 3) + write(1, &buffer[indx], len));
		}
		else if (!(flags & FLAG_MINUS) && pad == '0')
		{
			if (ext)
				buffer[--pad_st] = ext;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_st], x - pad_st) + write(1, &buffer[indx],
			 len - (1 - pad_st) - 2));
		}
	}
	buffer[--indx] = 'x';
	buffer[--indx] = '0';
	if (ext)
		buffer[--indx] = ext;
	return (write(1, &buffer[indx], BUFF_SIZE - indx - 1));
}
