#include <stdint.h>

uint8_t toggle_bit(uint8_t reg, const uint8_t pos) {
  reg ^= (1 << pos); // Toggle bit
  return reg;
}
