#include <iostream>
#include <vector>
#include <algorithm>

int N, M, K;
int parent[4'000'001];
std::vector<int> minsu = {};

int get_parent(int x)
{
  if(parent[x] == x)
    return x;
  return parent[x] = get_parent(parent[x]);
}

void unionize(int x, int y)
{
  x = get_parent(x);
  y = get_parent(y);

  parent[x] = y;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M >> K;

  int temp;
  for(int i = 0; i < M; ++i) {
    std::cin >> temp;
    minsu.push_back(temp);
    parent[i] = i;
  }
  std::sort(minsu.begin(), minsu.end());

  for(int i = 0; i < K; ++i) {
    std::cin >> temp;
    int to_show = get_parent(std::upper_bound(minsu.begin(), minsu.end(), temp) - minsu.begin());
    std::cout << minsu[to_show] << "\n";
    unionize(to_show, to_show + 1);
  }

  return 0;
}