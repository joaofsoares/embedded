#include <stdint.h>
#include <stdio.h>

int main(void) {
  // question 1
  uint8_t ctrl_reg = 0xCB;

  // = overide the whole register to 0x10
  ctrl_reg = (1 << 4);

  printf("reg: %#x\n", ctrl_reg);

  // Solution & Learning
  // Correct Answer:  0x10
  // The assignment ctrl_reg = (1 << 4) replaces the entire register with 0x10
  // (00010000). All previously configured bits in 0xCB are lost. The correct
  // approach is bitwise OR with assignment: ctrl_reg |= (1 << 4);  // Sets only
  // bit 4, others untouched With |=, the result would be 0xCB | 0x10 = 0xDB.
  // Learning: In register programming, = overwrites everything. |= is the safe
  // way to set bits. A single wrong operator can misconfigure an entire
  // peripheral.

  // question 2
  uint8_t reg;
  reg &= ~(0x03 << 5); // clear bit

  // Solution & Learning
  // Correct Answer: Clears the MODE field to 00
  // 0x03 << 5 produces 0x60 (01100000), which covers bits 5 and 6 — exactly the
  // MODE field. The ~ inverts it to 10011111, and &= clears only those two bits
  // to 00, leaving all other fields untouched. Learning: Reading register
  // operations against a datasheet bit layout is a daily firmware skill. The
  // pattern reg &= ~(mask << offset) is the standard way to clear a multi-bit
  // field before writing a new value.

  // question 3
  reg ^= (1 << 3);
  // Solution & Learning
  // Correct Answer:  ^=
  // The ^= operator performs bitwise XOR assignment.
  // XOR with a 1-bit flips the target bit — if it was 1, it becomes 0, and vice
  // versa.
  // |= would set the bit (always to 1).
  // &= combined with a mask would clear.
  // ~= is not a valid C operator.
  // Learning:
  // The three fundamental bit operations — set (|=), clear (&= ~), and toggle
  // (^=) — each require a different operator. Mixing them up is one of the most
  // common register bugs.

  // question 4
  uint32_t val = 1;
  uint32_t result = val << 32;
  // Solution & Learning
  // Correct Answer: Undefined behavior
  // The C standard (C11 6.5.7) states that shifting a value by an amount equal
  // to or greater than the width of the type is undefined behavior. Even though
  // val is uint32_t, shifting by 32 exceeds the valid range of 0 to 31. Some
  // CPUs may produce 0, others may leave the value unchanged — the result is
  // unpredictable and non-portable Learning: Always ensure the shift count is
  // strictly less than the bit width of the type. For uint32_t, valid shifts
  // are 0 to 31. This matters in firmware when shift amounts come from
  // variables or macros whose values may not be obvious at a glance.

  // question 5
  reg |= (1 << 31);
  reg |= (1U << 31);

  // Solution & Learning
  // Correct Answer: Only Developer B's code is correct
  // In Developer A's code, 1 is a signed int.
  // Shifting a signed 1 into the sign bit (bit 31) is undefined behavior per
  // the C standard. The compiler may produce unexpected results or optimize the
  // code away entirely. Developer B uses 1U — an unsigned literal. Shifting an
  // unsigned value left by 31 is well-defined and produces 0x80000000.
  // Learning:
  // Always use 1U (or explicit unsigned cast) when shifting into high bit
  // positions of 32-bit registers. This is especially critical in firmware
  // where you routinely configure bits across the full 32-bit register width.

  // question 6
  reg ^= (1 << 2);
  reg ^= (1 << 2);

  // Solution & Learning
  // Correct Answer: 0xA5
  // XOR toggle is a self-inverse operation.
  // Toggling the same bit twice restores the original value.
  // First XOR: 0xA5 ^ 0x04 = 0xA1 (bit 2 flips from 1 to 0).
  // Second XOR: 0xA1 ^ 0x04 = 0xA5 (bit 2 flips back to 1).
  // Learning:
  // XOR is its own undo operation. This property is used in error detection and
  // encryption. But it also means accidental double-toggle silently does
  // nothing — a subtle bug that's hard to catch in interrupt-driven code.

  // question 7
  reg &= (0x03 << 2);
  // missing ~ in front of the command

  // Solution & Learning
  // Correct Answer: The mask is not inverted
  // (0x03 << 2) produces 0x0C (00001100).
  // When used with &=, it keeps only bits 2–3 and clears everything else.
  // The result is 0x0C, not 0xF3.
  // The correct code uses ~ to invert the mask:
  // reg &= ~(0x03 << 2);  // Clears only bits 2-3
  // Learning:
  // Forgetting the ~ inversion when clearing bits is a dangerous and common
  // bug. Without ~, the AND mask preserves the target bits and destroys
  // everything else — the exact opposite of what you intended.

  return 0;
}
