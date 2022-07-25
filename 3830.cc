#include <iostream>
#include <cstring>

int N, M;
int weight[100'001];
int set[100'001];
int rank[100'001];

void unionize(int a, int b) {
  a = find_set(a);
  b = find_set(b);

  if (rank[a] < rank[b]) {
    int temp = a;
    a = b;
    b = temp;
  }
  set[b] = a;

  if (rank[a] == rank[b]) {
    rank[a]++;
  }
}

int find_set(int n) {
  if (set[n] == n) {
    return n;
  }
  return (set[n] = find_set(set[n]));
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  while (true) {
    std::cin >> N >> M;

    if (N == 0 && M == 0) {
      break;
    }

    for (int i = 1; i <= N; ++i) {
      set[i] = i;
      rank[i] = 0;
      weight[i] = 0;
    }

    for (int i = 0; i < M; ++i) {
      char cmd;
      int a, b;
      std::cin >> cmd >> a >> b;
      if (cmd == '!') {
        int diff;
        std::cin >> diff;
        if (rank[find_set(a)] == 0 && rank[find_set(b)] == 0) {
          unionize(a, b);
          weight[b] = diff;
        } else if ()
      } else {

      }
    }
  }

  return 0;
}