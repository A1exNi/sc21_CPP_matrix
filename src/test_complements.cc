#include "test_main.h"

TEST(TestComplements, complements1) {
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
  O(0, 0) = -287.52218386508594;
  O(0, 1) = 62.0154831847248;
  O(0, 2) = -321.99530318472296;
  O(0, 3) = -665.3034690140292;
  O(1, 0) = -21.909909333060277;
  O(1, 1) = -4.858737813708748;
  O(1, 2) = 15.83710313580812;
  O(1, 3) = 406.1220290167821;
  O(2, 0) = -320.7150121781577;
  O(2, 1) = 191.3543288557128;
  O(2, 2) = -496.95539497628556;
  O(2, 3) = -899.0666423454255;
  O(3, 0) = -58.68556539466871;
  O(3, 1) = -9.495494891654378;
  O(3, 2) = -218.78953288252893;
  O(3, 3) = -558.2294615722393;
  S21Matrix C = A.CalcComplements();
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_FLOAT_EQ(C(i, j), O(i, j));
}

TEST(TestComplements, complements2) {
  int rows = 3;
  int columns = 3;
  S21Matrix A(rows, columns);
  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(1, 0) = 0;
  A(1, 1) = 4;
  A(1, 2) = 2;
  A(2, 0) = 5;
  A(2, 1) = 2;
  A(2, 2) = 1;
  S21Matrix O(rows, columns);
  O(0, 0) = 0;
  O(0, 1) = 10;
  O(0, 2) = -20;
  O(1, 0) = 4;
  O(1, 1) = -14;
  O(1, 2) = 8;
  O(2, 0) = -8;
  O(2, 1) = -2;
  O(2, 2) = 4;
  S21Matrix C = A.CalcComplements();
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) ASSERT_FLOAT_EQ(C(i, j), O(i, j));
}

TEST(TestComplements, complements3) {
  int rows = 3;
  int columns = 4;
  S21Matrix A(rows, columns);
  ASSERT_ANY_THROW(A.CalcComplements());
}