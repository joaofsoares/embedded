#include "../../../../src/ewskills/embedded_c/bitwise/bit_check.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_bit_check(void) {
  const int actual = isKthBitSet(8, 3);
  TEST_ASSERT_EQUAL(1, actual);
}

// int main() {
//   int n, k;
//   scanf("%d %d", &n, &k);
//   printf("%d", isKthBitSet(n, k));
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_bit_check);
  return UNITY_END();
}
