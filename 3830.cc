#include <iostream>
#include <cstring>

int N, M;
long long diff[100'001];
int parent[100'001];
int rank[100'001];

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int find_set(int n) {
  if (parent[n] == n) {
    return n;
  }
  int parent_n = find_set(parent[n]);
  diff[n] += diff[parent[n]];
  return (parent[n] = parent_n);
}

void unionize(int a, int b, int w) {
  int parent_a = find_set(a);
  int parent_b = find_set(b);

  if (parent_a == parent_b) {
    return;
  } else if (rank[parent_a] < rank[parent_b]) {
    swap(&parent_a, &parent_b);
    swap(&a, &b);
    w = -w;
  }
  if (rank[parent_a] == rank[parent_b]) {
    ++rank[parent_a];
  }

  diff[parent_b] = diff[a] + w - diff[b];
  parent[parent_b] = parent_a;
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
      parent[i] = i;
      rank[i] = 0;
      diff[i] = 0;
    }

    for (int i = 0; i < M; ++i) {
      char cmd;
      int a, b;
      std::cin >> cmd >> a >> b;
      if (cmd == '!') {
        int w;
        std::cin >> w;
        unionize(a, b, w);
      } else {
        if (find_set(a) == find_set(b)) {
          std::cout << diff[b] - diff[a] << "\n";
        } else {
          std::cout << "UNKNOWN" << "\n";
        }
      }
    }
  }

  return 0;
}