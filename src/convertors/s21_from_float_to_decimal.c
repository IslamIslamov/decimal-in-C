#include "./s21_convertors.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int conversion_status = OK;
  if (!dst) {
    conversion_status = ERROR;
  } else if (isinf(src) || (fabsf(src) > DEC_MAX) || fabsf(src) < 1e-28 ||
             fabsf(src) == 0.0 || isnan(src)) {
    conversion_status = ERROR;
    s21_init_decimal_conv(dst);
  } else {
    s21_init_decimal_conv(dst);
    char str[20] = {0};
    if (src < 0) {
      src = fabsf(src);
      s21_set_sign_conv(dst, 1);
    }

    sprintf(str, "%.7g", src);

    int i = s21_round_string_conv(str);

    unsigned int int_src = 0;
    if (s21_significant_numbers_conv(src)) {
      sscanf(str, "%u", &int_src);
    } else {
      int_src = (unsigned int)src;
    }
    if (int_src) dst->bits[0] = (unsigned int)int_src;
    if (i != -1 && s21_significant_numbers_conv(src))
      s21_set_scale_conv(dst, i);
  }
  return conversion_status;
}
