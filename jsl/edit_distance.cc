#include <iostream>
#include <string>

typedef std::pair<int, int> pii;

inline int min(int a, int b)
{
  return a < b ? a : b;
}
inline int max(int a, int b)
{
  return a < b ? b : a;
}

std::string A, B;

int memo[100][100];
pii parent[100][100];

int solve(int i, int j)
{
  if(memo[i][j] != -1)
    return memo[i][j];
  if(i == A.length() && j == B.length())
    return 0;
  
  int ans = 2147000000;
  if(A[i] == B[j] && i < A.length() && j < B.length()) {
    if(ans > solve(i + 1, j + 1)) {
      ans = solve(i + 1, j + 1);
      parent[i][j] = pii(i + 1, j + 1);
    }
  }

  if(j < B.length()) {
    if(ans > solve(i, j + 1) + 1) {
      ans = solve(i, j + 1) + 1;
      parent[i][j] = pii(i, j + 1);
    }
  }

  if(i < A.length()) {
    if(ans > solve(i + 1, j) + 1) {
      ans = solve(i + 1, j) + 1;
      parent[i][j] = pii(i + 1, j);
    }
  }
  
  memo[i][j] = ans;
  return ans;
}

int main()
{
  std::cin >> A >> B;

  for(int i = 0; i <= A.length(); ++i)
    for(int j = 0; j <= B.length(); ++j)
      memo[i][j] = -1;

  std::cout << solve(0, 0) << "\n";

  pii curr(0, 0);
  while(curr.first != A.length() || curr.second != B.length()) {
    pii next = parent[curr.first][curr.second];
    if(next.first == curr.first) {
      std::cout << "Delete " << B[curr.second] << " from B\n";
    } else if(next.second == curr.second) {
      std::cout << "Delete " << A[curr.first] << " from A\n";
    } else {
      std::cout << "Same letter " << A[curr.first] << "\n"; 
    }
    curr = parent[curr.first][curr.second];
  }

  return 0;
}