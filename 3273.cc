#include <iostream>
#include <algorithm>

int N, X;
int arr[100'000];

int main() {
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> arr[i];
  }
  std::cin >> X;

  if (N == 1) {
    std::cout << 0 << "\n";
    return 0;
  }

  std::sort(arr, arr + N);

  int left = 0, right = N - 1;
  int sum;
  long long ans = 0;

  while (left < right) {
    sum = arr[left] + arr[right];
    if (sum < X) {
      ++left;
    } else if (sum == X) {
      ++ans;
      ++left;
    } else {
      --right;
    }
  }

  std::cout << ans << std::endl;
  return 0;
}