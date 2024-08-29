#ifndef ARITHMETIC_EXTENTION_FUNCS_H_
#define ARITHMETIC_EXTENTION_FUNCS_H_
#include "../../s21_decimal.h"
#include "arithmetic.h"

unsigned char *s21_get_power(s21_decimal *value);

s21_big_decimal *s21_mini_mul(s21_decimal value_1, s21_decimal value_2,
                              int index_value_2, s21_big_decimal *result);

float s21_rand_r(float a, float b);

int s21_get_bit(s21_decimal src, int bit);
int s21_realisation_plus_big_decimal(s21_big_decimal value1,
                                     s21_big_decimal value2,
                                     s21_big_decimal *result);
int s21_is_mini_less(s21_decimal decimal_1, s21_decimal decimal_2);
int s21_shift_left(s21_decimal *varPtr, int offset);
int s21_get_empty1(s21_decimal val);
int s21_get_empty2(s21_decimal val);
int s21_is_correct_value_decimal(s21_decimal value);
int s21_get_sign(s21_decimal value);
int s21_get_bit_big_decimal(s21_big_decimal src, int bit);
int s21_get_last_bit(s21_decimal value);
int s21_get_last_bit_big_decimal(s21_big_decimal value);
int s21_get_result(s21_big_decimal *big_decimal_value, s21_decimal decimal_1,
                   s21_decimal decimal_2);

void s21_power_normalizator(s21_decimal *value1, s21_decimal *value2);
void s21_set_power(s21_decimal *res, unsigned char scale);
void s21_do_zero_decimal(s21_decimal *value);
void s21_do_zero_big_decimal(s21_big_decimal *value);
void s21_get_ten_decimal(s21_decimal *value);
void s21_clear_big_decimal(s21_big_decimal *src, int bit);
void s21_set_bit_big_decimal(s21_big_decimal *src, int bit);
void s21_big_decimal_to_decimal(s21_decimal *decimal,
                                s21_big_decimal big_decimal);
void s21_set_sign(s21_decimal *decimal, int sign);
void s21_set_bit(s21_decimal *decimal, int bit_position, int bit_value);
void s21_set_bit_big_decimal_for_position(s21_big_decimal *src,
                                          int bit_position, int bit_value);
void s21_bits_copy(s21_decimal src, s21_decimal *dest);
#endif  // ARITHMETIC_EXTENTION_FUNCS_H_