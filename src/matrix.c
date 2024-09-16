#include "matrix.h"

// returns
// 0 - OK
// 1 - Error, incorrect matrix
// 2 - Calculation error
// mismatched sizes of the matrixes;
// matrix, whitch couldn't calculate for, etc.
int create_matrix(int rows, int columns, matrix_t* result) {
  if (rows <= 0 || columns <= 0 || result == NULL) return 1;
  int cod_res = 1;
  result->matrix =
      malloc(rows * sizeof(double*) + rows * columns * sizeof(double));
  if (result->matrix != NULL) {
    double* start_pos = (double*)(result->matrix + rows);
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = start_pos + columns * i;
    }
    result->rows = rows;
    result->columns = columns;
    reset_matrix(result);
    cod_res = 0;
  }
  return cod_res;
}

void reset_matrix(matrix_t* A) {
  int m = A->rows;
  int n = A->columns;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      A->matrix[i][j] = 0;
    }
  }
}

void remove_matrix(matrix_t* A) {
  if (A == NULL || A->matrix == NULL) return;
  free(A->matrix);
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

// returns
// 1 - equal
// 0 - not equal
int eq_matrix(matrix_t* A, matrix_t* B) {
  if (!is_matrix_correct(A) || !is_matrix_correct(B)) return FAILURE;

  int cod_res = FAILURE;
  if (A->rows == B->rows && A->columns == B->columns) {
    int m = A->rows;
    int n = A->columns;
    int flag = 0;
    for (int i = 0; i < m && flag == 0; i++) {
      for (int j = 0; j < n && flag == 0; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) flag = 1;
      }
    }
    if (flag == 0) cod_res = SUCCESS;
  }
  return cod_res;
}

int sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (!is_matrix_correct(A) || !is_matrix_correct(B) || result == NULL)
    return 1;

  int cod_res = 2;
  if (A->rows == B->rows && A->columns == B->columns) {
    int m = A->rows;
    int n = A->columns;
    int create_cod = create_matrix(m, n, result);

    if (create_cod == 0) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
      cod_res = 0;
    }
  }
  return cod_res;
}

int sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (!is_matrix_correct(A) || !is_matrix_correct(B) || result == NULL)
    return 1;

  int cod_res = 2;
  if (A->rows == B->rows && A->columns == B->columns) {
    int m = A->rows;
    int n = A->columns;
    int create_cod = create_matrix(m, n, result);

    if (create_cod == 0) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
      cod_res = 0;
    }
  }
  return cod_res;
}

int mult_number(matrix_t* A, double number, matrix_t* result) {
  if (!is_matrix_correct(A) || result == NULL) return 1;

  int cod_res = 2;
  int m = A->rows;
  int n = A->columns;
  int create_cod = create_matrix(m, n, result);
  if (create_cod == 0) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
    cod_res = 0;
  }
  return cod_res;
}

int mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  if (!is_matrix_correct(A) || !is_matrix_correct(B) || result == NULL)
    return 1;

  if (A->columns != B->rows) return 2;
  int m = A->rows;
  int n = B->columns;
  int create_cod = create_matrix(m, n, result);
  if (create_cod == 0) {
    int k_max = A->columns;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        double sum = 0.0;
        for (int k = 0; k < k_max; k++) {
          sum += A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = sum;
      }
    }
  }
  return 0;
}

int transpose(matrix_t* A, matrix_t* result) {
  if (!is_matrix_correct(A) || result == NULL) return 1;

  int cod_res = 2;
  int m = A->rows;
  int n = A->columns;
  int create_cod = create_matrix(n, m, result);
  if (create_cod == 0) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
    cod_res = 0;
  }
  return cod_res;
}

int calc_complements(matrix_t* A, matrix_t* result) {
  if (!is_matrix_correct(A) || result == NULL) return 1;
  int cod_res = 2;

  if (A->rows < 2 || A->rows != A->columns) return cod_res;
  int n = A->rows;
  int create_cod = create_matrix(n, n, result);
  if (create_cod == 0) {
    matrix_t temp_minor_matrix = {NULL, n - 1, n - 1};
    create_cod = create_matrix(n - 1, n - 1, &temp_minor_matrix);
    if (create_cod == 0) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          matr_minor(A, i, j, &temp_minor_matrix);
          double cur_det = det_recursion(&temp_minor_matrix);
          result->matrix[i][j] = pow(-1, (i + j)) * cur_det;
        }
      }
      remove_matrix(&temp_minor_matrix);
      cod_res = 0;
    }
  }
  return cod_res;
}

int determinant(matrix_t* A, double* result) {
  if (!is_matrix_correct(A) || result == NULL) return 1;
  int cod_res = 2;

  if (A->rows == A->columns) {
    *result = det_recursion(A);
    cod_res = 0;
  }
  return cod_res;
}

double det_recursion(matrix_t* A) {
  double result = 0.0;
  if (A->rows == 1) {
    result = A->matrix[0][0];
  } else if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    int n = A->columns;
    matrix_t temp_minor_matrix = {NULL, n - 1, n - 1};
    int create_cod = create_matrix(n - 1, n - 1, &temp_minor_matrix);
    if (create_cod == 0) {
      for (int j = 0; j < n; j++) {
        matr_minor(A, 0, j, &temp_minor_matrix);

        result += pow(-1, j) * A->matrix[0][j] *
                  det_recursion(&temp_minor_matrix);
      }
      remove_matrix(&temp_minor_matrix);
    }
  }
  return result;
}

int inverse_matrix(matrix_t* A, matrix_t* result) {
  if (!is_matrix_correct(A) || result == NULL) return 1;

  int cod_res = 2;
  if (A->rows == A->columns) {
    int n = A->rows;

    if (n == 1) {
      int create_cod = create_matrix(n, n, result);
      if (create_cod == 0) {
        result->matrix[0][0] = 1.0 / A->matrix[0][0];
        cod_res = 0;
      }
    } else {
      double det = det_recursion(A);
      if (fabs(det) > 1e-6) {
        matrix_t temp_matrix = {NULL, n, n};
        matrix_t tr_matrix = {NULL, n, n};
        int create_cod = calc_complements(A, &temp_matrix);

        if (create_cod == 0) {
          create_cod = transpose(&temp_matrix, &tr_matrix);
        }
        if (create_cod == 0) {
          create_cod = mult_number(&tr_matrix, 1.0 / det, result);
        }
        remove_matrix(&temp_matrix);
        remove_matrix(&tr_matrix);
        if (create_cod == 0) cod_res = 0;
      }
    }
  }
  return cod_res;
}

int matr_minor(matrix_t* A, int row, int column, matrix_t* result) {
  if (!is_matrix_correct(A) || result == NULL) return 1;

  int cod_res = 2;
  if (A->rows < 2 || A->columns < 2 || A->rows - 1 != result->rows ||
      A->columns - 1 != result->columns)
    return cod_res;

  int m = A->rows;
  int n = A->columns;
  cod_res = 0;
  int i_res = 0;
  for (int i = 0; i < m; i++) {
    int j_res = 0;
    if (i != row) {
      for (int j = 0; j < n && i != row; j++) {
        if (j != column) {
          result->matrix[i_res][j_res] = A->matrix[i][j];
          j_res++;
        }
      }
      i_res++;
    }
  }
  return cod_res;
}

bool is_matrix_correct(matrix_t* A) {
  return A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0;
}