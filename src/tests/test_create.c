#include "tests.h"

START_TEST(create_1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, m.matrix[i][j], 1e-07);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  remove_matrix(&m);
}
END_TEST

START_TEST(create_2) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {NULL, 0, 0};
  ck_assert_int_eq(create_matrix(rows, cols, &m), INCORRECT_MATRIX);
  remove_matrix(&m);
}
END_TEST

START_TEST(create_3) {
  const int rows = 10;
  const int cols = 0;
  matrix_t m = {NULL, 0, 0};
  ck_assert_int_eq(create_matrix(rows, cols, &m), INCORRECT_MATRIX);
  remove_matrix(&m);
}
END_TEST

START_TEST(create_matrix_01) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(1, 1, &A);
  ck_assert_int_eq(res, OK);
  remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_02) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(2, 2, &A);
  ck_assert_int_eq(res, OK);
  remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_03) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(3, 2, &A);
  ck_assert_int_eq(res, OK);
  remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_04) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(2, 4, &A);
  ck_assert_int_eq(res, OK);
  remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_05) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(10, 15, &A);
  ck_assert_int_eq(res, OK);
  remove_matrix(&A);
}
END_TEST

START_TEST(create_matrix_06) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(0, 0, &A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix_07) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(1, 0, &A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix_08) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(0, 1, &A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(create_matrix_09) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(-1, 1, &A);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite* test_create_suite(void) {
  Suite* s = suite_create("suite_create_matrix");
  TCase* tc = tcase_create("case_create_matrix");

  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  tcase_add_test(tc, create_matrix_01);
  tcase_add_test(tc, create_matrix_02);
  tcase_add_test(tc, create_matrix_03);
  tcase_add_test(tc, create_matrix_04);
  tcase_add_test(tc, create_matrix_05);
  tcase_add_test(tc, create_matrix_06);
  tcase_add_test(tc, create_matrix_07);
  tcase_add_test(tc, create_matrix_08);
  tcase_add_test(tc, create_matrix_09);

  suite_add_tcase(s, tc);
  return s;
}
