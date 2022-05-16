#include <iostream>

int X;
int memo[1000001], parent[1000001];

int solve(int x)
{
  if(memo[x] != -1)
    return memo[x];
  
  int min = 2147000000, argmin = -1;
  if(x % 3 == 0) {
    int temp = 1 + solve(x / 3);
    if(min > temp) {
      min = temp;
      argmin = x / 3;
    }
  }
  if(x % 2 == 0) {
    int temp = 1 + solve(x / 2);
    if(min > temp) {
      min = temp;
      argmin = x / 2;
    }
  }
  int temp = 1 + solve(x - 1);
  if(min > temp) {
    min = temp;
    argmin = x - 1;
  }

  memo[x] = min;
  parent[x] = argmin;
  return memo[x];
}

int main()
{
  std::cin >> X;

  for(int i = 0; i <= X; ++i)
    memo[i] = -1;
  
  memo[1] = 0;

  solve(X);
  std::cout << memo[X] << "\n";
  int curr = X;
  while(curr != 0) {
    std::cout << curr << " ";
    curr = parent[curr];
  }
  std::cout << "\n";

  return 0;
}