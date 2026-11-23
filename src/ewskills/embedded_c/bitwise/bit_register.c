unsigned char modifyBit(unsigned char reg, const int pos, const int mode) {
  switch (mode) {
  case 0:
    reg &= ~(1 << pos); // clear
    break;
  default:
    reg |= (1 << pos); // set
  }

  return reg;
}
