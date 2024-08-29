#include "../s21_decimal.h"

void s21_check_residue_for_floor(s21_decimal value, s21_decimal *result) {
  char scale = *(s21_get_power(&value));
  int residue = 0;
  unsigned long int b[4] = {value.bits[0], value.bits[1], value.bits[2],
                            value.bits[3]};
  s21_do_zero_decimal(result);
  while (scale) {
    for (int i = 2; i >= 0; i--) {
      if (i != 0) {
        b[i - 1] += (b[i] % 10) << 32;
      } else if (scale == 1) {
        residue = b[i] % 10;
        if (residue > 0) {
          b[i] += 10;
        }
      }
      b[i] = b[i] / 10;
    }
    scale--;
  }
  for (int i = 0; i <= 3; i++) {
    result->bits[i] = b[i];
  }
  s21_set_power(result, 0);
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int check = OK;
  int power = *(s21_get_power(&value));
  if (power < 0 || power > 28) {
    check = ERROR;
  } else {
    *result = value;
    if (s21_get_bit(value, 127)) {
      s21_set_bit(result, 127, 0);
    } else {
      s21_set_bit(result, 127, 1);
    }
  }

  return check;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  if (!result) return 1;
  s21_do_zero_decimal(result);
  if (*s21_get_power(&value) > 28) return 1;
  int error = 0;
  int sign = s21_get_sign(value);
  int scale = *s21_get_power(&value);
  s21_do_zero_decimal(result);
  s21_set_sign(&value, 0);
  int rem = 0;
  s21_truncate(value, result);
  for (int i = 0; i < scale; i++) {
    rem = s21_div_on_ten(&value);
  }
  if (rem >= 5) {
    s21_decimal one = {{1, 0, 0, 0}};
    error = s21_add_help(*result, one, result);
  }
  if (sign) s21_set_sign(result, 1);
  return error;
}

int s21_div_on_ten(s21_decimal *dec) {
  int ost = 0;
  for (int i = 95; i >= 0; --i) {
    int bit = s21_get_bit(*dec, i);
    int new = (bit + ost * 2) / 10;
    ost = (bit + ost * 2) % 10;
    s21_set_bit(dec, i, new);
  }
  return ost;
}

int s21_add_help(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result) {
  unsigned int remainder = 0;
  for (int i = 0; i < (int)(sizeof(s21_decimal) / sizeof(unsigned) - 1) * 32;
       ++i) {
    int bit_a = s21_get_bit(value_1, i);
    int bit_b = s21_get_bit(value_2, i);
    unsigned sum = bit_a + bit_b + remainder;
    remainder = sum / 2;
    sum %= 2;
    s21_set_bit(result, i, sum);
  }
  return remainder;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int check = 0, sign = s21_get_bit(value, 127);
  char scale = *(s21_get_power(&value));
  if (result != NULL && scale < 29 && scale >= 0) {
    if (sign == 1) {
      s21_check_residue_for_floor(value, result);
    } else {
      check = s21_truncate(value, result);
    }
  } else {
    check = 1;
  }
  return check;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int check = 0;

  char scale = *(s21_get_power(&value));
  unsigned long int b[3] = {value.bits[0], value.bits[1], value.bits[2]};

  if (result != NULL && scale < 29 && scale >= 0) {
    s21_do_zero_decimal(result);
    while (scale) {
      for (int i = 2; i >= 0; i--) {
        if (i != 0) {
          b[i - 1] += (b[i] % 10) << 32;
        }
        b[i] = b[i] / 10;
      }
      scale--;
    }
    for (int i = 2; i >= 0; i--) {
      result->bits[i] = b[i];
    }
    result->bits[3] = value.bits[3];
    s21_set_power(result, 0);
  } else {
    check = 1;
  }

  return check;
}
