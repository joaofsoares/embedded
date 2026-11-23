#include "../../../../src/ewskills/embedded_c/bitwise/bit_spread_interleave.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_one(void) {
  const uint16_t actual = spread_bits(0b11001010);
  TEST_ASSERT_EQUAL(0b0101000001000100, actual);
}

static void test_two(void) {
  const uint16_t actual = spread_bits(0b10101010);
  TEST_ASSERT_EQUAL(0b0100010001000100, actual);
}

static void test_three(void) {
  const uint16_t actual = spread_bits(0b11111111);
  TEST_ASSERT_EQUAL(0b0101010101010101, actual);
}

// int main() {
//   uint8_t val;
//   scanf("%hhu", &val);
//
//   uint16_t result = spread_bits(val);
//   printf("%u", result);
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_one);
  RUN_TEST(test_two);
  RUN_TEST(test_three);
  return UNITY_END();
}
