#include <iostream>
#include <cstring>

int N;
long long B;

int mat[5][5], ans[5][5];

void matMul(int (*mat1)[5], int (*mat2)[5])
{
  int res[5][5];
  memset(res, 0, sizeof(res));

  for(int c = 0; c < N; ++c) 
    for(int r = 0; r < N; ++r) 
      for(int rp = 0; rp < N; ++rp) 
        res[rp][c] = (res[rp][c] + mat2[r][c] * mat1[rp][r]) % 1000;

  for(int r = 0; r < N; ++r)
    for(int c = 0; c < N; ++c) 
      mat1[r][c] = res[r][c];
}

void matPow(long long b)
{
  for(int i = 0; i < N; ++i)
    ans[i][i] = 1;

  while(b > 0) {
    if(b & 1)
      matMul(ans, mat);
    matMul(mat, mat);
    b = b >> 1;
  }
}

int main()
{
  std::cin >> N >> B;
  for(int r = 0; r < N; ++r)
    for(int c = 0; c < N; ++c)
      std::cin >> mat[r][c];
  
  matPow(B);
  
  for(int r = 0; r < N; ++r) {
    for(int c = 0; c < N; ++c)
      std::cout << ans[r][c] << " ";
    std::cout << std::endl;
  }

  return 0;
}