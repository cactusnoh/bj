#include <iostream>
#include <vector>

#define LOG 17

int N, M;
int parent[100'001][LOG + 1];
std::vector<int> adj_list[100'001];
int height[100'001];

int LCA(int a, int b)
{
  if(height[a] > height[b]) {
    int temp = a;
    a = b;
    b = temp;
  }

  for(int j = LOG; j >= 0; --j) {
    if(height[parent[b][j]] >= height[a]) {
      b = parent[b][j];
    }
  }

  if(a == b)
    return a;

  for(int j = LOG; j >= 0; --j) {
    if(parent[a][j] != parent[b][j]) {
      a = parent[a][j];
      b = parent[b][j];
    }
  }

  return parent[a][0];
}

void build_tree(int n)
{

  for(size_t i = 0; i < adj_list[n].size(); ++i) {
    int next = adj_list[n][i];

    if(parent[n][0] == next) {
      continue;
    }

    parent[next][0] = n;
    height[next] = height[n] + 1;
    build_tree(next);
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;

  int a, b;
  for(int i = 0; i < N - 1; ++i) {
    std::cin >> a >> b;
    adj_list[a].push_back(b);
    adj_list[b].push_back(a);
  }

  height[1] = 1;
  build_tree(1);

  for(int j = 1; j < LOG + 1; ++j) {
    for(int i = 1; i <= N; ++i) {
      parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
  }

  std::cin >> M;
  
  for(int i = 0; i < M; ++i) {
    std::cin >> a >> b;
    std::cout << LCA(a, b) << "\n";
  }

  return 0;
}