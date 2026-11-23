#include <stdint.h>

uint8_t clear_bit(uint8_t reg, const uint8_t pos) {
  reg &= ~(1 << pos);
  return reg;
}
