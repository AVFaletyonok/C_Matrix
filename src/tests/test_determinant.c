#include "tests.h"

START_TEST(determinant1) {
  const int size = 5;
  matrix_t m = {NULL, 0, 0};
  create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
  double res = 0;
  int code = determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  remove_matrix(&m);
}
END_TEST

START_TEST(determinant2) {
  const int size = 4;
  matrix_t m = {NULL, 0, 0};
  create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;

  double res = 0;
  int code = determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  remove_matrix(&m);
}
END_TEST

START_TEST(determinant3) {
  const int size = 5;
  matrix_t m = {NULL, 0, 0};
  create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  int code = determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-6);
  ck_assert_int_eq(code, OK);

  remove_matrix(&m);
}
END_TEST

START_TEST(determinant4) {
  const int size = 3;
  matrix_t m = {NULL, 0, 0};
  create_matrix(size, size, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, 1e-6);
  ck_assert_int_eq(code, OK);

  remove_matrix(&m);
}
END_TEST

START_TEST(determinant5) {
  const int size = 2;
  matrix_t m = {NULL, 0, 0};
  create_matrix(size, size, &m);
  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;
  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;

  double res = 0;
  int code = determinant(&m, &res);
  ck_assert_double_eq_tol(res, 7, 1e-6);
  ck_assert_int_eq(code, OK);

  remove_matrix(&m);
}
END_TEST

START_TEST(determinant6) {
  const int size = 1;
  matrix_t m = {NULL, 0, 0};
  create_matrix(size, size, &m);
  m.matrix[0][0] = -5;

  double res = 0;
  int code = determinant(&m, &res);
  ck_assert_double_eq_tol(res, -5, 1e-6);
  ck_assert_int_eq(code, OK);

  remove_matrix(&m);
}
END_TEST

START_TEST(determinant7) {
  matrix_t m = {NULL, 0, 0};
  int rows = rand() % 100 + 1;
  rows = -rows;
  create_matrix(rows, rows, &m);
  double res = 0;
  int code = determinant(&m, &res);
  ck_assert_int_eq(code, INCORRECT_MATRIX);

  remove_matrix(&m);
}
END_TEST

START_TEST(determinant8) {
  matrix_t m = {NULL, 0, 0};
  int rows = 4;
  int cols = 5;
  create_matrix(rows, cols, &m);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  double res = 0;
  int code = determinant(&m, &res);
  ck_assert_int_eq(code, CALC_ERROR);

  remove_matrix(&m);
}
END_TEST

START_TEST(determinant_01) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};

  res = determinant(&A, &determ);
  remove_matrix(&A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_02) {
  int res = 0;
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};
  create_matrix(1, 2, &A);

  res = determinant(&A, &determ);
  remove_matrix(&A);
  ck_assert_int_eq(res, CALC_ERROR);
}
END_TEST

START_TEST(determinant_03) {
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};

  create_matrix(1, 1, &A);
  init_matrix(1.0, &A);

  determinant(&A, &determ);
  remove_matrix(&A);
  ck_assert_double_eq(determ, 1.0);
}
END_TEST

START_TEST(determinant_06) {
  double determ = 0.0;
  matrix_t A = {NULL, 0, 0};

  create_matrix(8, 8, &A);
  init_matrix(1.0, &A);

  determinant(&A, &determ);
  remove_matrix(&A);
  ck_assert_double_eq(determ, 0.0);
}
END_TEST

Suite* test_determinant_suite(void) {
  Suite* s = suite_create("suite_determinant");
  TCase* tc = tcase_create("case_determinant");

  tcase_add_test(tc, determinant1);
  tcase_add_test(tc, determinant2);
  tcase_add_test(tc, determinant3);
  tcase_add_test(tc, determinant4);
  tcase_add_test(tc, determinant5);
  tcase_add_test(tc, determinant6);
  tcase_add_loop_test(tc, determinant7, 0, 100);
  tcase_add_test(tc, determinant8);

  tcase_add_test(tc, determinant_01);
  tcase_add_test(tc, determinant_02);
  tcase_add_test(tc, determinant_03);
  tcase_add_test(tc, determinant_06);

  suite_add_tcase(s, tc);
  return s;
}
