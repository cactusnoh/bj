#include <iostream>
#include <cstring>

int T, N, M;
int max_priority;
int seg_tree[800'008];
int priority[100'001];

void update(int update_idx, int val, int t_idx, int tr_beg, int tr_end) {
  if (update_idx < tr_beg || update_idx > tr_end) {
    return;
  }
  if (tr_beg == tr_end) {
    seg_tree[t_idx] = val;
    return;
  }

  int left_child = t_idx << 1, right_child = left_child + 1;
  int tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);

  update(update_idx, val, left_child, tr_beg, tr_mid);
  update(update_idx, val, right_child, tr_mid + 1, tr_end);

  seg_tree[t_idx] = seg_tree[left_child] + seg_tree[right_child];
}

int query(int t_idx, int tr_beg, int tr_end, int qr_beg, int qr_end) {
  if (qr_beg > tr_end || qr_end < tr_beg) {
    return 0;
  }
  if (qr_beg <= tr_beg && tr_end <= qr_end) {
    return seg_tree[t_idx];
  }

  int left_child = t_idx << 1, right_child = left_child + 1;
  int tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);

  int left_ret = query(left_child, tr_beg, tr_mid, qr_beg, qr_end);
  int right_ret = query(right_child, tr_mid + 1, tr_end, qr_beg, qr_end);

  return left_ret + right_ret;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    std::cin >> N >> M;
    max_priority = N;
    memset(seg_tree, 0, sizeof(seg_tree));

    for (int i = 1; i <= N; ++i) {
      priority[i] = N - i + 1;
      update(i, 1, 1, 1, N + 100'000);
    }

    for (int i = 0; i < M; ++i) {
      int title;
      std::cin >> title;
      std::cout << query(1, 1, N + 100'000, priority[title], N + 100'000) - 1 << " ";
      update(priority[title], 0, 1, 1, N + 100'000);
      priority[title] = ++max_priority;
      update(priority[title], 1, 1, 1, N + 100'000);
    }
    std::cout << "\n";
  }

  return 0;
}