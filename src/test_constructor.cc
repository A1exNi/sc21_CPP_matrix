#include "test_main.h"

TEST(TestConstructors, Construct1) { ASSERT_NO_THROW(S21Matrix matrix); }

TEST(TestConstructors, Construct2) { ASSERT_NO_THROW(S21Matrix matrix(3, 4)); }

TEST(TestConstructors, Construct3) {
  ASSERT_ANY_THROW(S21Matrix matrix(-3, 4));
}

TEST(TestConstructors, Construct4) {
  ASSERT_ANY_THROW(S21Matrix matrix(3, -4));
}

TEST(TestConstructors, Construct5) { ASSERT_ANY_THROW(S21Matrix matrix(0, 4)); }

TEST(TestConstructors, Construct6) { ASSERT_ANY_THROW(S21Matrix matrix(3, 0)); }

TEST(TestConstructors, Construct7) {
  ASSERT_ANY_THROW(S21Matrix matrix(0, -4));
}

TEST(TestConstructors, Construct8) {
  S21Matrix matrix(3, 4);
  S21Matrix matrix2(matrix);
  ASSERT_EQ(matrix2.GetRows(), 3);
  ASSERT_EQ(matrix2.GetCols(), 4);
  ASSERT_NE(&matrix(0, 0), &matrix2(0, 0));
}

TEST(TestConstructors, Construct9) {
  S21Matrix matrix(3, 4);
  S21Matrix matrix2;
  ASSERT_NO_THROW(matrix2 = matrix);
  ASSERT_EQ(matrix2.GetRows(), 3);
  ASSERT_EQ(matrix2.GetCols(), 4);
  ASSERT_NE(&matrix(0, 0), &matrix2(0, 0));
}

TEST(TestConstructors, Construct10) {
  S21Matrix matrix(3, 4);
  S21Matrix matrix2;
  ASSERT_NO_THROW(matrix2 = std::move(matrix));
  ASSERT_EQ(matrix2.GetRows(), 3);
  ASSERT_EQ(matrix2.GetCols(), 4);
  ASSERT_EQ(matrix.GetRows(), 0);
  ASSERT_EQ(matrix.GetCols(), 0);
}