#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char *get_human_readable(size_t bit) {
  switch (bit) {
  case 0:
    return "Power On";
  case 1:
    return "Error";
  case 2:
    return "Tx Ready";
  case 3:
    return "Rx Ready";
  case 4:
    return "Overheat";
  case 5:
    return "Undervoltage";
  case 6:
    return "Timeout";
  case 7:
    return "Reserved";
  }
  return "";
}

char *decode_status(uint8_t status_reg) {
  char *str = malloc(255);

  for (size_t i = 0; i < 8; i++) {
    if (status_reg & (1 << i)) {
      strcat(str, get_human_readable(i));
      strcat(str, "\n");
    }
  }

  return str;
}
