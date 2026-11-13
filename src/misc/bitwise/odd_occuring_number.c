#include <stddef.h>
#include <stdio.h>

// Finding the odd occurring number in a set where all other numbers
// occur even times can be done efficiently using XOR.

int main(void) {
  int arr[] = {12, 90, 12, 14, 90, 14, 14, 11, 14};
  size_t n = sizeof(arr) / sizeof(arr[0]);

  int answer = 0;
  for (size_t i = 0; i < n; i++) {
    answer = (answer ^ arr[i]);
  }

  printf("answer: %d\n", answer);

  return 0;
}
