#include <stdint.h>

uint8_t set_range(uint8_t reg, uint8_t start, uint8_t end) {
  while (start < (end + 1)) {
    reg |= ((0x01 & 1U) << start);
    start++;
  }

  return reg;
}
