#include "tests.h"

START_TEST(mult_number_matrix) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);
  matrix_t check = {NULL, 0, 0};
  create_matrix(rows, cols, &check);
  double mult_number_result = get_rand(-10e5, 10e5);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] * mult_number_result;
    }
  }
  matrix_t res = {NULL, 0, 0};
  create_matrix(rows, cols, &res);
  ck_assert_int_eq(mult_number(&m, mult_number_result, &res), OK);
  ck_assert_int_eq(eq_matrix(&check, &res), SUCCESS);
  remove_matrix(&m);
  remove_matrix(&res);
  remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);
  matrix_t check = {NULL, 0, 0};
  create_matrix(rows, cols, &check);
  double mult_number_result = get_rand(-10e5, 10e5);

  matrix_t res = {NULL, 0, 0};
  create_matrix(rows, cols, &res);
  ck_assert_int_eq(mult_number(&m, mult_number_result, &res), INCORRECT_MATRIX);

  remove_matrix(&m);
  remove_matrix(&res);
  remove_matrix(&check);
}
END_TEST

START_TEST(mult_number_01) {
  int res = 0;
  double number = 3.0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);

  init_matrix(1.0, &A);

  create_matrix(4, 4, &Z);
  mult_number(&A, number, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = 3.0;
  X.matrix[0][1] = 6.0;
  X.matrix[0][2] = 9.0;
  X.matrix[0][3] = 12.0;
  X.matrix[1][0] = 15.0;
  X.matrix[1][1] = 18.0;
  X.matrix[1][2] = 21.0;
  X.matrix[1][3] = 24.0;
  X.matrix[2][0] = 27.0;
  X.matrix[2][1] = 30.0;
  X.matrix[2][2] = 33.0;
  X.matrix[2][3] = 36.0;
  X.matrix[3][0] = 39.0;
  X.matrix[3][1] = 42.0;
  X.matrix[3][2] = 45.0;
  X.matrix[3][3] = 48.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_number_02) {
  int res = 0;
  double number = 5.0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
  init_matrix(1.0, &A);

  create_matrix(4, 4, &Z);
  mult_number(&A, number, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = 5.0;
  X.matrix[0][1] = 10.0;
  X.matrix[0][2] = 15.0;
  X.matrix[0][3] = 20.0;
  X.matrix[1][0] = 25.0;
  X.matrix[1][1] = 30.0;
  X.matrix[1][2] = 35.0;
  X.matrix[1][3] = 40.0;
  X.matrix[2][0] = 45.0;
  X.matrix[2][1] = 50.0;
  X.matrix[2][2] = 55.0;
  X.matrix[2][3] = 60.0;
  X.matrix[3][0] = 65.0;
  X.matrix[3][1] = 70.0;
  X.matrix[3][2] = 75.0;
  X.matrix[3][3] = 80.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_number_03) {
  int res = 0;
  double number = 2.0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 2, &A);
  init_matrix(2.0, &A);

  create_matrix(4, 2, &Z);
  mult_number(&A, number, &Z);

  create_matrix(4, 2, &X);

  X.matrix[0][0] = 4.0;
  X.matrix[0][1] = 6.0;
  X.matrix[1][0] = 8.0;
  X.matrix[1][1] = 10.0;
  X.matrix[2][0] = 12.0;
  X.matrix[2][1] = 14.0;
  X.matrix[3][0] = 16.0;
  X.matrix[3][1] = 18.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_number_04) {
  int res = 0;
  double number = -2.0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 2, &A);
  init_matrix(2.0, &A);

  create_matrix(4, 2, &Z);
  mult_number(&A, number, &Z);

  create_matrix(4, 2, &X);

  X.matrix[0][0] = -4.0;
  X.matrix[0][1] = -6.0;
  X.matrix[1][0] = -8.0;
  X.matrix[1][1] = -10.0;
  X.matrix[2][0] = -12.0;
  X.matrix[2][1] = -14.0;
  X.matrix[3][0] = -16.0;
  X.matrix[3][1] = -18.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_number_05) {
  int res = 0;
  double number = 2.0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(1, 1, &A);
  init_matrix(2.0, &A);

  create_matrix(1, 1, &Z);
  mult_number(&A, number, &Z);

  create_matrix(1, 1, &X);

  X.matrix[0][0] = 4.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_number_06) {
  int res = 0;
  double number = 2.0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};

  create_matrix(0, 0, &A);

  res = mult_number(&A, number, &Z);

  remove_matrix(&A);
  remove_matrix(&Z);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite* test_mult_number_suite(void) {
  Suite* s = suite_create("suite_mult_number_matrix");
  TCase* tc = tcase_create("case_mult_number_matrix");

  tcase_add_loop_test(tc, mult_number_matrix, 0, 100);
  tcase_add_loop_test(tc, mult_number_matrix2, 0, 100);

  tcase_add_test(tc, mult_number_01);
  tcase_add_test(tc, mult_number_02);
  tcase_add_test(tc, mult_number_03);
  tcase_add_test(tc, mult_number_04);
  tcase_add_test(tc, mult_number_05);
  tcase_add_test(tc, mult_number_06);

  suite_add_tcase(s, tc);
  return s;
}
