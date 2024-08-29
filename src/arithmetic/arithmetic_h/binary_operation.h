#ifndef BINARY_OPERATION_H_
#define BINARY_OPERATION_H_
#include "../../s21_decimal.h"

int s21_binary_add(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
void s21_binary_sub(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result);
void s21_binary_div(s21_decimal number_1, s21_decimal number_2,
                    s21_decimal *buf, s21_decimal *result);
#endif  // BINARY_OPERATION_H_