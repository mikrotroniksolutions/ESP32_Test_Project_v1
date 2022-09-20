#include <Arduino.h>

// cppcheck-suppress unusedFunction
void setup() {
  // put your setup code here, to run once:
  uint8_t *ptr1 = (uint8_t*)malloc(512);
  uint8_t *ptr2 = (uint8_t*)malloc(512);
  uint8_t *ptr3 = (uint8_t*)malloc(512);

  (void)ptr1;
  (void)ptr2;
  (void)ptr3;

  free(ptr1);
  free(ptr2);
  free(ptr3);
}

// cppcheck-suppress unusedFunction
void loop() {
  // put your main code here, to run repeatedly:
}