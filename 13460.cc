#include <cstdio>
#include <iostream>

#define INF 2147000000
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef std::pair<int, int> pii;

int N, M, ans = INF;
char map[10][11];
pii blue, red, hole;

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
bool move(pii &n, int direction)
{
  int r = n.first, c = n.second;
  bool hole = false;

  while(1) {
    int nr = r + dr[direction], nc = c + dc[direction];
    if(nr < 0 || nr >= N || nc < 0 || nc >= M)
      break;
    if(map[nr][nc] != '.') {
      if(map[nr][nc] == 'O')
        hole = true;
      break;
    }
    r = nr; c = nc;
  }

  char temp = map[n.first][n.second];
  map[n.first][n.second] = '.';

  if(hole)
    return true;
    
  map[r][c] = temp;
  n.first = r; n.second = c;
  
  return false;
}

void DFS(int move_cnt)
{
  if(move_cnt >= 10)
    return;

  pii b_save = blue, r_save = red;
  bool r, b;
  // up
  if(blue.first > red.first) {
    r = move(red, UP);
    b = move(blue, UP);
  } else {
    b = move(blue, UP);
    r = move(red, UP);
  }
  if(r && !b) {
    if(move_cnt + 1 < ans)
      ans = move_cnt + 1;
    return;
  } else if(!r && !b) {
    DFS(move_cnt + 1);
  }
  map[red.first][red.second] = map[blue.first][blue.second] = '.';
  map[r_save.first][r_save.second] = 'R';
  map[b_save.first][b_save.second] = 'B';
  blue = b_save; red = r_save;
  // down
  if(blue.first > red.first) {
    b = move(blue, DOWN);
    r = move(red, DOWN);
  } else {
    r = move(red, DOWN);
    b = move(blue, DOWN);
  }
  if(r && !b) {
    if(move_cnt + 1 < ans)
      ans = move_cnt + 1;
    return;
  } else if(!r && !b) {
    DFS(move_cnt + 1);
  }
  map[red.first][red.second] = map[blue.first][blue.second] = '.';
  map[r_save.first][r_save.second] = 'R';
  map[b_save.first][b_save.second] = 'B';
  blue = b_save; red = r_save;
  // left
  if(blue.second < red.second) {
    b = move(blue, LEFT);
    r = move(red, LEFT);
  } else {
    r = move(red, LEFT);
    b = move(blue, LEFT);
  }
  if(r && !b) {
    if(move_cnt + 1 < ans)
      ans = move_cnt + 1;
    return;
  } else if(!r && !b) {
    DFS(move_cnt + 1);
  }
  map[red.first][red.second] = map[blue.first][blue.second] = '.';
  map[r_save.first][r_save.second] = 'R';
  map[b_save.first][b_save.second] = 'B';
  blue = b_save; red = r_save;
  // right
  if(blue.second > red.second) {
    b = move(blue, RIGHT);
    r = move(red, RIGHT);
  } else {
    r = move(red, RIGHT);
    b = move(blue, RIGHT);
  }
  if(r && !b) {
    if(move_cnt + 1 < ans)
      ans = move_cnt + 1;
    return;
  } else if(!r && !b) {
    DFS(move_cnt + 1);
  }
  map[red.first][red.second] = map[blue.first][blue.second] = '.';
  map[r_save.first][r_save.second] = 'R';
  map[b_save.first][b_save.second] = 'B';
  blue = b_save; red = r_save;
}

int main()
{
  std::cin >> N >> M;

  for(int i = 0; i < N; ++i)
    std::cin >> map[i];

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < M; ++j) {
      if(map[i][j] == 'B')
        blue = pii(i, j);
      if(map[i][j] == 'R')
        red = pii(i, j);
      if(map[i][j] == 'O')
        hole = pii(i, j);
    }
  }

  DFS(0);

  // for(int i = 0; i < N; ++i)
  //   std::cout << map[i] << "\n";

  std::cout << (ans == INF ? -1 : ans) << std::endl;

  return 0;
}