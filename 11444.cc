#include <iostream>

#define P 1000000007

void matMul(long long (*mat1)[2], long long (*mat2)[2])
{
  int res[2][2] = {0, 0, 0, 0};
  for(int c = 0; c < 2; ++c)
    for(int r = 0; r < 2; ++r)
      for(int rp = 0; rp < 2; ++rp)
        res[rp][c] = (res[rp][c] + mat2[r][c] * mat1[rp][r]) % P;

  for(int r = 0; r < 2; ++r)
    for(int c = 0; c < 2; ++c)
      mat1[r][c] = res[r][c];
}

long long res[2][2] = {1, 0, 0, 1}, mat[2][2] = {1, 1, 1, 0};

void matPow(long long b)
{
  if(b < 0)
    return;
  while(b > 0) {
    if(b & 1)
      matMul(res, mat);
    matMul(mat, mat);
    b = b >> 1;
  }
}

int main()
{
  long long n;
  std::cin >> n;

  if(n == 0) {
    std::cout << 0 << std::endl;
    return 0;
  }
  
  matPow(n - 1);
  std::cout << (res[0][0]) % P << std::endl;

  return 0;
}