#include "test_main.h"

// A == B
TEST(TestEqual, equal1) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A(i, j) = number;
      B(i, j) = number++;
    }
  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(TestEqual, equal2) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A(i, j) = number;
      B(i, j) = number++;
    }
  ASSERT_TRUE(A == B);
}

// A[3][4] != B[3][4]
TEST(TestEqual, equal3) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A(i, j) = number;
      B(i, j) = number++;
    }
  B(0, 3) += 1e-6;
  ASSERT_FALSE(A.EqMatrix(B));
}

TEST(TestEqual, equal4) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A(i, j) = number;
      B(i, j) = number++;
    }
  B(0, 3) += 1e-6;
  ASSERT_FALSE(A == B);
}

// A[3][4] == B[3][4]
TEST(TestEqual, equal5) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A(i, j) = number;
      B(i, j) = number++;
    }
  B(0, 3) += 1e-7;
  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(TestEqual, equal6) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A(i, j) = number;
      B(i, j) = number++;
    }
  B(0, 3) += 1e-7;
  ASSERT_TRUE(A == B);
}

// A[3][4] != B[4][4]
TEST(TestEqual, equal7) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  number = 0;
  S21Matrix B(rows + 1, columns);
  for (int i = 0; i < rows + 1; i++)
    for (int j = 0; j < columns; j++) B(i, j) = number++;
  ASSERT_FALSE(A.EqMatrix(B));
}

TEST(TestEqual, equal8) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  number = 0;
  S21Matrix B(rows + 1, columns);
  for (int i = 0; i < rows + 1; i++)
    for (int j = 0; j < columns; j++) B(i, j) = number++;
  ASSERT_FALSE(A == B);
}

// A[3][4] != B[3][5]
TEST(TestEqual, equal9) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  number = 0;
  S21Matrix B(rows, columns + 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns + 1; j++) B(i, j) = number++;
  ASSERT_FALSE(A.EqMatrix(B));
}

TEST(TestEqual, equal10) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  number = 0;
  S21Matrix B(rows, columns + 1);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns + 1; j++) B(i, j) = number++;
  ASSERT_FALSE(A == B);
}

// A[3][4] != B[4][5]
TEST(TestEqual, equal11) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  number = 0;
  S21Matrix B(rows + 1, columns + 1);
  for (int i = 0; i < rows + 1; i++)
    for (int j = 0; j < columns + 1; j++) B(i, j) = number++;
  ASSERT_FALSE(A.EqMatrix(B));
}

TEST(TestEqual, equal12) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  number = 0;
  S21Matrix B(rows + 1, columns + 1);
  for (int i = 0; i < rows + 1; i++)
    for (int j = 0; j < columns + 1; j++) B(i, j) = number++;
  ASSERT_FALSE(A == B);
}

// A[3][4] != B[3][4]
TEST(TestEqual, equal13) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  number = 0;
  S21Matrix B(rows + 1, columns + 1);
  for (int i = 0; i < rows + 1; i++)
    for (int j = 0; j < columns + 1; j++) B(i, j) = number++;
  B(0, 3) *= -1;
  ASSERT_FALSE(A.EqMatrix(B));
}

TEST(TestEqual, equal14) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  number = 0;
  S21Matrix B(rows + 1, columns + 1);
  for (int i = 0; i < rows + 1; i++)
    for (int j = 0; j < columns + 1; j++) B(i, j) = number++;
  B(0, 3) *= -1;
  ASSERT_FALSE(A == B);
}

// -A == -B
TEST(TestEqual, equal15) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = -1 * number++;
  number = 0;
  S21Matrix B(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) B(i, j) = -1 * number++;
  ASSERT_TRUE(A.EqMatrix(B));
}

TEST(TestEqual, equal16) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = -1 * number++;
  number = 0;
  S21Matrix B(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) B(i, j) = -1 * number++;
  ASSERT_TRUE(A == B);
}
