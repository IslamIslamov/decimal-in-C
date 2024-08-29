#ifndef S21_OTHER_H_
#define S21_OTHER_H_
#include "./../types.h"
#include "./../s21_decimal.h"

#define SUCCESS 0
#define ERROR 1

enum s21_other_result { OTHER_OK = 0, OTHER_ERROR = 1 };

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

void s21_check_residue_for_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_div_on_ten(s21_decimal *dec);
int s21_add_help(s21_decimal value_1, s21_decimal value_2,
                 s21_decimal *result);

#endif  // S21_OTHER_H_