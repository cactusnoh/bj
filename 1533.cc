#include <cstdio>

#define P 1'000'003

struct Matrix {
  Matrix(int size_ = 0) : size(size_) {}
  size_t size;
  long long values[50][50] = {{0}};
};

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
  Matrix ret(lhs.size);
  for (size_t r_l = 0; r_l < lhs.size; ++r_l) {
    for (size_t c = 0; c < rhs.size; ++c) {
      for (size_t r = 0; r < rhs.size; ++r) {
        ret.values[r_l][c] += rhs.values[r][c] * lhs.values[r_l][r];
      }
      ret.values[r_l][c] %= P; 
    }
  }
  return ret;
}

Matrix power(Matrix m, int x) {
  Matrix ret(m.size);
  for (size_t i = 0; i < ret.size; ++i) {
    ret.values[i][i] = 1;
  }
  while (x > 0) {
    if (x & 1) {
      ret = ret * m;
    }
    x = x >> 1;
    m = m * m;
  }
  return ret;
}

int N, S, E, T;
Matrix adj_list;

int main() {
  scanf("%d%d%d%d", &N, &S, &E, &T);

  for (int i = 0; i < N; ++i) {
    adj_list.values[i][N + 4 * i] = 1;
    adj_list.values[N + 4 * i][N + 4 * i + 1] = 1;
    adj_list.values[N + 4 * i + 1][N + 4 * i + 2] = 1;
    adj_list.values[N + 4 * i + 2][N + 4 * i + 3] = 1;
    for (int j = 0; j < N; ++j) {
      int dist;
      scanf("%1d", &dist);
      if (dist > 1) {
        adj_list.values[N + 4 * i + dist - 2][j] = 1;
      } else {
        adj_list.values[i][j] = dist;
      }
    }
  }
  adj_list.size = 5 * N;

  Matrix ans = power(adj_list, T);
  
  printf("%lld\n", ans.values[S - 1][E - 1]);

  return 0;
}