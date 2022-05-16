#include <iostream>

inline int min(int a, int b)
{
  return a < b ? a : b;
}

int N, S;
int seq[100000];

int main() 
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> S;

  for(int i = 0; i < N; ++i)
    std::cin >> seq[i];

  int left = 0, right = 0, sum = seq[0];
  int minLen = 2147000000;
  while(right >= left && right < N) {
    if(sum >= S) {
      minLen = min(minLen, right - left + 1);
      sum -= seq[left++];
    } else
      sum += seq[++right];
  }
  
  if(minLen != 2147000000)
    std::cout << minLen << std::endl;
  else
    std::cout << 0 << std::endl;

  return 0;
}