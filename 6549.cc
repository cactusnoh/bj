#include <iostream>

inline long long max(long long a, long long b)
{
  return a < b ? b : a;
}

int N;
long long height[100'001];
int seg_tree[400'005];

int query(int tree_idx, int tr_begin, int tr_end, int qr_begin, int qr_end)
{
  if (tr_end < qr_begin || qr_end < tr_begin) {
    return -1;
  }

  if (qr_begin <= tr_begin && tr_end <= qr_end) {
    return seg_tree[tree_idx];
  }

  int tr_mid = tr_begin + ((tr_end - tr_begin) >> 1);
  int left_child = tree_idx << 1;
  int right_child = left_child + 1;

  int left_query = query(left_child, tr_begin, tr_mid, qr_begin, qr_end);
  int right_query = query(right_child, tr_mid + 1, tr_end, qr_begin, qr_end);

  if (left_query == -1 || right_query == -1) {
    return left_query == -1 ? right_query : left_query;
  }

  return height[left_query] < height[right_query] ? left_query : right_query;
}

void build_tree(int tree_idx, int tr_begin, int tr_end)
{
  if (tr_begin == tr_end) {
    seg_tree[tree_idx] = tr_begin;
    return;
  } else if (tr_begin > tr_end) {
    return;
  }

  int tr_mid = tr_begin + ((tr_end - tr_begin) >> 1);
  int left_child = tree_idx << 1;
  int right_child = left_child + 1;

  build_tree(left_child, tr_begin, tr_mid);
  build_tree(right_child, tr_mid + 1, tr_end);

  seg_tree[tree_idx] = 
      height[seg_tree[left_child]] < height[seg_tree[right_child]] ? seg_tree[left_child] : seg_tree[right_child];
}

long long solve(int begin, int end)
{
  if (begin == end) {
    return height[begin];
  } else if (begin > end) {
    return 0;
  }
  int min_index = query(1, 1, N, begin, end);
  long long ans = height[min_index] * (end - begin + 1);

  ans = max(ans, solve(begin, min_index - 1));
  ans = max(ans, solve(min_index + 1, end));

  return ans;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  while(1) {
    std::cin >> N;

    if(N == 0) {
      break;
    }

    for(int i = 1; i <= N; ++i) {
      std::cin >> height[i];
    }

    build_tree(1, 1, N);

    std::cout << solve(1, N) << "\n";
  }

  return 0;
}