#include <iostream>
#include <utility>
#include <cmath>
#include <iomanip>

typedef std::pair<int, int> pii;

inline double magnitude(const pii &p)
{
  return sqrt((double) p.first * p.first + (double) p.second * p.second);
}

int T, N;
pii points[20], sum;
int plus, minus;
double ans;

void solve(int seen)
{
  if(seen == N) {
    double temp = magnitude(sum);
    if(temp < ans)
      ans = temp;
    return;
  }

  if(plus < N / 2) {
    sum.first += points[seen].first;
    sum.second += points[seen].second;
    plus += 1;
    solve(seen + 1);
    plus -= 1;
    sum.first -= points[seen].first;
    sum.second -= points[seen].second;
  }

  if(minus < N / 2) {
    sum.first -= points[seen].first;
    sum.second -= points[seen].second;
    minus += 1;
    solve(seen + 1);
    minus -= 1;
    sum.first += points[seen].first;
    sum.second += points[seen].second;
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> T;

  for(int tc = 0; tc < T; ++tc) {
    sum = pii(0, 0);
    ans = 2147000000.0;
    std::cin >> N;
    for(int i = 0; i < N; ++i)
      std::cin >> points[i].first >> points[i].second;
    solve(0);
    std::cout << std::fixed << std::setprecision(6) << ans << "\n";
  }

  return 0;
}