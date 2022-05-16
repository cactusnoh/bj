#include <iostream>
#include <cstring>

#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

struct Shark {
  Shark(int _s = 0, int _v = 0, int _d = 0, int _r = 0, int _c = 0)
    : size(_s), velocity(_v), direction(_d), r(_r), c(_c) {}
  int size, velocity, direction;
  int r, c;
};

bool dead[10010];
Shark sharks[10010];
int map[101][101];
int R, C, M, ans;

void moveShark(int shark_no, int distance)
{
  if(distance == 0)
    return;
  Shark &s = sharks[shark_no];

  switch(s.direction) {
    case UP:
    distance %= (2 * R - 2);
    if(s.r - distance > 0)
      s.r = s.r - distance;
    else {
      distance = distance - (s.r - 1);
      s.r = 1;
      s.direction = DOWN;
      moveShark(shark_no, distance);
    }
    break;
    case DOWN:
    distance %= (2 * R - 2);
    if(s.r + distance <= R)
      s.r = s.r + distance;
    else {
      distance = distance - (R - s.r);
      s.r = R;
      s.direction = UP;
      moveShark(shark_no, distance);
    }
    break;
    case LEFT:
    distance %= (2 * C - 2);
    if(s.c - distance > 0)
      s.c = s.c - distance;
    else {
      distance = distance - (s.c - 1);
      s.c = 1;
      s.direction = RIGHT;
      moveShark(shark_no, distance);
    }
    break;
    case RIGHT:
    distance %= (2 * C - 2);
    if(s.c + distance <= C)
      s.c = s.c + distance;
    else {
      distance = distance - (C - s.c);
      s.c = C;
      s.direction = LEFT;
      moveShark(shark_no, distance);
    }
    break;
  }
}

void updateSharks()
{
  memset(map, 0, sizeof(map));
  for(int i = 1; i <= M; ++i) {
    if(dead[i]) 
      continue;

    moveShark(i, sharks[i].velocity);
    int r = sharks[i].r, c = sharks[i].c;

    if(map[r][c] != 0 && sharks[map[r][c]].size > sharks[i].size) {
      dead[i] = true;
      continue;
    } else if(map[r][c] != 0) {
      dead[map[r][c]] = true; 
    }
    map[r][c] = i;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> R >> C >> M;

  for(int i = 1; i <= M; ++i) {
    int r, c;
    std::cin >> r >> c 
             >> sharks[i].velocity >> sharks[i].direction >> sharks[i].size;
    sharks[i].r = r; sharks[i].c = c;
    map[r][c] = i;
  }

  for(int c = 1; c <= C; ++c) {
    int r;
    for(r = 1; r <= R; ++r)
      if(map[r][c])
        break;
    if(r <= R) {
      dead[map[r][c]] = true;
      ans += sharks[map[r][c]].size;
      map[r][c] = 0;
    }
    updateSharks();
  }

  std::cout << ans << std::endl;

  return 0;
}