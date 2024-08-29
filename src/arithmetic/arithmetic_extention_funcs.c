#include "./arithmetic_h/arithmetic_extention_funcs.h"

int s21_get_sign(s21_decimal value) {
  s21_decimal_bit3 bit3;
  bit3.i = value.bits[3];
  return bit3.parts.sign;
}

int s21_get_bit(s21_decimal src, int bit) {
  int x = bit / 32;
  int offset = bit % 32;
  return ((src.bits[x] & (1 << offset)) != 0);
}

void s21_get_ten_decimal(s21_decimal *value) {
  value->bits[0] = 10;
  value->bits[1] = 0;
  value->bits[2] = 0;
  value->bits[3] = 0;
}

void s21_power_normalizator(s21_decimal *value_1, s21_decimal *value_2) {
  char power_1 = *s21_get_power(value_1);
  char power_2 = *s21_get_power(value_2);
  if (power_1 != power_2) {
    int diff = abs(power_1 - power_2);
    if (!diff || power_1 > 28 || power_2 > 28) return;
    int max_power = power_1 > power_2 ? power_1 : power_2;
    s21_set_power(value_1, 0);
    s21_set_power(value_2, 0);
    s21_decimal ten_decimal = {};
    s21_get_ten_decimal(&ten_decimal);
    s21_decimal tmp = {};
    s21_do_zero_decimal(&tmp);
    if (power_1 > power_2) {
      while (diff) {
        s21_mul(*value_2, ten_decimal, &tmp);
        value_2->bits[0] = tmp.bits[0];
        value_2->bits[1] = tmp.bits[1];
        value_2->bits[2] = tmp.bits[2];
        diff--;
      }
    } else if (power_2 > power_1) {
      while (diff) {
        s21_mul(*value_1, ten_decimal, &tmp);
        value_1->bits[0] = tmp.bits[0];
        value_1->bits[1] = tmp.bits[1];
        value_1->bits[2] = tmp.bits[2];
        diff--;
      }
    }
    s21_set_power(value_1, max_power);
    s21_set_power(value_2, max_power);
  }
}

unsigned char *s21_get_power(s21_decimal *value) {
  return (((unsigned char *)(&value->bits[3])) + 2);
}

void s21_set_power(s21_decimal *res, unsigned char scale) {
  unsigned char *sc = (((unsigned char *)(&res->bits[3])) + 2);
  *sc = scale;
}

int s21_get_last_bit(s21_decimal value) {
  int index_1 = 0, index_2 = 0, bit = 0;
  while (bit < 96) {
    if (s21_get_bit(value, bit) == 1) {
      index_1 = index_2;
    }
    bit++;
    index_2++;
  }

  return index_1;
}

s21_big_decimal *s21_mini_mul(s21_decimal value_1, s21_decimal value_2,
                              int index_value_2, s21_big_decimal *result) {
  s21_big_decimal temp = {0};
  s21_do_zero_big_decimal(&temp);
  int step = 0, j = 0;
  while (j <= index_value_2) {
    if (s21_get_bit(value_2, j)) {
      temp.bits[0] = value_1.bits[0], temp.bits[1] = value_1.bits[1],
      temp.bits[2] = value_1.bits[2];
    }
    int k = s21_get_last_bit_big_decimal(temp);
    while (k >= 0) {
      if (s21_get_bit_big_decimal(temp, k)) {
        s21_set_bit_big_decimal(&temp, k + step);
      } else {
        s21_clear_big_decimal(&temp, k + step);
      }
      if (k == 0)
        for (int g = step - 1; g >= 0; g--) s21_clear_big_decimal(&temp, g);
      k--;
    }
    step++;
    s21_realisation_plus_big_decimal(*result, temp, result);
    temp.bits[0] = temp.bits[1] = temp.bits[2] = 0;
    j++;
  }
  return result;
}

int s21_realisation_plus_big_decimal(s21_big_decimal value_1,
                                     s21_big_decimal value_2,
                                     s21_big_decimal *result) {
  int carry = 0, i = 0;
  while (i < 192) {
    int sum = s21_get_bit_big_decimal(value_1, i) +
              s21_get_bit_big_decimal(value_2, i) + carry;
    carry = sum > 1;
    s21_set_bit_big_decimal_for_position(result, i, sum & 0x1);
    i++;
  }
  if (carry) s21_set_bit_big_decimal(result, 191);
  return 0;
}

void s21_do_zero_decimal(s21_decimal *value) {
  value->bits[0] = 0;
  value->bits[1] = 0;
  value->bits[2] = 0;
  value->bits[3] = 0;
}

void s21_do_zero_big_decimal(s21_big_decimal *value) {
  value->bits[0] = 0;
  value->bits[1] = 0;
  value->bits[2] = 0;
  value->bits[3] = 0;
  value->bits[4] = 0;
  value->bits[5] = 0;
  value->bits[6] = 0;
}

int s21_get_bit_big_decimal(s21_big_decimal src, int bit) {
  int index = bit / 32;
  int offset = bit % 32;
  return (src.bits[index] & (1 << offset)) != 0;
}

void s21_clear_big_decimal(s21_big_decimal *src, int bit) {
  int index = bit / 32;
  int offset = bit % 32;
  src->bits[index] &= ~(1 << offset);
}

void s21_set_bit_big_decimal(s21_big_decimal *src, int bit) {
  int index = bit / 32;
  int offset = bit % 32;
  src->bits[index] |= (1 << offset);
}

void s21_set_bit_big_decimal_for_position(s21_big_decimal *src,
                                          int bit_position, int bit_value) {
  int x = bit_position / 32;
  int offset = bit_position % 32;
  if (bit_value) {
    src->bits[x] |= (1 << (offset));
  } else {
    src->bits[x] &= ~(1 << (offset));
  }
}

void s21_set_bit(s21_decimal *decimal, int bit_position, int bit_value) {
  unsigned int mask = 1u << (bit_position % 32);
  if (bit_position / 32 < 4 && bit_value) {
    decimal->bits[bit_position / 32] |= mask;
  } else if (bit_position / 32 < 4 && !bit_value) {
    decimal->bits[bit_position / 32] &= ~mask;
  }
}

int s21_get_last_bit_big_decimal(s21_big_decimal value) {
  int bit = 191;
  while (bit >= 0 && !s21_get_bit_big_decimal(value, bit)) {
    bit--;
  }
  return bit;
}

int s21_get_result(s21_big_decimal *big_decimal_value, s21_decimal decimal_1,
                   s21_decimal decimal_2) {
  int flags = 0;
  if (s21_get_bit(decimal_1, 127) != s21_get_bit(decimal_2, 127)) {
    s21_set_bit_big_decimal(big_decimal_value, 223);
  } else {
    s21_clear_big_decimal(big_decimal_value, 223);
  }
  if (s21_get_last_bit_big_decimal(*big_decimal_value) >= 96 &&
      !s21_get_bit_big_decimal(*big_decimal_value, 223)) {
    flags = 1;
  } else if (s21_get_last_bit_big_decimal(*big_decimal_value) >= 96 &&
             s21_get_bit_big_decimal(*big_decimal_value, 223)) {
    flags = 2;
  }
  return flags;
}

void s21_big_decimal_to_decimal(s21_decimal *decimal,
                                s21_big_decimal big_decimal) {
  decimal->bits[0] = big_decimal.bits[0];
  decimal->bits[1] = big_decimal.bits[1];
  decimal->bits[2] = big_decimal.bits[2];
  decimal->bits[3] = big_decimal.bits[6];
}

int s21_is_correct_value_decimal(s21_decimal value) {
  int code = 1;
  if (s21_get_empty1(value) != 0 || s21_get_empty2(value) != 0) {
    code = 0;
  } else {
    char power = *s21_get_power(&value);
    if (power < 0 || power > 28) {
      code = 0;
    }
  }
  return code;
}

int s21_get_empty1(s21_decimal val) {
  s21_decimal_bit3 bits3;
  bits3.i = val.bits[3];
  return bits3.parts.empty1;
}

int s21_get_empty2(s21_decimal val) {
  s21_decimal_bit3 bits3;
  bits3.i = val.bits[3];
  return bits3.parts.empty2;
}

void s21_set_sign(s21_decimal *decimal, int sign) {
  s21_decimal_bit3 bit3;
  bit3.i = decimal->bits[3];
  bit3.parts.sign = sign;
  decimal->bits[3] = bit3.i;
}

float s21_rand_r(float a, float b) {
  float m = (float)rand() / RAND_MAX;
  float num = a + m * (b - a);
  return num;
}

int s21_is_mini_less(s21_decimal decimal_1, s21_decimal decimal_2) {
  int total = 0, flag = 1, i = 95;
  while (i >= 0 && flag == 1) {
    if (s21_get_bit(decimal_1, i) ^ s21_get_bit(decimal_2, i)) {
      total = s21_get_bit(decimal_2, i);
      flag = -1;
    }
    i--;
  }
  return total;
}

int s21_shift_left(s21_decimal *value, int offset) {
  int return_value = OK;
  int last_bit = s21_get_last_bit(*value);
  if (last_bit + offset > 95) {
    return_value = ARITHMETIC_BIGGER_OR_INFINITY;
  } else {
    int i = 0;
    while (i < offset) {
      int bit_31 = s21_get_bit(*value, 31);
      int bit_63 = s21_get_bit(*value, 63);
      value->bits[0] <<= 1;
      value->bits[1] <<= 1;
      value->bits[2] <<= 1;
      if (bit_31) s21_set_bit(value, 32, 1);
      if (bit_63) s21_set_bit(value, 64, 1);
      i++;
    }
  }
  return return_value;
}

void s21_bits_copy(s21_decimal src, s21_decimal *dest) {
  dest->bits[0] = src.bits[0];
  dest->bits[1] = src.bits[1];
  dest->bits[2] = src.bits[2];
}