#include <iostream>
#include <queue>
#include <vector>

void sort(std::vector<int> &A) {
  if (A[0] > A[1]) {
    int temp = A[0];
    A[0] = A[1];
    A[1] = temp;
  }
  if (A[1] > A[2]) {
    int temp = A[1];
    A[1] = A[2];
    A[2] = temp;
  }
  if (A[0] > A[1]) {
    int temp = A[0];
    A[0] = A[1];
    A[1] = temp;
  }
}

bool visited[1501][1501] = {false};

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int A, B, C;
  std::cin >> A >> B >> C;

  if ((A + B + C) % 3 != 0) {
    std::cout << 0 << "\n";
    return 0;
  }

  std::queue<std::vector<int>> Q;

  std::vector<int> init{A, B, C};
  sort(init);
  Q.emplace(init);
  visited[init[0]][init[1]] = true;

  bool possible = false;
  while (!Q.empty()) {
    auto curr = Q.front();
    Q.pop();

    if (curr[0] == curr[1] && curr[1] == curr[2]) {
      possible = true;
      break;
    }

    if (curr[2] > curr[1]) {
      std::vector<int> next{curr[0], curr[1] * 2, curr[2] - curr[1]};
      sort(next);
      if (!visited[next[0]][next[1]]) {
        Q.emplace(next);
        visited[next[0]][next[1]] = true;
      }
    }

    if (curr[2] > curr[0]) {
      std::vector<int> next{curr[1], curr[0] * 2, curr[2] - curr[0]};
      sort(next);
      if (!visited[next[0]][next[1]]) {
        Q.emplace(next);
        visited[next[0]][next[1]] = true;
      }
    }

    if (curr[1] > curr[0]) {
      std::vector<int> next{curr[2], curr[0] * 2, curr[1] - curr[0]};
      sort(next);
      if (!visited[next[0]][next[1]]) {
        Q.emplace(next);
        visited[next[0]][next[1]] = true;
      }
    }
  }

  std::cout << possible << "\n";

  return 0;
}