#include "test_main.h"

// A[3][4] -> C[4][3]
TEST(TestTranspose, transpose1) {
  int number = 0;
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  S21Matrix C = A.Transpose();
  S21Matrix O(columns, rows);
  O(0, 0) = 0;
  O(0, 1) = 4;
  O(0, 2) = 8;
  O(1, 0) = 1;
  O(1, 1) = 5;
  O(1, 2) = 9;
  O(2, 0) = 2;
  O(2, 1) = 6;
  O(2, 2) = 10;
  O(3, 0) = 3;
  O(3, 1) = 7;
  O(3, 2) = 11;
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) ASSERT_EQ(C(i, j), O(i, j));
}

// A[4][3] -> C[3][4]
TEST(TestTranspose, transpose2) {
  int number = 0;
  int rows = 4;
  int columns = 3;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  S21Matrix C = A.Transpose();
  S21Matrix O(columns, rows);
  O(0, 0) = 0;
  O(0, 1) = 3;
  O(0, 2) = 6;
  O(0, 3) = 9;
  O(1, 0) = 1;
  O(1, 1) = 4;
  O(1, 2) = 7;
  O(1, 3) = 10;
  O(2, 0) = 2;
  O(2, 1) = 5;
  O(2, 2) = 8;
  O(2, 3) = 11;
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) ASSERT_EQ(C(i, j), O(i, j));
}

// A[4][4] -> C[4][4]
TEST(TestTranspose, transpose3) {
  int number = 0;
  int rows = 4;
  int columns = 4;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  S21Matrix C = A.Transpose();
  S21Matrix O(columns, rows);
  O(0, 0) = 0;
  O(0, 1) = 4;
  O(0, 2) = 8;
  O(0, 3) = 12;
  O(1, 0) = 1;
  O(1, 1) = 5;
  O(1, 2) = 9;
  O(1, 3) = 13;
  O(2, 0) = 2;
  O(2, 1) = 6;
  O(2, 2) = 10;
  O(2, 3) = 14;
  O(3, 0) = 3;
  O(3, 1) = 7;
  O(3, 2) = 11;
  O(3, 3) = 15;
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) ASSERT_EQ(C(i, j), O(i, j));
}