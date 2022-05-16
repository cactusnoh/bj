#include <iostream>
#include <deque>

int row[9], col[9], seg[3][3];
int map[9][9];
std::deque<std::pair<int, int>> left;
bool complete = false;

void DFS()
{
  if(left.empty()) {
    complete = true;
    return;
  }

  auto p = left.front();
  left.pop_front();
  int r = p.first, c = p.second;

  for(int i = 1; i <= 9; ++i) {
    if((row[r] & (1 << i)) == 0 && (col[c] & (1 << i)) == 0 && (seg[r / 3][c / 3] & (1 << i)) == 0) {
      map[r][c] = i;
      row[r] |= (1 << i);
      col[c] |= (1 << i);
      seg[r / 3][c / 3] |= (1 << i);

      DFS();
      if(complete) return;

      map[r][c] = 0;
      row[r] ^= (1 << i);
      col[c] ^= (1 << i);
      seg[r / 3][c / 3] ^= (1 << i);
    }
  }

  left.push_front(p);
}

int main()
{
  for(int r = 0; r < 9; ++r) {
    for(int c = 0; c < 9; ++c) {
      std::cin >> map[r][c];
      if(map[r][c] == 0)
        left.push_back({r, c});
      row[r] |= (1 << map[r][c]);
      col[c] |= (1 << map[r][c]);
      seg[r / 3][c / 3] |= (1 << map[r][c]);
    }
  }

  DFS();

  for(int r = 0; r < 9; ++r) {
    for(int c = 0; c < 9; ++c)
      std::cout << map[r][c] << " ";
    std::cout << std::endl;
  }

  return 0;
}