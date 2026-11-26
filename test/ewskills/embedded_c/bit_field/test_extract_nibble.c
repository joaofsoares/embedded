#include "../../../../src/ewskills/embedded_c/bit_field/extract_nibble.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp() {}

void tearDown() {}

static void test_one(void) {
  const unsigned char actual = extractNibble(0xAB, 0);
  TEST_ASSERT_EQUAL(0xB, actual); // 0xB = 11
}

static void test_two(void) {
  const unsigned char actual = extractNibble(0xAB, 1);
  TEST_ASSERT_EQUAL(0xA, actual); // 0xA = 10
}

static void test_three(void) {
  const unsigned char actual = extractNibble(0xFF, 0);
  TEST_ASSERT_EQUAL(0xF, actual); // 0xF = 15
}

// int main() {
//   unsigned char reg;
//   int pos;
//   scanf("%hhu %d", &reg, &pos);
//   printf("%d", extractNibble(reg, pos));
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_one);
  RUN_TEST(test_two);
  RUN_TEST(test_three);
  return UNITY_END();
}
