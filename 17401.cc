#include <iostream>

#define P 1'000'000'007

struct Matrix {
  long long mat_[21][21] = {{0}};
};

int T, N, D, M;

Matrix mat_mul(Matrix a, Matrix b)
{
  Matrix c;
  for(int col_b = 1; col_b <= N; ++col_b) {
    for(int col_a = 1; col_a <= N; ++col_a) {
      for(int row_a = 1; row_a <= N; ++row_a) {
        c.mat_[row_a][col_b] = (c.mat_[row_a][col_b] + a.mat_[row_a][col_a] * b.mat_[col_a][col_b]) % P;
      }
    }
  }
  return c;
}

Matrix mat_pow(Matrix a, int x)
{
  Matrix ret;
  
  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= N; ++j) {
      if(i == j) {
        ret.mat_[i][j] = 1;
      }
    }
  }

  while(x) {
    if(x & 1) {
      ret = mat_mul(a, ret);
    }
    a = mat_mul(a, a);
    x >>= 1;
  }

  return ret;
}

Matrix way_mat[101];
Matrix ans_mat;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> T >> N >> D;

  if(D == 0) {
    for(int i = 1; i <= N; ++i) {
      for(int j = 1; j <= N; ++j) {
        std::cout << 0 << " ";
      }
      std::cout << "\n";
    }
    return 0;
  }

  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= N; ++j) {
      if(i == j) {
        ans_mat.mat_[i][j] = 1;
      }
    }
  }

  for(int i = 0; i < T; ++i) {
    std::cin >> M;
    for(int j = 0; j < M; ++j) {
      int a, b, c;
      std::cin >> a >> b >> c;
      way_mat[i].mat_[a][b] = c;
    }
  }

  for(int i = 0; i < T; ++i) {
    ans_mat = mat_mul(ans_mat, way_mat[i]);
  }

  ans_mat = mat_pow(ans_mat, D / T);

  for(int i = 0; i < D % T; ++i) {
    ans_mat = mat_mul(ans_mat, way_mat[i]);
  }

  for(int i = 1; i <= N; ++i) {
    for(int j = 1; j <= N; ++j) {
      std::cout << ans_mat.mat_[i][j] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}