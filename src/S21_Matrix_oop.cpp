#include "S21_Matrix_oop.h"

#include <iostream>

using namespace std;
// using namespace s21_mtrx;

/* default constructor */
Matrix::Matrix() : rows_(0), cols_(0), matrix_(nullptr){};

/* parametrized constructor */
Matrix::Matrix(int rows, int columns) : rows_(rows), cols_(columns) {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
}

/*  destructor */
Matrix::~Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  matrix_ = nullptr;
}

/* copy constructor */
Matrix::Matrix(const Matrix &other) : Matrix(other.rows_, other.cols_) {
  // copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

/* move constructor */
Matrix::Matrix(Matrix &&other) {
  rows_ = std::move(other.rows_);
  cols_ = std::move(other.cols_);
  matrix_ = std::move(other.matrix_);
}

/* setters */
void Matrix::set_Rows(int new_data) { rows_ = new_data; }
void Matrix::set_Cols(int new_data) { cols_ = new_data; }

/* getters */
int Matrix::get_Rows() const { return rows_; }
int Matrix::get_Cols() const { return cols_; }

/* overloaded operator for rows and cols*/
double &Matrix::operator()(int i, int j) const { return matrix_[i][j]; }

/* operations */
void Matrix::SumMatrix(const Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw invalid_argument(
        "Matrices must have the same dimensions fpr addition.");
  for (int i = 0; i != rows_; ++i) {
    for (int j = 0; j != cols_; ++j) {
      matrix_[i][j] += other(i, j);
    }
  }
}

void Matrix::SubMatrix(const Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw invalid_argument(
        "Matrix dimensions should be the same for substraction.");
  for (int i = 0; i != rows_; ++i) {
    for (int j = 0; j != cols_; ++j) {
      matrix_[i][j] -= other(i, j);
    }
  }
}

void Matrix::MulMatrix(const Matrix &other) {
  if (cols_ != other.rows_)
    throw invalid_argument(
        "Number of columns in the first matrix must equal the number of rows "
        "in the second matrix for multiplication.");
  Matrix res(rows_, other.cols_);
  for (int i = 0; i != rows_; ++i) {
    for (int j = 0; j != other.cols_; ++j) {
      res.matrix_[i][j] = 0;
      for (int k = 0; k != cols_; ++k) {
        res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = res;
}

bool Matrix::EqMatrix(const Matrix &other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  bool flag = true;
  // const double epsilon = 1e-7;  // Точность до 7 чисел после запятой
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
        flag = false;;
      }
    }
  }

  return flag;
}

void Matrix::MulNumber(const double scalar) {
  for (int i = 0; i != rows_; ++i) {
    for (int j = 0; j != cols_; ++j) {
      matrix_[i][j] *= scalar;
    }
  }
}

Matrix Matrix::Transpose() {
  Matrix transposed(cols_, rows_);
  for (int i = 0; i != rows_; ++i) {
    for (int j = 0; j != cols_; ++j) {
      transposed(j, i) = matrix_[i][j];
    }
  }
  return transposed;
}

Matrix Matrix::CalcComplements() const {
  if (rows_ != cols_) throw std::invalid_argument("Matrix must be square");

  Matrix cofactor(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      int sign = ((i + j) % 2 == 0) ? 1 : -1;
      cofactor(i, j) = sign * Cofactor(i, j);
    }
  }
  return cofactor;
}

double Matrix::Cofactor(int i, int j) const {
  if (i >= rows_ || j >= cols_) return 0;
  double sum = 0;
  for (int row = 0; row < rows_; ++row) {
    for (int col = 0; col < cols_; ++col) {
      if (row != i && col != j) {
        sum += ((i + row) % 2 == 0 ? 1 : -1) * matrix_[row][col];
      }
    }
  }
  return sum;
}

double Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square");
  }
  double result = 1.0;
  Matrix matrix(*this);
  Matrix temp(rows_, cols_);
  for (int i = 0; i < rows_ && result; i++) {
    if (matrix(i, i) == 0) {
      int found = 0;
      for (int j = i + 1; j < rows_ && !found; j++) {
        if (matrix(j, i) != 0) {
          matrix.swap_rows(i, j);
          found = 1;
        }
      }
      if (!found) result = 0.0;
    }
    if (result) {
      result *= matrix(i, i);
      for (int m = 0; m < rows_; m++) {
        temp.matrix_[i][m] = matrix(i, m);
      }
      for (int x = i + 1; x < rows_; x++) {
        double rate = matrix(x, i) / matrix(i, i);
        for (int k = 0; k < rows_; k++) {
          matrix(x, k) -= rate * temp.matrix_[i][k];
        }
      }
    }
  }
  return result;
}

Matrix Matrix::swap_rows(int i, int j) noexcept {
  Matrix matrix(*this);
  for (int k = 0; k < rows_; k++) {
    double temp = matrix(i, k);
    matrix(i, k) = matrix(j, k);
    matrix(j, k) = temp;
  }
  for (int x = 0; x < rows_; x++) {
    matrix(i, x) *= -1;
  }
  return matrix;
}

Matrix Matrix::InverseMatrix() const {
  if (rows_ != cols_)
    throw range_error("Only square matrices have determinants.");
  Matrix res(*this);
  double det = res.Determinant();
  if (det == 0)
    throw logic_error(
        "The determinant of the matrix is zero, so it does not have an "
        "inverse.");
  Matrix neo(rows_, cols_);
  Matrix temp = CalcComplements();
  Matrix second_temp = temp.Transpose();
  neo = second_temp;
  neo.MulNumber(1.0 / det);
  return neo;
}

/* overloaded operator + */
Matrix Matrix::operator+(const Matrix &other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw invalid_argument(
        "Matrices must have the same dimensions for addition.");

  Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

/* overloaded operator - */
Matrix Matrix::operator-(const Matrix &other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw invalid_argument(
        "Matrix dimensions should be the same for substraction.");

  Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

/* overloaded operator  == */
bool Matrix::operator==(const Matrix &other) const { return EqMatrix(other); }

/* overloaded = copy operator  */
Matrix &Matrix::operator=(const Matrix &other) {
  if (&other == this) return *this;
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < other.cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

/* overloaded = move operator*/
Matrix &Matrix::operator=(Matrix &&other) noexcept {
  if (&other == this) return *this;
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  delete[] other.matrix_;
  return *this;
}

/* overloaded += operator */
Matrix &Matrix::operator+=(const Matrix &other) {
  SumMatrix(other);
  return *this;
}

/* overloaded -= operator */
Matrix &Matrix::operator-=(const Matrix &other) {
  SubMatrix(other);
  return *this;
}

/* overloaded *= operator (matrix * matrix) */
Matrix &Matrix::operator*=(const Matrix &other) {
  MulMatrix(other);
  return *this;
}

/* overloaded * operator (matrix * matrix) */
Matrix Matrix::operator*(const Matrix &other) const {
  Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

/* overloaded * operator (matrix * scalar) */
Matrix Matrix::operator*(const double scalar) {
  Matrix res(*this);
  res.MulNumber(scalar);
  return res;
}
