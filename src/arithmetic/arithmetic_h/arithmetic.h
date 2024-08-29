#ifndef S21_ARITHMETIC_H_
#define S21_ARITHMETIC_H_
#include "./../../types.h"
#include "./arithmetic_extention_funcs.h"
#include "./binary_operation.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif  // S21_ARITHMETIC_H_