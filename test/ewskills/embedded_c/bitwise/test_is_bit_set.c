#include "../../../../src/ewskills/embedded_c/bitwise/is_bit_set.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_check_one(void) {
  const uint8_t actual = is_bit_set(0b00000100, 2);
  TEST_ASSERT_EQUAL(1, actual);
}

static void test_check_two(void) {
  const uint8_t actual = is_bit_set(0b00000100, 1);
  TEST_ASSERT_EQUAL(0, actual);
}

// int main() {
//   uint8_t reg, pos;
//   scanf("%hhu %hhu", &reg, &pos);
//   printf("%u", is_bit_set(reg, pos));
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_check_one);
  RUN_TEST(test_check_two);
  return UNITY_END();
}
