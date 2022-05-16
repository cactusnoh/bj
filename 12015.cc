#include <iostream>

int binSearch(int seq[], int a, int b, int n)
{
  if(a >= b)
    return a;

  int middle = a + (b - a) / 2;
  if(seq[middle] <= n)
    return binSearch(seq, middle + 1, b, n);
  else
    return binSearch(seq, a, middle, n);
}

int N, seq[1000001], cnt;

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); std::cout.tie(NULL);

  std::cin >> N;
  for(int i = 1; i <= N; ++i) {
    int temp;
    std::cin >> temp;
    if(seq[cnt] < temp) {
      seq[++cnt] = temp;
      continue;
    }
    seq[binSearch(seq, 1, cnt, temp)] = temp;
  }
  std::cout << cnt << std::endl;

  return 0;
}