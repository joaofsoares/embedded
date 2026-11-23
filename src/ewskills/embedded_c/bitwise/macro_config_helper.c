#include <stdint.h>

// set 1 or 0 to bit 0
#define ENABLE(reg, enable)                                                    \
  do {                                                                         \
    if (enable) {                                                              \
      reg |= (1 << 0);                                                         \
    } else {                                                                   \
      reg &= ~(1 << 0);                                                        \
    }                                                                          \
  } while (0)

// reg &= ~(0x03 << 1);// Clear MODE bits (bits 1–2)
// reg |= ((mode & 0x03) << 1) // set MODE to bits 1-2
#define MODE(reg, mode)                                                        \
  do {                                                                         \
    reg &= ~(0x03 << 1);                                                       \
    reg |= ((mode & 0x03) << 1);                                               \
  } while (0)

// reg &= ~(0x07 << 7);// Clear SPEED bits (bits 3–5)
// reg |= ((speed & 0x07) << 1) // set SPEED to bits 3-5
#define SPEED(reg, speed)                                                      \
  do {                                                                         \
    reg &= ~(0x07 << 3);                                                       \
    reg |= ((speed & 0x07) << 3);                                              \
  } while (0)

// set 0 to bits 6-7
#define RESERVE(reg)                                                           \
  do {                                                                         \
    reg &= ~(0x03 << 6);                                                       \
  } while (0)

uint16_t build_register(uint8_t enable, uint8_t mode, uint8_t speed) {
  uint16_t reg;

  ENABLE(reg, enable);
  MODE(reg, mode);
  SPEED(reg, speed);
  RESERVE(reg);

  return reg;
}
