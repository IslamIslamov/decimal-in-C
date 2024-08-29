#include "s21_tests.h"

START_TEST(negate_1) {
  s21_decimal value_one = {{2, 0, 0, ~(UINT_MAX >> 1)}}, result = {0};
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(value_one), s21_get_sign(result));
}

END_TEST

START_TEST(negate_2) {
  s21_decimal value_one = {{0, 0, 0, ~(UINT_MAX >> 1)}}, result = {0};
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(value_one), s21_get_sign(result));
}

END_TEST

START_TEST(negate_3) {
  s21_decimal value_one = {0}, result = {0};
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(value_one), s21_get_sign(result));
}

END_TEST

START_TEST(negate_4) {
  s21_decimal value_one = {{655678, 0, 0, 0}}, result = {0};
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(result), s21_get_sign(value_one));
}

END_TEST

START_TEST(negate_5) {
  s21_decimal value_one = {{777, 346678, 455678, 0}}, result = {0};
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(result), s21_get_sign(value_one));
}

END_TEST

START_TEST(negate_6) {
  s21_decimal value_one = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}}, result = {0};
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(result), s21_get_sign(value_one));
}

END_TEST

START_TEST(negate_7) {
  s21_decimal value_one = {{67295, 7777666, 1234567, 0}}, result = {0};
  s21_set_bit(&value_one, 127, 1);
  s21_set_power(&value_one, 10);
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(result), s21_get_sign(value_one));
}

END_TEST

START_TEST(negate_8) {
  s21_decimal value_one = {{0, 346678, 0, 0}}, result = {0};
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(result), s21_get_sign(value_one));
}

END_TEST

START_TEST(negate_9) {
  s21_decimal value_one = {{UINT_MAX, 346678, UINT_MAX, 0}}, result = {0};
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(result), s21_get_sign(value_one));
}

END_TEST

START_TEST(negate_10) {
  s21_decimal value_one = {{UINT_MAX, UINT_MAX, 0, 0}}, result = {0};
  s21_set_bit(&value_one, 127, 1);
  s21_set_power(&value_one, 5);
  s21_negate(value_one, &result);
  ck_assert_int_ne(s21_get_sign(result), s21_get_sign(value_one));
}

Suite *suite_negate(void) {
  Suite *suite;
  TCase *tc;
  suite = suite_create("s21_negate");
  tc = tcase_create("tcase_negate");

  tcase_add_test(tc, negate_1);
  tcase_add_test(tc, negate_2);
  tcase_add_test(tc, negate_3);
  tcase_add_test(tc, negate_4);
  tcase_add_test(tc, negate_5);
  tcase_add_test(tc, negate_6);
  tcase_add_test(tc, negate_7);
  tcase_add_test(tc, negate_8);
  tcase_add_test(tc, negate_9);
  tcase_add_test(tc, negate_10);

  suite_add_tcase(suite, tc);
  return suite;
}