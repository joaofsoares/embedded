#include "../../../src/misc/circular_buffer.c"

#include "../../../Unity-2.7.0/src/unity.c"

#include <stdint.h>

void setUp() {}

void tearDown() {}

static void test_circular_buffer_creation(void) {
  CircularBuffer cb = create_circular_buffer();
  TEST_ASSERT_EQUAL(0, cb.head);
  TEST_ASSERT_EQUAL(0, cb.tail);
  TEST_ASSERT_EQUAL(0, cb.count);
}

static void test_circular_buffer_push(void) {
  CircularBuffer cb = create_circular_buffer();

  bool b = push(&cb, 10);
  TEST_ASSERT_TRUE(b);
  TEST_ASSERT_EQUAL(10, cb.buffer[0]);

  TEST_ASSERT_EQUAL(1, cb.head);
  TEST_ASSERT_EQUAL(0, cb.tail);
  TEST_ASSERT_EQUAL(1, cb.count);

  b = push(&cb, 20);
  TEST_ASSERT_TRUE(b);
  TEST_ASSERT_EQUAL(20, cb.buffer[1]);

  TEST_ASSERT_EQUAL(2, cb.head);
  TEST_ASSERT_EQUAL(0, cb.tail);
  TEST_ASSERT_EQUAL(2, cb.count);
}

static void test_circular_buffer_pop(void) {
  CircularBuffer cb = create_circular_buffer();

  bool b = push(&cb, 10);
  TEST_ASSERT_TRUE(b);
  TEST_ASSERT_EQUAL(10, cb.buffer[0]);

  TEST_ASSERT_EQUAL(1, cb.head);
  TEST_ASSERT_EQUAL(0, cb.tail);
  TEST_ASSERT_EQUAL(1, cb.count);

  uint8_t data = 0;

  pop(&cb, &data);
  TEST_ASSERT_EQUAL(10, data);

  TEST_ASSERT_EQUAL(0, cb.head);
  TEST_ASSERT_EQUAL(0, cb.tail);
  TEST_ASSERT_EQUAL(0, cb.count);
}

static void test_circular_buffer_peek() {
  CircularBuffer cb = create_circular_buffer();

  bool b = push(&cb, 10);
  TEST_ASSERT_TRUE(b);
  TEST_ASSERT_EQUAL(10, cb.buffer[0]);

  TEST_ASSERT_EQUAL(1, cb.head);
  TEST_ASSERT_EQUAL(0, cb.tail);
  TEST_ASSERT_EQUAL(1, cb.count);

  uint8_t data = 0;

  peek(&cb, &data);
  TEST_ASSERT_EQUAL(10, data);

  TEST_ASSERT_EQUAL(1, cb.head);
  TEST_ASSERT_EQUAL(0, cb.tail);
  TEST_ASSERT_EQUAL(1, cb.count);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_circular_buffer_creation);
  RUN_TEST(test_circular_buffer_push);
  RUN_TEST(test_circular_buffer_pop);
  RUN_TEST(test_circular_buffer_peek);
  return UNITY_END();
}
