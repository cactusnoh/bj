#include <iostream>
#include <queue>
#include <cstring>

typedef std::pair<int, int> pii;

int N, M;
int map[100][100];

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, 1, -1, 0};

bool outside[100][100];

int detectOut()
{
  int cnt = 1;

  std::queue<pii> Q;
  Q.push(pii(0, 0));
  outside[0][0] = true;

  while(!Q.empty()) {
    auto curr = Q.front(); Q.pop();
    for(int i = 0; i < 4; ++i) {
      int nr = curr.first + dr[i], nc = curr.second + dc[i];
      if(nr < 0 || nr >= N || nc < 0 || nc >= M || outside[nr][nc] || map[nr][nc] == 1) continue;
      Q.push(pii(nr, nc));
      outside[nr][nc] = true;
      ++cnt;
    }
  }
  return cnt;
}

std::queue<pii> Q;
void doCheese()
{
  int len = Q.size();
  while(len--) {
    int out_cnt = 0;
    auto curr = Q.front(); Q.pop();

    for(int i = 0; i < 4; ++i) {
      int nr = curr.first + dr[i], nc = curr.second + dc[i];
      if(outside[nr][nc])
        out_cnt++;
    }

    if(out_cnt >= 2)
      map[curr.first][curr.second] = 0;
    else
      Q.push(pii(curr.first, curr.second));
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> N >> M;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      std::cin >> map[i][j];
      Q.push(pii(i, j));
    }
  }

  int time = 0;
  while(1) {
    memset(outside, 0, sizeof(outside));
    if(detectOut() == N * M) break;
    doCheese();
    ++time;
  }

  std::cout << time << std::endl;

  return 0;
}