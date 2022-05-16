#include <iostream>

typedef std::pair<int, int> pii;

struct Point {
  Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
  int x, y;
};

bool operator<(const Point &lhs, const Point &rhs)
{
  return lhs.x == rhs.x ? lhs.y < rhs.y : lhs.x < rhs.x;
}
bool operator==(const Point &lhs, const Point &rhs)
{
  return lhs.x == rhs.x && lhs.y == rhs.y;
}
bool operator<=(const Point &lhs, const Point &rhs)
{
  return lhs < rhs || lhs == rhs;
}

struct Line {
  Line(Point _A = Point(), Point _B = Point()) : A(_A), B(_B) {}
  Point A, B;
};

int N;
Line lines[3000];

int ccw(const Point &a, const Point &b, const Point &c)
{
  int outer = ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
  return outer == 0 ? 0 : (outer < 0 ? -1 : 1);
}

bool intersect(Line &lhs, Line &rhs)
{
  int dir1 = ccw(lhs.A, lhs.B, rhs.A) * ccw(lhs.A, lhs.B, rhs.B),
      dir2 = ccw(rhs.A, rhs.B, lhs.A) * ccw(rhs.A, rhs.B, lhs.B);

  if(dir1 == 0 && dir2 == 0) {
    if(lhs.B < lhs.A) {
      Point temp = lhs.A;
      lhs.A = lhs.B;
      lhs.B = temp;
    }
    if(rhs.B < rhs.A) {
      Point temp = rhs.A;
      rhs.A = rhs.B;
      rhs.B = temp;
    }

    if(rhs.A <= lhs.B && lhs.A <= rhs.B)
      return true;
    else
      return false;
  } else if(dir1 <= 0 && dir2 <= 0)
    return true;
  else
    return false;
}

int parent[3000], rank[3000], cnt[3000];

int get_parent(int x)
{
  return parent[x] == x ? x : (parent[x] = get_parent(parent[x]));
}

void unionize(int x, int y)
{
  x = get_parent(x);
  y = get_parent(y);

  if(x == y)
    return;

  if(rank[x] > rank[y]) {
    int temp = x;
    x = y;
    y = x;
  }

  parent[x] = y;
  if(rank[x] == rank[y])
    ++rank[y];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    parent[i] = i;
    std::cin >> lines[i].A.x >> lines[i].A.y
             >> lines[i].B.x >> lines[i].B.y;
  }

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      if(intersect(lines[i], lines[j]))
        unionize(i, j);
    }
  }

  int num_groups = 0, max_cnt = 0;
  for(int i = 0; i < N; ++i) {
    int p = get_parent(i);
    if((cnt[p]++) == 0)
      ++num_groups;
    if(max_cnt < cnt[p])
      max_cnt = cnt[p];
  }
  
  std::cout << num_groups << "\n" << max_cnt << "\n";
  
}