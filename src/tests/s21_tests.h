#ifndef S21_TESTS_H_
#define S21_TESTS_H_

#include <check.h>
#include <stdbool.h>

#include "../s21_decimal.h"

Suite *suite_add(void);
Suite *suite_sub(void);
Suite *suite_mul(void);
Suite *suite_div(void);

Suite *suite_is_less(void);
Suite *suite_is_less_or_equal(void);
Suite *suite_is_greater(void);
Suite *suite_is_greater_or_equal(void);
Suite *suite_is_equal(void);
Suite *suite_is_not_equal(void);
Suite *s21_from_int_to_decimal_suite(void);
Suite *s21_from_decimal_to_int_suite(void);
Suite *s21_from_float_to_decimal_suite(void);
Suite *s21_from_decimal_to_float_suite(void);

Suite *suite_floor(void);
Suite *suite_negate(void);
Suite *suite_round(void);
Suite *suite_truncate(void);

#define S21_TRUE 1
#define S21_FALSE 0
#define CONVERTERS_S21_TRUE 0
#define CONVERTERS_S21_FALSE 1

#define ck_assert_decimal_eq(A, B)                          \
  ;                                                         \
  for (int i = 0; i < 128; i++) {                           \
    ck_assert_int_eq(s21_get_bit(A, i), s21_get_bit(A, i)); \
  }

void run_test(void);
void test_div_func(s21_decimal val_1, s21_decimal val_2, s21_decimal check);
void run_testcase(Suite *testcase);

#endif  //  S21_TESTS_H_