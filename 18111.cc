#include <iostream>

inline int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, M, B;
  int map[500][500];

  std::cin >> N >> M >> B;
  int tot_blocks = B;
  for (int r = 0; r < N; ++r) {
    for (int c = 0; c < M; ++c) {
      std::cin >> map[r][c];
      tot_blocks += map[r][c];
    }
  }

  int min_time = 0x7fffffff;
  int max_height = 0;

  int max_height_possible = min(tot_blocks / (N * M), 256);
  for (int height = 0; height <= max_height_possible; ++height) {
    int tot_time = 0;
    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < M; ++c) {
        if (map[r][c] > height) {
          tot_time += ((map[r][c] - height) << 1);
        } else if (map[r][c] < height) {
          tot_time += height - map[r][c];
        }
      }
    }
    if (tot_time <= min_time) {
      min_time = tot_time;
      max_height = height;
    }
  }

  std::cout << min_time << " " << max_height << std::endl;

  return 0;
}