#ifndef S21_DIFFERENCES_H_
#define S21_DIFFERENCES_H_

#define FALSE 0
#define TRUE 1

#define MAXBITS 0xffffffff
#define MINUS 0x80000000

#define MAX_INT 2147483647
#define MIN_INT (-2147483648)

#define DEC_MAX 79228162514264337593543950335.0f
#define DEC_MIN 1e-28

enum error_status { OK, ERROR };

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);

int s21_loop_for_less(s21_decimal value_1, s21_decimal value_2);

#endif  // S21_DIFFERENCES_H_