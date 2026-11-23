#include <stddef.h>
#include <stdint.h>

uint16_t spread_bits(const uint8_t val) {
  uint16_t bit;

  size_t original_cnt = 0;
  for (size_t i = 0; i < 16; i++) {
    if (i % 2 == 0) {

      if (val & (1 << original_cnt)) {
        bit |= (1 << i);
      } else {
        bit &= ~(1 << i);
      }

      original_cnt++;
    } else {
      bit &= ~(1 << i);
    }
  }

  return bit;
}
