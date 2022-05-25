#include <iostream>

int N;

int seg_tree[4'000'010];

void update(size_t idx, int val, size_t tree_idx, size_t tr_beg, size_t tr_end)
{
  if(idx < tr_beg || idx > tr_end) {
    return;
  }

  if(tr_beg == tr_end) {
    seg_tree[tree_idx] += val;
    return;
  }

  size_t tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  size_t left_child = tree_idx << 1, right_child = left_child + 1;

  update(idx, val, left_child, tr_beg, tr_mid);
  update(idx, val, right_child, tr_mid + 1, tr_end);

  seg_tree[tree_idx] = seg_tree[left_child] + seg_tree[right_child];
}

size_t query(size_t tree_idx, size_t tr_beg, size_t tr_end, int q)
{
  if(tr_beg == tr_end) {
    return tr_beg;
  }

  size_t tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  size_t left_child = tree_idx << 1, right_child = left_child + 1;

  if(q > seg_tree[left_child]) {
    return query(right_child, tr_mid + 1, tr_end, q - seg_tree[left_child]);
  } else {
    return query(left_child, tr_beg, tr_mid, q);
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;

  int A, B, C;
  for(int i = 0; i < N; ++i) {
    std::cin >> A;
    if(A == 1) {
      std::cin >> B;
      C = query(1, 1, 1'000'000, B);
      update(C, -1, 1, 1, 1'000'000);
      std::cout << C << "\n";
    } else {
      std::cin >> B >> C;
      update(B, C, 1, 1, 1'000'000);
    }
  }

  return 0;
}