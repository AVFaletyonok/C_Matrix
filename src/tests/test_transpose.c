#include "tests.h"

START_TEST(transpose_matrix) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);

  matrix_t check = {NULL, 0, 0};
  create_matrix(cols, rows, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(-10e10, 10e10);
      m.matrix[i][j] = rand_val;
      check.matrix[j][i] = rand_val;
    }
  }

  matrix_t res = {NULL, 0, 0};
  ck_assert_int_eq(transpose(&m, &res), OK);
  ck_assert_int_eq(eq_matrix(&check, &res), SUCCESS);

  remove_matrix(&m);
  remove_matrix(&res);
  remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {NULL, 0, 0};
  matrix_t check = {NULL, 0, 0};
  matrix_t res = {NULL, 0, 0};

  if (create_matrix(rows, cols, &m) == OK) {
    remove_matrix(&m);
  }

  if (create_matrix(cols, rows, &check) == OK) {
    remove_matrix(&check);
  }

  ck_assert_int_eq(transpose(&m, &res), INCORRECT_MATRIX);

  remove_matrix(&res);
}
END_TEST

START_TEST(transpose_01) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = transpose(&A, &A);
  remove_matrix(&A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(transpose_02) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t T = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  create_matrix(2, 3, &A);
  init_matrix(1.0, &A);
  create_matrix(3, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 5.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 6.0;

  res = transpose(&A, &T);
  res = eq_matrix(&T, &B);
  remove_matrix(&A);
  remove_matrix(&T);
  remove_matrix(&B);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

Suite* test_transpose_suite(void) {
  Suite* s = suite_create("suite_transpose_matrix");
  TCase* tc = tcase_create("case_transpose_matrix");

  tcase_add_loop_test(tc, transpose_matrix, 0, 100);
  tcase_add_loop_test(tc, transpose_matrix2, 0, 100);

  tcase_add_test(tc, transpose_01);
  tcase_add_test(tc, transpose_02);

  suite_add_tcase(s, tc);
  return s;
}
