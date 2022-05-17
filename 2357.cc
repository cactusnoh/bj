#include <iostream>
#include <utility>

typedef std::pair<int, int> pii; 

int min(int a, int b)
{
  return a < b ? a : b;
}

int max(int a, int b)
{
  return a < b ? b : a;
}

int N, M;
int seq[100'001];
std::pair<int, int> seg_tree[400'010];

void build_tree(size_t tree_idx, size_t tr_beg, size_t tr_end)
{
  if(tr_beg == tr_end) {
    seg_tree[tree_idx] = pii(seq[tr_beg], seq[tr_beg]);
    return;
  }

  int tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  int left_child = tree_idx << 1, right_child = left_child + 1;

  build_tree(left_child, tr_beg, tr_mid);
  build_tree(right_child, tr_mid + 1, tr_end);
  
  seg_tree[tree_idx] = pii(min(seg_tree[left_child].first, seg_tree[right_child].first), 
                           max(seg_tree[left_child].second, seg_tree[right_child].second));
}

void update_tree(size_t updated_idx, int val, size_t tree_idx, size_t tr_beg, size_t tr_end)
{
  if(updated_idx < tr_beg || updated_idx > tr_end) {
    return;
  }

  if(tr_beg == tr_end) {
    seg_tree[tree_idx] = pii(val, val);
    return;
  }

  int tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  int left_child = tree_idx << 1, right_child = left_child + 1;

  update_tree(updated_idx, val, left_child, tr_beg, tr_mid);
  update_tree(updated_idx, val, right_child, tr_mid + 1, tr_end);

  seg_tree[tree_idx] = pii(min(seg_tree[left_child].first, seg_tree[right_child].first), 
                           max(seg_tree[left_child].second, seg_tree[right_child].second));  
}

pii query(size_t tree_idx, size_t tr_beg, size_t tr_end, size_t qr_beg, size_t qr_end)
{
  if(qr_beg > tr_end || qr_end < tr_beg) {
    return pii(2147000000, 0);
  }

  if(qr_beg <= tr_beg && tr_end <= qr_end) {
    return seg_tree[tree_idx];
  }

  int tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  int left_child = tree_idx << 1, right_child = left_child + 1;

  pii left_query = query(left_child, tr_beg, tr_mid, qr_beg, qr_end);
  pii right_query = query(right_child, tr_mid + 1, tr_end, qr_beg, qr_end);

  return pii(min(left_query.first, right_query.first), 
             max(left_query.second, right_query.second));  
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N >> M;

  for(int i = 1; i <= N; ++i)
    std::cin >> seq[i];

  build_tree(1, 1, N);

  int a, b;
  for(int i = 0; i < M; ++i) {
    std::cin >> a >> b;
    pii result = query(1, 1, N, a, b);
    std::cout << result.first << " " << result.second << "\n";
  }

  return 0;
}