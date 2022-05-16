#include <iostream>
#include <cstring>

#define INF 2147000000

inline int min(int a, int b)
{
  return a < b ? a : b;
}

char A[2501];
int memo[2501];
bool isPalindrome[2501][2501];

int solve(int end)
{
  if(end < 0)
    return 0;
  if(memo[end] != -1)
    return memo[end];

  memo[end] = 2147000000;
  for(int i = 0; i <= end; ++i)
    if(isPalindrome[i][end])
      memo[end] = min(memo[end], solve(i - 1) + 1);
  return memo[end];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  for(int i = 0; i <= 2500; ++i)
    memo[i] = -1;

  std::cin >> A;

  // length 1
  for(int i = 0; i < strlen(A); ++i)
    isPalindrome[i][i] = true;
  // length 2
  for(int i = 0; i < strlen(A) - 1; ++i)
    if(A[i] == A[i + 1])
      isPalindrome[i][i + 1] = true;
  // length longer than 2
  for(int len = 3; len <= strlen(A); ++len) {
    for(int start = 0; start <= strlen(A) - len; ++start) {
      int end = start + len - 1;
      isPalindrome[start][end] = (A[start] == A[end] ? isPalindrome[start + 1][end - 1] : false);
    }
  }

  std::cout << solve(strlen(A) - 1) << '\n';

  return 0;
}