#include <iostream>

#define LOG 17

int N, M;
int parent[100'001][LOG + 1];
int height[100'001];

int get_height(int n)
{
  if(n == 1) {
    return 1;
  }

  int &ret = height[n];

  if(ret != 0) {
    return ret;
  }
  
  for(int i = LOG; i >= 0; --i) {
    if(parent[n][i] != 0) {
      ret = (1 << i) + get_height(parent[n][i]);
      break;
    }
  }

  return ret;
}

int LCA(int a, int b)
{
  if(get_height(a) > get_height(b)) {
    int temp = a;
    a = b;
    b = temp;
  }

  for(int j = LOG; j >= 0; --j) {
    if(get_height(parent[b][j]) >= get_height(a)) {
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

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;

  parent[1][0] = 1;

  int a, b;
  for(int i = 0; i < N - 1; ++i) {
    std::cin >> a >> b;

    if(parent[b][0] != 0) {
      int temp = a;
      a = b;
      b = temp;
    }
    
    parent[b][0] = a;
  }

  parent[1][0] = 0;

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