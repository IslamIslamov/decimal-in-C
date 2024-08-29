#include "./s21_convertors.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int conversion_status = OK;
  if (!dst) {
    conversion_status = ERROR;
  } else {
    int scale = s21_get_scale_conv(&src);
    double num = 0;
    for (int i = 0; i < 96; i++) {
      if (s21_get_bit_conv(&src, i)) {
        num += pow(2, i);
      }
    }

    num /= pow(10, scale);
    if (s21_get_sign_conv(&src)) {
      num = -num;
    }

    conversion_status = (num > INT_MAX || num < INT_MIN) ? ERROR : OK;
    *dst = (conversion_status == OK) ? (int)num : 0;
  }

  return conversion_status;
}
