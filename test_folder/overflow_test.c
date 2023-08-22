#include <stdio.h>
#include <limits.h>  // For INT_MAX
#include "main.h"  // Include your _printf prototype

int main() {
  // Test your _printf function
  int len1 = _printf("Testing _printf: %d\n", 123);

  // Test the standard printf function
  int len2 = printf("Testing printf: %d\n", 123);

  printf("Length of _printf output: %d\n", len1);
  printf("Length of printf output: %d\n", len2);

  // Compare the output lengths
  if (len1 != len2) {
    printf("Output lengths do not match!\n");
  } else {
    printf("Output lengths match.\n");
  }

  // Check for overflow manually
  int counter = INT_MAX - 10;  // Start with a value close to the maximum
  int increment = 11;          // Increment by a value greater than the remaining space to INT_MAX

  // Simulate an overflow
  for (int i = 0; i < 5; i++) {
    // Check for overflow before incrementing
    if (counter > INT_MAX - increment) {
      printf("Overflow detected!\n");
      break;
    }
    counter += increment;
  }

  return 0;
}
