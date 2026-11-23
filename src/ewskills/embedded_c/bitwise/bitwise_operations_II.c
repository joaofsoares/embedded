#include <stdint.h>
#include <stdio.h>

int main(void) {
  // question 1
  // Solution & Learning
  // Correct Answer:  reg |= 0x02;
  // TX_EN is at bit 1. Setting bit 1 requires OR-ing with 0x02 (00000010).
  // This sets TX_EN without disturbing the existing RX_EN at bit 0.
  // reg |= 0x01; sets bit 0 (RX_EN), which is already set — no change. reg =
  // 0x03; uses = which overwrites the entire register. reg |= (1 << 2); sets
  // bit 2 (PARITY), not TX_EN.
  // Learning: Always map bit positions from the
  // datasheet before writing register code. An off-by-one in the bit position
  // can enable the wrong peripheral feature.

  // question 2
  // Solution & Learning
  // Correct Answer: Both (status >> 4) & 0x07 and (status & 0x70) >> 4
  // Option (status >> 4) & 0x07: shift first, then mask. >> 4 brings bits 4–6
  // down to positions 0–2, then & 0x07 isolates the 3-bit value.
  // Option (status & 0x70) >> 4: mask first, then shift. & 0x70 isolates bits
  // 4–6 in place (0x70 = 01110000), then >> 4 brings the value down to bit 0.
  // Both approaches give the same result. Option status & 0x70 masks the bits
  // but does not shift — the result stays in the range 0x00–0x70 instead of
  // 0–7.
  // Option status & (0x07 << 4) extracts error code but it remains at
  // position 4-6.
  // Learning: Shift-then-mask and mask-then-shift are both valid
  // for field extraction. Firmware codebases use both styles. The key is that
  // you must always do both operations — masking alone leaves the value at the
  // wrong bit position.
  //
  // question 3
  uint8_t reg = 0x0F;
  reg &= ~(0x03 << 2);       // Step 1: Clear bits 2-3
  reg |= (0x01 << 2);        // Step 2: Set new value
  printf("reg: %#x\n", reg); // 0x07

  // Solution & Learning
  // Correct Answer: 0x07
  // Starting value: 0x0F = 00001111.
  // Step 1 — ~(0x03 << 2) = ~0x0C = 11110011. After AND: 0x0F & 0xF3 = 0x03
  // (00000011).
  // Step 2 — (0x01 << 2) = 0x04. After OR: 0x03 | 0x04 = 0x07
  // (00000111).
  // Learning: The clear-then-set pattern (&= ~mask followed by |=
  // value) is the standard technique for updating a multi-bit field. Skipping
  // the clear step would OR old and new values together, corrupting the field.

  // question 4
  const uint8_t status = 0x0E; // 00001110
  if (status & 1U << 3) {
    printf("Set\n");
  } else {
    printf("Clear\n");
  }

  // it prints Set by coincidence
  // Solution & Learning
  // Correct Answer: Yes — but only by coincidence
  // << has higher precedence than &.
  // So the expression evaluates as status & (1 << 3) = 0x0E & 0x08 = 0x08.
  // Since 0x08 is non-zero, it correctly prints "Set".
  // Yes, it works because << has higher precedence than &, but it is risky
  // style and should use parentheses. Adding another operator — say status & 1
  // << 3 == 0x08 — would break because == binds tighter than &, completely
  // changing the logic.
  // Learning: Always use explicit parentheses in bitwise
  // expressions: if (status & (1 << 3)). Relying on precedence is a ticking
  // time bomb — it works until someone extends the expression.

  // question 5
  // Solution & Learning
  // Correct Answer: Swapping two values without a temporary variable
  // This is the classic XOR swap algorithm. Three XOR operations swap the
  // values of a and b without needing a temporary variable. It works because
  // XOR is associative and self-inverse: x ^ x = 0 and x ^ 0 = x. This makes
  // each step undo part of the previous one, leaving the values exchanged.
  // Learning:
  // XOR swap is useful in register-constrained environments where temporaries
  // are expensive. However, it fails if both variables are the same memory
  // location — both become zero. Always ensure a and b are distinct. Note- In
  // real embedded C today, XOR swap is usually worse for readability and often
  // not preferred over a temporary variable. This is a classic bitwise trick,
  // but in production firmware a temporary variable is usually clearer and
  // safer.

  // question 6
  uint8_t mask = 0x0F;
  if (~mask == 0xF0) {
    printf("Match\n");
  } else {
    printf("No match\n");
  }

  // Correct Answer: No match
  // The ~ operator causes integer promotion. Before the NOT is applied, mask is
  // promoted from uint8_t to int. So ~0x0000000F produces 0xFFFFFFF0 (on a
  // 32-bit system), not 0xF0. Since 0xFFFFFFF0 != 0xF0, the comparison fails.
  // To get the expected 8-bit result, cast after the NOT: if ((uint8_t)~mask ==
  // 0xF0). Now matches
  // Learning: C always promotes small integer types to int
  // before applying operators like ~. In firmware, this integer promotion is a
  // common source of comparison bugs when working with 8-bit or 16-bit register
  // values.

  // question 7
  //
  // Since these bits do not overlap, addition produces the same result as
  // bitwise OR.
  //
  // Solution & Learning
  // Correct Answers:
  // reg |= (1 << 1) | (1 << 3) | (1 << 5);
  // reg |= (1 << 1) + (1 << 3) + (1 << 5);
  // Option reg |= (1 << 1) | (1 << 3) | (1 << 5); uses bitwise OR to combine
  // masks: 0x02 | 0x08 | 0x20 = 0x2A. This is the standard approach. Option reg
  // |= (1 << 1) + (1 << 3) + (1 << 5); uses addition: 2 + 8 + 32 = 42 = 0x2A.
  // Since the bit positions don't overlap, addition and OR give the same
  // result. Option reg |= (1 << 1) & (1 << 3) & (1 << 5); uses AND: 0x02 & 0x08
  // & 0x20 = 0x00. AND between non-overlapping single-bit masks always gives
  // zero.
  // Learning: When setting non-overlapping bits, OR and addition are
  // equivalent. But OR is always safe even if bits overlap, while addition
  // gives wrong results with overlapping bits. Firmware convention strongly
  // favors |.

  return 0;
}
