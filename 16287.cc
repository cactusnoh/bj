#include <iostream>

int W, N;
int weight[5000];
bool sum_exists[800000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> W >> N;

  for (int i = 0; i < N; ++i) {
    std::cin >> weight[i];
  }

  // 0 <= i < j < k < l < N
  for (int k = 2; k < N - 1; ++k) {
    int j = k - 1;
    for (int i = 0; i < j; ++i) {
      int two_sum = weight[i] + weight[j];
      if (two_sum < W) {
        sum_exists[two_sum] = true;
      }
    }

    for (int l = k + 1; l < N; ++l) {
      int two_sum = weight[k] + weight[l];
      if (two_sum < W && sum_exists[W - two_sum]) {
        std::cout << "YES" << "\n";
        return 0;
      }
    }
  }

  std::cout << "NO" << "\n";
  return 0;
}