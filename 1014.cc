#include <iostream>
#include <cstring>

inline int max(int a, int b) {
  return a < b ? b : a;
}

int C, M, N;
int broken[11];
int memo[11][1 << 10];

int solve(int line, int state) {
  if (memo[line][state] != -1) {
    return memo[line][state];
  }

  int &ret = memo[line][state];
  ret = 0;

  for (int i = 0; i < M; ++i) {
    if ((state & (1 << i)) != 0) {
      ++ret;
    }
  }

  if (line == N) {
    return ret;
  }

  int to_add = 0;
  for (int next_state = 0; next_state < (1 << M); ++next_state) {
    bool available = true;

    if ((broken[line + 1] & next_state) != 0) {
      continue;
    }

    for (int i = 0; i < M; ++i) {
      if ((next_state & (1 << i)) == 0) {
        continue;
      }
      if ((i > 0 && (next_state & (1 << (i - 1))) != 0) || 
          (i > 0 && (state & (1 << (i - 1))) != 0) ||
          (i < M - 1 && (next_state & (1 << (i + 1))) != 0) ||
          (i < M - 1 && (state & (1 << (i + 1))) != 0)) {
        available = false;
        break;
      }
    }

    if (available) {
      to_add = max(to_add, solve(line + 1, next_state));
    }
  }

  ret += to_add;

  return ret;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> C;

  for (int tc = 1; tc <= C; ++tc) {
    std::cin >> N >> M;

    memset(broken, 0, sizeof(broken));
    for (int j = 0; j <= N; ++j) {
      for (int k = 0; k < (1 << M); ++k) {
        memo[j][k] = -1;
      }
    }

    for (int j = 1; j <= N; ++j) {
      char line[11];
      std::cin >> line;
      for (int k = 0; k < M; ++k) {
        if (line[k] == 'x') {
          broken[j] |= (1 << k);
        }
      }
    }

    std::cout << solve(0, 0) << "\n";
  }

  return 0;
}