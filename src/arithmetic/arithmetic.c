#include "./arithmetic_h/arithmetic.h"

#include <stdio.h>

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_val = ARITHMETIC_OK;
  s21_do_zero_decimal(result);
  float val_1 = .0, val_2 = .0;
  s21_from_decimal_to_float(value_1, &val_1);
  s21_from_decimal_to_float(value_2, &val_2);
  if (isinf(val_1) || isinf(val_2)) {
    return ARITHMETIC_BIGGER_OR_INFINITY;
  }

  int sign_first_decimal = s21_get_sign(value_1),
      sign_second_decimal = s21_get_sign(value_2);
  if (*s21_get_power(&value_1) != *s21_get_power(&value_2)) {
    s21_power_normalizator(&value_1, &value_2);
  }
  if (sign_first_decimal == sign_second_decimal) {
    if (!sign_first_decimal) {  // a + b
      return_val = s21_binary_add(value_1, value_2, result);
      s21_set_sign(result, 0);
    } else {  // -a + -b
      if (s21_binary_add(value_1, value_2, result)) {
        return_val = ARITHMETIC_LESS_OR_MINUS_INFINITY;
      }
      s21_set_sign(result, 1);
    }
  } else {
    if (!sign_first_decimal && sign_second_decimal) {  // a + -b
      if (s21_is_mini_less(value_1, value_2)) {
        s21_binary_sub(value_2, value_1, result);
        s21_set_sign(result, 1);
      } else {
        s21_binary_sub(value_1, value_2, result);
        s21_set_sign(result, 0);
      }
    } else {  // -a + b
      if (s21_is_mini_less(value_1, value_2)) {
        s21_binary_sub(value_2, value_1, result);
        s21_set_sign(result, 0);
      } else {
        s21_binary_sub(value_1, value_2, result);
        s21_set_sign(result, 1);
      }
    }
  }
  s21_set_power(result, *s21_get_power(&value_1));
  return return_val;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_val = 0;
  s21_do_zero_decimal(result);
  int sign_second_decimal = s21_get_sign(value_2);
  if (!sign_second_decimal) {  // a - b -> a + -b
    s21_set_sign(&value_2, 1);
    return_val = s21_add(value_1, value_2, result);
  } else {  // a - (-b) - > a + b
    s21_set_sign(&value_2, 0);
    return_val = s21_add(value_1, value_2, result);
  }
  return return_val;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (!s21_is_correct_value_decimal(value_1) ||
      !s21_is_correct_value_decimal(value_2)) {
    return ARITHMETIC_ERROR;
  }
  s21_big_decimal big_decimal_1;
  s21_decimal ten_decimal;
  s21_do_zero_big_decimal(&big_decimal_1);
  s21_do_zero_decimal(result);
  s21_do_zero_decimal(&ten_decimal), s21_get_ten_decimal(&ten_decimal);
  int scale_number_1 = (int)*s21_get_power(&value_1),
      scale_number_2 = (int)*s21_get_power(&value_2);
  if (scale_number_1 <= 28 && scale_number_2 <= 28 &&
      scale_number_1 != scale_number_2) {
    s21_power_normalizator(&value_1, &value_2);
  }
  int dec2 = s21_get_last_bit(value_2);
  s21_big_decimal *big_decimal_2 =
      s21_mini_mul(value_1, value_2, dec2, &big_decimal_1);
  int flags = s21_get_result(big_decimal_2, value_1, value_2);
  s21_big_decimal_to_decimal(result, *big_decimal_2);

  return flags;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_value = OK;
  s21_decimal zero;
  s21_do_zero_decimal(result), s21_do_zero_decimal(&zero);
  if (s21_is_equal(value_2, zero) == TRUE) {
    return_value = ARITHMETIC_DIVIDE_ON_ZERO;
    s21_do_zero_decimal(result);
  } else {
    int start_power = *s21_get_power(&value_1) - *s21_get_power(&value_2);
    int result_sign = s21_get_sign(value_1) != s21_get_sign(value_2);
    s21_decimal rest = {0}, first_result = {0};
    s21_do_zero_decimal(&rest), s21_do_zero_decimal(&first_result);
    s21_set_power(&value_2, 0);
    s21_set_power(&value_1, 0);
    s21_set_sign(&value_2, 0);
    s21_set_sign(&value_1, 0);
    s21_binary_div(value_1, value_2, &rest, &first_result);
    s21_bits_copy(first_result, result);
    s21_decimal max_value = {{4294967295u, 4294967295, 4294967295u, 0}};
    s21_decimal ten_decimal;
    s21_get_ten_decimal(&ten_decimal);
    s21_set_power(&max_value, 1);
    int corrector = 0;
    while (corrector <= 27 && s21_is_equal(rest, zero) == FALSE) {
      if (s21_is_less(*result, max_value) == FALSE) break;
      s21_mul(rest, ten_decimal, &rest);
      s21_binary_div(rest, value_2, &rest, &first_result);
      s21_mul(*result, ten_decimal, result);
      s21_binary_add(*result, first_result, result);
      corrector++;
    }
    s21_decimal tmp;
    s21_do_zero_decimal(&tmp);
    int end_power = start_power + corrector;
    while (end_power > 28) {
      s21_binary_div(*result, ten_decimal, &tmp, result);
      end_power--;
    }
    while (end_power < 0) {
      s21_mul(*result, ten_decimal, result);
      end_power++;
    }
    s21_set_power(result, end_power);
    s21_set_sign(result, result_sign);
  }
  return return_value;
}
