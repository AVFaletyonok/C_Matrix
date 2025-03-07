#include "tests.h"

START_TEST(equal_matrix) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {NULL, 0, 0};
  create_matrix(rows, cols, &m);
  matrix_t mtx = {NULL, 0, 0};
  create_matrix(rows, cols, &mtx);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      double rand_val = get_rand(DBL_MIN, DBL_MAX);
      m.matrix[i][j] = rand_val;
      mtx.matrix[i][j] = rand_val;
    }
  }
  ck_assert_int_eq(eq_matrix(&m, &mtx), SUCCESS_EQUAL);
  remove_matrix(&m);
  remove_matrix(&mtx);
}
END_TEST

START_TEST(not_eq) {
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
  ck_assert_int_eq(eq_matrix(&m, &mtx), 0);
  remove_matrix(&m);
  remove_matrix(&mtx);
}
END_TEST

START_TEST(not_eq1) {
  matrix_t m = {NULL, 0, 0};
  int rows = rand() % 100 + 1;
  int cols = rand() % 100 + 1;
  rows = -rows;
  cols = -cols;
  create_matrix(rows, cols, &m);
  matrix_t mtx = {NULL, 0, 0};
  const int rows1 = rand() % 100 + 1;
  const int cols1 = rand() % 100 + 1;
  create_matrix(rows1, cols1, &mtx);
  ck_assert_int_eq(eq_matrix(&m, &mtx), FAILURE);
  remove_matrix(&m);
  remove_matrix(&mtx);
}
END_TEST

START_TEST(zero_matrix) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(zero_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(0, 0, &A);
  create_matrix(0, 0, &B);
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(casual_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(casual_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(1, 1, &A);
  create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(casual_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(casual_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(casual_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(casual_matrix_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = -4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = -4;
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(casual_matrix_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.00000000234;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(1, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

START_TEST(casual_matrix_8) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  create_matrix(2, 2, &A);
  create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0001;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  remove_matrix(&A);
  remove_matrix(&B);
}

Suite* test_eq_suite(void) {
  Suite* s = suite_create("suite_eq_matrix");
  TCase* tc = tcase_create("case_eq_matrix");

  tcase_add_test(tc, not_eq);
  tcase_add_loop_test(tc, equal_matrix, 0, 100);
  tcase_add_test(tc, not_eq1);

  tcase_add_test(tc, zero_matrix);
  tcase_add_test(tc, zero_matrix_1);
  tcase_add_test(tc, casual_matrix_1);
  tcase_add_test(tc, casual_matrix_2);
  tcase_add_test(tc, casual_matrix_3);
  tcase_add_test(tc, casual_matrix_4);
  tcase_add_test(tc, casual_matrix_5);
  tcase_add_test(tc, casual_matrix_6);
  tcase_add_test(tc, casual_matrix_7);
  tcase_add_test(tc, casual_matrix_8);

  suite_add_tcase(s, tc);
  return s;
}
