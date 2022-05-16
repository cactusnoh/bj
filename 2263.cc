#include <iostream>

int N;
int inorder[100000], postorder[100000];
int idx[100001];

void solve(int beg_i, int end_i, int beg_p, int end_p)
{
  std::cout << postorder[end_p] << " ";

  int i = idx[postorder[end_p]];
  int left_len = i - beg_i, right_len = end_i - i;
  
  if(left_len)
    solve(beg_i, i - 1, beg_p, beg_p + left_len - 1);

  if(right_len)
    solve(i + 1, end_i, end_p - right_len, end_p - 1);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  for(int i = 0; i < N; ++i) {
    std::cin >> inorder[i];
    idx[inorder[i]] = i;
  }
  for(int i = 0; i < N; ++i)
    std::cin >> postorder[i];

  solve(0, N - 1, 0, N - 1);

  return 0;
}