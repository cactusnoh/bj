#include <iostream>

int a, b, c;
int memo[21][21][21];

int w(int a, int b, int c)
{
  if(a <= 0 || b <= 0 || c <= 0)
    return 1;
  if(a > 20 || b > 20 || c > 20)
    return w(20, 20, 20);

  if(memo[a][b][c] != -1)
    return memo[a][b][c];
  
  memo[a][b][c] = (a < b && b < c ? w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c)
                                  : w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1));

  return memo[a][b][c];
}

int main()
{
  for(int i = 0; i < 21; ++i)
    for(int j = 0; j < 21; ++j)
      for(int k = 0; k < 21; ++k)
        memo[i][j][k] = -1;

  std::cin >> a >> b >> c;
  while(a != -1 || b != -1 || c != -1) {
    std::cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << std::endl;
    std::cin >> a >> b >> c;
  }

  return 0;
}