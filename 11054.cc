#include <iostream>

int N, seq[1000]; 
int memo_incr[1000], memo_decr[1000];

void solve_incr(int seen)
{
  int max = 0;
  for(int i = 0; i < seen; ++i)
    if(seq[i] < seq[seen] && max < memo_incr[i])
      max = memo_incr[i];
  memo_incr[seen] = max + 1;
}

void solve_decr(int seen)
{
  int max = 0;
  for(int i = seen + 1; i < N; ++i)
    if(seq[i] < seq[seen] && max < memo_decr[i])
      max = memo_decr[i];
  memo_decr[seen] = max + 1;
}

int main()
{
  std::cin >> N;
  for(int i = 0; i < N; ++i)
    std::cin >> seq[i];
  memo_incr[0] = 1;
  memo_decr[N - 1] = 1;

  for(int i = 1; i < N; ++i)
    solve_incr(i);
  for(int i = N - 2; i >= 0; --i)
    solve_decr(i); 

  int max = 0;  
  for(int i = 0; i < N; ++i)
    if(memo_decr[i] + memo_incr[i] > max)
      max = memo_decr[i] + memo_incr[i];
  std::cout << max - 1 << std::endl;
  
  return 0;
}