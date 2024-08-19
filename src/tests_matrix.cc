#include <gtest/gtest.h>

#include "S21_Matrix_oop.h"

TEST(EqMatrix, True) {
  Matrix matrix_a(3, 3);
  matrix_a(0, 0) = 0;
  matrix_a(1, 0) = 0;
  matrix_a(0, 1) = 0;
  matrix_a(1, 1) = 1;
  matrix_a(1, 2) = 0;
  matrix_a(2, 1) = 0;
  matrix_a(2, 2) = 0;
  matrix_a(2, 0) = 0;
  matrix_a(0, 2) = 0;

  Matrix matrix_b(3, 3);
  matrix_b(0, 0) = 0;
  matrix_b(1, 0) = 0;
  matrix_b(0, 1) = 0;
  matrix_b(1, 1) = 1;
  matrix_b(1, 2) = 0;
  matrix_b(2, 1) = 0;
  matrix_b(2, 2) = 0;
  matrix_b(2, 0) = 0;
  matrix_b(0, 2) = 0;
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(EqMatrix, False) {
  Matrix matrix_a(3, 3);
  Matrix matrix_b(2, 2);
  ASSERT_FALSE(matrix_a == matrix_b);
  Matrix matrix_c(3, 3);
  matrix_a(1, 1) = 2;
  matrix_c(1, 1) = 2;
  ASSERT_TRUE(matrix_a == matrix_c);
}

TEST(OperatorEqMatrix, True) {
  Matrix matrix_a(3, 3);
  Matrix matrix_b(1, 3);
  matrix_a = matrix_b;
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(Determinant, true) {
  Matrix matrix_a(1, 1);
  matrix_a(0, 0) = 1;
  ASSERT_TRUE(matrix_a.Determinant() == 1);
}

TEST(Determinant3, True) {
  Matrix matrix_c(3, 3);
  matrix_c(0, 0) = 3;
  matrix_c(0, 1) = 5;
  matrix_c(0, 2) = 12;
  matrix_c(1, 0) = 6;
  matrix_c(1, 1) = 67;
  matrix_c(1, 2) = 120;
  matrix_c(2, 0) = 34;
  matrix_c(2, 1) = 90;
  matrix_c(2, 2) = 123;
  ASSERT_TRUE(std::round(matrix_c.Determinant()) == -11823);
}

TEST(CalcComplements, True) {
  Matrix matrix_a(2, 3);

  ASSERT_ANY_THROW(matrix_a.CalcComplements());
}

TEST(SumMatrix, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;
  matrix_a.SumMatrix(matrix_b);
  ASSERT_TRUE(matrix_a == result);
}

TEST(SumMatrix, False) {
  Matrix matrix_a(1, 2);
  Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a.SumMatrix(matrix_b));
}

TEST(SubMatrix, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  matrix_a.SubMatrix(matrix_b);

  ASSERT_TRUE(matrix_a == result);
}

TEST(SubMatrix, False) {
  Matrix matrix_a(1, 2);
  Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a.SubMatrix(matrix_b));
}

TEST(MulNumber, True) {
  Matrix matrix_a(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  matrix_a.MulNumber(10);

  ASSERT_TRUE(matrix_a == result);
}

TEST(MulMatrix, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  matrix_a.MulMatrix(matrix_b);
  ASSERT_TRUE(matrix_a == result);
}

TEST(MulMatrix, False) {
  Matrix matrix_a(2, 1);
  Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(1, 0) = -6.6;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a.MulMatrix(matrix_b));
}

TEST(OperatorMultiplyMatrix, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  ASSERT_TRUE((matrix_a * matrix_b) == result);
}

TEST(OperatorMultiplyNum, True) {
  Matrix matrix_a(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((matrix_a * 10) == result);
}

TEST(OperatorMulMatrix, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  result(0, 0) = -28;
  result(0, 1) = 4;
  result(1, 0) = 46.2;
  result(1, 1) = 0;

  matrix_a *= matrix_b;
  ASSERT_TRUE(matrix_a == result);
}

TEST(OperatorMulMatrix2, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix matrix_c(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  matrix_c(0, 0) = 2;
  matrix_c(0, 1) = 3;
  matrix_c(1, 0) = 4;
  matrix_c(1, 1) = 5;

  result(0, 0) = -40;
  result(0, 1) = -64;
  result(1, 0) = 92.4;
  result(1, 1) = 138.6;

  matrix_a *= matrix_b * matrix_c;
  ASSERT_TRUE(matrix_a == result);
}

TEST(OperatorMulMatrix, False) {
  Matrix matrix_a(2, 1);
  Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(1, 0) = -6.6;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3.5;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a *= matrix_b);
}

TEST(OperatorMultiplyNumber, True) {
  Matrix matrix_a(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((matrix_a * 10) == result);
}

TEST(OperatorMulNumber, True) {
  Matrix matrix_a(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = -78.14;
  matrix_a(0, 1) = 0;
  matrix_a(1, 0) = -0.3;
  matrix_a(1, 1) = 2;

  result(0, 0) = -781.4;
  result(0, 1) = 0;
  result(1, 0) = -3;
  result(1, 1) = 20;

  ASSERT_TRUE((matrix_a * 10) == result);
}

TEST(OperatorParentheses, True) {
  Matrix matrix_a(2, 2);
  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  ASSERT_EQ(matrix_a(0, 1), 2);
}

TEST(OperatorParentheses, False) {
  Matrix matrix_a(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6.6;
  matrix_a(1, 1) = 0;
  ASSERT_NE(matrix_a(0, 1), 10);
}

TEST(OperatorPlus, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;

  ASSERT_TRUE((matrix_a + matrix_b) == result);
}

TEST(Get, True) {
  Matrix matrix_a(3, 3);

  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  ASSERT_EQ(matrix_a.get_Rows(), 3);
  ASSERT_EQ(matrix_a.get_Cols(), 3);
}

TEST(Set, True) {
  Matrix matrix_a(3, 3);
  Matrix result(3, 2);

  matrix_a(0, 0) = 2;
  matrix_a(0, 1) = 5;
  matrix_a(0, 2) = 7;
  matrix_a(1, 0) = 6;
  matrix_a(1, 1) = 3;
  matrix_a(1, 2) = 4;
  matrix_a(2, 0) = 5;
  matrix_a(2, 1) = -2;
  matrix_a(2, 2) = -3;

  result(0, 0) = 2;
  result(0, 1) = 5;

  result(1, 0) = 6;
  result(1, 1) = 3;

  result(2, 0) = 5;
  result(2, 1) = -2;
  matrix_a.set_Cols(2);

  ASSERT_TRUE(matrix_a == result);
}
TEST(Set2, True) {
  Matrix result_c(4, 4);
  Matrix matrix_c(1, 1);
  Matrix matrix_b(3, 3);
  Matrix result_b(2, 3);

  matrix_b(0, 0) = 2;
  matrix_b(0, 1) = 5;
  matrix_b(0, 2) = 7;
  matrix_b(1, 0) = 6;
  matrix_b(1, 1) = 3;
  matrix_b(1, 2) = 4;
  matrix_b(2, 0) = 5;
  matrix_b(2, 1) = -2;
  matrix_b(2, 2) = -3;

  result_b(0, 0) = 2;
  result_b(0, 1) = 5;
  result_b(0, 2) = 7;
  result_b(1, 0) = 6;
  result_b(1, 1) = 3;
  result_b(1, 2) = 4;

  matrix_b.set_Rows(2);
  ASSERT_TRUE(matrix_b == result_b);
}

TEST(Set3, True) {
  Matrix matrix_c(3, 3);
  Matrix result_c(2, 2);
  matrix_c.set_Cols(2);
  matrix_c.set_Rows(2);
  ASSERT_TRUE(matrix_c == result_c);
}

TEST(OperatorMinus, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;

  ASSERT_TRUE((matrix_a - matrix_b) == result);
}

TEST(OperatorSumMatrix1, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  result(0, 0) = -75;
  result(0, 1) = 0.56;
  result(1, 0) = -69.6;
  result(1, 1) = 2;
  matrix_a += matrix_b;
  ASSERT_TRUE(matrix_a == result);
}

TEST(OperatorSumMatrix2, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix matrix_c(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;
  matrix_a(1, 0) = -69.3;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;

  matrix_c(0, 0) = 1;
  matrix_c(0, 1) = 1;
  matrix_c(1, 0) = 1;
  matrix_c(1, 1) = 1;

  result(0, 0) = -74;
  result(0, 1) = 1.56;
  result(1, 0) = -68.6;
  result(1, 1) = 3;
  matrix_a += matrix_b + matrix_c;
  ASSERT_TRUE(matrix_a == result);
}

TEST(OperatorSumMatrix, False) {
  Matrix matrix_a(1, 2);
  Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3.14;
  matrix_a(0, 1) = 0.56;

  matrix_b(0, 0) = -78.14;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -0.3;
  matrix_b(1, 1) = 2;
  ASSERT_ANY_THROW(matrix_a += matrix_b);
}

TEST(OperatorSubMatrix1, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix matrix_c(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;
  
  matrix_c(0, 0) = 1;
  matrix_c(0, 1) = 1;
  matrix_c(1, 0) = 1;
  matrix_c(1, 1) = 1;

  result(0, 0) = 11;
  result(0, 1) = 3;
  result(1, 0) = -2;
  result(1, 1) = -1;
  matrix_a -= matrix_b - matrix_c;
  ASSERT_TRUE(matrix_a == result);
}

TEST(OperatorSubMatrix2, True) {
  Matrix matrix_a(2, 2);
  Matrix matrix_b(2, 2);
  Matrix result(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;
  matrix_a(1, 0) = -6;
  matrix_a(1, 1) = 0;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  result(0, 0) = 10;
  result(0, 1) = 2;
  result(1, 0) = -3;
  result(1, 1) = -2;
  matrix_a -= matrix_b;
  ASSERT_TRUE(matrix_a == result);
}

TEST(OperatorSubMatrix, False) {
  Matrix matrix_a(1, 2);
  Matrix matrix_b(2, 2);

  matrix_a(0, 0) = 3;
  matrix_a(0, 1) = 2;

  matrix_b(0, 0) = -7;
  matrix_b(0, 1) = 0;
  matrix_b(1, 0) = -3;
  matrix_b(1, 1) = 2;

  ASSERT_ANY_THROW(matrix_a -= matrix_b);
}

TEST(Transpose, True) {
  Matrix matrix_a(4, 3);
  Matrix result(3, 4);

  matrix_a(0, 0) = 7;
  matrix_a(0, 1) = -98;
  matrix_a(0, 2) = 0.5;
  matrix_a(1, 0) = 0;
  matrix_a(1, 1) = 5.4;
  matrix_a(1, 2) = 32;
  matrix_a(2, 0) = 3.12;
  matrix_a(2, 1) = 2323;
  matrix_a(2, 2) = 23;
  matrix_a(3, 0) = -78;
  matrix_a(3, 1) = 476.4;
  matrix_a(3, 2) = 21;

  result(0, 0) = 7;
  result(0, 1) = 0;
  result(0, 2) = 3.12;
  result(0, 3) = -78;
  result(1, 0) = -98;
  result(1, 1) = 5.4;
  result(1, 2) = 2323;
  result(1, 3) = 476.4;
  result(2, 0) = 0.5;
  result(2, 1) = 32;
  result(2, 2) = 23;
  result(2, 3) = 21;
  Matrix res = matrix_a.Transpose();
  ASSERT_TRUE(res == result);
}

TEST(Inverse, False) {
  Matrix matrix_a(4, 3);
  Matrix result(2, 2);
  matrix_a(0, 0) = 7;
  matrix_a(0, 1) = -98;
  matrix_a(0, 2) = 0.5;
  matrix_a(1, 0) = 0;
  matrix_a(1, 1) = 5.4;
  matrix_a(1, 2) = 32;
  matrix_a(2, 0) = 3.12;
  matrix_a(2, 1) = 2323;
  matrix_a(2, 2) = 23;
  matrix_a(3, 0) = -78;
  matrix_a(3, 1) = 476.4;
  matrix_a(3, 2) = 21;
  ASSERT_ANY_THROW(matrix_a.InverseMatrix());
  ASSERT_ANY_THROW(result.InverseMatrix());
}

TEST(Copy, False) { ASSERT_ANY_THROW(Matrix a(-1, -1)); }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
