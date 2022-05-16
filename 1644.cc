#include <iostream>
#include <vector>

bool isPrime[4000001];
int N;
std::vector<int> primes;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  for(int i = 2; i <= N; ++i)
    isPrime[i] = true;
  for(int i = 2; i <= N; ++i) {
    if(!isPrime[i]) continue;
    for(int j = 2 * i; j <= N; j += i)
      isPrime[j] = false;
  }
  for(int i = 2; i <= N; ++i)
    if(isPrime[i])
      primes.push_back(i);

  if(primes.size() == 0) {
    std::cout << 0 << std::endl;
    return 0;
  }

  int cnt = 0, left = 0, right = 0;
  long long sum = primes[0];
  while(left <= right && right < primes.size()) {
    if(sum == N)
      ++cnt;

    if(sum <= N && right < primes.size() - 1)
      sum += primes[++right];
    else if(sum <= N)
      break;
    else
      sum -= primes[left++];
  }

  std::cout << cnt << std::endl;

  return 0;
}