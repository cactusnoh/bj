#include <iostream>

typedef std::pair<int, int> Point;
typedef std::pair<int, int> pii;

inline int max(int a, int b)
{
  return a < b ? b : a;
}
inline int abs(int a)
{
  return a < 0 ? -a : a;
}
inline int get_dist(const Point &lhs, const Point &rhs)
{
  return abs(lhs.first - rhs.first) + abs(lhs.second - rhs.second);
}

int N, W;
Point to_go[1001];

int memo[1001][1001];
pii parent[1001][1001];

int solve(int n, int m)
{
  if(n >= W || m >= W) {
    return 0;
  }

  int &ret = memo[n][m];

  if(ret != -1) {
    return ret;
  }

  int next = max(n, m) + 1;
  int cand_1 = solve(next, m);
  int cand_2 = solve(n, next);
  
  if(n == 0) {
    cand_1 += get_dist(Point(1, 1), to_go[next]);
  } else {
    cand_1 += get_dist(to_go[n], to_go[next]);
  }

  if(m == 0) {
    cand_2 += get_dist(Point(N, N), to_go[next]);
  } else {
    cand_2 += get_dist(to_go[m], to_go[next]);
  }

  if(cand_1 > cand_2) {
    ret = cand_2;
    parent[n][m] = pii(n, next);
  } else {
    ret = cand_1;
    parent[n][m] = pii(next, m);
  }

  return ret;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> W;

  for(int i = 0; i < W; ++i) {
    for(int j = 0; j < W; ++j) {
      memo[i][j] = -1;
    }
  }

  for(int i = 1; i <= W; ++i) {
    std::cin >> to_go[i].first >> to_go[i].second;
  }

  std::cout << solve(0, 0) << "\n";

  int n = 0, m = 0;
  for(int i = 0; i < W; ++i) {
    pii &temp = parent[n][m];
    if(temp.first == n) {
      std::cout << 2 << "\n";
    } else {
      std::cout << 1 << "\n";
    }
    n = temp.first;
    m = temp.second;
  }

  return 0;
}