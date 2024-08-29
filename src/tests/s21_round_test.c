#include "s21_tests.h"

void round_test_function(float n, float accuracy) {
  s21_decimal var1 = {{0}}, var2 = {{0}};
  float value1 = 0.0, value2 = 0.0;
  s21_from_float_to_decimal(n, &var1);
  s21_round(var1, &var2);
  s21_from_decimal_to_float(var2, &value2);
  value1 = roundf(n);
  ck_assert_float_eq_tol(value1, value2, accuracy);
  return;
}

START_TEST(_round_0) {
  s21_decimal val = {{7, 7, 7, 0}};
  s21_decimal res;
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(_round_1) {
  s21_decimal val = {{3, 3, 3, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(_round_2) {
  s21_decimal val = {{3, 3, 3, 0}};
  s21_decimal res = {{0}};
  s21_set_power(&val, 5);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(_round_3) {
  s21_decimal val = {{7, 7, 7, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  s21_set_power(&val, 5);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(_round_4) {
  s21_decimal val = {{25, 0, 0, ~(UINT_MAX / 2)}};
  s21_decimal res = {{0}};
  s21_set_power(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(_round_5) {
  s21_decimal val = {{26, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_power(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(_round_6) {
  s21_decimal val = {{115, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_power(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(_round_7) {
  s21_decimal val = {{118, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_power(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(_round_8) {
  s21_decimal val = {{125, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_power(&val, 1);
  ck_assert_int_eq(0, s21_round(val, &res));
}
END_TEST

START_TEST(_round_9) {
  s21_decimal val = {{128, 0, 0, 0}};
  s21_decimal res = {{0}};
  s21_set_power(&val, 1);
  s21_round(val, &res);
  float fres = 0;
  s21_from_decimal_to_float(res, &fres);
  float need = 13;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(_round_10) {
  float n = s21_rand_r(-8388608, 8388608);
  round_test_function(n, 10);
}

START_TEST(_round_11) {
  s21_decimal value_1 = {{7464923, 0, 0, 0}};
  s21_set_power(&value_1, 5);
  s21_decimal check = {{75, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(_round_12) {
  s21_decimal value_1 = {{7444923, 0, 0, 0}};
  s21_set_power(&value_1, 5);
  s21_decimal check = {{74, 0, 0, 0}};
  s21_decimal result = {0};
  int return_value = s21_round(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(_round_15) {
  s21_decimal src1 = {0};
  src1.bits[0] = 0b01010101001110101110101110110001;
  src1.bits[1] = 0b00001101101101001101101001011111;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000100100000000000000000;
  s21_decimal result = {0};
  result.bits[0] = 0b00000000000000000000000000000001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res_od = {0};
  s21_round(src1, &res_od);
  ck_assert_float_eq(res_od.bits[0], result.bits[0]);
  ck_assert_float_eq(res_od.bits[1], result.bits[1]);
  ck_assert_float_eq(res_od.bits[2], result.bits[2]);
  ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_1) {
  s21_decimal src = {{0x93F01C52, 0x120, 0x0, 0xA0000}};  // 123.9432567890
  s21_decimal test = {{0x7C, 0x0, 0x0, 0x0}};             // 124
  s21_decimal result = {0};
  s21_round(src, &result);
  ck_assert_int_eq(s21_is_equal(result, test), 1);
}
END_TEST

START_TEST(s21_round_3) {
  s21_decimal src = {{0xF7274, 0x0, 0x0, 0x80030000}};  // -1012.340
  s21_decimal test = {{0x3F4, 0x0, 0x0, 0x80000000}};   // -1012
  s21_decimal result = {0};
  s21_round(src, &result);
  ck_assert_int_eq(s21_is_equal(result, test), 1);
}
END_TEST

START_TEST(s21_round_5) {
  s21_decimal src = {{0x800003F4, 0x0, 0x0, 0x0}};   // 2147484660
  s21_decimal test = {{0x800003F4, 0x0, 0x0, 0x0}};  // 2147484660
  s21_decimal result = {0};
  s21_round(src, &result);
  ck_assert_int_eq(s21_is_equal(result, test), 1);
}
END_TEST

START_TEST(s21_round_7) {
  s21_decimal src = {{0x23, 0x0, 0x0, 0x10000}};  // 3.5
  s21_decimal test = {{0x4, 0x0, 0x0, 0x0}};      // 4
  s21_decimal result = {0};
  s21_round(src, &result);
  ck_assert_int_eq(s21_is_equal(result, test), 1);
}
END_TEST

START_TEST(s21_round_8) {
  s21_decimal src = {{0x23, 0x0, 0x0, 0x80010000}};  // -3.5
  s21_decimal test = {{0x4, 0x0, 0x0, 0x80000000}};  // -4
  s21_decimal result = {0};
  s21_round(src, &result);
  ck_assert_int_eq(s21_is_equal(result, test), 1);
}
END_TEST

START_TEST(s21_round_9) {
  s21_decimal src = {{0x0, 0x0, 0x0, 0x0}};   // 0
  s21_decimal test = {{0x0, 0x0, 0x0, 0x0}};  // 0
  s21_decimal result = {0};
  s21_round(src, &result);
  ck_assert_int_eq(s21_is_equal(result, test), 1);
}
END_TEST

START_TEST(s21_round_10) {
  s21_decimal src = {{0x79B1F98, 0x664891A3, 0x48B1D,
                      0x80180000}};  // -5.492654545456454545645464
  s21_decimal test = {{0x5, 0x0, 0x0, 0x80000000}};  // -5
  s21_decimal result = {0};
  s21_round(src, &result);
  ck_assert_int_eq(s21_is_equal(result, test), 1);
}
END_TEST

START_TEST(s21_round_11) {
  s21_decimal src = {{0x4EE43976, 0x4B35A1D9, 0x19B974BF,
                      0x800F0000}};  // -7961327845421.879754123131254
  s21_decimal test = {{0xA41E402E, 0x73D, 0x0, 0x80000000}};  // -7961327845422
  s21_decimal result = {0};
  s21_round(src, &result);
  ck_assert_int_eq(s21_is_equal(result, test), 1);
}
END_TEST

START_TEST(s21_round_12) {
  s21_decimal src = {{0x0, 0x0, 0x0, 0x0}};  // 0
  int code = s21_round(src, NULL);
  ck_assert_int_eq(code, ERROR);
}
END_TEST

START_TEST(round_0) {
  s21_decimal value_one = {{7, 7, 7, 0}}, result = {0};
  float result_f = 0, value_two_f = (float)129127208515966861312.0;
  s21_round(value_one, &result);
  s21_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(value_two_f, result_f);
}

END_TEST

START_TEST(round_1) {
  s21_decimal value_one = {{3, 3, 3, ~(UINT_MAX >> 1)}}, result = {0};
  ck_assert_int_eq(0, s21_round(value_one, &result));
}

END_TEST

START_TEST(round_2) {
  s21_decimal value_one = {{3, 3, 3, 0}}, result = {0};
  s21_set_power(&value_one, 5);
  ck_assert_int_eq(0, s21_round(value_one, &result));
}

END_TEST

START_TEST(round_3) {
  s21_decimal value_one = {{7, 7, 7, ~(UINT_MAX >> 1)}}, result = {0};
  s21_set_power(&value_one, 5);
  ck_assert_int_eq(0, s21_round(value_one, &result));
}

END_TEST

START_TEST(round_4) {
  s21_decimal value_one = {{25, 0, 0, ~(UINT_MAX >> 1)}}, result = {0};
  s21_set_power(&value_one, 1);
  ck_assert_int_eq(0, s21_round(value_one, &result));
}

END_TEST

START_TEST(round_5) {
  s21_decimal value_one = {{26, 0, 0, 0}}, result = {0};
  s21_set_power(&value_one, 1);
  ck_assert_int_eq(0, s21_round(value_one, &result));
}

END_TEST

START_TEST(round_6) {
  s21_decimal value_one = {{115, 0, 0, 0}}, result = {0};
  s21_set_power(&value_one, 1);
  ck_assert_int_eq(0, s21_round(value_one, &result));
}

END_TEST

START_TEST(round_7) {
  s21_decimal value_one = {{118, 0, 0, 0}}, result = {0};
  s21_set_power(&value_one, 1);
  ck_assert_int_eq(0, s21_round(value_one, &result));
}

END_TEST

START_TEST(round_8) {
  s21_decimal value_one = {{125, 0, 0, 0}}, result = {0};
  s21_set_power(&value_one, 1);
  ck_assert_int_eq(0, s21_round(value_one, &result));
}

END_TEST

START_TEST(round_9) {
  s21_decimal value_one = {{345, 0, 0, 0}}, result = {0};
  s21_set_power(&value_one, 1);
  ck_assert_int_eq(0, s21_round(value_one, &result));
}

END_TEST

START_TEST(round_10) {
  s21_decimal value_one = {{128, 0, 0, 0}}, result = {0};
  float result_f = 0, value_two_f = 13;
  s21_set_power(&value_one, 1);
  s21_round(value_one, &result);
  s21_from_decimal_to_float(result, &result_f);
  ck_assert_float_eq(value_two_f, result_f);
}

START_TEST(round_11) {
  // 79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(round_12) {
  // -79228162514264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -79228162514264337593543950335
  s21_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int res = s21_round(decimal, &result);
  int sign_check = s21_get_sign(decimal_check);
  int sign_result = s21_get_sign(result);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(s21_is_not_equal(result, decimal_check), 0);
  ck_assert_int_eq(sign_check, sign_result);
}

START_TEST(round_13) {
  s21_decimal decimal = {{0, 0, 0, 0}};
  s21_decimal *result = NULL;
  int res = s21_round(decimal, result);
  ck_assert_int_eq(res, 1);
}

START_TEST(round_14) {
  s21_decimal value, rez_function, rez_round_in_our_head;
  int result_int;
  //+123.456
  value.bits[0] = 123456;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000110000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 123;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(round_15) {
  s21_decimal value, rez_function, rez_round_in_our_head;
  int result_int;
  // 1.1
  value.bits[0] = 11;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000010000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 1;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(round_17) {
  s21_decimal value, rez_function, rez_round_in_our_head;
  int result_int;
  // 12
  value.bits[0] = 12;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b00000000000000000000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 12;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(round_18) {
  s21_decimal value, rez_function, rez_round_in_our_head;
  int result_int;
  //-12
  value.bits[0] = 12;
  value.bits[1] = 0;
  value.bits[2] = 0;
  value.bits[3] = 0b10000000000000000000000000000000;
  result_int = s21_round(value, &rez_function);

  rez_round_in_our_head.bits[0] = 12;
  rez_round_in_our_head.bits[1] = 0;
  rez_round_in_our_head.bits[2] = 0;
  rez_round_in_our_head.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(rez_round_in_our_head.bits[0], rez_function.bits[0]);
  ck_assert_int_eq(rez_round_in_our_head.bits[1], rez_function.bits[1]);
  ck_assert_int_eq(rez_round_in_our_head.bits[2], rez_function.bits[2]);
  ck_assert_int_eq(rez_round_in_our_head.bits[3], rez_function.bits[3]);
  ck_assert_int_eq(result_int, 0);
}
END_TEST

START_TEST(round_19) {
  s21_decimal value1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal restest = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};

  s21_decimal result;
  int code = s21_round(value1, &result);
  ck_assert_int_eq(result.bits[0], restest.bits[0]);
  ck_assert_int_eq(result.bits[1], restest.bits[1]);
  ck_assert_int_eq(result.bits[2], restest.bits[2]);
  ck_assert_int_eq(result.bits[3], restest.bits[3]);
  ck_assert_int_eq(code, 0);
}

END_TEST

START_TEST(round_22) {
  s21_decimal value1 = {
      {0x000186A0, 0x00000000, 0x00000000, 0x00000000}};  // 100000
  s21_decimal restest = {
      {0x000186A0, 0x00000000, 0x00000000, 0x00000000}};  // 100000

  s21_decimal result;
  int code = s21_round(value1, &result);
  ck_assert_int_eq(result.bits[0], restest.bits[0]);
  ck_assert_int_eq(result.bits[1], restest.bits[1]);
  ck_assert_int_eq(result.bits[2], restest.bits[2]);
  ck_assert_int_eq(result.bits[3], restest.bits[3]);
  ck_assert_int_eq(code, 0);
}

END_TEST

START_TEST(round_23) {
  s21_decimal value1 = {{0x075BCD15, 0x00000000, 0x00000000,
                         0x00120000}};  // 0.000000000123456789
  s21_decimal restest = {
      {0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0

  s21_decimal result;
  int code = s21_round(value1, &result);
  ck_assert_int_eq(result.bits[0], restest.bits[0]);
  ck_assert_int_eq(result.bits[1], restest.bits[1]);
  ck_assert_int_eq(result.bits[2], restest.bits[2]);
  ck_assert_int_eq(result.bits[3], restest.bits[3]);
  ck_assert_int_eq(code, 0);
}

END_TEST

START_TEST(round_26) {
  s21_decimal value1 = {
      {0x00000086, 0x00000000, 0x00000000, 0x80020000}};  // -1.34
  s21_decimal restest = {
      {0x00000001, 0x00000000, 0x00000000, 0x80000000}};  //-1

  s21_decimal result;
  int code = s21_round(value1, &result);
  ck_assert_int_eq(result.bits[0], restest.bits[0]);
  ck_assert_int_eq(result.bits[1], restest.bits[1]);
  ck_assert_int_eq(result.bits[2], restest.bits[2]);
  ck_assert_int_eq(result.bits[3], restest.bits[3]);
  ck_assert_int_eq(code, 0);
}

END_TEST

START_TEST(round_28) {
  s21_decimal value1 = {{0x075BCD15, 0x00000000, 0x00000000,
                         0x001B0000}};  // 0.000000000000000000123456789
  s21_decimal restest = {
      {0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0

  s21_decimal result;
  int code = s21_round(value1, &result);
  ck_assert_int_eq(result.bits[0], restest.bits[0]);
  ck_assert_int_eq(result.bits[1], restest.bits[1]);
  ck_assert_int_eq(result.bits[2], restest.bits[2]);
  ck_assert_int_eq(result.bits[3], restest.bits[3]);
  ck_assert_int_eq(code, 0);
}

END_TEST

Suite *suite_round(void) {
  Suite *suite = suite_create("s21_round");
  TCase *tc = tcase_create("tcase_round");

  tcase_add_test(tc, round_0);
  tcase_add_test(tc, round_1);
  tcase_add_test(tc, round_2);
  tcase_add_test(tc, round_3);
  tcase_add_test(tc, round_4);
  tcase_add_test(tc, round_5);
  tcase_add_test(tc, round_6);
  tcase_add_test(tc, round_7);
  tcase_add_test(tc, round_8);
  tcase_add_test(tc, round_9);
  tcase_add_test(tc, round_10);
  tcase_add_test(tc, round_11);
  tcase_add_test(tc, round_12);
  tcase_add_test(tc, round_13);
  tcase_add_test(tc, round_14);
  tcase_add_test(tc, round_15);
  tcase_add_test(tc, round_17);
  tcase_add_test(tc, round_18);
  tcase_add_test(tc, round_19);
  tcase_add_test(tc, round_22);
  tcase_add_test(tc, round_23);
  tcase_add_test(tc, round_26);
  tcase_add_test(tc, round_28);

  tcase_add_test(tc, s21_round_1);
  tcase_add_test(tc, s21_round_3);
  tcase_add_test(tc, s21_round_5);
  tcase_add_test(tc, s21_round_7);
  tcase_add_test(tc, s21_round_8);
  tcase_add_test(tc, s21_round_9);
  tcase_add_test(tc, s21_round_10);
  tcase_add_test(tc, s21_round_11);
  tcase_add_test(tc, s21_round_12);

  tcase_add_test(tc, _round_0);
  tcase_add_test(tc, _round_1);
  tcase_add_test(tc, _round_2);
  tcase_add_test(tc, _round_3);
  tcase_add_test(tc, _round_4);
  tcase_add_test(tc, _round_5);
  tcase_add_test(tc, _round_6);
  tcase_add_test(tc, _round_7);
  tcase_add_test(tc, _round_8);
  tcase_add_test(tc, _round_9);
  tcase_add_loop_test(tc, _round_10, 0, 10);
  tcase_add_test(tc, _round_11);
  tcase_add_test(tc, _round_12);
  tcase_add_test(tc, _round_15);

  suite_add_tcase(suite, tc);

  return suite;
}
