#include "s21_tests.h"

START_TEST(from_float_to_decimal_1) {
  s21_decimal value = {{0, 0, 0, 0}};
  float result, value_f = -INFINITY;
  s21_from_float_to_decimal(value_f, &value);
  s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, 0);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
  s21_decimal value = {{0, 0, 0, 0}};
  s21_do_zero_decimal(&value);
  float result = 0, value_f = -7777.777f;
  s21_from_float_to_decimal(value_f, &value);
  s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, value_f);
}
END_TEST

START_TEST(from_float_to_decimal_3) {
  s21_decimal value = {{0, 0, 0, 0}};
  float result, value_f = 85899;
  s21_from_float_to_decimal(value_f, &value);
  s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, value_f);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  s21_decimal value = {{0, 0, 0, 0}};
  float result, value_f = -1234.56789;
  s21_from_float_to_decimal(value_f, &value);
  s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq_tol(result, value_f, 7);
}
END_TEST

START_TEST(from_float_to_decimal_5) {
  s21_decimal value = {{0, 0, 0, 0}};
  float result, value_f = 4294.967;
  s21_from_float_to_decimal(value_f, &value);
  s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq(result, value_f);
}
END_TEST

START_TEST(from_float_to_decimal_6) {
  s21_decimal value = {{0, 0, 0, 0}};
  float result, value_f = -8589;
  s21_from_float_to_decimal(value_f, &value);
  s21_from_decimal_to_float(value, &result);
  ck_assert_float_eq_tol(result, value_f, 6);
}
END_TEST

START_TEST(from_float_to_decimal_7) {
  float inp = -321.2;
  s21_decimal out = {{0, 0, 0, 0}};
  int error = s21_from_float_to_decimal(inp, &out);
  s21_decimal res = {{0x00000C8C, 0, 0, 2147549184}};
  ck_assert_int_eq(out.bits[0], res.bits[0]);
  ck_assert_int_eq(out.bits[1], res.bits[1]);
  ck_assert_int_eq(out.bits[2], res.bits[2]);
  ck_assert_int_eq(out.bits[3], res.bits[3]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_8) {
  s21_decimal val;
  float fl1 = -128.023;
  float fl1_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
}
END_TEST

START_TEST(from_float_to_decimal_9) {
  s21_decimal val;
  float fl1 = 22.14836E+03;
  float fl1_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
}
END_TEST

START_TEST(from_float_to_decimal_10) {
  s21_decimal val;
  s21_from_float_to_decimal(1.02E+09, &val);
  ck_assert_int_eq(val.bits[0], 1020000000);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_11) {
  s21_decimal val;
  float fl1 = -333.2222;
  float fl1_res = 0;

  s21_from_float_to_decimal(fl1, &val);
  s21_from_decimal_to_float(val, &fl1_res);
  ck_assert_double_eq_tol(fl1, fl1_res, 1e-28);
}
END_TEST

START_TEST(from_float_to_decimal_12) {
  s21_decimal val;
  float a = 1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_13) {
  s21_decimal val;
  float a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_14) {
  s21_decimal val;
  float a = 1e-30;
  s21_from_float_to_decimal(a, &val);
  ck_assert_int_eq(val.bits[0], 0);
  ck_assert_int_eq(val.bits[1], 0);
  ck_assert_int_eq(val.bits[2], 0);
  ck_assert_int_eq(val.bits[3], 0);
}
END_TEST

START_TEST(from_float_to_decimal_15) {
  s21_decimal dec;
  float tmp = 0;
  float tmp1 = 0.03;
  s21_from_float_to_decimal(tmp1, &dec);
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, tmp1, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_16) {
  s21_decimal dec;
  s21_from_float_to_decimal(-128.023, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -128.023, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_17) {
  s21_decimal dec;
  s21_from_float_to_decimal(-2.147483E+06, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -2.147483E+06, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_18) {
  s21_decimal dec;
  s21_from_float_to_decimal(22.14836E+03, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 22.14836E+03, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_19) {
  s21_decimal dec;
  s21_from_float_to_decimal(1.0020000, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, 1.0020000, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_20) {
  s21_decimal dec;
  s21_from_float_to_decimal(-333.2222, &dec);
  float tmp = 0;
  s21_from_decimal_to_float(dec, &tmp);
  ck_assert_float_eq_tol(tmp, -333.2222, 1e-06);
}
END_TEST

START_TEST(from_float_to_decimal_21) {
  s21_decimal dec;
  float a = 1.0 / 0.0;
  int ret = s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(ret, 1);
}
END_TEST

START_TEST(from_float_to_decimal_22) {
  s21_decimal dec;
  float a = -1.0 / 0.0;
  s21_from_float_to_decimal(a, &dec);
  ck_assert_int_eq(dec.bits[0], 0);
  ck_assert_int_eq(dec.bits[1], 0);
  ck_assert_int_eq(dec.bits[2], 0);
  ck_assert_int_eq(dec.bits[3], 0);
}
END_TEST

Suite *s21_from_float_to_decimal_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("---FLOAT-TO-DEC---");
  tc = tcase_create("FLOAT-TO-DEC");

  tcase_add_test(tc, from_float_to_decimal_1);
  tcase_add_test(tc, from_float_to_decimal_2);
  tcase_add_test(tc, from_float_to_decimal_3);
  tcase_add_test(tc, from_float_to_decimal_4);
  tcase_add_test(tc, from_float_to_decimal_5);
  tcase_add_test(tc, from_float_to_decimal_6);
  tcase_add_test(tc, from_float_to_decimal_7);
  tcase_add_test(tc, from_float_to_decimal_8);
  tcase_add_test(tc, from_float_to_decimal_9);
  tcase_add_test(tc, from_float_to_decimal_10);
  tcase_add_test(tc, from_float_to_decimal_11);
  tcase_add_test(tc, from_float_to_decimal_12);
  tcase_add_test(tc, from_float_to_decimal_13);
  tcase_add_test(tc, from_float_to_decimal_14);
  tcase_add_test(tc, from_float_to_decimal_15);
  tcase_add_test(tc, from_float_to_decimal_16);
  tcase_add_test(tc, from_float_to_decimal_17);
  tcase_add_test(tc, from_float_to_decimal_18);
  tcase_add_test(tc, from_float_to_decimal_19);
  tcase_add_test(tc, from_float_to_decimal_20);
  tcase_add_test(tc, from_float_to_decimal_21);
  tcase_add_test(tc, from_float_to_decimal_22);

  suite_add_tcase(s, tc);
  return s;
}