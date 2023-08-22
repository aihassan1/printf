#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_0 4
#define FLAG_HASHTAG 8
#define FLAG_SPACE 16

#define SIZE_LONG 2
#define SIZE_SHORT 1

/* FUNCTIONS */

int _printf(const char *format, ...);
int get_flags(const char *format, int *idx);
int get_width(const char *format, int *idx, va_list list);

int is_digit(char);
int _strlen(char *s);
int is_printable(char);
int append_hexa_code(char, char[], int);
int handle_print(const char *ft, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

long int convert_size_unsgnd(unsigned long int numb1, int size);
long int convert_size_number(long int numb, int size);

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);


/**
 * struct ft - Struct op
 *
 * @ft: format
 * @fn: function pointer
 */
struct ft
{
	char ft;
	int (*fnc)(va_list, char[], int, int, int, int);
};

/**
 * typedef - Struct op
 *
 * @ft: old format
 * @f_t: new function format 
 */
typedef struct ft ft_t;

#endif
