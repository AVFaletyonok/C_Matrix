#include "tests.h"

START_TEST(inverse_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t C = {NULL, 0, 0};
  create_matrix(3, 3, &A);
  create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B = {NULL, 0, 0};
  inverse_matrix(&A, &B);
  int res = eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  remove_matrix(&A);
  remove_matrix(&B);
  remove_matrix(&C);
}
END_TEST

START_TEST(test_one_by_one) {
  matrix_t m = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int codec = create_matrix(1, 1, &m);
  if (codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = inverse_matrix(&m, &result);
    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
    ck_assert_int_eq(code, OK);
    remove_matrix(&result);
  }
  remove_matrix(&m);
}
END_TEST

START_TEST(test_zero_det) {
  matrix_t m = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int codec = create_matrix(1, 1, &m);
  if (codec) {
    int code = inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    remove_matrix(&result);
  }
  remove_matrix(&m);
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int code = inverse_matrix(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(determinant_test) {
  const int size = 2;
  matrix_t m = {NULL, 0, 0};
  create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;

  matrix_t result = {NULL, 0, 0};
  int code = inverse_matrix(&m, &result);
  ck_assert_int_eq(code, CALC_ERROR);

  remove_matrix(&result);
  remove_matrix(&m);
}
END_TEST

START_TEST(test_not_sqare) {
  matrix_t m = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int codec = create_matrix(1, 4, &m);
  if (codec) {
    int code = inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    remove_matrix(&result);
  }
  remove_matrix(&m);
}
END_TEST

START_TEST(test_normal) {
  matrix_t m = {NULL, 0, 0};
  matrix_t expected = {NULL, 0, 0};
  int codec1, codec2;
  codec1 = create_matrix(3, 3, &m);
  if (codec1) codec2 = create_matrix(3, 3, &expected);

  if (codec1 && codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {NULL, 0, 0};
    int code = inverse_matrix(&m, &result);

    ck_assert_int_eq(eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);

    remove_matrix(&result);
    remove_matrix(&expected);
  }
  remove_matrix(&m);
}
END_TEST

START_TEST(inverse) {
  /* const int size = rand() % 100 + 1; */
  const int size = 3;
  matrix_t m = {NULL, 0, 0};
  create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {NULL, 0, 0};
  inverse_matrix(&m, &res);

  matrix_t expected = {NULL, 0, 0};
  create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(eq_matrix(&expected, &res), SUCCESS);

  remove_matrix(&expected);
  remove_matrix(&res);
  remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_01) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  if (create_matrix(4, 4, &A) != OK) {
    ck_abort_msg("Failed to create matrix A");
  }

  create_matrix(4, 4, &X);

  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  if (inverse_matrix(&A, &Z) != OK) {
    remove_matrix(&A);
    ck_abort_msg("Failed to compute inverse matrix");
  }
  remove_matrix(&A);

  if (create_matrix(4, 4, &X) != OK) {
    remove_matrix(&Z);
    ck_abort_msg("Failed to create matrix X");
  }

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 1.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = -5.0 / 23.0;
  X.matrix[1][1] = -121.0 / 23.0;
  X.matrix[1][2] = 2.0 / 23.0;
  X.matrix[1][3] = 1.0 / 23.0;
  X.matrix[2][0] = -18.0 / 23.0;
  X.matrix[2][1] = -379.0 / 46.0;
  X.matrix[2][2] = 19.0 / 46.0;
  X.matrix[2][3] = -25.0 / 46.0;
  X.matrix[3][0] = 53.0 / 69.0;
  X.matrix[3][1] = 1061.0 / 138.0;
  X.matrix[3][2] = -47.0 / 138.0;
  X.matrix[3][3] = 19.0 / 46.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(inverse_matrix_03) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};

  create_matrix(3, 3, &A);
  init_matrix(1.0, &A);
  remove_matrix(&A);

  res = inverse_matrix(&A, &Z);
  ck_assert_int_eq(res, INCORRECT_MATRIX);

  remove_matrix(&Z);
}
END_TEST

START_TEST(inverse_matrix_04) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};

  create_matrix(3, 2, &A);
  init_matrix(1.0, &A);

  res = inverse_matrix(&A, &Z);
  remove_matrix(&A);
  remove_matrix(&Z);
  ck_assert_int_eq(res, CALC_ERROR);
}
END_TEST

START_TEST(inverse_matrix_05) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};

  create_matrix(3, 3, &A);
  init_matrix(1.0, &A);
  remove_matrix(&A);

  res = inverse_matrix(&A, &Z);
  remove_matrix(&Z);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

START_TEST(inverse_matrix_06) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(3, 3, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;

  inverse_matrix(&A, &Z);

  create_matrix(3, 3, &X);

  X.matrix[0][0] = -3.0 / 5.0;
  X.matrix[0][1] = 0.0;
  X.matrix[0][2] = 1.0 / 5.0;
  ;
  X.matrix[1][0] = -4.0 / 5.0;
  X.matrix[1][1] = 1.0;
  X.matrix[1][2] = -2.0 / 5.0;
  X.matrix[2][0] = 16.0 / 15.0;
  X.matrix[2][1] = -2.0 / 3.0;
  X.matrix[2][2] = 1.0 / 5.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

Suite* test_inverse_suite(void) {
  Suite* s = suite_create("suite_inverse_matrix");
  TCase* tc = tcase_create("case_inverse_matrix");

  tcase_add_test(tc, inverse);
  tcase_add_test(tc, inverse_1);
  tcase_add_test(tc, determinant_test);

  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_not_sqare);
  tcase_add_test(tc, test_zero_det);
  tcase_add_test(tc, test_incorrect);
  tcase_add_test(tc, test_one_by_one);

  tcase_add_test(tc, inverse_matrix_01);
  tcase_add_test(tc, inverse_matrix_03);
  tcase_add_test(tc, inverse_matrix_04);
  tcase_add_test(tc, inverse_matrix_05);
  tcase_add_test(tc, inverse_matrix_06);

  suite_add_tcase(s, tc);
  return s;
}
