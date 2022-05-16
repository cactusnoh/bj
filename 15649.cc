#include <iostream>

int N, M, arr[8];

void fcn(int used, int sel)
{
  if(sel >= M) {
    for(int i = 0; i < M; ++i)
      std::cout << arr[i] << " ";
    std::cout << "\n";
    return;
  }

  for(int i = 0; i < N; ++i) {
    if(used & (1 << i)) continue;
    arr[sel] = i + 1;
    fcn(used | (1 << i), sel + 1);
  }

}

int main()
{
  std::cin >> N >> M;

  fcn(0, 0);

  return 0;
}