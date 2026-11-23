#define POS 5

int toggleFifthBit(int reg) {
  reg ^= (1 << POS); // Toggle bit
  return reg;
}
