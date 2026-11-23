#include <stdint.h>

#define SET_BIT(reg, pos) (reg |= (1 << pos))

#define CLEAR_BIT(reg, pos) (reg &= ~(1 << pos))

#define TOGGLE_BIT(reg, pos) (reg ^= (1 << pos))

uint8_t modify_register(uint8_t reg) {
  SET_BIT(reg, 2);
  SET_BIT(reg, 7);
  CLEAR_BIT(reg, 3);
  TOGGLE_BIT(reg, 5);
  return reg;
}
