#include <stdint.h>

uint16_t highest_set_bit(uint16_t reg) {
  uint16_t result = 0;

  while (reg != 0) {
    result = reg; // The last set bit remaining before result becomes zero is
                  // the highest set bit.

    reg &= (result - 1); // Clear lowest set bit
  }

  return result;
}
