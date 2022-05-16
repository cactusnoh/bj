#include <iostream>
#include <cstring>
#include <queue>

typedef std::pair<int, int> pii;

int N;
char map[3073][6144];

std::queue<pii> Q;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  memset(map, ' ', sizeof(map));

  Q.push(pii(1, (2 * N - 1) / 2));

  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    int r = curr.first, c = curr.second;
    if(map[r - 1][c - 1] == '*' && map[r - 1][c + 1] == '*') continue;

    map[r][c] = '*';
    map[r + 1][c - 1] = map[r + 1][c + 1] = '*';
    map[r + 2][c - 2] = map[r + 2][c - 1] = map[r + 2][c] = map[r + 2][c + 1] = map[r + 2][c + 2] = '*';

    if(r + 3 <= N) {
      Q.push(pii(r + 3, c - 3));
      Q.push(pii(r + 3, c + 3));
    }
  }

  for(int i = 1; i <= N; ++i) {
    for(int j = 0; j < 2 * N - 1; ++j)
      std::cout << map[i][j];
    std::cout << "\n";
  }
}