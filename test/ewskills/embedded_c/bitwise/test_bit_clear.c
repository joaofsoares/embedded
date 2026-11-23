#include "../../../../src/ewskills/embedded_c/bitwise/bit_clear.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_bit_clear_one(void) {
  const uint8_t actual = clear_bit(0b00000111, 0);
  TEST_ASSERT_EQUAL(0b00000110, actual);
}

static void test_bit_clear_two(void) {
  const uint8_t actual = clear_bit(0b00001111, 3);
  TEST_ASSERT_EQUAL(0b00000111, actual);
}

// int main() {
//   uint8_t reg, pos;
//   scanf("%hhu %hhu", &reg, &pos);
//   uint8_t result = clear_bit(reg, pos);
//   printf("%u", result);
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_bit_clear_one);
  RUN_TEST(test_bit_clear_two);
  return UNITY_END();
}
