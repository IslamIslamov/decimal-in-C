#include "./arithmetic_h/binary_operation.h"

int s21_binary_add(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  s21_do_zero_decimal(result);
  int return_value = ARITHMETIC_OK;
  int carry = 0;

  for (int i = 0; i < 96; i++) {
    int current_bit_val_1 = s21_get_bit(value_1, i);
    int current_bit_val_2 = s21_get_bit(value_2, i);

    if (!current_bit_val_1 && !current_bit_val_2) {
      if (carry) {
        s21_set_bit(result, i, 1);
        carry = 0;
      } else {
        s21_set_bit(result, i, 0);
      }
    } else if (current_bit_val_1 != current_bit_val_2) {
      if (carry) {
        s21_set_bit(result, i, 0);
        carry = 1;
      } else {
        s21_set_bit(result, i, 1);
      }
    } else {
      if (carry) {
        s21_set_bit(result, i, 1);
        carry = 1;
      } else {
        s21_set_bit(result, i, 0);
        carry = 1;
      }
    }
    if (i == 95 && carry == 1) return_value = ARITHMETIC_BIGGER_OR_INFINITY;
  }
  return return_value;
}

void s21_binary_sub(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *result) {
  s21_do_zero_decimal(result);
  int next = 0;
  for (int i = 0; i < 96; i++) {
    int bit_val_1 = s21_get_bit(value_1, i);
    int bit_val_2 = s21_get_bit(value_2, i);
    s21_set_bit(result, i, bit_val_1 ^ bit_val_2);
    if (!bit_val_1 && bit_val_2) {
      next = i + 1;
      while ((bit_val_2 = s21_get_bit(value_1, next)) != 1 && next < 96) {
        s21_set_bit(&value_1, next, 1);
        next++;
      }
      s21_set_bit(&value_1, next, 0);
    }
  }
}

void s21_binary_div(s21_decimal value_1, s21_decimal value_2,
                    s21_decimal *buffer, s21_decimal *result) {
  s21_do_zero_decimal(buffer);
  s21_do_zero_decimal(result);
  for (int i = s21_get_last_bit(value_1); i >= 0; i--) {
    if (s21_get_bit(value_1, i)) s21_set_bit(buffer, 0, 1);
    if (s21_is_greater_or_equal(*buffer, value_2) == TRUE) {
      s21_binary_sub(*buffer, value_2, buffer);
      if (i != 0) s21_shift_left(buffer, 1);
      if (s21_get_bit(value_1, i - 1)) s21_set_bit(buffer, 0, 1);
      s21_shift_left(result, 1);
      s21_set_bit(result, 0, 1);
    } else {
      s21_shift_left(result, 1);
      if (i != 0) s21_shift_left(buffer, 1);
      if ((i - 1) >= 0 && s21_get_bit(value_1, i - 1))
        s21_set_bit(buffer, 0, 1);
    }
  }
}