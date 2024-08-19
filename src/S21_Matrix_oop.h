#pragma once

#include <cmath>
#include <stdexcept>

// namespace s21_mtrx {

class Matrix {
 private:
  /* data */
  int rows_, cols_;
  double **matrix_;

 public:
  /* methods */
  Matrix();  // A basic constructor that initialises a matrix of some
             // predefined dimension.
  Matrix(
      int rows_,
      int cols_);  // Parametrized constructor with number of rows and columns.
  Matrix(const Matrix &other);  // Copy constructor.
  Matrix(Matrix &&other);       // Move constructor.
  ~Matrix();                    // Destructor.

  /* setters */
  void set_Rows(int new_data);
  void set_Cols(int new_data);
  /* getters */
  int get_Rows() const;
  int get_Cols() const;

  /* overload operators */
  Matrix operator+(const Matrix &other) const;  // addition of two matrices
  Matrix operator-(const Matrix &) const;  // substraction oned matrix from another
  bool operator==(const Matrix &other) const;  // equality
  Matrix &operator+=(const Matrix &other);
  Matrix &operator-=(const Matrix &other);
  Matrix &operator*=(const Matrix &other);
  Matrix operator*(const Matrix &other) const;  // matrix multiplication
  Matrix operator*(const double scalar);        // multiplication

  Matrix &operator=(const Matrix &other);      // copy operator
  Matrix &operator=(Matrix &&other) noexcept;  // move operator
  double &operator()(int i, int j) const;      // rows n cols operator

  /* operations */
  bool EqMatrix(const Matrix &other) const;  // use operator ==
  void SumMatrix(const Matrix &other);       // use operator +
  void SubMatrix(const Matrix &other);       // use operator -
  void MulNumber(const double num);          // use operator *
  void MulMatrix(const Matrix &other);       // use operator *
  Matrix Transpose();
  Matrix CalcComplements() const;
  double Determinant();
  // double DetOfSubmatrix(int startRow, int startCol) const;
  // double Determinant() const;
  Matrix InverseMatrix() const;

  /* other functions */
  Matrix swap_rows(int i, int j) noexcept;
  double Cofactor(int i, int j) const;
};

//}  // namespace s21_mtrx
