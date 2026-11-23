#include "../../../../src/ewskills/embedded_c/bitwise/bit_operation_macro.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_one(void) {
  const uint8_t actual = modify_register(0);
  TEST_ASSERT_EQUAL(164, actual);
}

static void test_two(void) {
  const uint8_t actual = modify_register(255);
  TEST_ASSERT_EQUAL(215, actual);
}

static void test_three(void) {
  const uint8_t actual = modify_register(36);
  TEST_ASSERT_EQUAL(132, actual);
}

// int main() {
//   uint8_t reg;
//   scanf("%hhu", &reg);
//   printf("%u", modify_register(reg));
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_one);
  RUN_TEST(test_two);
  RUN_TEST(test_three);
  return UNITY_END();
}
