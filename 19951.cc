#include <iostream>

int N, M;
int array[100001];
int darray[100001];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    std::cin >> array[i];
  }

  int a, b, k;
  for (int i = 0; i < M; ++i) {
    std::cin >> a >> b >> k;
    darray[a] += k;
    darray[b + 1] -= k;
  }

  for (int i = 2; i <= N; ++i) {
    darray[i] += darray[i - 1];
  }

  for (int i = 1; i <= N; ++i) {
    std::cout << array[i] + darray[i] << " ";
  }

  return 0;
}