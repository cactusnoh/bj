#include <iostream>
#include <cstring>

// States
#define NONE 0
#define UP 1
#define DOWN 2
#define BOTH 3
#define UP_DOWN 4

#define INF 2147000000

inline int max(int a, int b)
{
  return a < b ? b : a;
}

int T, N, W;
int people[2][10000];
int dp[10000][5][5];


int solve(int idx, int last, int curr)
{
  if(dp[idx][last][curr] != -1) {
    return dp[idx][last][curr];
  }

  int left_idx = (idx - 1 + N) % N;

  if(curr == UP) {
    if(people[0][idx] + people[0][left_idx] > W) {
      dp[idx][last][curr] = -INF;
      return -INF;
    }
  } else if(curr == DOWN) {
    if(people[1][idx] + people[1][left_idx] > W) {
      dp[idx][last][curr] = -INF;
      return -INF;
    }
  } else if(curr == BOTH) {
    if(people[0][idx] + people[0][left_idx] > W || 
       people[1][idx] + people[1][left_idx] > W) {
      dp[idx][last][curr] = -INF;
      return -INF;
    }
  } else if(curr == UP_DOWN) {
    if(people[0][idx] + people[1][idx] > W) {
      dp[idx][last][curr] = -INF;
      return -INF;
    }
  }

  if(idx == N - 1) {
    if(last != curr) {
      return -INF;
    }
    switch(curr) {
      case NONE:
      return 0;
      case UP: case DOWN: case UP_DOWN:
      return 1;
      case BOTH: 
      return 2;
    }
  }

  int ret = -INF;
  if(curr == NONE) {
    ret = max(ret, solve(idx + 1, last, NONE));
    ret = max(ret, solve(idx + 1, last, UP));
    ret = max(ret, solve(idx + 1, last, DOWN));
    ret = max(ret, solve(idx + 1, last, BOTH));
    ret = max(ret, solve(idx + 1, last, UP_DOWN));
  } else if(curr == UP) {
    ret = max(ret, 1 + solve(idx + 1, last, NONE));
    ret = max(ret, 1 + solve(idx + 1, last, DOWN));
    ret = max(ret, 1 + solve(idx + 1, last, UP_DOWN));
  } else if(curr == DOWN) {
    ret = max(ret, 1 + solve(idx + 1, last, NONE));
    ret = max(ret, 1 + solve(idx + 1, last, UP));
    ret = max(ret, 1 + solve(idx + 1, last, UP_DOWN));
  } else if(curr == BOTH) {
    ret = max(ret, 2 + solve(idx + 1, last, NONE));
    ret = max(ret, 2 + solve(idx + 1, last, UP_DOWN));
  } else if(curr == UP_DOWN) {
    ret = max(ret, 1 + solve(idx + 1, last, NONE));
    ret = max(ret, 1 + solve(idx + 1, last, UP_DOWN));
  }

  dp[idx][last][curr] = ret;

  return ret;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> T;

  for(int i = 0; i < T; ++i) {
    std::cin >> N >> W;

    memset(dp, -1, sizeof(dp));

    for(int j = 0; j < N; ++j) {
      std::cin >> people[0][j];
    }
    for(int j = 0; j < N; ++j) {
      std::cin >> people[1][j];
    }

    int ans = 0;
    ans = max(ans, solve(0, NONE, NONE));
    ans = max(ans, solve(0, NONE, UP));
    ans = max(ans, solve(0, NONE, DOWN));
    ans = max(ans, solve(0, NONE, BOTH));
    ans = max(ans, solve(0, NONE, UP_DOWN));

    ans = max(ans, solve(0, UP, NONE));
    ans = max(ans, solve(0, UP, DOWN));
    ans = max(ans, solve(0, UP, UP_DOWN));

    ans = max(ans, solve(0, DOWN, NONE));
    ans = max(ans, solve(0, DOWN, UP));
    ans = max(ans, solve(0, DOWN, UP_DOWN));

    ans = max(ans, solve(0, BOTH, NONE));
    ans = max(ans, solve(0, BOTH, UP_DOWN));

    ans = max(ans, solve(0, UP_DOWN, NONE));
    ans = max(ans, solve(0, UP_DOWN, UP_DOWN));

    std::cout << 2 * N - ans << "\n";
  }

  return 0;
}