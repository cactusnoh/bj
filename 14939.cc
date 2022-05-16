#include <iostream>

typedef std::pair<int, int> pii;

char map[10][10];
int num_on, ans = 2147000000;
int dr[5] = {-1, 0, 0, 1, 0}, dc[5] = {0, 1, -1, 0, 0};

void switch_light(int r, int c)
{
  for(int k = 0; k < 5; ++k) {
    int nr = r + dr[k], nc = c + dc[k];
    if(nr < 0 || nr >= 10 || nc < 0 || nc >= 10)
      continue;
    if(map[nr][nc] == '#') {
      ++num_on;
      map[nr][nc] = 'O';
    } else {
      --num_on;
      map[nr][nc] = '#';
    }
  }
}

void DFS(int c, int switched)
{
  if(c < 10) {
    DFS(c + 1, switched);
    switch_light(0, c);
    DFS(c + 1, switched + 1);
    switch_light(0, c);
    return;
  }

  pii clean_up[100]; int num_clean = 0;
  for(int r = 1; r < 10; ++r) {
    for(int c = 0; c < 10; ++c) {
      if(map[r - 1][c] == 'O') {
        switch_light(r, c);
        ++switched;
        clean_up[num_clean++] = pii(r, c);
      }
    }
  }

  if(num_on == 0 && switched < ans)
    ans = switched;

  for(int i = 0; i < num_clean; ++i)
    switch_light(clean_up[i].first, clean_up[i].second);
}

int main()
{
  for(int i = 0; i < 10; ++i) {
    for(int j = 0; j < 10; ++j) {
      std::cin >> map[i][j];
      if(map[i][j] == 'O')
        ++num_on;
    }
  }

  DFS(0, 0);

  std::cout << (ans == 2147000000 ? -1 : ans) << std::endl;
  
  return 0;
}