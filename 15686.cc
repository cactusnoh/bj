#include <iostream>

#define INF 2147000000

typedef std::pair<int, int> pii;

inline int abs(int a)
{
  return a < 0 ? -a : a;
}
inline int min(int a, int b)
{
  return a < b ? a : b;
}

int N, M;
int map[50][50];
pii houses[100]; int houseCnt;
pii chickens[13]; int chickenCnt;
bool selected[13];

int ans = INF;

void selectChickens(int tosee, int cnt)
{
  if(tosee == chickenCnt) {
    if(cnt != M) return;
    
    int dists[houseCnt];
    for(int i = 0; i < houseCnt; ++i)
      dists[i] = INF;
    
    for(int i = 0; i < chickenCnt; ++i) {
      if(!selected[i]) continue;
      for(int j = 0; j < houseCnt; ++j)
        dists[j] = min(dists[j], abs(houses[j].first - chickens[i].first) + abs(houses[j].second - chickens[i].second));
    }

    int sum = 0;
    for(int i = 0; i < houseCnt; ++i)
      sum += dists[i];

    if(sum < ans)
      ans = sum;

    return;
  }

  selected[tosee] = false;
  selectChickens(tosee + 1, cnt);
  selected[tosee] = true;
  selectChickens(tosee + 1, cnt + 1);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < N; ++j) {
      std::cin >> map[i][j];
      if(map[i][j] == 1)
        houses[houseCnt++] = pii(i, j);
      else if(map[i][j] == 2)
        chickens[chickenCnt++] = pii(i, j);
    }
  }

  selectChickens(0, 0);
  std::cout << ans << std::endl;

  return 0;
}