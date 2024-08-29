#ifndef TYPES_H_
#define TYPES_H_
#include <stdint.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[7];
} s21_big_decimal;

#define START_LOW 0
#define START_MID 32
#define START_HIGHT 64
#define START_INFO 96

#define DECIMAL_MAX                           \
  (s21_decimal) {                             \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0 } \
  }
#define DECIMAL_MIN                                 \
  (s21_decimal) {                                   \
    { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1 << 31 } \
  }


typedef union {
  int i;
  struct {
    uint32_t empty1 : 16;  // 0
    uint32_t power : 8;  // содержат показатель степени
    uint32_t empty2 : 7;  // 0
    uint32_t sign : 1;    // содержит знак (+/-)
  } parts;
} s21_decimal_bit3;

typedef enum { S21_POSITIVE_SIGN = 0, S21_NEGATIVE_SIGN = 1 } number_sign;

typedef enum {
  ARITHMETIC_OK = 0,
  ARITHMETIC_BIGGER_OR_INFINITY = 1,
  ARITHMETIC_LESS_OR_MINUS_INFINITY = 2,
  ARITHMETIC_DIVIDE_ON_ZERO = 3,
  ARITHMETIC_ERROR = 4
} s21_errors_arithmetic;

#endif  // TYPES_H_