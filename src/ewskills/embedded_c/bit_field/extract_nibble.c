#define GET_NIBBLE(reg, pos) (((reg) >> ((pos) * 4)) & 0x0F)

unsigned char extractNibble(const unsigned char reg, const int pos) {
  return GET_NIBBLE(reg, pos);
}
