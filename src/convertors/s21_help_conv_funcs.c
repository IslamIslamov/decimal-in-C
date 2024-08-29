#include "./s21_convertors.h"

int s21_init_decimal_conv(s21_decimal *dst) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = 0;
  }
  return 0;
}

void s21_set_sign_conv(s21_decimal *value, int sign) {
  if (sign == 0)
    value->bits[3] = value->bits[3] & ~(1U << 31);
  else
    value->bits[3] = value->bits[3] | (1U << 31);
}

int s21_round_string_conv(char str[14]) {
  int pos_of_dot = -1;
  int str_len = strlen(str);
  for (int i = 0; i < str_len; i++) {
    if (str[i] == '.') pos_of_dot = i;
    if (pos_of_dot != -1) str[i] = str[i + 1];
  }
  return pos_of_dot != -1 ? str_len - pos_of_dot - 1 : -1;
}

void s21_set_scale_conv(s21_decimal *value, int scale) {
  value->bits[3] =
      ((unsigned int)s21_get_bit_conv(value, 127) << 31) | (scale << 16);
}

int s21_get_bit_conv(s21_decimal *value, int position) {
  return ((value->bits[position / 32] & ((1U << (position % 32)))) != 0);
}

int s21_significant_numbers_conv(float number) {
  return fmodf(fabsf(number), 1.0f) != 0.0f ? 1 : 0;
}

int s21_get_sign_conv(s21_decimal *value) {
  return s21_get_bit_conv(value, 127);
}

int s21_get_scale_conv(s21_decimal *value) {
  int mask = 0b11111111;
  return (mask << 16 & value->bits[3]) >> 16;
}
