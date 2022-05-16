#include <iostream>

#define DIVISOR 1'000'000'007

struct Matrix {
  Matrix(long long (*M)[8] = nullptr);
  void print();
  long long mat[8][8] = {{0}};
};

Matrix::Matrix(long long (*M)[8])
{
  if(M == nullptr)
    return;
  for(int i = 0; i < 8; ++i)
    for(int j = 0; j < 8; ++j)
      mat[i][j] = M[i][j];
}

void Matrix::print()
{
  for(int i = 0; i < 8; ++i) {
    for(int j = 0; j < 8; ++j)
      std::cout << mat[i][j] << " ";
    std::cout << "\n";
  }
}

Matrix operator*(const Matrix &A, const Matrix &B)
{
  Matrix ans;

  for(int c = 0; c < 8; ++c) {
    for(int r = 0; r < 8; ++r) {
      for(int k = 0; k < 8; ++k) {
        ans.mat[k][c] = (ans.mat[k][c] + B.mat[r][c] * A.mat[k][r]) % DIVISOR;
      }
    }
  }

  return ans;
}

int D;
long long adj_mat[8][8] = {
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0},
  {0, 0, 1, 1, 0, 1, 1, 0},
  {0, 0, 0, 1, 1, 0, 0, 1},
  {0, 0, 0, 0, 1, 0, 0, 1},
  {0, 0, 0, 0, 0, 1, 1, 0},
};

Matrix power(Matrix A, int x)
{
  if(x == 1)
    return A;
  Matrix temp = power(A, x >> 1);
  if(x & 1)
    return temp * temp * A;
  else
    return temp * temp;
}

int main()
{
  std::cin >> D;
  Matrix adj(adj_mat), ans = power(adj, D);

  std::cout << ans.mat[0][0] << "\n";

  return 0;
}