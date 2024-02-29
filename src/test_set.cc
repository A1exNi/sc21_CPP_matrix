#include "test_main.h"

TEST(TestSet, set1) {
  int rows = 3;
  int columns = 4;
  double number = 0;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  ASSERT_NO_THROW(A.SetRows(5));
  ASSERT_EQ(A.GetRows(), 5);
  ASSERT_EQ(A.GetCols(), 4);
  ASSERT_DOUBLE_EQ(A(0, 1), 1);
  ASSERT_DOUBLE_EQ(A(4, 0), 0);
}

TEST(TestSet, set2) {
  int rows = 3;
  int columns = 4;
  double number = 0;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  ASSERT_NO_THROW(A.SetCols(5));
  ASSERT_EQ(A.GetRows(), 3);
  ASSERT_EQ(A.GetCols(), 5);
  ASSERT_DOUBLE_EQ(A(0, 1), 1);
  ASSERT_DOUBLE_EQ(A(0, 4), 0);
}

TEST(TestSet, set3) {
  int rows = 3;
  int columns = 4;
  double number = 0;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  ASSERT_NO_THROW(A.SetRows(2));
  ASSERT_EQ(A.GetRows(), 2);
  ASSERT_EQ(A.GetCols(), 4);
  ASSERT_DOUBLE_EQ(A(0, 1), 1);
}

TEST(TestSet, set4) {
  int rows = 3;
  int columns = 4;
  double number = 0;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  ASSERT_NO_THROW(A.SetCols(2));
  ASSERT_EQ(A.GetRows(), 3);
  ASSERT_EQ(A.GetCols(), 2);
  ASSERT_DOUBLE_EQ(A(0, 1), 1);
}

TEST(TestSet, set5) {
  int rows = 3;
  int columns = 4;
  const S21Matrix A(rows, columns);
  ASSERT_EQ(A.GetRows(), 3);
  ASSERT_EQ(A.GetCols(), 4);
  ASSERT_DOUBLE_EQ(A(0, 1), 0);
  const double t = A(1, 1);
  ASSERT_DOUBLE_EQ(t, 0);
}

TEST(TestSet, set6) {
  int rows = 3;
  int columns = 4;
  double number = 0;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  ASSERT_ANY_THROW(A.SetCols(0));
}

TEST(TestSet, set7) {
  int rows = 3;
  int columns = 4;
  double number = 0;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) A(i, j) = number++;
  ASSERT_ANY_THROW(A.SetRows(0));
}