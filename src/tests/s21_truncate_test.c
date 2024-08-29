#include "s21_tests.h"

START_TEST(s21_truncate_test_1) {
  s21_decimal value = {{0xD3, 0x0, 0x0, 1 << 16}};
  s21_decimal org_result = {{0x15, 0x0, 0x0, 0x0}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_2) {
  s21_decimal value = {{0xA5, 0x0, 0x0, 1 << 16}};
  s21_decimal org_result = {{0x10, 0x0, 0x0, 0x0}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_3) {
  s21_decimal value = {{0x800000A5, 0x0, 0x0, 1 << 16 | 1 << 17 | 1 << 18}};
  s21_decimal org_result = {{0x10, 0x0, 0x0, 0x0}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_4) {
  s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x000A0000}};
  s21_decimal org_result = {{0x6DF37F67, 0x0, 0x0, 0x0}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_5) {
  s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x000A0000}};
  s21_decimal org_result = {{0x6DF37F67, 0x0, 0x0, 0x0}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_6) {
  s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x000A0000}};
  s21_decimal org_result = {{0x6DF37F67, 0x0, 0x0, 0x0}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_7) {
  s21_decimal value = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0x0, 1 << 18 | 1 << 19 | 1 << 31}};
  s21_decimal org_result = {{0x1197998, 0x0, 0x0, 1 << 31}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_8) {
  s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};
  s21_decimal org_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_9) {
  s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};
  s21_decimal org_result = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_10) {
  s21_decimal value = {{INT_MAX, 0x0, 0x0, 0x0}};
  s21_decimal org_result = {{INT_MAX, 0x0, 0x0, 0x0}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

START_TEST(s21_truncate_test_11) {
  s21_decimal value = {{INT_MIN, 0x0, 0x0, 0x0}};
  s21_decimal org_result = {{INT_MIN, 0x0, 0x0, 0x0}};
  s21_decimal s21_result = {{0x0, 0x0, 0x0, 0x0}};
  ck_assert_int_eq(SUCCESS, s21_truncate(value, &s21_result));
  ck_assert_decimal_eq(org_result, s21_result);
}
END_TEST

Suite *suite_truncate(void) {
  Suite *suite = suite_create("s21_truncate");
  TCase *tcase = tcase_create("tcase_truncate");
  tcase_add_test(tcase, s21_truncate_test_1);
  tcase_add_test(tcase, s21_truncate_test_2);
  tcase_add_test(tcase, s21_truncate_test_3);
  tcase_add_test(tcase, s21_truncate_test_4);
  tcase_add_test(tcase, s21_truncate_test_5);
  tcase_add_test(tcase, s21_truncate_test_6);
  tcase_add_test(tcase, s21_truncate_test_7);
  tcase_add_test(tcase, s21_truncate_test_8);
  tcase_add_test(tcase, s21_truncate_test_9);
  tcase_add_test(tcase, s21_truncate_test_10);
  tcase_add_test(tcase, s21_truncate_test_11);
  suite_add_tcase(suite, tcase);
  return suite;
}