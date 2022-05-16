#include <iostream>
#include <vector>

int N;
int seq[1000001], memo[1000001], parent[1000001], IndexSeq[1000001];

// get upperbound
int binSearch(int arr[], int beg, int end, int target)
{
  if(beg > end)
    return beg;

  int mid = beg + (end - beg) / 2;

  if(arr[mid] < target) {
    return binSearch(arr, mid + 1, end, target);
  } else {  // arr[mid] > target || arr[mid] == target
    return binSearch(arr, beg, mid - 1, target);
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  for(int i = 1; i <= N; ++i)
    std::cin >> seq[i];
  memo[0] = -2147000000;
  
  int ans = 0;
  for(int i = 1; i <= N; ++i) {
    if(memo[ans] < seq[i]) {
      parent[i] = IndexSeq[ans];
      memo[++ans] = seq[i];
      IndexSeq[ans] = i;
      continue;
    }
    
    int idx = binSearch(memo, 1, ans, seq[i]);
    parent[i] = IndexSeq[idx - 1];
    memo[idx] = seq[i];
    IndexSeq[idx] = i;
  }
  std::cout << ans << "\n";

  std::vector<int> parents;
  int curr = IndexSeq[ans];
  while(curr != 0) {
    parents.push_back(seq[curr]);
    curr = parent[curr];
  }

  for(int i = parents.size() - 1; i >= 0; --i)
    std::cout << parents[i] << " ";
  std::cout << "\n";

  return 0;
}