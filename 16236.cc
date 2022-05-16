#include <iostream>
#include <queue>

#define INF 2147000000

typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

int N;

int shark_size = 2;
int curr_eaten;

int shark_r, shark_c;
int map[20][20];
int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, -1, 1, 0};

int curr_time;

bool BFS()
{
  bool visited[20][20] = {0};
  std::priority_queue<piii, std::vector<piii>, std::greater<piii>> Q;

  Q.push(piii(0, pii(shark_r, shark_c))); 
  visited[shark_r][shark_c] = true;

  while(!Q.empty()) {
    auto curr = Q.top(); Q.pop();
    int r = curr.second.first, c = curr.second.second;

    if(map[r][c] != 9 && map[r][c] != 0 && map[r][c] < shark_size) {
      if(++curr_eaten == shark_size) {
        curr_eaten = 0;
        ++shark_size;
      }
      map[r][c] = 0;

      map[shark_r][shark_c] = 0;
      shark_r = r; shark_c = c;

      curr_time += curr.first;
      return true;
    } 

    for(int i = 0; i < 4; ++i) {
      int nr = curr.second.first + dr[i], nc = curr.second.second + dc[i];
      if(nr < 0 || nr >= N || nc < 0 || nc >= N || 
         map[nr][nc] > shark_size || visited[nr][nc]) continue;
      visited[nr][nc] = true;
      Q.push(piii(curr.first + 1, pii(nr, nc)));
    }
  }

  return false;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  int val;
  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      std::cin >> val;
      map[i][j] = val;
      if(val == 9) {
        shark_r = i;
        shark_c = j;
      }
    }
  }

  while(BFS());

  std::cout << curr_time << std::endl;

  return 0;
}