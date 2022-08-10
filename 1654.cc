#include <iostream>

inline long long max(long long a, long long b) {
  return a < b ? b : a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int K, N;
  std::cin >> K >> N;

  int wires[10'000];
  int max_length = 0;
  for (int i = 0; i < K; ++i) {
    std::cin >> wires[i];
    max_length = max(max_length, wires[i]);
  }

  long long answer = 0;
  long long left = 1, right = max_length;
  while (right >= left) {
    long long mid = left + ((right - left) >> 1);
    long long cnt = 0;
    for (int i = 0; i < K; ++i) {
      cnt += wires[i] / mid;
    }
    if (cnt >= N) {
      answer = max(answer, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}