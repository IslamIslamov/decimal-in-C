#include "s21_tests.h"

START_TEST(from_int_to_decimal_1) {
  s21_decimal a;
  int value1 = 0;
  s21_from_int_to_decimal(value1, &a);
  ck_assert_uint_eq(a.bits[0], 0);
  ck_assert_uint_eq(a.bits[1], 0);
  ck_assert_uint_eq(a.bits[2], 0);
  ck_assert_uint_eq(a.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  s21_decimal a;
  int value = 2147483647;
  s21_from_int_to_decimal(value, &a);
  ck_assert_uint_eq(a.bits[0], 2147483647);
  ck_assert_uint_eq(a.bits[1], 0);
  ck_assert_uint_eq(a.bits[2], 0);
  ck_assert_uint_eq(a.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(from_int_to_decimal_4) {
  s21_decimal a;
  int value1 = 12312321;
  s21_from_int_to_decimal(value1, &a);
  ck_assert_uint_eq(a.bits[0], 12312321);
  ck_assert_uint_eq(a.bits[1], 0);
  ck_assert_uint_eq(a.bits[2], 0);
  ck_assert_uint_eq(a.bits[3], 0b00000000000000000000000000000000);
}
END_TEST

START_TEST(from_int_to_decimal_7) {
  s21_decimal value_one = {{0, 0, 0, 0}};
  int result, value_one_i = -123456789;
  s21_from_int_to_decimal(value_one_i, &value_one);
  s21_from_decimal_to_int(value_one, &result);
  ck_assert_int_eq(result, value_one_i);
}

END_TEST

START_TEST(from_int_to_decimal_8) {
  s21_decimal value_one = {{0, 0, 0, 0}};
  int result, value_one_i = -19121993;
  s21_from_int_to_decimal(value_one_i, &value_one);
  s21_from_decimal_to_int(value_one, &result);
  ck_assert_int_eq(result, value_one_i);
}

END_TEST

START_TEST(from_int_to_decimal_9) {
  s21_decimal value_one = {{0, 0, 0, 0}};
  int result, value_one_i = 7777777;
  s21_from_int_to_decimal(value_one_i, &value_one);
  s21_from_decimal_to_int(value_one, &result);
  ck_assert_int_eq(result, value_one_i);
}

END_TEST

START_TEST(from_int_to_decimal_10) {
  s21_decimal value_one = {{0, 0, 0, 0}};
  int result, value_one_i = UINT_MAX;
  s21_from_int_to_decimal(value_one_i, &value_one);
  s21_from_decimal_to_int(value_one, &result);
  ck_assert_int_eq(result, value_one_i);
}

END_TEST

START_TEST(from_int_to_decimal_11) {
  s21_decimal value_one = {{0, 0, 0, 0}};
  int result, value_one_i = -UINT_MAX;
  s21_from_int_to_decimal(value_one_i, &value_one);
  s21_from_decimal_to_int(value_one, &result);
  ck_assert_int_eq(result, value_one_i);
}
END_TEST

int a, add, equal;

START_TEST(from_int_to_decimal_13) {
  a = 100;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{100, 0, 0, 0}};
  ck_assert_int_eq(add, CONVERTERS_S21_TRUE);
  // выходное значение s21_from_int_to_decimal - 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(from_int_to_decimal_14) {
  a = 100;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{1000, 0, 0, 0}};
  ck_assert_int_eq(add, CONVERTERS_S21_TRUE);
  // выходное значение s21_from_int_to_decimal -
  // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, S21_FALSE);
}
END_TEST

START_TEST(from_int_to_decimal_15) {
  a = INT_MAX;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{INT_MAX, 0, 0, 0}};
  ck_assert_int_eq(
      add, CONVERTERS_S21_TRUE);  // выходное значение s21_from_int_to_decimal -
                                  // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(from_int_to_decimal_16) {
  a = -INT_MAX;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{INT_MAX, 0, 0, 0}};
  ck_assert_int_eq(
      add, CONVERTERS_S21_TRUE);  // выходное значение s21_from_int_to_decimal -
                                  // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, S21_FALSE);
}
END_TEST

START_TEST(from_int_to_decimal_17) {
  a = -INT_MAX;
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{INT_MAX, 0, 0, ~(INT_MAX)}};
  ck_assert_int_eq(
      add, CONVERTERS_S21_TRUE);  // выходное значение s21_from_int_to_decimal -
                                  // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, S21_TRUE);
}
END_TEST

START_TEST(from_int_to_decimal_18) {
  a = 0;  // ERROR of NAN
  s21_decimal b = {{0, 0, 0, 0}};
  s21_decimal *ptr_b = &b;

  add = s21_from_int_to_decimal(a, ptr_b);  // a записываем в b
  s21_decimal etalon = {{INT_MAX, 0, 0, ~(INT_MAX)}};
  ck_assert_int_eq(
      add, CONVERTERS_S21_TRUE);  // выходное значение s21_from_int_to_decimal -
                                  // 0 TRUE и 1 FALSE
  // s21_is_equal Возвращаемое значение: 0 - FALSE 1 - TRUE
  equal = s21_is_equal(b, etalon);
  ck_assert_int_eq(equal, S21_FALSE);
}
END_TEST

START_TEST(from_int_to_decimal_19) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_20) {
  s21_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -123456789;
  s21_from_int_to_decimal(tmp, &val);
  s21_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_21) {
  // 6412
  int src1 = 1;
  s21_decimal origin, result;
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_22) {
  // 6428
  int src1 = -1;
  s21_decimal origin, result;
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_23) {
  // 6444
  int src1 = 0;
  s21_decimal origin, result;
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_24) {
  // 6460
  int src1 = 0;
  s21_decimal origin, result;
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_25) {
  // 6476
  int src1 = -987879878;
  s21_decimal origin, result;
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00111010111000011101100111000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_26) {
  // 6492
  int src1 = -2147483646;
  s21_decimal origin, result;
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b01111111111111111111111111111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_27) {
  // 6508
  int src1 = 2147483646;
  s21_decimal origin, result;
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b01111111111111111111111111111110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_28) {
  // 6524
  int src1 = 796132784;
  s21_decimal origin, result;
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);

  origin.bits[0] = 0b00101111011101000000010110110000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(from_int_to_decimal_29) {
  // 6540
  int src1 = -12345677;
  s21_decimal origin, result;
  s21_decimal *res = &result;
  s21_from_int_to_decimal(src1, res);
  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

Suite *s21_from_int_to_decimal_suite(void) {
  Suite *s = suite_create("---INT-TO-DEC---");
  TCase *t = tcase_create("INT-TO-DEC");

  tcase_add_test(t, from_int_to_decimal_1);
  tcase_add_test(t, from_int_to_decimal_2);
  tcase_add_test(t, from_int_to_decimal_4);
  tcase_add_test(t, from_int_to_decimal_7);
  tcase_add_test(t, from_int_to_decimal_8);
  tcase_add_test(t, from_int_to_decimal_9);
  tcase_add_test(t, from_int_to_decimal_10);
  tcase_add_test(t, from_int_to_decimal_11);
  tcase_add_test(t, from_int_to_decimal_13);
  tcase_add_test(t, from_int_to_decimal_14);
  tcase_add_test(t, from_int_to_decimal_15);
  tcase_add_test(t, from_int_to_decimal_16);
  tcase_add_test(t, from_int_to_decimal_17);
  tcase_add_test(t, from_int_to_decimal_18);
  tcase_add_test(t, from_int_to_decimal_19);
  tcase_add_test(t, from_int_to_decimal_20);
  tcase_add_test(t, from_int_to_decimal_21);
  tcase_add_test(t, from_int_to_decimal_22);
  tcase_add_test(t, from_int_to_decimal_23);
  tcase_add_test(t, from_int_to_decimal_24);
  tcase_add_test(t, from_int_to_decimal_25);
  tcase_add_test(t, from_int_to_decimal_26);
  tcase_add_test(t, from_int_to_decimal_27);
  tcase_add_test(t, from_int_to_decimal_28);
  tcase_add_test(t, from_int_to_decimal_29);

  suite_add_tcase(s, t);
  return s;
}
