#include <iostream>
#include <cstring>

#define INF 2147000000

// Available tile
#define UPPER 0
#define LOWER 1
#define ALL 2
#define NONE 3

inline int min(int a, int b) {
  return a < b ? a : b;
}

int T, N, W;
int rooms[10001][2];
int memo[10001][4];
int init_mode;

int solve(int section, int mode) {
  if (section == N) {
    return (mode == init_mode ? 0 : INF);
  }

  if (memo[section][mode] != -1) {
    return memo[section][mode];
  }

  int &ret = memo[section][mode];
  ret = INF;

  int next_section = (section + 1) % N;
  if (mode == UPPER) {
    if (rooms[section][0] + rooms[next_section][0] <= W) {
      ret = min(ret, 1 + solve(section + 1, LOWER));
    }
    ret = min(ret, 1 + solve(section + 1, ALL));
  } else if (mode == LOWER) {
    if (rooms[section][1] + rooms[next_section][1] <= W) {
      ret = min(ret, 1 + solve(section + 1, UPPER));
    }
    ret = min(ret, 1 + solve(section + 1, ALL));
  } else if (mode == ALL) {
    if (rooms[section][0] + rooms[section][1] <= W) {
      ret = min(ret, 1 + solve(section + 1, ALL));
    } else {
      ret = min(ret, 2 + solve(section + 1, ALL));
    }
    if (rooms[section][0] + rooms[next_section][0] <= W) {
      ret = min(ret, 2 + solve(section + 1, LOWER));
    }
    if (rooms[section][1] + rooms[next_section][1] <= W) {
      ret = min(ret, 2 + solve(section + 1, UPPER));
    }
    if (rooms[section][0] + rooms[next_section][0] <= W &&
        rooms[section][1] + rooms[next_section][1] <= W) {
      ret = min(ret, 2 + solve(section + 1, NONE));
    }
  } else {
    ret = solve(section + 1, ALL);
  }

  return ret;
}

int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    std::cin >> N >> W;
    for (int i = 0; i < N; ++i) {
      std::cin >> rooms[i][0];
    }
    for (int i = 0; i < N; ++i) {
      std::cin >> rooms[i][1];
    }

    int answer = INF;

    if (rooms[N - 1][1] + rooms[0][1] <= W) {
      memset(memo, -1, sizeof(memo));
      init_mode = UPPER;
      answer = min(answer, solve(0, UPPER));
    }

    if (rooms[N - 1][0] + rooms[0][0] <= W) {
      memset(memo, -1, sizeof(memo));
      init_mode = LOWER;
      answer = min(answer, solve(0, LOWER));
    }
    
    memset(memo, -1, sizeof(memo));
    init_mode = ALL;
    answer = min(answer, solve(0, ALL));

    if (rooms[N - 1][0] + rooms[0][0] <= W &&
        rooms[N - 1][1] + rooms[0][1] <= W) {
      memset(memo, -1, sizeof(memo));
      init_mode = NONE;
      answer = min(answer, solve(0, NONE));
    }

    std::cout << answer << "\n";
  }

  return 0;
}