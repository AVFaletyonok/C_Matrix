#include <check.h>
#include <stdio.h>

#include "../matrix.h"

#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2
#define SUCCESS_EQUAL 1

Suite* test_create_suite(void);
Suite* test_remove_suite(void);

Suite* test_eq_suite(void);
Suite* test_sub_suite(void);
Suite* test_sum_suite(void);

Suite* test_mult_matrix_suite(void);
Suite* test_mult_number_suite(void);

Suite* test_transpose_suite(void);
Suite* test_calc_complements_suite(void);
Suite* test_determinant_suite(void);
Suite* test_inverse_suite(void);

void init_matrix(double number, matrix_t* A);
double get_rand(double min, double max);