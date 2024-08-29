#include "./s21_convertors.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int conversion_status = OK;
  if (dst && s21_get_scale_conv(&src) < 29) {
    double temp = 0.0;
    for (int i = 0; i < 96; ++i) {
      if (s21_get_bit_conv(&src, i)) temp += pow(2.0, i);
    }
    int scale = s21_get_scale_conv(&src);
    temp *= pow(10.0, -scale);
    if (s21_get_sign_conv(&src)) temp *= -1.0;
    *dst = (float)temp;
  } else
    conversion_status = ERROR;
  return conversion_status;
}
