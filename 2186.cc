#include <iostream>
#include <cstring>

int N, M, K;
char map[100][101];
char word[81];

/* 
 * Dynamic Programming: 
 * memo[idx][r][c] indicates how many paths exist for word[0 ~ idx]
 * when the path ends at map[r][c]   
 */
int memo[80][100][100];

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, 1, -1, 0};

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  // Get input
  std::cin >> N >> M >> K;
  for (int i = 0; i < N; ++i) {
    std::cin >> map[i];
  }
  std::cin >> word;

  size_t word_len = strlen(word);

  // Memoization init
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      if (word[0] == map[r][c]) {
        memo[0][r][c] = 1;
      }
    }
  }

  // Do DP
  for (size_t idx = 1; idx < word_len; ++idx) {
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < M; ++c) {
        if (map[r][c] != word[idx]) {
          continue;
        }
        for (int dir = 0; dir < 4; ++dir) {
          for (int step = 1; step <= K; ++step) {
            // (prev_r, prev_c) is the position before coming to (r, c)
            int prev_r = r + step * dr[dir];
            int prev_c = c + step * dc[dir];
            if (0 <= prev_r && prev_r < N && 0 <= prev_c && prev_c < M) {
              memo[idx][r][c] += memo[idx - 1][prev_r][prev_c];
            }
          }
        }
      }
    }
  }

  // Sum up path count
  int ans = 0;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      ans += memo[word_len - 1][r][c];
    }
  }

  std::cout << ans << std::endl;

  return 0;
}