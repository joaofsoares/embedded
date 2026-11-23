#include "../../../../src/ewskills/embedded_c/bitwise/bit_toggle.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp() {}

void tearDown() {}

// Input: 10
// Explanation:
// Binary representation of 10 is 00001010.
// Toggling the 5th bit (position 5) results in 00101010, which is 42 in
// decimal. Expected Output: 42
static void test_input_10(void) {
  const int actual = toggleFifthBit(10);
  TEST_ASSERT_EQUAL(42, actual);
}

// Input: 31
// Explanation:
// Binary representation of 31 is 00011111.
// Toggling the 5th bit (position 5) results in 00111111, which is 63 in
// Toggling the 6th bit (position 6) results in 01011111, which is 95 in
// decimal. Expected Output: 63
static void test_input_31(void) {
  const int actual = toggleFifthBit(31);
  TEST_ASSERT_EQUAL(63, actual);
}

// Input: 0
// Explanation:
// Binary representation of 0 is 00000000.
// Toggling the 5th bit (position 5) results in 00100000, which is 32 in
// decimal. Expected Output: 32
static void test_input_0(void) {
  const int actual = toggleFifthBit(0);
  TEST_ASSERT_EQUAL(32, actual);
}

// int main() {
//   int n;
//   scanf("%d", &n);
//   printf("%d", toggleFifthBit(n));
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_input_10);
  RUN_TEST(test_input_31);
  RUN_TEST(test_input_0);
  return UNITY_END();
}
