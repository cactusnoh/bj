#include <iostream>
#include <queue>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

struct Pos {
  Pos(int r = 0, int c = 0) : r_(r), c_(c) {}
  int r_;
  int c_;
};

bool operator==(const Pos &lhs, const Pos &rhs) {
  return lhs.r_ == rhs.r_ && lhs.c_ == rhs.c_;
}
bool operator!=(const Pos &lhs, const Pos &rhs) {
  return !(lhs == rhs);
}

struct Entry {
  Entry(Pos p, int dir = 0) : p_(p), dir_(dir) {}
  Entry(int r = 0, int c = 0, int dir = 0) : p_(r, c), dir_(dir) {}
  Pos p_;
  int dir_;
};

int R, C;
char map[26][26];
char block[7] = {'|', '-', '+', '1', '2', '3', '4'};
Pos moscow, zagreb, broken(25, 25);

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool valid(Entry e) {
  Pos curr = e.p_;
  int dir = e.dir_;

  char curr_block = map[curr.r_][curr.c_];
  if (curr_block == '|') {
    return dir == UP || dir == DOWN;
  } else if (curr_block == '-') {
    return dir == LEFT || dir == RIGHT;
  } else if (curr_block == '+') {
    return true;
  } else if (curr_block == '1') {
    return dir == LEFT || dir == UP;
  } else if (curr_block == '2') {
    return dir == LEFT || dir == DOWN;
  } else if (curr_block == '3') {
    return dir == RIGHT || dir == DOWN;
  } else if (curr_block == '4') {
    return dir == RIGHT || dir == UP;
  }
  return false;
}

Entry next_entry(Entry e) {
  Pos curr = e.p_;
  int dir = e.dir_;
  char curr_block = map[curr.r_][curr.c_];
  if (curr_block == '|' || curr_block == '-' || curr_block == '+') {
    return Entry(curr.r_ + dr[dir], curr.c_ + dc[dir], dir);
  } else if (curr_block == '1') {
    if (dir == LEFT) {
      return Entry(curr.r_ + 1, curr.c_, DOWN);
    } else if (dir == UP) {
      return Entry(curr.r_, curr.c_ + 1, RIGHT);
    }
  } else if (curr_block == '2') {
    if (dir == LEFT) {
      return Entry(curr.r_ - 1, curr.c_, UP);
    } else if (dir == DOWN) {
      return Entry(curr.r_, curr.c_ + 1, RIGHT);
    }
  } else if (curr_block == '3') {
    if (dir == RIGHT) {
      return Entry(curr.r_ - 1, curr.c_, UP);
    } else if (dir == DOWN) {
      return Entry(curr.r_, curr.c_ - 1, LEFT);
    }
  } else if (curr_block == '4') {
    if (dir == RIGHT) {
      return Entry(curr.r_ + 1, curr.c_, DOWN);
    } else if (dir == UP) {
      return Entry(curr.r_, curr.c_ - 1, LEFT);
    }
  }
  return Entry(e.p_, -1);
}

Pos simulate(Pos start) {
  Entry curr = Entry(start, 0);

  // figure out block position next to starting position
  for (int dir = 0; dir < 4; ++dir) {
    int nr = start.r_ + dr[dir];
    int nc = start.c_ + dc[dir];
    if (0 <= nr && nr < R && 0 <= nc && nc < C &&
        map[nr][nc] != '.' && map[nr][nc] != 'Z' && Pos(nr, nc) != broken) {
      curr = Entry(nr, nc, dir);
    }
  }

  // simulate until we reach zagreb or invalid position
  while (curr.p_ != zagreb && valid(curr)) {
    curr = next_entry(curr);
  }
  return curr.p_;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  std::cin >> R >> C;
  for (int i = 0; i < R; ++i) {
    std::cin >> map[i];
  }

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (map[i][j] == 'M') {
        moscow = Pos(i, j);
      } else if (map[i][j] == 'Z') {
        zagreb = Pos(i, j);
      }
    }
  }

  broken = simulate(moscow); // figure out broken position
  std::cout << broken.r_ + 1 << " " << broken.c_ + 1 << " ";

  // try to fill a block in the broken position and simulate
  for (int i = 0; i < 7; ++i) {
    map[broken.r_][broken.c_] = block[i];
    auto dest = simulate(moscow);
    if (dest == zagreb) {
      std::cout << block[i] << "\n";
      break;
    }
  }

  return 0;
}