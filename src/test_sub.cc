#include "test_main.h"

// A[3][4] B[3][4]
TEST(TestSub, sub1) {
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
      O(i, j) = number - number - 1;
    }
  ASSERT_NO_THROW(A.SubMatrix(B));
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(A(i, j), O(i, j));
}

TEST(TestSub, sub2) {
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
      O(i, j) = number - number - 1;
    }
  ASSERT_NO_THROW(A -= B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(A(i, j), O(i, j));
}

TEST(TestSub, sub3) {
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
      O(i, j) = number - number - 1;
    }
  S21Matrix C;
  ASSERT_NO_THROW(C = A - B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(C(i, j), O(i, j));
}

// A[3][4] B[3][5]
TEST(TestSub, sub4) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns + 1);
  ASSERT_ANY_THROW(A.SubMatrix(B));
}

TEST(TestSub, sub5) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns + 1);
  ASSERT_ANY_THROW(A -= B);
}

TEST(TestSub, sub6) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows, columns + 1);
  ASSERT_ANY_THROW(S21Matrix C = A - B);
}

// A[3][4] B[4][4]
TEST(TestSub, sub7) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns);
  ASSERT_ANY_THROW(A.SubMatrix(B));
}

TEST(TestSub, sub8) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns);
  ASSERT_ANY_THROW(A -= B);
}

TEST(TestSub, sub9) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns);
  ASSERT_ANY_THROW(S21Matrix C = A - B);
}

// A[3][4] B[4][5]
TEST(TestSub, sub10) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns + 1);
  ASSERT_ANY_THROW(A.SubMatrix(B));
}

TEST(TestSub, sub11) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns + 1);
  ASSERT_ANY_THROW(A -= B);
}

TEST(TestSub, sub12) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  S21Matrix B(rows + 1, columns + 1);
  ASSERT_ANY_THROW(S21Matrix C = A - B);
}

// C=O random
TEST(TestSub, sub13) {
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
      O(i, j) = r1 - r2;
    }
  ASSERT_NO_THROW(A.SubMatrix(B));
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(A(i, j), O(i, j));
}

TEST(TestSub, sub14) {
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
      O(i, j) = r1 - r2;
    }
  ASSERT_NO_THROW(A -= B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(A(i, j), O(i, j));
}

TEST(TestSub, sub15) {
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
      O(i, j) = r1 - r2;
    }
  S21Matrix C;
  ASSERT_NO_THROW(C = A - B);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_DOUBLE_EQ(C(i, j), O(i, j));
}
