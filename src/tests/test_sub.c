#include "tests.h"

START_TEST(sub_matrix_test) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);
  matrix_t mtx = {NULL, 0, 0};
  create_matrix(rows, cols, &mtx);
  matrix_t check = {NULL, 0, 0};
  create_matrix(rows, cols, &check);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
      check.matrix[i][j] = m.matrix[i][j] - mtx.matrix[i][j];
    }
  }
  matrix_t res = {NULL, 0, 0};
  ck_assert_int_eq(sub_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(eq_matrix(&check, &res), SUCCESS);

  remove_matrix(&m);
  remove_matrix(&mtx);
  remove_matrix(&res);
  remove_matrix(&check);
}
END_TEST

START_TEST(sub_matrix1) {
  matrix_t m = {NULL, 0, 0};
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  create_matrix(rows, cols, &m);
  matrix_t mtx = {NULL, 0, 0};
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  create_matrix(rows1, cols1, &mtx);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX) + 1;
    }
  }
  for (int i = 0; i < rows1; i++) {
    for (int j = 0; j < cols1; j++) {
      mtx.matrix[i][j] = get_rand(DBL_MIN, DBL_MAX);
    }
  }

  matrix_t res = {NULL, 0, 0};
  ck_assert_int_eq(sub_matrix(&m, &mtx, &res), CALC_ERROR);
  remove_matrix(&m);
  remove_matrix(&mtx);
  remove_matrix(&res);
}
END_TEST

START_TEST(sub_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);
  matrix_t mtx = {NULL, 0, 0};
  create_matrix(rows, cols, &mtx);
  matrix_t check = {NULL, 0, 0};
  create_matrix(rows, cols, &check);

  matrix_t res = {NULL, 0, 0};
  ck_assert_int_eq(sub_matrix(&m, &mtx, &res), INCORRECT_MATRIX);

  remove_matrix(&m);
  remove_matrix(&mtx);
  remove_matrix(&res);
  remove_matrix(&check);
}
END_TEST

START_TEST(sub_matrix_01) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
  init_matrix(1.0, &A);

  create_matrix(4, 4, &B);
  init_matrix(1.0, &B);

  create_matrix(4, 4, &X);

  sub_matrix(&A, &B, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 0.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = 0.0;
  X.matrix[1][1] = 0.0;
  X.matrix[1][2] = 0.0;
  X.matrix[1][3] = 0.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 0.0;
  X.matrix[2][2] = 0.0;
  X.matrix[2][3] = 0.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 0.0;
  X.matrix[3][2] = 0.0;
  X.matrix[3][3] = 0.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(sub_matrix_02) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
  init_matrix(0.0, &A);

  create_matrix(4, 4, &B);
  init_matrix(2.0, &B);

  create_matrix(4, 4, &X);

  sub_matrix(&A, &B, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = -2.0;
  X.matrix[0][1] = -2.0;
  X.matrix[0][2] = -2.0;
  X.matrix[0][3] = -2.0;
  X.matrix[1][0] = -2.0;
  X.matrix[1][1] = -2.0;
  X.matrix[1][2] = -2.0;
  X.matrix[1][3] = -2.0;
  X.matrix[2][0] = -2.0;
  X.matrix[2][1] = -2.0;
  X.matrix[2][2] = -2.0;
  X.matrix[2][3] = -2.0;
  X.matrix[3][0] = -2.0;
  X.matrix[3][1] = -2.0;
  X.matrix[3][2] = -2.0;
  X.matrix[3][3] = -2.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(sub_matrix_03) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
  init_matrix(-3.0, &A);

  create_matrix(4, 4, &B);
  init_matrix(5.0, &B);

  create_matrix(4, 4, &X);

  sub_matrix(&A, &B, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = -8.0;
  X.matrix[0][1] = -8.0;
  X.matrix[0][2] = -8.0;
  X.matrix[0][3] = -8.0;
  X.matrix[1][0] = -8.0;
  X.matrix[1][1] = -8.0;
  X.matrix[1][2] = -8.0;
  X.matrix[1][3] = -8.0;
  X.matrix[2][0] = -8.0;
  X.matrix[2][1] = -8.0;
  X.matrix[2][2] = -8.0;
  X.matrix[2][3] = -8.0;
  X.matrix[3][0] = -8.0;
  X.matrix[3][1] = -8.0;
  X.matrix[3][2] = -8.0;
  X.matrix[3][3] = -8.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(sub_matrix_04) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
  init_matrix(5.0, &A);

  create_matrix(4, 4, &B);
  init_matrix(-3.0, &B);

  create_matrix(4, 4, &X);

  sub_matrix(&A, &B, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = 8.0;
  X.matrix[0][1] = 8.0;
  X.matrix[0][2] = 8.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 8.0;
  X.matrix[1][1] = 8.0;
  X.matrix[1][2] = 8.0;
  X.matrix[1][3] = 8.0;
  X.matrix[2][0] = 8.0;
  X.matrix[2][1] = 8.0;
  X.matrix[2][2] = 8.0;
  X.matrix[2][3] = 8.0;
  X.matrix[3][0] = 8.0;
  X.matrix[3][1] = 8.0;
  X.matrix[3][2] = 8.0;
  X.matrix[3][3] = 8.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(sub_matrix_05) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 2, &A);
  init_matrix(1.0, &A);

  create_matrix(4, 2, &B);
  init_matrix(1.0, &B);

  create_matrix(4, 2, &X);

  sub_matrix(&A, &B, &Z);

  create_matrix(4, 2, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 0.0;
  X.matrix[1][0] = 0.0;
  X.matrix[1][1] = 0.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 0.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 0.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(sub_matrix_06) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 2, &A);
  init_matrix(-1.0, &A);

  create_matrix(4, 2, &B);
  init_matrix(3.0, &B);

  create_matrix(4, 2, &X);

  sub_matrix(&A, &B, &Z);

  create_matrix(4, 2, &X);

  X.matrix[0][0] = -4.0;
  X.matrix[0][1] = -4.0;
  X.matrix[1][0] = -4.0;
  X.matrix[1][1] = -4.0;
  X.matrix[2][0] = -4.0;
  X.matrix[2][1] = -4.0;
  X.matrix[3][0] = -4.0;
  X.matrix[3][1] = -4.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(sub_matrix_07) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 2, &A);
  init_matrix(4.0, &A);

  create_matrix(4, 2, &B);
  init_matrix(-2.0, &B);

  create_matrix(4, 2, &X);

  sub_matrix(&A, &B, &Z);

  create_matrix(4, 2, &X);

  X.matrix[0][0] = 6.0;
  X.matrix[0][1] = 6.0;
  X.matrix[1][0] = 6.0;
  X.matrix[1][1] = 6.0;
  X.matrix[2][0] = 6.0;
  X.matrix[2][1] = 6.0;
  X.matrix[3][0] = 6.0;
  X.matrix[3][1] = 6.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(sub_matrix_08) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};

  create_matrix(4, 2, &A);

  create_matrix(4, 3, &B);

  res = sub_matrix(&A, &B, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&Z);

  ck_assert_int_eq(res, CALC_ERROR);
}
END_TEST

Suite* test_sub_suite(void) {
  Suite* s = suite_create("suite_sub_matrix");
  TCase* tc = tcase_create("case_sub_matrix");

  tcase_add_loop_test(tc, sub_matrix_test, 0, 100);
  tcase_add_loop_test(tc, sub_matrix1, 0, 100);
  tcase_add_loop_test(tc, sub_matrix2, 0, 100);

  tcase_add_test(tc, sub_matrix_01);
  tcase_add_test(tc, sub_matrix_02);
  tcase_add_test(tc, sub_matrix_03);
  tcase_add_test(tc, sub_matrix_04);
  tcase_add_test(tc, sub_matrix_05);
  tcase_add_test(tc, sub_matrix_06);
  tcase_add_test(tc, sub_matrix_07);
  tcase_add_test(tc, sub_matrix_08);

  suite_add_tcase(s, tc);
  return s;
}
