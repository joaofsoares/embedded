#include "../../../../src/ewskills/embedded_c/bitwise/bit_set.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_bit_set_one(void) {
  const int actual = set_bit(0b00000101, 1);
  TEST_ASSERT_EQUAL(0b00000111, actual);
}

static void test_bit_set_two(void) {
  const int actual = set_bit(0b00001000, 0);
  TEST_ASSERT_EQUAL(0b00001001, actual);
}

// int main() {
//   uint8_t reg, pos;
//   scanf("%hhu %hhu", &reg, &pos); // Accept register value and position
//   uint8_t result = set_bit(reg, pos);
//   printf("%u", result); // Output the result as an integer
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_bit_set_one);
  RUN_TEST(test_bit_set_two);
  return UNITY_END();
}
