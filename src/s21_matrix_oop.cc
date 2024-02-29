#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::length_error("Matrix size must be greater then 0");
  } else {
    matrix_ = AllocMatrix(rows, cols);
  }
}

double** S21Matrix::AllocMatrix(int rows, int cols) {
  double** matrix = nullptr;
  try {
    matrix = new double*[rows]();
    for (int i = 0; i < rows; i++) {
      try {
        matrix[i] = new double[cols]();
      } catch (...) {
        for (int j = 0; j < i; j++) delete[] matrix[j];
        delete[] matrix;
        matrix = nullptr;
        throw;
      }
    }
  } catch (...) {
    throw;
  }
  return matrix;
}

void S21Matrix::FreeMatrix() {
  for (int i = 0; i < rows_; i++) delete[] matrix_[i];
  delete[] matrix_;
  matrix_ = nullptr;
}

void S21Matrix::NullMatrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = AllocMatrix(rows_, cols_);
  for (int i = 0; i < rows_; i++)
    std::copy(other.matrix_[i], other.matrix_[i] + cols_, matrix_[i]);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  S21Matrix result(other);
  *this = std::move(result);
  return *this;
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.NullMatrix();
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this != &other) {
    FreeMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.NullMatrix();
  }
  return *this;
}

S21Matrix::~S21Matrix() { FreeMatrix(); }

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  bool answer = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    answer = false;
  } else {
    for (int i = 0; i < rows_ && answer; i++)
      for (int j = 0; j < cols_ && answer; j++)
        if (std::abs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7)
          answer = false;
  }
  return answer;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::length_error("Matrix size error");
  else
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) matrix_[i][j] += other.matrix_[i][j];
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix operator+(S21Matrix A, const S21Matrix& B) {
  A.SumMatrix(B);
  return A;
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::length_error("Matrix size error");
  else
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) matrix_[i][j] -= other.matrix_[i][j];
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix operator-(S21Matrix A, const S21Matrix& B) {
  A.SubMatrix(B);
  return A;
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] *= num;
}

S21Matrix& S21Matrix::operator*=(const double num) noexcept {
  MulNumber(num);
  return *this;
}

S21Matrix operator*(S21Matrix A, const double num) {
  A.MulNumber(num);
  return A;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::length_error("Matrix size error");
  } else {
    S21Matrix new_matrix(rows_, other.cols_);
    for (int i = 0; i < rows_; i++)
      for (int k = 0; k < other.cols_; k++)
        for (int j = 0; j < cols_; j++)
          new_matrix.matrix_[i][k] += matrix_[i][j] * other.matrix_[j][k];
    cols_ = other.cols_;
    *this = std::move(new_matrix);
  }
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix operator*(S21Matrix A, const S21Matrix& B) {
  A.MulMatrix(B);
  return A;
}

double& S21Matrix::operator()(int i, int j) {
  assert(i >= 0 && i < rows_);
  assert(j >= 0 && j < cols_);
  return matrix_[i][j];
}

const double& S21Matrix::operator()(int i, int j) const {
  assert(i >= 0 && i < rows_);
  assert(j >= 0 && j < cols_);
  return matrix_[i][j];
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0) {
    throw std::length_error("Matrix size must be greater then 0");
  } else {
    double** new_matrix = AllocMatrix(rows, cols_);
    int b_rows = rows;
    if (b_rows > rows_) b_rows = rows_;
    for (int i = 0; i < b_rows; i++)
      for (int j = 0; j < cols_; j++) new_matrix[i][j] = matrix_[i][j];
    FreeMatrix();
    rows_ = rows;
    matrix_ = new_matrix;
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) {
    throw std::length_error("Matrix size must be greater then 0");
  } else {
    double** new_matrix = AllocMatrix(rows_, cols);
    int b_cols = cols;
    if (b_cols > cols_) b_cols = cols_;
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < b_cols; j++) new_matrix[i][j] = matrix_[i][j];
    FreeMatrix();
    cols_ = cols;
    matrix_ = new_matrix;
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) result.matrix_[j][i] = matrix_[i][j];
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) {
      S21Matrix reduce = ReduceMatrix(i, j);
      double det = reduce.Determinant();
      result.matrix_[i][j] = pow(-1, i + j) * det;
    }
  return result;
}

S21Matrix S21Matrix::ReduceMatrix(int i, int j) {
  S21Matrix result(rows_ - 1, cols_ - 1);
  if (i >= rows_ || j >= cols_) {
    throw std::length_error("Matrix size error");
  } else {
    int k = 0;
    for (int m = 0; m < rows_; m++)
      if (m != i) {
        int l = 0;
        for (int n = 0; n < cols_; n++)
          if (n != j) result.matrix_[k][l++] = matrix_[m][n];
        k++;
      }
  }
  return result;
}

double S21Matrix::Determinant() {
  double result = 0;
  if (rows_ != cols_) {
    throw std::length_error("Matrix size error");
  } else {
    if (rows_ == 1) result = matrix_[0][0];
    if (rows_ == 2)
      result = matrix_[0][0] * matrix_[1][1] - matrix_[1][0] * matrix_[0][1];
    if (rows_ > 2) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix reduce = ReduceMatrix(0, j);
        double minor = reduce.Determinant();
        result += pow(-1, j) * matrix_[0][j] * minor;
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix result(rows_, cols_);
  double det = Determinant();
  if (det == 0) {
    throw std::logic_error("The matrix determinant is zero");
  } else {
    if (rows_ == 1) {
      result.matrix_[0][0] = 1.0 / det;
    } else {
      S21Matrix comp = CalcComplements();
      S21Matrix compT = comp.Transpose();
      result = compT * (1.0 / det);
    }
  }
  return result;
}