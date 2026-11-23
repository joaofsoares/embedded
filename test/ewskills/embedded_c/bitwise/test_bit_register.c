#include "../../../../src/ewskills/embedded_c/bitwise/bit_register.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp() {}

void tearDown() {}

static void test_case_one() {
  unsigned char actual = modifyBit(10, 3, 1);
  TEST_ASSERT_EQUAL(10, actual);
}

static void test_case_two() {
  unsigned char actual = modifyBit(10, 3, 0);
  TEST_ASSERT_EQUAL(2, actual);
}

static void test_case_three() {
  unsigned char actual = modifyBit(5, 2, 1);
  TEST_ASSERT_EQUAL(5, actual);
}

static void test_case_four() {
  unsigned char actual = modifyBit(5, 2, 0);
  TEST_ASSERT_EQUAL(1, actual);
}

static void test_case_five() {
  unsigned char actual = modifyBit(7, 1, 0);
  TEST_ASSERT_EQUAL(5, actual);
}

static void test_case_six() {
  unsigned char actual = modifyBit(7, 2, 1);
  TEST_ASSERT_EQUAL(7, actual);
}

// tests based on:
// int main() {
//   unsigned char reg;
//   int pos, mode;
//   scanf("%hhu %d %d", &reg, &pos, &mode);
//   printf("%d", modifyBit(reg, pos, mode));
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_case_one);
  return UNITY_END();
}
