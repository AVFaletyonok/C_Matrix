#include "tests.h"

START_TEST(mult_matrix_test) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);
  matrix_t mtx = {NULL, 0, 0};
  create_matrix(cols, rows, &mtx);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = get_rand(-10e10, 10e10);

  for (int i = 0; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = get_rand(-10e10, 10e10);

  matrix_t check = {NULL, 0, 0};
  create_matrix(m.rows, mtx.columns, &check);

  for (int i = 0; i < m.rows; i++) {
    for (int j = 0; j < mtx.columns; j++) {
      check.matrix[i][j] = 0;
      for (int k = 0; k < m.columns; k++)
        check.matrix[i][j] += m.matrix[i][k] * mtx.matrix[k][j];
    }
  }

  matrix_t res = {NULL, 0, 0};
  ck_assert_int_eq(mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(eq_matrix(&check, &res), SUCCESS);

  remove_matrix(&m);
  remove_matrix(&mtx);
  remove_matrix(&res);
  remove_matrix(&check);
}
END_TEST

START_TEST(simple_mult) {
  const int rows = 2;
  const int cols = 3;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);
  matrix_t mtx = {NULL, 0, 0};
  create_matrix(cols, rows, &mtx);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = c++;

  matrix_t check = {NULL, 0, 0};
  create_matrix(m.rows, mtx.columns, &check);
  check.matrix[0][0] = 58;
  check.matrix[0][1] = 64;
  check.matrix[1][0] = 139;
  check.matrix[1][1] = 154;

  matrix_t res = {NULL, 0, 0};
  ck_assert_int_eq(mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(eq_matrix(&check, &res), SUCCESS);

  remove_matrix(&m);
  remove_matrix(&mtx);
  remove_matrix(&res);
  remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix2) {
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);
  matrix_t mtx = {NULL, 0, 0};
  create_matrix(cols, rows, &mtx);

  matrix_t check = {NULL, 0, 0};
  create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {NULL, 0, 0};
  ck_assert_int_eq(mult_matrix(&m, &mtx, &res), INCORRECT_MATRIX);

  remove_matrix(&m);
  remove_matrix(&mtx);
  remove_matrix(&res);
  remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix3) {
  matrix_t m = {NULL, 0, 0};
  int rows = 2;
  int cols = 3;
  create_matrix(rows, cols, &m);
  matrix_t mtx = {NULL, 0, 0};
  int rows1 = 4;
  int cols1 = 5;
  create_matrix(rows1, cols1, &mtx);

  matrix_t check = {NULL, 0, 0};
  create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {NULL, 0, 0};
  ck_assert_int_eq(mult_matrix(&m, &mtx, &res), CALC_ERROR);

  remove_matrix(&m);
  remove_matrix(&mtx);
  remove_matrix(&res);
  remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix_01) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
  init_matrix(1.0, &A);

  create_matrix(4, 4, &B);
  init_matrix(1.0, &B);

  mult_matrix(&A, &B, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = 90.0;
  X.matrix[0][1] = 100.0;
  X.matrix[0][2] = 110.0;
  X.matrix[0][3] = 120.0;
  X.matrix[1][0] = 202.0;
  X.matrix[1][1] = 228.0;
  X.matrix[1][2] = 254.0;
  X.matrix[1][3] = 280.0;
  X.matrix[2][0] = 314.0;
  X.matrix[2][1] = 356.0;
  X.matrix[2][2] = 398.0;
  X.matrix[2][3] = 440.0;
  X.matrix[3][0] = 426.0;
  X.matrix[3][1] = 484.0;
  X.matrix[3][2] = 542.0;
  X.matrix[3][3] = 600.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_matrix_02) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
  init_matrix(1.0, &A);

  create_matrix(4, 4, &B);
  init_matrix(-5.0, &B);

  mult_matrix(&A, &B, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = 30.0;
  X.matrix[0][1] = 40.0;
  X.matrix[0][2] = 50.0;
  X.matrix[0][3] = 60.0;
  X.matrix[1][0] = 46.0;
  X.matrix[1][1] = 72.0;
  X.matrix[1][2] = 98.0;
  X.matrix[1][3] = 124.0;
  X.matrix[2][0] = 62.0;
  X.matrix[2][1] = 104.0;
  X.matrix[2][2] = 146.0;
  X.matrix[2][3] = 188.0;
  X.matrix[3][0] = 78.0;
  X.matrix[3][1] = 136.0;
  X.matrix[3][2] = 194.0;
  X.matrix[3][3] = 252.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_matrix_03) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
  init_matrix(-5.0, &A);

  create_matrix(4, 4, &B);
  init_matrix(1.0, &B);

  mult_matrix(&A, &B, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = -78.0;
  X.matrix[0][1] = -92.0;
  X.matrix[0][2] = -106.0;
  X.matrix[0][3] = -120.0;
  X.matrix[1][0] = 34.0;
  X.matrix[1][1] = 36.0;
  X.matrix[1][2] = 38.0;
  X.matrix[1][3] = 40.0;
  X.matrix[2][0] = 146.0;
  X.matrix[2][1] = 164.0;
  X.matrix[2][2] = 182.0;
  X.matrix[2][3] = 200.0;
  X.matrix[3][0] = 258.0;
  X.matrix[3][1] = 292.0;
  X.matrix[3][2] = 326.0;
  X.matrix[3][3] = 360.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_matrix_04) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 2, &A);
  init_matrix(-5.0, &A);

  create_matrix(2, 4, &B);
  init_matrix(1.0, &B);

  mult_matrix(&A, &B, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = -25.0;
  X.matrix[0][1] = -34.0;
  X.matrix[0][2] = -43.0;
  X.matrix[0][3] = -52.0;
  X.matrix[1][0] = -13.0;
  X.matrix[1][1] = -18.0;
  X.matrix[1][2] = -23.0;
  X.matrix[1][3] = -28.0;
  X.matrix[2][0] = -1.0;
  X.matrix[2][1] = -2.0;
  X.matrix[2][2] = -3.0;
  X.matrix[2][3] = -4.0;
  X.matrix[3][0] = 11.0;
  X.matrix[3][1] = 14.0;
  X.matrix[3][2] = 17.0;
  X.matrix[3][3] = 20.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_matrix_05) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(1, 1, &A);
  init_matrix(-5.0, &A);

  create_matrix(1, 1, &B);
  init_matrix(1.0, &B);

  mult_matrix(&A, &B, &Z);

  create_matrix(1, 1, &X);

  X.matrix[0][0] = -5.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(mult_matrix_06) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};

  res = mult_matrix(&A, &B, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&Z);

  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(mult_matrix_07) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};

  create_matrix(2, 3, &A);
  init_matrix(-5.0, &A);

  create_matrix(2, 2, &B);
  init_matrix(1.0, &B);

  res = mult_matrix(&A, &B, &Z);

  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&Z);

  ck_assert_int_eq(res, CALC_ERROR);
}
END_TEST

Suite* test_mult_matrix_suite(void) {
  Suite* s = suite_create("suite_mult_matrix");
  TCase* tc = tcase_create("case_mult_matrix");

  tcase_add_loop_test(tc, mult_matrix_test, 0, 100);
  tcase_add_loop_test(tc, mult_matrix2, 0, 100);
  tcase_add_test(tc, mult_matrix3);
  tcase_add_test(tc, simple_mult);

  tcase_add_test(tc, mult_matrix_01);
  tcase_add_test(tc, mult_matrix_02);
  tcase_add_test(tc, mult_matrix_03);
  tcase_add_test(tc, mult_matrix_04);
  tcase_add_test(tc, mult_matrix_05);
  tcase_add_test(tc, mult_matrix_06);
  tcase_add_test(tc, mult_matrix_07);

  suite_add_tcase(s, tc);
  return s;
}
