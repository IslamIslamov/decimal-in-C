#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = TRUE, flag = 0;

  if (s21_get_power(&value_1) != s21_get_power(&value_2))
    s21_power_normalizator(&value_1, &value_2);
  for (int i = 0; i < 4 && !flag; i++) {
    if (value_1.bits[i] != value_2.bits[i]) {
      res = FALSE;
      flag = 1;
    }
  }
  return res;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  return (!s21_is_equal(value_1, value_2));
}

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int res = TRUE;
  int sign1 = s21_get_bit(value_1, 127), sign2 = s21_get_bit(value_2, 127);
  s21_power_normalizator(&value_1, &value_2);

  if (sign1 > sign2) {
    res = TRUE;
  } else if (sign1 < sign2) {
    res = FALSE;
  } else if (sign1 == sign2) {
    if (sign1 == 1) {
      res = s21_loop_for_less(value_1, value_2);
    } else if (sign1 == 0) {
      res = (s21_loop_for_less(value_2, value_1));
    }
  }
  return res;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int res = FALSE;
  if (s21_is_equal(value_1, value_2) || s21_is_less(value_1, value_2))
    res = TRUE;
  return res;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  return s21_is_less(value_2, value_1);
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  return (!(s21_is_less(value_1, value_2))) || (s21_is_equal(value_1, value_2));
}

int s21_loop_for_less(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  for (int n = 2; n >= 0 && !res; n--) {
    if (value_1.bits[n] > value_2.bits[n]) {
      res = 1;
    }
  }
  return res;
}