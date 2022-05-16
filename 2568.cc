#include <iostream>
#include <algorithm>

typedef std::pair<int, int> pii;

int N, LIS[100001], LIS2seq_idx[100001];
pii seq[100001]; int parent[100001];
bool exist[100001];

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> N;

  for(int i = 1; i <= N; ++i)
    std::cin >> seq[i].first >> seq[i].second;

  std::sort(seq + 1, seq + N + 1);

  int LIS_size = 0;
  LIS2seq_idx[0] = 0;
  parent[0] = 0;

  for(int i = 1; i <= N; ++i) {
    int *p = std::upper_bound(LIS + 1, LIS + LIS_size + 1, seq[i].second);
    if(p == LIS + LIS_size + 1) {
      parent[i] = LIS2seq_idx[LIS_size];
      LIS2seq_idx[++LIS_size] = i;
      LIS[LIS_size] = seq[i].second;
    } else {
      parent[i] = LIS2seq_idx[p - LIS - 1];
      LIS2seq_idx[p - LIS] = i;
      *p = seq[i].second;
    }
  }

  std::cout << N - LIS_size << std::endl;

  int curr = LIS2seq_idx[LIS_size];
  while(curr) {
    exist[curr] = true;
    curr = parent[curr];
  }
  
  for(int i = 1; i <= N; ++i)
    if(!exist[i])
      std::cout << seq[i].first << "\n";
    
  return 0;
}