#include <iostream>
#include <vector>
#include <algorithm>

int N, K;
bool seen[10] = {false};
bool duplicate_exists = false;
std::vector<int> max_num;

void DFS(std::vector<int> &digits, int idx, int swaps) {
  if (swaps == K) {
    // did required number of swaps
    // update max_num
    if (max_num < digits) {
      max_num = digits;
    }
    return;
  }

  int M = digits.size();

  if (idx == M) {
    // 'digits' is sorted in descending order but we need to do more swaps
    // 1. If number of remaining swaps is even, we can ignore swaps
    // 2. If duplicate digit exists, we can ignore swaps
    if (((K - swaps) % 2 == 1) && !duplicate_exists) {
      int temp = digits[M - 1];
      digits[M - 1] = digits[M - 2];
      digits[M - 2] = temp;
    }
    if (max_num < digits) {
      max_num = digits;
    }
    return;
  }

  // get maximum number from subarray digits[idx...M-1]
  int max_ = digits[idx];
  for (int j = idx + 1; j <= M - 1; ++j) {
    if (max_ < digits[j]) {
      max_ = digits[j];
    }
  }

  if (max_ == digits[idx]) {
    // if digits[idx] is maximum element, we don't need any swaps
    DFS(digits, idx + 1, swaps);
  } else {
    // try all swaps
    for (int j = idx + 1; j <= M - 1; ++j) {
      if (digits[j] == max_) {
        int temp = digits[j];
        digits[j] = digits[idx];
        digits[idx] = temp;
        DFS(digits, idx + 1, swaps + 1);
        digits[idx] = digits[j];
        digits[j] = temp;
      }
    }
  }
}

int main() {
  std::cin >> N >> K;

  // extract digits
  std::vector<int> digits;
  while (N > 0) {
    digits.emplace_back(N % 10);
    if (!seen[N % 10]) {
      seen[N % 10] = true;
    } else {
      duplicate_exists = true;
    }
    N /= 10;
  }

  int M = digits.size();
  if (M < 2 || (M == 2 && seen[0])) {
    // One digit / Two digits with one zero
    // Can't swap any digits...
    std::cout << -1 << std::endl;
    return 0;
  }

  std::reverse(digits.begin(), digits.end());
  max_num = std::vector<int>(M, 0);
  DFS(digits, 0, 0);

  for (auto i : max_num) {
    std::cout << i;
  }

  return 0;
}