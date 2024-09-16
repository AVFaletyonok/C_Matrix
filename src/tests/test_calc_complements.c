#include "tests.h"

START_TEST(test_one_by_one) {
  matrix_t m = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int codec = create_matrix(1, 1, &m);
  if (codec) {
    int code = calc_complements(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    remove_matrix(&result);
  }
  remove_matrix(&m);
}
END_TEST

START_TEST(test_incorrect) {
  matrix_t m = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int code = calc_complements(&m, &result);
  ck_assert_int_eq(code, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_not_sqare) {
  matrix_t m = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int codec = create_matrix(3, 4, &m);
  if (codec == OK) {
    int code = calc_complements(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    remove_matrix(&result);
  }
  remove_matrix(&m);
}
END_TEST

START_TEST(test_normal) {
  matrix_t expected = {NULL, 0, 0};
  matrix_t m = {NULL, 0, 0};
  matrix_t result = {NULL, 0, 0};
  int code1 = create_matrix(3, 3, &m);
  int code2 = create_matrix(3, 3, &expected);
  if (code1 && code2) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = calc_complements(&m, &result);

    ck_assert_int_eq(eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);
    remove_matrix(&result);
  }
  remove_matrix(&m);
  remove_matrix(&expected);
}
END_TEST

START_TEST(calc_complements_01) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
  A.matrix[0][0] = 112.0;
  A.matrix[0][1] = 243.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = -8.0;
  A.matrix[1][0] = 47.0;
  A.matrix[1][1] = 51.0;
  A.matrix[1][2] = -66.0;
  A.matrix[1][3] = 99.0;
  A.matrix[2][0] = -74.0;
  A.matrix[2][1] = 85.0;
  A.matrix[2][2] = 97.0;
  A.matrix[2][3] = 63.0;
  A.matrix[3][0] = -13.0;
  A.matrix[3][1] = 79.0;
  A.matrix[3][2] = -99.0;
  A.matrix[3][3] = -121.0;

  calc_complements(&A, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = -2879514.0;
  X.matrix[0][1] = -1236631.0;
  X.matrix[0][2] = -1685096.0;
  X.matrix[0][3] = 880697.0;
  X.matrix[1][0] = 1162090.0;
  X.matrix[1][1] = -714015.0;
  X.matrix[1][2] = 4046255.0;
  X.matrix[1][3] = -3901600.0;
  X.matrix[2][0] = 4362897.0;
  X.matrix[2][1] = -2049432.0;
  X.matrix[2][2] = -532912.0;
  X.matrix[2][3] = -1370781.0;
  X.matrix[3][0] = 3412773.0;
  X.matrix[3][1] = -1569493.0;
  X.matrix[3][2] = 3144517.0;
  X.matrix[3][3] = 1284666.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(calc_complements_02) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};
  matrix_t X = {NULL, 0, 0};

  create_matrix(4, 4, &A);
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

  calc_complements(&A, &Z);

  create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = -30.0;
  X.matrix[0][2] = -108.0;
  X.matrix[0][3] = 106.0;
  X.matrix[1][0] = 138.0;
  X.matrix[1][1] = -726.0;
  X.matrix[1][2] = -1137.0;
  X.matrix[1][3] = 1061.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 12.0;
  X.matrix[2][2] = 57.0;
  X.matrix[2][3] = -47.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 6.0;
  X.matrix[3][2] = -75.0;
  X.matrix[3][3] = 57.0;

  res = eq_matrix(&X, &Z);

  remove_matrix(&A);
  remove_matrix(&X);
  remove_matrix(&Z);

  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(calc_complements_03) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};

  create_matrix(4, 3, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;

  res = calc_complements(&A, &Z);

  remove_matrix(&A);
  remove_matrix(&Z);

  ck_assert_int_eq(res, CALC_ERROR);
}
END_TEST

START_TEST(calc_complements_04) {
  int res = 0;
  matrix_t A = {NULL, 0, 0};
  matrix_t Z = {NULL, 0, 0};

  create_matrix(2, 2, &A);
  remove_matrix(&A);

  res = calc_complements(&A, &Z);
  remove_matrix(&Z);
  ck_assert_int_eq(res, INCORRECT_MATRIX);
}
END_TEST

Suite* test_calc_complements_suite(void) {
  Suite* s = suite_create("suite_calc_complements");
  TCase* tc = tcase_create("case_calc_complements");

  tcase_add_test(tc, test_normal);
  tcase_add_test(tc, test_not_sqare);
  tcase_add_test(tc, test_incorrect);
  tcase_add_test(tc, test_one_by_one);

  tcase_add_test(tc, calc_complements_01);
  tcase_add_test(tc, calc_complements_02);
  tcase_add_test(tc, calc_complements_03);
  tcase_add_test(tc, calc_complements_04);

  suite_add_tcase(s, tc);
  return s;
}
