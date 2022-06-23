#include <iostream>
#include <algorithm>

int N;
int solutions[100'000];

inline int abs(int a) {
  return a < 0 ? -a : a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); 
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> solutions[i];
  }

  std::sort(solutions, solutions + N);

  int left = 0, right = N - 1;
  int sum;
  int ans_left = -2147000000, ans_right = 0;

  while (left < right) {
    sum = solutions[left] + solutions[right];

    if (abs(sum) < abs(ans_left + ans_right)) {
      ans_left = solutions[left];
      ans_right = solutions[right];
    }

    if (sum < 0) {
      ++left;
    } else if (sum == 0) {
      break;
    } else {
      --right;
    }
  }

  std::cout << ans_left << " " << ans_right << "\n";

  return 0;
}