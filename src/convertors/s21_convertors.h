#ifndef S21_CONVERTORS_H_
#define S21_CONVERTORS_H_
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../s21_decimal.h"

#define DEC_MAX 79228162514264337593543950335.0f
#define DEC_MIN 1e-28
#define OK 0
#define ERROR 1

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_init_decimal_conv(s21_decimal *dst);
void s21_set_sign_conv(s21_decimal *value, int sign);
int s21_round_string_conv(char str[14]);
void s21_set_scale_conv(s21_decimal *value, int scale);
int s21_get_bit_conv(s21_decimal *value, int position);
int s21_get_sign_conv(s21_decimal *value);
int s21_get_scale_conv(s21_decimal *value);
int s21_significant_numbers_conv(float number);

#endif  // S21_CONVERTORS_H_
