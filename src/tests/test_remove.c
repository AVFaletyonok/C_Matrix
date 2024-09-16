#include "tests.h"

START_TEST(remove_matrix_01) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(2, 2, &A);
  remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_02) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(1, 1, &A);
  remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_03) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(3, 2, &A);
  remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_04) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(3, 4, &A);
  remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(remove_matrix_05) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};

  res = create_matrix(3, 2, &A);
  remove_matrix(&A);
  if (A.matrix != NULL) {
    res = INCORRECT_MATRIX;
  }
  ck_assert_int_eq(res, OK);
}
END_TEST

Suite* test_remove_suite(void) {
  Suite* s = suite_create("suite_remove_matrix");
  TCase* tc = tcase_create("suite_remove_matrix");

  tcase_add_test(tc, remove_matrix_01);
  tcase_add_test(tc, remove_matrix_02);
  tcase_add_test(tc, remove_matrix_03);
  tcase_add_test(tc, remove_matrix_04);
  tcase_add_test(tc, remove_matrix_05);

  suite_add_tcase(s, tc);
  return s;
}
