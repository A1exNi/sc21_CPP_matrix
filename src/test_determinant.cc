#include "test_main.h"

// A[1][1]
TEST(TestDeterminant, det1) {
  int number = 2;
  int rows = 1;
  int columns = 1;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  double result;
  ASSERT_NO_THROW(result = A.Determinant());
  ASSERT_DOUBLE_EQ(result, 2);
}

// A[2][2]
TEST(TestDeterminant, det2) {
  int number = 1;
  int rows = 2;
  int columns = 2;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  double result;
  ASSERT_NO_THROW(result = A.Determinant());
  ASSERT_DOUBLE_EQ(result, -2);
}

// A[3][3]
TEST(TestDeterminant, det3) {
  int number = 0;
  int rows = 3;
  int columns = 3;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  double result;
  ASSERT_NO_THROW(result = A.Determinant());
  ASSERT_DOUBLE_EQ(result, 0);
}

// A[4][4]
TEST(TestDeterminant, det4) {
  int rows = 4;
  int columns = 4;
  S21Matrix A(rows, columns);
  A(0, 0) = -9.999843472614812;
  A(0, 1) = -7.369244237136675;
  A(0, 2) = 5.1121064439006645;
  A(0, 3) = -0.8269973615310136;
  A(1, 0) = 0.655344748243385;
  A(1, 1) = -5.620816273438193;
  A(1, 2) = -9.059107675710278;
  A(1, 3) = 3.5772943373663786;
  A(2, 0) = 3.5859281167322443;
  A(2, 1) = 8.693857918816551;
  A(2, 2) = -2.3299584502028106;
  A(2, 3) = 0.3883274413590918;
  A(3, 0) = 6.619306922247311;
  A(3, 1) = -9.308557789450772;
  A(3, 2) = -8.930767299109496;
  A(3, 3) = 0.5940038667032521;
  double orig = 1322.2995406586;
  double result;
  ASSERT_NO_THROW(result = A.Determinant());
  ASSERT_FLOAT_EQ(result, orig);
}

// A[4][3]
TEST(TestDeterminant, det5) {
  int number = 0;
  int rows = 4;
  int columns = 3;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  ASSERT_ANY_THROW(A.Determinant());
}

// A[3][4] по индексам 3,3 -> answer = 1;
TEST(TestReduce, reduce1) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  ASSERT_ANY_THROW(A.ReduceMatrix(3, 3));
}

// A[3][4] по индексам 2,4 -> answer = 1;
TEST(TestReduce, reduce2) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  ASSERT_ANY_THROW(A.ReduceMatrix(2, 4));
}
