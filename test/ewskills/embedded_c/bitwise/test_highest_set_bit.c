#include "../../../../src/ewskills/embedded_c/bitwise/highest_set_bit.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_one(void) {
  const uint16_t actual = highest_set_bit(44);
  TEST_ASSERT_EQUAL(32, actual);
}

static void test_two(void) {
  const uint16_t actual = highest_set_bit(512);
  TEST_ASSERT_EQUAL(512, actual);
}

static void test_three(void) {
  const uint16_t actual = highest_set_bit(255);
  TEST_ASSERT_EQUAL(128, actual);
}

// int main() {
//   uint16_t reg;
//   scanf("%hu", &reg);
//
//   uint16_t result = highest_set_bit(reg);
//   printf("%hu", result);
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_one);
  RUN_TEST(test_two);
  RUN_TEST(test_three);
  return UNITY_END();
}
