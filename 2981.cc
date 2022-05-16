#include <iostream>
#include <vector>
#include <algorithm>

int abs(int a)
{
  return a > 0 ? a : -a;
}

int N, numbers[100], subs[5050];

int main()
{
  std::cin >> N;

  for(int i = 0; i < N; ++i)
    std::cin >> numbers[i];
  
  int cnt = 0;
  for(int i = 0; i < N; ++i)
    for(int j = i + 1; j < N; ++j)
      subs[cnt++] = abs(numbers[i] - numbers[j]);
  
  int gcd = subs[0];
  for(int i = 1; i < cnt; ++i) {
    if(gcd >= subs[i]) {
      if(gcd % subs[i])
        gcd = gcd % subs[i];
      else
        gcd = subs[i];
    } else {
      if(subs[i] % gcd)
        gcd = subs[i] % gcd;
    }
  }

  std::vector<int> solution;

  for(int i = 1; i * i <= gcd; ++i) {
    if(gcd % i == 0) {
      solution.push_back(i);
      if(gcd/ i != i)
        solution.push_back(gcd / i);
    }
  }  
  
  std::sort(solution.begin(), solution.end());

  for(int i : solution)
    if(i != 1)
      std::cout << i << " ";

  return 0;
}