#include <iostream>
#include <cstring>

int N, K;
char numbers[15][51];
int remainders[15], tenexp[51], len[15];
long long factorial[16];
long long memo[1 << 15][100];

long long gcd(long long a, long long b)
{
  while(b != 0) {
    long long temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  for(int i = 0; i < N; ++i) {
    std::cin >> numbers[i];
    len[i] = strlen(numbers[i]);
  }

  std::cin >> K;

  for(int i = 0; i < N; ++i) {
    for(int j = 0; numbers[i][j] != '\0'; ++j) {
      remainders[i] = (remainders[i] * 10 + (numbers[i][j] - '0')) % K;
    }
  }
  
  tenexp[0] = 1;
  for(int i = 1; i <= 50; ++i) {
    tenexp[i] = (tenexp[i - 1] * 10) % K;
  }

  factorial[0] = 1;
  for(int i = 1; i <= N; ++i) {
    factorial[i] = factorial[i - 1] * i;
  }

  
  memo[0][0] = 1;

  for(int seen = 0; seen < (1 << N); ++seen) {
    for(int remainder = 0; remainder < K; ++remainder) {
      for(int k = 0; k < N; ++k) {
        if((seen & (1 << k)) != 0) {
          continue;
        }
        int new_remainder = (remainder * tenexp[len[k]] + remainders[k]) % K;
        memo[seen | (1 << k)][new_remainder] += memo[seen][remainder];
      }
    }
  }

  long long ret = memo[(1 << N) - 1][0], GCD = gcd(ret, factorial[N]);

  std::cout << ret / GCD  << "/" << factorial[N] / GCD << std::endl;

  return 0;
}