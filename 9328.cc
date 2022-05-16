#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <list>

typedef std::pair<int, int> pii;

int T, W, H;
char map[101][101];
bool canOpen[26], visited[101][101];

int dr[4] = {-1, 0, 0, 1}, dc[4] = {0, 1, -1, 0}, ans;
std::queue<pii> Q, locked[2]; 
//std::vector<pii> locked;

void dealPoint(int nr, int nc)
{
  if(nr < 0 || nr >= H || nc < 0 || nc >= W || visited[nr][nc] || map[nr][nc] == '*')
    return;
  if(map[nr][nc] == '$') {
    map[nr][nc] = '.';
    Q.push(pii(nr, nc));
    visited[nr][nc] = true;
    ++ans;
  } else if(map[nr][nc] == '.') {
    Q.push(pii(nr, nc));
    visited[nr][nc] = true;
  } else if('a' <= map[nr][nc] && map[nr][nc] <= 'z') {
    Q.push(pii(nr, nc));
    visited[nr][nc] = true;
    canOpen[map[nr][nc] - 'a'] = true;
  } else if('A' <= map[nr][nc] && map[nr][nc] <= 'Z' && canOpen[map[nr][nc] - 'A']){
    Q.push(pii(nr, nc));
    visited[nr][nc] = true;
  } else if('A' <= map[nr][nc] && map[nr][nc] <= 'Z') {
    locked.push_back(pii(nr, nc));
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::string keys;
  std::cin >> T;
  for(int tc = 0; tc < T; ++tc) { 
    ans = 0;
    memset(canOpen, 0, sizeof(canOpen));
    memset(visited, 0, sizeof(visited));
    locked = {};

    std::cin >> H >> W;
    for(int i = 0; i < H; ++i)
      std::cin >> map[i];
    std::cin >> keys;
    if(keys[0] != '0') {
      for(int i = 0; i < keys.length(); ++i)
        canOpen[keys[i] - 'a'] = true;
    }

    for(int i = 0; i < H; ++i) {
      dealPoint(i, 0);
      dealPoint(i, W - 1);
    }
    for(int j = 0; j < W; ++j) {
      dealPoint(0, j);
      dealPoint(H - 1, j);
    }

    while(1) {
      while(!Q.empty()) {
        int r = Q.front().first, c = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; ++i)
          dealPoint(r + dr[i], c + dc[i]);
      }

      for(int i = 0; i < locked.size(); ++i) {
        auto door = locked[i];
        if(!canOpen[map[door.first][door.second] - 'A'] || visited[door.first][door.second])
          continue;
        Q.push(door);
        visited[door.first][door.second] = true;
      }

      if(Q.empty())
        break;
    }
    std::cout << ans << std::endl;
  }
  return 0;
}