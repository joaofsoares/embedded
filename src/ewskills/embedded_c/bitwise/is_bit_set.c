#include <stdint.h>

uint8_t is_bit_set(uint8_t reg, uint8_t pos) {
  return (reg & (1 << pos)) ? 1 : 0;
}
