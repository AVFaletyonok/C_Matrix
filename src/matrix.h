#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

// returns
// 0 - OK
// 1 - Error, incorrect matrix
// 2 - Calculation error
// mismatched sizes of the matrixes;
// matrix, whitch couldn't calculate for, etc.
int create_matrix(int rows, int columns, matrix_t* result);
void remove_matrix(matrix_t* A);
int eq_matrix(matrix_t* A, matrix_t* B);

int sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int mult_number(matrix_t* A, double number, matrix_t* result);
int mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int transpose(matrix_t* A, matrix_t* result);
int calc_complements(matrix_t* A, matrix_t* result);
int determinant(matrix_t* A, double* result);
int inverse_matrix(matrix_t* A, matrix_t* result);

int matr_minor(matrix_t* A, int row, int column, matrix_t* result);
double det_recursion(matrix_t* A);
void reset_matrix(matrix_t* A);
bool is_matrix_correct(matrix_t* A);