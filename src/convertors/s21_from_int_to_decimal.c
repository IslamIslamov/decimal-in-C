#include "./s21_convertors.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int conversion_status = OK;
  if (!dst) {
    conversion_status = ERROR;
  } else {
    s21_init_decimal_conv(dst);
    if (src < 0) {
      dst->bits[3] = dst->bits[3] | (1U << 31);
      dst->bits[0] = (unsigned int)(-src);
    } else {
      dst->bits[0] = (unsigned int)src;
    }
  }

  return conversion_status;
}
