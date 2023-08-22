#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
  char buf[1024];
  int i, chars_printed_counter = 0, onechar, number;
  char *string = NULL;
  va_list args;
  va_start(args, format);

  /* Handle case where format string is NULL */
  if (format == NULL)
    {
      write(1, "(null)", strlen("(null)"));
      return (-1);
    }

  for (i = 0; format[i] != '\0'; i++)
    {
      if (format[i] == '%')
	{
	  if (format[i + 1] == 'c')
	    {
	      /* Handle %c specifier */
	      onechar = va_arg(args, int);
	      write(1, &onechar, sizeof(char));
	      i += 1;
	      chars_printed_counter++;
	    }
	  else if (format[i + 1] == 's')
	    {
	      /* Handle %s specifier */
	      string = va_arg(args, char*);

	      if (string == NULL)
		{
		  /* Handle NULL string */
		  write(1, "(null)", strlen("(null)"));
		  i += 1;
		  chars_printed_counter += strlen("(null)");
		}

	      
	      else
		{
		 
		  write(1, string, strlen(string));
		  i += 1;
		  chars_printed_counter += strlen(string);
		}
	    }
	  else if (format[i + 1] == '%')
	    {
	      /* Handle %% specifier */
	      write(1, "%", sizeof(char));
	      i += 1;
	      chars_printed_counter++;
	    }
	 
	  /* Handle %d, %i specifiers */
	  else if (format[i + 1] == 'd' || format[i + 1] == 'i')
	    {
	      number = va_arg(args, int);
	      _int_to_string(buf, sizeof(buf), number);
	      write(1, buf, strlen(buf));
	      i += 1;
	      chars_printed_counter++;
	    }

	  else
	    {
	      /* Handle unrecognized specifier */
	      write(1, &format[i], 2);
	      i++;
	      chars_printed_counter += 2;
	    }
	}
      else
	{
	  /* Write non-specifier character */
	  onechar = format[i];
	  write(1, &onechar, sizeof(char));
	  chars_printed_counter++;
	}
    }

  va_end(args);

  if (chars_printed_counter < 0)
    {
      /* Handle overflow */
      return -1;
    }

  return chars_printed_counter;
}


/* Prototype for your custom _printf function */
int main() {
  /* Test %d */
  _printf("Test %d: %d\n", 1, 123);
  _printf("Test %d: %d\n", 2, -456);
  _printf("Test %d: %d\n", 3, 0);

  /* Test %i */
  _printf("Test %i: %i\n", 4, 789);
  _printf("Test %i: %i\n", 5, -101112);
  _printf("Test %i: %i\n", 6, 0);

  return 0;
}

int _int_to_string(char *buf, size_t bufsize, int n)
{
  char *start;
  if (n < 0) {
    if (!bufsize)
      return -1;
    *buf++ = '-';
    bufsize--;
  }
  start = buf;
  do {
    int digit;
    if (!bufsize)
      return -1;
    digit = n % 10;
    if (digit < 0)
      digit *= -1;
    *buf++ = digit + '0';
    bufsize--;
    n /= 10;
  } while (n);
  if (!bufsize)
    return -1;
  *buf = 0;
  --buf;
  while (start < buf) {
    char a = *start;
    *start = *buf;
    *buf = a;
    ++start;
    --buf;
  }
  return 0;
}
