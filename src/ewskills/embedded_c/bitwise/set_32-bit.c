#include <stdint.h>
#include <stdio.h>

uint32_t set_bits(uint32_t reg, const uint8_t pos, const uint8_t len) {
  for (size_t i = 0; i < len; i++) {
    uint8_t p = (pos + i);
    if (!(reg & (1 << p))) {
      reg |= (1 << p);
    }
  }

  return reg;
}
