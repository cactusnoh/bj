#include <iostream>
#include <string>

typedef std::pair<int, int> pii;

std::string A, B;
int memo[1001][1001];
pii parent[1001][1001];

int solve(int i, int j)
{
  if(i < 0 || j < 0) 
    return 0;
  if(memo[i][j] != -1)
    return memo[i][j];

  if(A[i] == B[j]) {
    memo[i][j] = 1 + solve(i - 1, j - 1);
    parent[i][j] = pii(i - 1, j - 1);
  } else if(solve(i - 1, j) > solve(i, j - 1)) {
    memo[i][j] = solve(i - 1, j);
    parent[i][j] = pii(i - 1, j);
  } else {
    memo[i][j] = solve(i, j - 1);
    parent[i][j] = pii(i, j - 1);
  }

  return memo[i][j];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> A >> B;

  for(int i = 0; i < A.length(); ++i)
    for(int j = 0; j < B.length(); ++j)
      memo[i][j] = -1;

  int ans = solve(A.length() - 1, B.length() - 1);

  std::string ansStr;
  pii curr(A.length() - 1, B.length() - 1);
  while(curr.first >= 0 && curr.second >= 0) {
    pii next = parent[curr.first][curr.second];
    if(curr.first + curr.second - next.first - next.second == 2)
      ansStr.push_back(A[curr.first]);
    curr = next;
  }

  std::cout << ans << "\n";
  for(int i = ansStr.length(); i --> 0;)
    std::cout << ansStr[i];
  std::cout << "\n";

  return 0;
}