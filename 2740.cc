#include <iostream>

int N, M, K;

int mat1[100][100], mat2[100][100], ans[100][100];

int main()
{
  std::cin >> N >> M;
  for(int r = 0; r < N; ++r)
    for(int c = 0; c < M; ++c)
      std::cin >> mat1[r][c];
  std::cin >> M >> K;
  for(int r = 0; r < M; ++r)
    for(int c = 0; c < K; ++c)
      std::cin >> mat2[r][c];
  
  for(int c = 0; c < K; ++c) 
    for(int r = 0; r < M; ++r) 
      for(int rp = 0; rp < N; ++rp) 
        ans[rp][c] += mat2[r][c] * mat1[rp][r];
  
  for(int r = 0; r < N; ++r) {
    for(int c = 0; c < K; ++c)
      std::cout << ans[r][c] << " ";
    std::cout << std::endl;
  }

  return 0;
}