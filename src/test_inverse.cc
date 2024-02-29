#include "test_main.h"

TEST(TestInverse, inverse1) {
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
  S21Matrix O(rows, columns);
  O(0, 0) = -0.21744104;
  O(0, 1) = -0.016569550740482955;
  O(0, 2) = -0.24254339;
  O(0, 3) = -0.04438144579966978;
  O(1, 0) = 0.04689972375989467;
  O(1, 1) = -0.003674460789185998;
  O(1, 2) = 0.1447133;
  O(1, 3) = -0.007181046804965847;
  O(2, 0) = -0.24351162;
  O(2, 1) = 0.011976940661962183;
  O(2, 2) = -0.37582664;
  O(2, 3) = -0.1654614;
  O(3, 0) = -0.50314127;
  O(3, 1) = 0.3071331544246765;
  O(3, 2) = -0.67992661;
  O(3, 3) = -0.42216566;
  S21Matrix C;
  ASSERT_NO_THROW(C = A.InverseMatrix());
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_FLOAT_EQ(C(i, j), O(i, j));
}

TEST(TestInverse, inverse2) {
  int rows = 3;
  int columns = 3;
  S21Matrix A(rows, columns);
  A(0, 0) = 2;
  A(0, 1) = 5;
  A(0, 2) = 7;
  A(1, 0) = 6;
  A(1, 1) = 3;
  A(1, 2) = 4;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  S21Matrix O(rows, columns);
  O(0, 0) = 1;
  O(0, 1) = -1;
  O(0, 2) = 1;
  O(1, 0) = -38;
  O(1, 1) = 41;
  O(1, 2) = -34;
  O(2, 0) = 27;
  O(2, 1) = -29;
  O(2, 2) = 24;
  S21Matrix C;
  ASSERT_NO_THROW(C = A.InverseMatrix());
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_FLOAT_EQ(C(i, j), O(i, j));
}

TEST(TestInverse, inverse3) {
  int rows = 2;
  int columns = 3;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      A(i, j) = (double)rand() / RAND_MAX * 20.0 - 10.0;
  ASSERT_ANY_THROW(A.InverseMatrix());
}

TEST(TestInverse, inverse4) {
  int rows = 3;
  int columns = 2;
  S21Matrix A(rows, columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      A(i, j) = (double)rand() / RAND_MAX * 20.0 - 10.0;
  ASSERT_ANY_THROW(A.InverseMatrix());
}

TEST(TestInverse, inverse5) {
  int rows = 3;
  int columns = 3;
  S21Matrix A(rows, columns);
  A(0, 0) = 1;
  A(0, 1) = -1;
  A(0, 2) = 0;
  A(1, 0) = 2;
  A(1, 1) = -2;
  A(1, 2) = 0;
  A(2, 0) = 5;
  A(2, 1) = -2;
  A(2, 2) = -3;
  ASSERT_ANY_THROW(A.InverseMatrix());
}

TEST(TestInverse, inverse6) {
  int rows = 1;
  int columns = 1;
  S21Matrix A(rows, columns);
  A(0, 0) = 5;
  S21Matrix C = A.InverseMatrix();
  ASSERT_FLOAT_EQ(C(0, 0), 1.0 / 5.0);
}
