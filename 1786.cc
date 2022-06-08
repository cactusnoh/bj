#include <iostream>
#include <vector>
#include <string>

#define MAX_LEN 1'000'000

std::string T;
std::string P;

size_t n;
size_t m;

int pi[MAX_LEN];

void GetPi() {
  for (size_t i = 1, j = 0; i < m; ++i) {
    while (j > 0 && P[i] != P[j]) {
      j = pi[j - 1];
    }

    if (P[i] == P[j]) {
      pi[i] = ++j;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  getline(std::cin, T);
  getline(std::cin, P);

  n = T.size();
  m = P.size();

  GetPi();

  std::vector<size_t> match_idx;

  for (size_t i = 0, j = 0; i < n; ++i) {
    while (j > 0 && T[i] != P[j]) {
      j = pi[j - 1];
    }

    if (T[i] == P[j]) {
      if (j == m - 1) {
        match_idx.push_back(i - m + 1);
        j = pi[j];
      } else {
        ++j;
      }
    }
  }

  std::cout << match_idx.size() << "\n";

  for (auto idx : match_idx) {
    std::cout << idx + 1 << " ";
  }
  std::cout << "\n";

  return 0;
}
