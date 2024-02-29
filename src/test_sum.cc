#include "test_main.h"

// A[3][4] B[3][4]
TEST(TestSum, sum1) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  S21Matrix O(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A(i, j) = number++;
      B(i, j) = number;
      O(i, j) = number + number - 1;
    }
  ASSERT_NO_THROW(A.SumMatrix(B));
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(A(i, j), O(i, j));
}

TEST(TestSum, sum2) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  S21Matrix O(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A(i, j) = number++;
      B(i, j) = number;
      O(i, j) = number + number - 1;
    }
  ASSERT_NO_THROW(A += B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(A(i, j), O(i, j));
}

TEST(TestSum, sum3) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  S21Matrix O(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A(i, j) = number++;
      B(i, j) = number;
      O(i, j) = number + number - 1;
    }
  S21Matrix C;
  ASSERT_NO_THROW(C = A + B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(C(i, j), O(i, j));
}

// A[3][4] B[3][5]
TEST(TestSum, sum4) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns + 1);
  ASSERT_ANY_THROW(A.SumMatrix(B));
}

TEST(TestSum, sum5) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns + 1);
  ASSERT_ANY_THROW(A += B);
}

TEST(TestSum, sum6) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns + 1);
  ASSERT_ANY_THROW(S21Matrix C = A + B);
}

// A[3][4] B[4][4]
TEST(TestSum, sum7) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns);
  ASSERT_ANY_THROW(A.SumMatrix(B));
}

TEST(TestSum, sum8) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns);
  ASSERT_ANY_THROW(A += B);
}

TEST(TestSum, sum9) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns);
  ASSERT_ANY_THROW(S21Matrix C = A + B);
}

// A[3][4] B[4][5]
TEST(TestSum, sum10) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns + 1);
  ASSERT_ANY_THROW(A.SumMatrix(B));
}

TEST(TestSum, sum11) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns + 1);
  ASSERT_ANY_THROW(A += B);
}

TEST(TestSum, sum12) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns + 1);
  ASSERT_ANY_THROW(S21Matrix C = A + B);
}

// C=O random
TEST(TestSum, sum13) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  S21Matrix O(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      double r1 = (double)rand() / RAND_MAX * 20.0 - 10.0;
      A(i, j) = r1;
      double r2 = (double)rand() / RAND_MAX * 20.0 - 10.0;
      B(i, j) = r2;
      O(i, j) = r1 + r2;
    }
  ASSERT_NO_THROW(A.SumMatrix(B));
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(A(i, j), O(i, j));
}

TEST(TestSum, sum14) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  S21Matrix O(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      double r1 = (double)rand() / RAND_MAX * 20.0 - 10.0;
      A(i, j) = r1;
      double r2 = (double)rand() / RAND_MAX * 20.0 - 10.0;
      B(i, j) = r2;
      O(i, j) = r1 + r2;
    }
  ASSERT_NO_THROW(A += B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(A(i, j), O(i, j));
}

TEST(TestSum, sum15) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns);
  S21Matrix O(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      double r1 = (double)rand() / RAND_MAX * 20.0 - 10.0;
      A(i, j) = r1;
      double r2 = (double)rand() / RAND_MAX * 20.0 - 10.0;
      B(i, j) = r2;
      O(i, j) = r1 + r2;
    }
  S21Matrix C;
  ASSERT_NO_THROW(C = A + B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(C(i, j), O(i, j));
}