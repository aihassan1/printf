#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h> 

#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_0 4
#define FLAG_HASHTAG 8
#define FLAG_SPACE 16

#define SIZE_LONG 2
#define SIZE_SHORT 1

/* FUNCTIONS */

int _int_to_string(char *buf, size_t bufsize, int n);
int _printf(const char *format, ...);
int get_flags(const char *format, int *idx);
int get_width(const char *format, int *idx, va_list list);
int get_size(const char *format, int *idx);
int get_precision(const char *format, int *indx, va_list list);

int is_digit(char);
int _strlen(char *s);
int is_printable(char);
int append_hexa_code(char, char[], int);

long int convert_size_unsgnd(unsigned long int numb1, int size);
long int convert_size_number(long int numb, int size);




#endif
