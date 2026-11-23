#include "../../../../src/ewskills/embedded_c/bitwise/set_32-bit.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_set_one(void) {
  const uint32_t actual = set_bits(0b00000000000000000000000000000000, 4, 3);
  TEST_ASSERT_EQUAL(0b00000000000000000000000001110000, actual);
}

static void test_set_two(void) {
  const uint32_t actual = set_bits(0b00000000000000000000000000000001, 1, 2);
  TEST_ASSERT_EQUAL(0b00000000000000000000000000000111, actual);
}

// int main() {
//   uint32_t reg;
//   uint8_t pos, len;
//   scanf("%u %hhu %hhu", &reg, &pos, &len);
//   printf("%u", set_bits(reg, pos, len));
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_set_one);
  RUN_TEST(test_set_two);
  return UNITY_END();
}
