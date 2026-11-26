#include <stdint.h>
#include <stdio.h>

void print_binary(uint8_t val) {
  // iterate over bits
  for (int i = 7; i >= 0; i--) {
    int bit = (val >> i) & 1; // get bit
    printf("%d", bit);
  }
  printf("\n");
}

int main(void) {
  uint8_t reg = 0x00;
  print_binary(reg); // 0000 0000

  for (size_t i = 0; i < 8; i++) {
    reg &= ~(1U << i); // clear will always turn bit in zero even it is already
  }
  print_binary(reg); // 0000 0000

  reg |= ((0x01 & 1U) << 0);
  print_binary(reg); // 0000 0001

  reg = 0x00;
  reg |= ((0x03 & 1U) << 1U);
  print_binary(reg); // 0000 0010

  reg &= ~(0x03 << 1U); // clear bit 1-2
  print_binary(reg);    // 0000 0000

  reg |= ((0x03 & 2U) << 1U); // set 2 to bit 1-2
  print_binary(reg);          // 0000 0100

  reg = 0x00;
  reg |= ((0x07 & 5U) << 4U); // 5U = 101
  print_binary(reg);          // 0101 0000

  reg &= ~(0x07 << 4U);
  print_binary(reg); // 00000000

  reg |= ((0x07 & 7U) << 4U); // 7U = 111
  print_binary(reg);          // 0111 0000

  reg = 0x00;
  print_binary(reg); // 0000 0000
  reg = 0xFF;
  print_binary(reg); // 1111 1111

  return 0;
}
