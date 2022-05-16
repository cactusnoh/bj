#include <iostream>
#include <algorithm>

inline long long abs(long long a)
{
  return a < 0 ? -a : a;
}

int N;
long long seq[5000];
long long minDiff = 3'000'000'000;
int minLeft, minRight, minI;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cin >> seq[i];
  std::sort(seq, seq + N);

  for(int i = 0; i <= N - 3; ++i) {
    int left = i + 1, right = N - 1;
    while(right > left) {
      long long sum = seq[i] + seq[left] + seq[right];
      if(abs(sum) < minDiff) {
        minDiff = abs(sum);
        minLeft = left; minRight = right; minI = i;
      }
      
      if(sum > 0) --right;
      else if(sum < 0) ++left;
      else break;
    }
  }

  std::cout << seq[minI] << " " << seq[minLeft] << " " << seq[minRight] << std::endl;

  return 0;
}