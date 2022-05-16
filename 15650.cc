#include <iostream>

int N, M, arr[8];

void fcn(int used, int last, int sel)
{
  if(sel >= M) {
    for(int i = 0; i < M; ++i)
      std::cout << arr[i] << " ";
    std::cout << "\n";
    return;
  }

  for(int i = last + 1; i <= N; ++i) {
    if(used & (1 << i)) continue;
    arr[sel] = i;
    fcn(used | (1 << i), i, sel + 1);
  }

}

int main()
{
  std::cin >> N >> M;

  fcn(0, 0, 0);

  return 0;
}