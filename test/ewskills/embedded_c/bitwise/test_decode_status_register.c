#include "../../../../src/ewskills/embedded_c/bitwise/decode_status.c"

#include "../../../../Unity-2.7.0/src/unity.c"

void setUp(void) {}

void tearDown(void) {}

static void test_one(void) {
  char *actual = decode_status(13);
  TEST_ASSERT_EQUAL_STRING("Power On\nTx Ready\nRx Ready\n", actual);
  free(actual);
}

static void test_two(void) {
  char *actual = decode_status(48);
  TEST_ASSERT_EQUAL_STRING("Overheat\nUndervoltage\n", actual);
  free(actual);
}

static void test_three(void) {
  char *actual = decode_status(255);
  TEST_ASSERT_EQUAL_STRING("Power On\nError\nTx Ready\nRx "
                           "Ready\nOverheat\nUndervoltage\nTimeout\nReserved\n",
                           actual);
  free(actual);
}

// int main() {
//   uint8_t reg;
//   scanf("%hhu", &reg);
//   decode_status(reg);
//   return 0;
// }

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_one);
  RUN_TEST(test_two);
  RUN_TEST(test_three);
  return UNITY_END();
}
