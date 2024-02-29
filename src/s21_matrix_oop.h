#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  double** AllocMatrix(int rows, int cols);
  void FreeMatrix();
  void NullMatrix();

 public:
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  ~S21Matrix();

  bool EqMatrix(const S21Matrix& other) const;
  bool operator==(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  S21Matrix& operator*=(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix ReduceMatrix(int i, int j);
  double Determinant();
  S21Matrix InverseMatrix();
  double& operator()(int i, int j);
  const double& operator()(int i, int j) const;
  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);
};

S21Matrix operator+(S21Matrix A, const S21Matrix& B);
S21Matrix operator-(S21Matrix A, const S21Matrix& B);
S21Matrix operator*(S21Matrix A, const double num);
S21Matrix operator*(S21Matrix A, const S21Matrix& B);

#endif  // S21_MATRIX_OOP_H_