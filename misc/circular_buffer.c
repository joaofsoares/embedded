#include <stdbool.h>
#include <stdint.h>

#define BUFFER_SIZE 50

typedef struct {
  uint8_t buffer[BUFFER_SIZE];
  uint8_t head;
  uint8_t tail;
  uint8_t count;
} CircularBuffer;

CircularBuffer create_circular_buffer(void) {
  CircularBuffer circular_buffer;
  circular_buffer.head = 0;
  circular_buffer.tail = 0;
  circular_buffer.count = 0;

  return circular_buffer;
}

// insert operation (push)
bool push(CircularBuffer *cb, uint8_t data) {
  if (cb->count == BUFFER_SIZE) {
    return false;
  }

  cb->buffer[cb->head] = data;
  cb->head = (cb->head + 1) % BUFFER_SIZE;
  cb->count++;

  return true;
}

// read operation (pop)
bool pop(CircularBuffer *cb, uint8_t *data) {
  if (cb->count == 0) {
    return false;
  }

  *data = cb->buffer[cb->tail];

  if (cb->tail > 0) {
    cb->tail = (cb->tail - 1) % BUFFER_SIZE;
  }

  if (cb->head > 0) {
    cb->head = (cb->head - 1);
  }

  if (cb->count > 0) {
    cb->count--;
  }

  return true;
}

bool peek(CircularBuffer *cb, uint8_t *data) {
  if (cb->count == 0) {
    return false;
  }

  *data = cb->buffer[cb->tail];

  return true;
}

bool is_full(CircularBuffer *cb) { return cb->count == BUFFER_SIZE; }

bool is_empty(CircularBuffer *cb) { return cb->count == 0; }
