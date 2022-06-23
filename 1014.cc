#include <iostream>
#include <cstring>

int C, M, N;

int dr[6] = {-1, 1, -1, 1, -1, 1};
int dc[6] = {0, 0, 1, 1, -1, -1};

char possible[10][10];

void DFS(int r, int c) {
  
}

int main(void) {
  std::cin >> C;

  for (int i = 0; i < C; ++i) {
    memset(possible, 0, sizeof(possible));
    std::cin >> N >> M;
    for (int j = 0; j < N; ++j) {
      std::cin >> possible[j];
    }
    DFS(0, 0);
    if (M > 1) {
      DFS(0, 1);
    }
  }

  return 0;
}