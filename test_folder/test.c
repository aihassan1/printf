#include <stdio.h>
#include "main.h"

int _printf(const char *format, ...);

int main(void)
{
  int len;
  int len2;

  len = _printf("Let's print a character: %c\n", 'H');
  len2 = printf("Let's print a character: %c\n", 'H');
  printf("Length:[%d, %d]\n", len, len2);

  len = _printf("Let's print a string: %s\n", "Hello, world!");
  len2 = printf("Let's print a string: %s\n", "Hello, world!");
  printf("Length:[%d, %d]\n", len, len2);

  len = _printf("Let's print a percent sign: %%\n");
  len2 = printf("Let's print a percent sign: %%\n");
  printf("Length:[%d, %d]\n", len, len2);

  len = _printf("Let's print multiple characters: %c %c %c\n", 'A', 'B', 'C');
  len2 = printf("Let's print multiple characters: %c %c %c\n", 'A', 'B', 'C');
  printf("Length:[%d, %d]\n", len, len2);

  len = _printf("Let's print a mix of characters and strings: %c %s %c %s\n", 'X', "Hello", 'Y', "World!");
  len2 = printf("Let's print a mix of characters and strings: %c %s %c %s\n", 'X', "Hello", 'Y', "World!");
  printf("Length:[%d, %d]\n", len, len2);

  return (0);
}
