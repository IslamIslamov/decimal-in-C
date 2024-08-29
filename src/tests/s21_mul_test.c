#include "s21_tests.h"

START_TEST(mul_0) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res;
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4) {
  s21_decimal val1 = {{8, 0, 0, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5) {
  s21_decimal val1 = {{2, 0, 0, 0}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6) {
  s21_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_7) {
  s21_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{8, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_8) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_9) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(2, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_10) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal val2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(1, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_11) {
  s21_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  s21_decimal val2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_12) {
  s21_decimal value_1 = {{5, 0, 0, 0}};
  s21_decimal value_2 = {{7, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{35, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_13) {
  s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{1, 0xFFFFFFFE, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_14) {
  s21_decimal value_1 = {{666, 8888, 8888, 0}};
  s21_decimal value_2 = {{555, 2323, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(mul_15) {
  s21_decimal value_1 = {{25, 25, 25, 0}};
  s21_decimal value_2 = {{25, 25, 25, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 1);
}
END_TEST

START_TEST(mul_16) {
  s21_decimal value_1 = {{555, 0, 0, 0}};
  s21_decimal value_2 = {{555, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  s21_decimal check = {{308025, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_17) {
  s21_decimal value_1 = {{17, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{0, 0, 0, 0}};
  int return_value = s21_mul(value_1, value_2, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(mul_19) {
  s21_decimal src1, src2;
  int a = -32768;
  int b = 32768;
  int res_our_dec = 0;
  s21_from_int_to_decimal(a, &src1);
  s21_from_int_to_decimal(b, &src2);
  int res_origin = -1073741824;
  s21_decimal res_od = {0};
  s21_mul(src1, src2, &res_od);
  s21_from_decimal_to_int(res_od, &res_our_dec);
  ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(mul_test_1) {
  int num1 = -10;
  int num2 = -10;
  int prod_int = 100;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_2) {
  int num1 = 10;
  int num2 = 20;
  int prod_int = 200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_3) {
  int num1 = -10;
  int num2 = 20;
  int prod_int = -200;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, prod_int);
}
END_TEST

START_TEST(mul_test_4) {
  int num1 = 9403;
  int num2 = 202;
  int res_origin = 1899406;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_5) {
  int num1 = -32768;
  int num2 = 2;
  int res_origin = -65536;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_6) {
  int num1 = -32768;
  int num2 = 32768;
  int res_origin = -1073741824;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_int_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  int res_int = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_int(res_dec, &res_int);
  ck_assert_int_eq(res_int, res_origin);
}
END_TEST

START_TEST(mul_test_7) {
  float num1 = 9403.0e2;
  int num2 = 202;
  float res_origin = 189940600;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_int_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(mul_test_8) {
  float num1 = 9403.0e2;
  float num2 = 9403.0e2;
  float res_origin = 884164090000;
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_from_float_to_decimal(num1, &a);
  s21_from_float_to_decimal(num2, &b);
  s21_decimal res_dec = {0};
  float res_float = 0;
  s21_mul(a, b, &res_dec);
  s21_from_decimal_to_float(res_dec, &res_float);
  ck_assert_float_eq(res_float, res_origin);
}
END_TEST

START_TEST(test_s21_mul1) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;
  test_decimal1.bits[0] = 2;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 2;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 4;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul2) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;

  test_decimal1.bits[0] = 2;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0b10000000000000000000000000000000;
  test_decimal2.bits[0] = 2;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b00000000000000000000000000000000;
  test_decimal_result_in_function.bits[0] = 4;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0b10000000000000000000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul3) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;

  test_decimal1.bits[0] = 2;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0b10000000000000000000000000000000;
  test_decimal2.bits[0] = 2;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b10000000000000000000000000000000;
  test_decimal_result_in_function.bits[0] = 4;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0b0000000000000000000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul4) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;

  test_decimal1.bits[0] = 0b00000000000000000000000000000010;
  test_decimal1.bits[1] = 0b00000000000000000000000000000000;
  test_decimal1.bits[2] = 0b00000000000000000000000000000000;
  test_decimal1.bits[3] = 0b00000000000000000000000000000000;
  test_decimal2.bits[0] = 0b00000000000000000000000000000010;
  test_decimal2.bits[1] = 0b00000000000000000000000000000000;
  test_decimal2.bits[2] = 0b00000000000000000000000000000000;
  test_decimal2.bits[3] = 0b00000000000000000000000000000000;
  test_decimal_result_in_function.bits[0] = 0b00000000000000000000000000000100;
  test_decimal_result_in_function.bits[1] = 0b00000000000000000000000000000000;
  test_decimal_result_in_function.bits[2] = 0b00000000000000000000000000000000;
  test_decimal_result_in_function.bits[3] = 0b00000000000000000000000000000000;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul5) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;

  test_decimal1.bits[0] = 15;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 30;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 450;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul6) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;

  test_decimal1.bits[0] = 2100;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 234;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 491400;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul7) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result,
      test_decimal_result_in_function;

  test_decimal1.bits[0] = 2100;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 234;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  test_decimal_result_in_function.bits[0] = 491400;
  test_decimal_result_in_function.bits[1] = 0;
  test_decimal_result_in_function.bits[2] = 0;
  test_decimal_result_in_function.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(test_decimal_result_in_function.bits[0],
                   test_decimal_result.bits[0]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[1],
                   test_decimal_result.bits[1]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[2],
                   test_decimal_result.bits[2]);
  ck_assert_int_eq(test_decimal_result_in_function.bits[3],
                   test_decimal_result.bits[3]);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

START_TEST(test_s21_mul8) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result;

  test_decimal1.bits[0] = MAX_INT;
  test_decimal1.bits[1] = MAX_INT;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = MAX_INT;
  test_decimal2.bits[1] = MAX_INT;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0;
  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(result_function, 1);
}
END_TEST

START_TEST(test_s21_mul9) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result;

  test_decimal1.bits[0] = MAX_INT;
  test_decimal1.bits[1] = MAX_INT;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = MAX_INT;
  test_decimal2.bits[1] = MAX_INT;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b10000000000000000000000000000000;

  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(result_function, 2);
}
END_TEST

START_TEST(test_s21_mul10) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result;

  test_decimal1.bits[0] = MAX_INT;
  test_decimal1.bits[1] = MAX_INT;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = MAX_INT;
  test_decimal2.bits[1] = MAX_INT;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b00000000000000000000000000000000;

  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(result_function, 1);
}
END_TEST

START_TEST(test_s21_mul11) {
  s21_decimal test_decimal1, test_decimal2, test_decimal_result;

  test_decimal1.bits[0] = 0b11111111111111111111111111111111;
  test_decimal1.bits[1] = 0;
  test_decimal1.bits[2] = 0;
  test_decimal1.bits[3] = 0;
  test_decimal2.bits[0] = 2;
  test_decimal2.bits[1] = 0;
  test_decimal2.bits[2] = 0;
  test_decimal2.bits[3] = 0b00000000000000000000000000000000;

  int result_function =
      s21_mul(test_decimal1, test_decimal2, &test_decimal_result);
  ck_assert_int_eq(result_function, 0);
}
END_TEST

Suite *suite_mul(void) {
  Suite *s = suite_create("suite_mul");
  TCase *tc = tcase_create("mul_tc");

  tcase_add_test(tc, mul_0);
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  tcase_add_test(tc, mul_4);
  tcase_add_test(tc, mul_5);
  tcase_add_test(tc, mul_6);
  tcase_add_test(tc, mul_7);
  tcase_add_test(tc, mul_8);
  tcase_add_test(tc, mul_9);
  tcase_add_test(tc, mul_10);
  tcase_add_test(tc, mul_11);
  tcase_add_test(tc, mul_12);
  tcase_add_test(tc, mul_13);
  tcase_add_test(tc, mul_14);
  tcase_add_test(tc, mul_15);
  tcase_add_test(tc, mul_16);
  tcase_add_test(tc, mul_17);
  tcase_add_test(tc, mul_19);

  tcase_add_test(tc, mul_test_1);
  tcase_add_test(tc, mul_test_2);
  tcase_add_test(tc, mul_test_3);
  tcase_add_test(tc, mul_test_4);
  tcase_add_test(tc, mul_test_5);
  tcase_add_test(tc, mul_test_6);
  tcase_add_test(tc, mul_test_7);
  tcase_add_test(tc, mul_test_8);

  tcase_add_test(tc, test_s21_mul1);
  tcase_add_test(tc, test_s21_mul2);
  tcase_add_test(tc, test_s21_mul3);
  tcase_add_test(tc, test_s21_mul4);
  tcase_add_test(tc, test_s21_mul5);
  tcase_add_test(tc, test_s21_mul6);
  tcase_add_test(tc, test_s21_mul7);
  tcase_add_test(tc, test_s21_mul8);
  tcase_add_test(tc, test_s21_mul9);
  tcase_add_test(tc, test_s21_mul10);
  tcase_add_test(tc, test_s21_mul11);

  suite_add_tcase(s, tc);
  return s;
}