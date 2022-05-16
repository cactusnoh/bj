#include <iostream>

#define P 1'000'000'007

int N, M, K;
long long seq[1'000'001], seg_tree[4'000'001];

void build_tree(size_t tree_idx, size_t tr_beg, size_t tr_end)
{
  if(tr_beg == tr_end) {
    seg_tree[tree_idx] = seq[tr_beg];
    return;
  }

  size_t left_child = tree_idx << 1, right_child = left_child + 1;
  size_t tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);

  build_tree(left_child, tr_beg, tr_mid);
  build_tree(right_child, tr_mid + 1, tr_end);

  seg_tree[tree_idx] = (seg_tree[left_child] * seg_tree[right_child]) % P;
}

void update_tree(size_t updated_idx, long long val, size_t tree_idx, size_t tr_beg, size_t tr_end)
{
  if(updated_idx < tr_beg || updated_idx > tr_end) {
    return;
  }

  if(tr_beg == tr_end) {
    seg_tree[tree_idx] = val;
    return;
  }

  size_t left_child = tree_idx << 1, right_child = left_child + 1;
  size_t tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);

  update_tree(updated_idx, val, left_child, tr_beg, tr_mid);
  update_tree(updated_idx, val, right_child, tr_mid + 1, tr_end);

  seg_tree[tree_idx] = (seg_tree[left_child] * seg_tree[right_child]) % P;
}

long long query(size_t tree_idx, size_t tr_beg, size_t tr_end, size_t qr_beg, size_t qr_end)
{
  if(qr_beg > tr_end || qr_end < tr_beg) {
    return 1;
  }

  if(qr_beg <= tr_beg && tr_end <= qr_end) {
    return seg_tree[tree_idx];
  }

  size_t left_child = tree_idx << 1, right_child = left_child + 1;
  size_t tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);

  long long query_left = query(left_child, tr_beg, tr_mid, qr_beg, qr_end);
  long long query_right = query(right_child, tr_mid + 1, tr_end, qr_beg, qr_end);

  return (query_left * query_right) % P;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M >> K;

  for(int i = 1; i <= N; ++i) {
    std::cin >> seq[i];
  }

  build_tree(1, 1, N);

  int a, b;
  long long c;
  for(int i = 0; i < M + K; ++i) {
    std::cin >> a >> b >> c;
    if(a == 1) {
      update_tree(b, c, 1, 1, N);
    } else {
      std::cout << query(1, 1, N, b, c) << "\n";
    }
  }

  return 0;
}