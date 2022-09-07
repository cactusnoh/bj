#include <iostream>
#include <vector>

#define P 1'000'000

/**
 * @brief Matrix object
 * 
 */
struct Matrix {
  Matrix (size_t num_row = 1, size_t num_col = 1) :
    num_row_(num_row), num_col_(num_col), arr_(num_row, std::vector<long long>(num_col)) {}

  void print() {
    for (auto r = 0; r < num_row_; ++r) {
      for (auto c = 0; c < num_col_; ++c) {
        std::cout << arr_[r][c] << " ";
      }
      std::cout << "\n";
    }
    std::cout << "\n";
  }
  
  size_t num_row_;
  size_t num_col_;
  std::vector<std::vector<long long>> arr_;
};

/**
 * @brief Matrix multiplication
 * 
 * @param lhs Left matrix
 * @param rhs Right matrix
 * @return Resulting matrix
 */
Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
  Matrix ret(lhs.num_row_, rhs.num_col_);
  for (auto i = 0; i < rhs.num_col_; ++i) {
    for (auto j = 0; j < rhs.num_row_; ++j) {
      for (auto k = 0; k < lhs.num_row_; ++k) {
        ret.arr_[k][i] = (ret.arr_[k][i] + lhs.arr_[k][j] * rhs.arr_[j][i]) % P;
      }
    }
  }
  return ret;
}

/**
 * @brief Calculate M to the power of n
 * 
 * @param M Base Matrix 
 * @param n Exponent
 * @return Resulting matrix
 */
Matrix power(Matrix M, long long n) {
  Matrix ret(M.num_row_, M.num_col_);
  // ret is initialized to identity matrix
  for (auto r = 0; r < ret.num_row_; ++r) {
    ret.arr_[r][r] = 1;
  }
  // calculate M to the power of n
  while (n) {
    if ((n & 1) == 1) {
      ret = ret * M;
    }
    M = M * M;
    n = n >> 1;
  }
  return ret;
}

int main() {
  long long N;

  std::cin >> N;

  /**
   * 
   * Get fibonacci number by matrix multiplication
   * |1 1| |Fn-1| = |Fn-1 + Fn-2| = | Fn |
   * |1 0| |Fn-2|   |   Fn-1    |   |Fn-1|
   * 
   * |1 1|^(n - 1) |F1| = | Fn |
   * |1 0|         |F0|   |Fn-1|
   * 
   */

  Matrix A(2, 2);
  A.arr_[0][0] = 1;
  A.arr_[1][0] = 1;
  A.arr_[0][1] = 1;

  Matrix B(2, 1);
  B.arr_[0][0] = 1;
  B.arr_[1][0] = 0;

  Matrix ans = power(A, N - 1) * B;
  std::cout << ans.arr_[0][0] << std::endl;

  return 0; 
}