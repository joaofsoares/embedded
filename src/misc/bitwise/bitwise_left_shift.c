#include <assert.h>
#include <math.h>
#include <stdio.h>

// cannot be used for negative numbers
// if number is 0, no shift happens

int main(void) {
  int result = (5 * pow(2, 2));
  printf("'bitwise LEFT SHIFT' 5 << 2: %d\n", (5 << 2));
  assert(result == (5 << 2));

  result = (6 * pow(2, 2));
  printf("'bitwise LEFT SHIFT' 6 << 2: %d\n", (6 << 2));
  assert(result == (6 << 2));

  result = (5 * pow(2, 5));
  printf("'bitwise LEFT SHIFT' 5 << 5: %d\n", (5 << 5));
  assert(result == (5 << 5));

  return 0;
}
