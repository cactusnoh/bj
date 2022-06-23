#include <iostream>

int N, Q;
int arr[5001];
long long cnt[5001];
long long sum[5001];

inline int abs(int a) {
  return a < 0 ? -a : a;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> Q;

  for (int i = 1; i <= N; ++i) {
    std::cin >> arr[i];
  }

  bool exists[2'000'001] = {0}; // exists[N + 1'000'000]: does N exist?

  for (int j = 2; j <= N - 1; ++j) {
    exists[-arr[j - 1] + 1'000'000] = true;
    for (int k = j + 1; k <= N; ++k) {
      if (abs(arr[j] + arr[k]) <= 1'000'000 && exists[arr[j] + arr[k] + 1'000'000]) {
        cnt[k]++;
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    sum[i] = sum[i - 1] + cnt[i];
  }

  int a, b;
  for (int q = 0; q < Q; ++q) {
    std::cin >> a >> b;
    std::cout << sum[b] - sum[a - 1] << "\n";
  }

  return 0;
}