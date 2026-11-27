#include "../../../../src/ewskills/embedded_c/bit_field/multiple_bits.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_one(void) {
  uint8_t actual = set_range(0b00000000, 1, 3);
  TEST_ASSERT_EQUAL(0b00001110, actual);
}

static void test_two(void) {
  uint8_t actual = set_range(0b00001000, 0, 2);
  TEST_ASSERT_EQUAL(0b00001111, actual);
}

static void test_three(void) {
  uint8_t actual = set_range(0b00000001, 3, 5);
  TEST_ASSERT_EQUAL(0b00111001, actual);
}

// int main() {
//   uint8_t reg, start, end;
//   scanf("%hhu %hhu %hhu", &reg, &start, &end);
//   printf("%u", set_range(reg, start, end));
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_one);
  RUN_TEST(test_two);
  RUN_TEST(test_three);
  return UNITY_END();
}
