#include <stdint.h>
#include <stdio.h>

#define TOGGLE_BIT(reg, n) ((reg) ^= (1 << (n)), (reg) & (1 << (n)))

int main(void) {

  // question 1
  uint8_t ctrl = 0x00;
  uint8_t pos = 3;
  TOGGLE_BIT(ctrl, pos++);
  printf("ctr: %#x\n", ctrl);

  // Solution & Learning
  // Correct Answer: Toggles bit 3 but checks bit 4 — because pos++ is evaluated
  // twice The macro uses n twice — once in the toggle expression and once in
  // the check expression. With pos++ as the argument, the expansion becomes:
  // ((ctrl) ^= (1 << (pos++)), (ctrl) & (1 << (pos++)))
  // The first pos++ evaluates pos as 3 (toggles bit 3) and increments to 4. The
  // second pos++ evaluates pos as 4 (checks bit 4). The toggle and check target
  // different bits.
  // Learning:
  // Never pass expressions with side effects (++, --, function calls) to
  // macros. The argument may be expanded multiple times, causing the side
  // effect to execute more than once — a silent bug that's extremely hard to
  // catch in firmware.

  // question 2
  // Correct Answer: 5
  // 0xB5 in binary is 10110101.
  // Bit	7	6	5	4	3	2	1	0
  // Value	1	0	1	1	0	1	0	1
  // Field	ERR	DONE	BUSY	CH	CH	CH	DIR	EN
  // CH occupies bits 2–4. Extracting: (0xB5 >> 2) & 0x07 = (0x2D) & 0x07 = 0x05
  // = 5.
  // Learning: Decoding multi-bit fields from status registers is a daily
  // firmware task. Always shift first to bring the field to bit 0, then mask to
  // isolate it. Practice reading binary against the datasheet layout.

  // question 3
  // Correct Answer: No — gives a completely different result than the original
  // logic
  // With & replacing &&: the expression becomes flags & 0x01 & flags & 0x80.
  // Since & is left-associative, this evaluates as ((flags & 0x01) & flags) &
  // 0x80 — which gives a completely different result than the original logic.
  // The individual checks get merged into a single chain instead of being
  // evaluated as two separate conditions. Additionally, logical && provides
  // short-circuit evaluation — if the left side is false, the right side is
  // never evaluated. Bitwise & always evaluates both sides.
  // Learning:
  // Use && for conditions and & for bit manipulation.
  // Confusing them is a common bug, especially dangerous when the right-hand
  // side has side effects like function calls or register reads.

  // question 4
  // Solution & Learning
  // Correct Answer: (0x05 << 3)
  // The BAUD field starts at bit 3 and is 3 bits wide. To place the value 5
  // (101) into bits 3–5, it must be shifted left by 3: 0x05 << 3 = 0x28
  // (00101000). (0x05 << 2) shifts by 2 — off by one, placing the value in bits
  // 2–4. (0x07 << 3) writes 0x07 (all 1s) instead of the desired value. (0x05)
  // doesn't shift at all, placing 5 in bits 0–2.
  // Learning: When writing a field
  // value, you must shift by the field's starting bit position. Getting the
  // offset wrong by even one bit corrupts the target field and bleeds into an
  // adjacent field.

  // question 5
  uint8_t reg = 0x00;
  reg |= (1 << 0);  // Operation 1
  reg |= (1 << 4);  // Operation 2
  reg ^= (1 << 0);  // Operation 3
  reg |= (1 << 7);  // Operation 4
  reg &= ~(1 << 4); // Operation 5

  printf("reg: %d\n", reg);
  printf("reg: %#x\n", reg);

  // Correct Answer:  0x80
  //  Tracing step by step:
  //  After Op 1: 0x00 | 0x01 = 0x01 (bit 0 set)
  //  After Op 2: 0x01 | 0x10 = 0x11 (bit 4 set)
  //  After Op 3: 0x11 ^ 0x01 = 0x10 (bit 0 toggled off)
  //  After Op 4: 0x10 | 0x80 = 0x90 (bit 7 set)
  //  After Op 5: 0x90 & ~0x10 = 0x80 (bit 4 cleared)
  //  Final: 0x80 — only bit 7 remains set.
  // Learning:
  // In real firmware, initialization sequences often involve multiple register
  // operations in a specific order.
  // Being able to mentally trace cumulative bit state through set, clear,
  // and toggle operations is an essential debugging skill.

  // question 6
  // Correct Answer: Both work for the if-check, but they return different
  // non-zero values when the bit is set Both correctly detect whether bit 5 is
  // set — any non-zero value is true in C. Style A: reg & 0x20 returns 0x20
  // (32) when bit 5 is set. Style B: (reg >> 5) & 1 returns 1 when bit 5 is
  // set. For a simple if check, both are fine. But if you store or compare the
  // result (e.g., if (result == 1)), only Style B gives a normalized 0/1 value.
  // Learning:
  // Style A is the more common firmware idiom for if-checks.
  // Style B is better when you need a clean 0 or 1 value — for example, when
  // packing extracted bits into another variable or using the result in
  // arithmetic.

  return 0;
}
