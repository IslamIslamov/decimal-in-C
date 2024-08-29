#include "s21_tests.h"

void test_div_func(s21_decimal val_1, s21_decimal val_2, s21_decimal check) {
  s21_decimal result = {{0}};
  int val = s21_div(val_1, val_2, &result);
  ck_assert_int_eq(s21_is_equal(check, result), 1);
  ck_assert_int_eq(val, 0);
}

START_TEST(div_test_1) {
  int num1 = 100;
  int num2 = 50;
  int res_origin = 2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_2) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -16384;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_3) {
  int num1 = 2;
  int num2 = 2;
  int res_origin = 1;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_4) {
  int num1 = 0;
  int num2 = 5;
  int res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_5) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(div_test_9) {
  float num1 = -0.9;
  float num2 = 30.323;
  float res_origin = num1 / num2;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_int_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_div_10) {
  s21_decimal dec1 = {{100, 0, 0, 0}};
  s21_decimal dec2 = {{99999, 0, 0, 0}};
  float res_s21 = 0;
  float res = 100.0 / 99999.0;
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(test_div_11) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = 100;
  float tmp2 = 999.99;
  float res_s21 = 0.0;
  float res = 0.100001;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_float_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(test_div_12) {
  s21_decimal dec1;
  s21_decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  float res_s21 = 0;
  float res = 0.00100001;
  s21_from_int_to_decimal(tmp1, &dec1);
  s21_from_int_to_decimal(tmp2, &dec2);
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_float(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(test_div_13) {
  s21_decimal dec1 = {{10.0e3, 0, 0, 0}};
  s21_decimal dec2 = {{2.00e2, 0, 0, 0}};
  int res_s21 = 0;
  int res = 50;
  s21_decimal res1;
  s21_div(dec1, dec2, &res1);
  s21_from_decimal_to_int(res1, &res_s21);
  ck_assert_float_eq_tol(res_s21, res, 6);
}
END_TEST

START_TEST(div_test_14) {
  int num1 = 123456;
  int num2 = 123;
  int res_origin = 1003;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_15) {
  int num1 = -123456;
  int num2 = -123;
  int res_origin = 1003;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_16) {
  int num1 = 123456;
  int num2 = -123;
  int res_origin = -1003;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_17) {
  int num1 = -123456;
  int num2 = 123;
  int res_origin = -1003;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_18) {
  int num1 = 0;
  int num2 = 123;
  int res_origin = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_19) {
  int num1 = 123;
  int num2 = 0;
  int res_origin = 0;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_21) {
  int num1 = 1111111111;
  int num2 = -1;
  int res_origin = -1111111111;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_22) {
  int num1 = 1111111111;
  int num2 = 1;
  int res_origin = 1111111111;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_23) {
  int num1 = -1111111111;
  int num2 = -1;
  int res_origin = 1111111111;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_24) {
  int num1 = 255;
  int num2 = 6;
  int res_origin = 42;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_25) {
  int num1 = -255;
  int num2 = 6;
  int res_origin = -42;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_26) {
  int num1 = 255;
  int num2 = -6;
  int res_origin = -42;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(div_test_27) {
  int num1 = -255;
  int num2 = -6;
  int res_origin = 42;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_div(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(test_div_null_14) {
  s21_decimal dec1 = {{1110, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal res1;
  int res = s21_div(dec1, dec2, &res1);
  ck_assert_int_eq(res, 3);
}
END_TEST

START_TEST(test_div_22) {
  s21_decimal dec_1 = {{0x563b23e3, 0x451c, 0x0, 0x0}};  // 75988008117219
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x0}};            // 5
  s21_decimal result = {
      {0xAC7647C6, 0x8A38, 0x0, 0x10000}};  // 15197601623443.8
  test_div_func(dec_1, dec_2, result);
}
END_TEST

START_TEST(s21_div_3) {
  s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_1 = {0};
  s21_decimal result = {0};
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(s21_div_5) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, MINUS}};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  int return_value = s21_div(value_2, value_1, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_div_13) {
  s21_decimal value_1 = {{35, 0, 0, 0}};
  s21_decimal value_2 = {{5, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{70, 0, 0, 0}};
  s21_set_power(&value_1, 1);
  s21_set_power(&value_2, 2);
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_div_14) {
  s21_decimal value_1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
  s21_decimal value_2 = {{0x2, 0, 0, 0}};
  s21_set_sign(&value_2, 1);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0x44444444, 0x44444444, 0x44444444, 0}};
  s21_set_sign(&check, 1);
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_div_16) {
  s21_decimal value_1 = {{15, 0, 0, 0}};
  s21_set_sign(&value_1, 1);
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, ARITHMETIC_DIVIDE_ON_ZERO);
}
END_TEST

START_TEST(s21_div_17) {
  s21_decimal value_1 = {{10, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_set_power(&value_2, 2);
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{1000u, 0, 0, 0}};
  int return_value = s21_div(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(special_test_div_5) {
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                        0x800D0000}};  // -7922816251426433.7593543950335
  s21_decimal dec_2 = {{5421523, 0x0, 0x0, 0x80040000}};  // -542.1523
  s21_decimal result = {
      {0x89266AC2, 0x34EFBECC, 0x318, 0x90000}};  // 14613635783573,054581442
  test_div_func(dec_1, dec_2, result);
}

Suite *suite_div(void) {
  Suite *s = suite_create("s21_div");
  TCase *tc = tcase_create("div_tc");

  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, s21_div_13);
  tcase_add_test(tc, s21_div_14);
  tcase_add_test(tc, s21_div_16);
  tcase_add_test(tc, s21_div_17);
  tcase_add_test(tc, div_test_1);
  tcase_add_test(tc, div_test_2);
  tcase_add_test(tc, div_test_3);
  tcase_add_test(tc, div_test_4);
  tcase_add_test(tc, div_test_5);
  tcase_add_test(tc, div_test_9);
  tcase_add_test(tc, div_test_14);
  tcase_add_test(tc, div_test_15);
  tcase_add_test(tc, div_test_16);
  tcase_add_test(tc, div_test_17);
  tcase_add_test(tc, div_test_18);
  tcase_add_test(tc, div_test_19);
  tcase_add_test(tc, div_test_21);
  tcase_add_test(tc, div_test_22);
  tcase_add_test(tc, div_test_23);
  tcase_add_test(tc, div_test_24);
  tcase_add_test(tc, div_test_25);
  tcase_add_test(tc, div_test_26);
  tcase_add_test(tc, div_test_27);
  tcase_add_test(tc, test_div_11);
  tcase_add_test(tc, test_div_12);
  tcase_add_test(tc, test_div_13);
  tcase_add_test(tc, test_div_null_14);
  tcase_add_test(tc, test_div_22);
  tcase_add_test(tc, test_div_10);
  tcase_add_test(tc, special_test_div_5);
  suite_add_tcase(s, tc);
  return s;
}