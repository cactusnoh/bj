#include <iostream>

int N, M, K;
long long seq[1'000'001], tree[4'000'001];

void build_tree(int t_idx, int tr_beg, int tr_end)
{
  if(tr_beg == tr_end) {
    tree[t_idx] = seq[tr_beg];
    return;
  }

  int tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  int t_left = t_idx << 1, t_right = t_left + 1;
  build_tree(t_left, tr_beg, tr_mid);
  build_tree(t_right, tr_mid + 1, tr_end);
  tree[t_idx] = tree[t_left] + tree[t_right];
}

long long query(int t_idx, int tr_beg, int tr_end, int qr_beg, int qr_end)
{
  if(qr_beg > tr_end || qr_end < tr_beg)
    return 0;
    
  if(qr_beg <= tr_beg && tr_end <= qr_end)
    return tree[t_idx];
  
  int tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  int t_left = t_idx << 1, t_right = t_left + 1;
  long long query_left = query(t_left, tr_beg, tr_mid, qr_beg, qr_end);
  long long query_right = query(t_right, tr_mid + 1, tr_end, qr_beg, qr_end);
  return query_left + query_right;
}

void update_tree(int us_idx, long long val, int t_idx, int tr_beg, int tr_end)
{
  if(us_idx > tr_end || us_idx < tr_beg)
    return;
  
  if(tr_beg == tr_end) {
    tree[t_idx] = val;
    return;
  }

  int tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  int t_left = t_idx << 1, t_right = t_left + 1;
  update_tree(us_idx, val, t_left, tr_beg, tr_mid);
  update_tree(us_idx, val, t_right, tr_mid + 1, tr_end);
  tree[t_idx] = tree[t_left] + tree[t_right];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M >> K;

  for(int i = 1; i <= N; ++i)
    std::cin >> seq[i];
  build_tree(1, 1, N);
  
  long long a, b, c;
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