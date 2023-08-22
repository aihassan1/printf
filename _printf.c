#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int _int_to_string(int n, char *string, size_t size);
/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */

int _printf(const char *format, ...) {
  int i, chars_printed_counter = 0, onechar, number;
  char *string = NULL;
  char buf[1024];

  va_list args;
  va_start(args, format);

  /* Handle case where format string is NULL */
  if (format == NULL) {
    write(1, "(null)", strlen("(null)"));
    return (-1);
  }

  for (i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      if (format[i + 1] == 'c') {
	/* Handle %c specifier */
	onechar = va_arg(args, int);
	write(1, &onechar, sizeof(char));
	i += 1;
	chars_printed_counter++;
      } else if (format[i + 1] == 's') {
	/* Handle %s specifier */
	string = va_arg(args, char *);

	if (string == NULL) {
	  /* Handle NULL string */
	  write(1, "(null)", strlen("(null)"));
	  i += 1;
	  chars_printed_counter += strlen("(null)");
	} else {
	  write(1, string, strlen(string));
	  i += 1;
	  chars_printed_counter += strlen(string);
	}
      } else if (format[i + 1] == '%') {
	/* Handle %% specifier */
	write(1, "%", sizeof(char));
	i += 1;
	chars_printed_counter++;
      }
      /* Handle % char only*/
      else if (format[i + 1] == '\0')
	{
	  return(-1);
	}

      /* Handle %d, %i specifiers */
      else if (format[i + 1] == 'd' || format[i + 1] == 'i') {
	number = va_arg(args, int);
	_int_to_string(number, buf, sizeof(buf));
	write(1, buf, strlen(buf));
	i += 1;
	chars_printed_counter += strlen(buf);
      }


      else {
	/* Handle unrecognized specifier */
	write(1, &format[i], 2);
	i++;
	chars_printed_counter += 2;
      }

    }

    else {
      /* Write non-specifier character */
      onechar = format[i];
      write(1, &onechar, sizeof(char));
      chars_printed_counter++;
    }
  }

  va_end(args);

  if (chars_printed_counter < 0) {
    /* Handle overflow */
    return -1;
  }

  return chars_printed_counter;
}

int _int_to_string(int n, char *string, size_t size) {
  char *start_ptr;
  int digit;
  int temp;

  if (n < 0) {
    if (size == 0)
      return (-1);

    *string = '-';
    string++;
    size--;
  }
  start_ptr = string;

  do {
    if (size == 0)
      return (-1);

    digit = n % 10;
    if (digit < 0)
      digit *= -1;

    *string = digit + '0';
    string++;
    size--;

    n /= 10;

  } while (n != 0);

  if (size == 0)
    return (-1);

  *string = '\0';
  string--;

  while (start_ptr < string) {
    temp = *start_ptr;
    *start_ptr = *string;
    *string = temp;
    start_ptr++;
    string--;
  }
  return (0);
}

