#include "../../src/ewskills/bit_register.c"

#include "../../Unity-2.7.0/src/unity.c"

void setUp() {}

void tearDown() {}

static void test_case_one() {
  unsigned char reg = modifyBit(10, 3, 1);
  TEST_ASSERT_EQUAL(10, reg);
}

static void test_case_two() {
  unsigned char reg = modifyBit(10, 3, 0);
  TEST_ASSERT_EQUAL(2, reg);
}

static void test_case_three() {
  unsigned char reg = modifyBit(5, 2, 1);
  TEST_ASSERT_EQUAL(5, reg);
}

static void test_case_four() {
  unsigned char reg = modifyBit(5, 2, 0);
  TEST_ASSERT_EQUAL(1, reg);
}

static void test_case_five() {
  unsigned char reg = modifyBit(7, 1, 0);
  TEST_ASSERT_EQUAL(5, reg);
}

static void test_case_six() {
  unsigned char reg = modifyBit(7, 2, 1);
  TEST_ASSERT_EQUAL(7, reg);
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
