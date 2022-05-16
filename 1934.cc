#include <iostream>

void swap(int &A, int &B)
{
  if(A >= B) return;

  int temp = A;
  A = B;
  B = temp;
}

int T, A, B;

int solve()
{
  swap(A, B);

  while(A % B) {
    int temp = B;
    B = A % B;
    A = temp;
  }

  return B;
}

int main()
{
  std::cin >> T;

  for(int i = 0; i < T; ++i) {
    std::cin >> A >> B;
    std::cout << A * B / solve() << std::endl;
  }

  return 0;
}