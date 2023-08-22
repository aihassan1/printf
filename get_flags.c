#include "main.h"

/**
 * get_flags - Gets the flags
 * @format: The formatted string
 * @idx: Pointer to current index
 *
 * Return: The flags
*/  
int get_flags(const char *format, int *idx)
{
      int f = 0;
      int i, x;
      const char flags[] = {'-', '+', '0', '#', ' ', '\0'};
      const int flags_val[] = {FLAG_MINUS, FLAG_PLUS, FLAG_0, FLAG_HASHTAG, FLAG_SPACE, 0};
      i = *idx + 1;
      
      for (; format[i]; i++)
      {
             for (x = 0; flags[x] != '\0'; x++)
	     {
                    if (format[i] == flags[x])
		    {
                          f |= flags_val[x];
                          break;
                    }
             }
             if (!flags[x])
                    break;
      }

      *idx = i - 1;
      return (f);
}
