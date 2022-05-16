#include <iostream>

int N, M, num_truth, ans;

int parent[51], rank[51];
int party[50][50], partyCnt[50];

int findSet(int a)
{
  if(parent[a] != a)
    return parent[a] = findSet(parent[a]);
  return a;
}

void makeUnion(int a, int b)
{
  a = findSet(a);
  b = findSet(b);

  if(a != b) {
    if(rank[a] < rank[b]) {
      int temp = a;
      a = b;
      b = temp;
    }
    parent[b] = a;
    if(rank[a] == rank[b])
      ++rank[a];
  }
}

int main()
{
  std::cin >> N >> M;

  for(int i = 0; i <= N; ++i)
    parent[i] = i;
  rank[0] = 99;

  std::cin >> num_truth;
  for(int i = 0; i < num_truth; ++i) {
    int temp;
    std::cin >> temp;
    makeUnion(0, temp);
  }

  for(int i = 0; i < M; ++i) {
    int num, first;
    std::cin >> num >> first;
    party[i][partyCnt[i]++] = first;
    for(int j = 0; j < num - 1; ++j) {
      int temp;
      std::cin >> temp;
      party[i][partyCnt[i]++] = temp;
      makeUnion(first, temp);
    }
  }

  for(int i = 0; i < M; ++i) {
    bool canLie = true;
    for(int j = 0; j < partyCnt[i]; ++j) {
      if(findSet(party[i][j]) == 0) {
        canLie = false;
        break;
      }
    }
    if(canLie)
      ++ans;
  }

  std::cout << ans << std::endl;

  return 0;
}