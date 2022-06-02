#include <iostream>

// Merge sort implementation
int N;

int col1[500'000];
int col2[1'000'000];
int seq[500'000];

int left[250'001], right[250'001];

long long ans;

void merge_sort(size_t beg, size_t end)
{
  if(beg >= end) {
    return;
  }

  size_t mid = beg + ((end - beg) >> 1);

  merge_sort(beg, mid);
  merge_sort(mid + 1, end);

  size_t left_size = mid - beg + 1, right_size = end - mid;
  size_t left_cur = 0, right_cur = 0, orig_cur = beg;

  for(size_t i = 0; i < left_size; ++i) {
    left[i] = seq[beg + i];
  }

  for(size_t i = 0; i < right_size; ++i) {
    right[i] = seq[mid + 1 + i];
  }

  while(left_cur < left_size && right_cur < right_size) {
    if(left[left_cur] > right[right_cur]) {
      seq[orig_cur++] = right[right_cur++];
      ans += (left_size) - left_cur;
    } else {
      seq[orig_cur++] = left[left_cur++];
    }
  }

  while(left_cur < left_size) {
    seq[orig_cur++] = left[left_cur++];
  }

  while(right_cur < right_size) {
    seq[orig_cur++] = right[right_cur++];
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;

  int temp;
  for(int i = 0; i < N; ++i) {
    std::cin >> col1[i];
  }

  for(int i = 0; i < N; ++i) {
    std::cin >> temp;
    col2[temp] = i;
  }

  for(int i = 0; i < N; ++i) {
    seq[col2[col1[i]]] = i;
  }

  merge_sort(0, N - 1);

  std::cout << ans << std::endl;

  return 0;
}

// Segment tree implementation
/*
int N;
int row_1[500'001];
int row_2[1'000'001];

long long seg_tree[2'000'004];
long long ans;

long long query(size_t tree_idx, size_t tr_beg, size_t tr_end, size_t qr_beg, size_t qr_end)
{ 
  if(tr_end < qr_beg || qr_end < tr_beg) {
    return 0;
  }

  if(qr_beg <= tr_beg && tr_end <= qr_end) {
    return seg_tree[tree_idx];
  }

  size_t tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  size_t left_child = tree_idx << 1, right_child = left_child + 1;

  return query(left_child, tr_beg, tr_mid, qr_beg, qr_end) + query(right_child, tr_mid + 1, tr_end, qr_beg, qr_end);
}

void update(long long dv, size_t idx, size_t tree_idx, size_t tr_beg, size_t tr_end)
{
  if(idx < tr_beg || idx > tr_end) {
    return;
  }

  if(tr_beg == tr_end) {
    seg_tree[tree_idx] += dv;
    return;
  }

  size_t tr_mid = tr_beg + ((tr_end - tr_beg) >> 1);
  size_t left_child = tree_idx << 1, right_child = left_child + 1;
  
  update(dv, idx, left_child, tr_beg, tr_mid);
  update(dv, idx, right_child, tr_mid + 1, tr_end);

  seg_tree[tree_idx] = seg_tree[left_child] + seg_tree[right_child];

  return;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> N;

  for(int i = 1; i <= N; ++i) {
    std::cin >> row_1[i];
  }

  int temp;
  for(int i = 1; i <= N; ++i) {
    std::cin >> temp;
    row_2[temp] = i;
  }

  for(int i = 1; i <= N; ++i) {
    ans += query(1, 1, N, row_2[row_1[i]], N);
    update(1, row_2[row_1[i]], 1, 1, N);
  }

  std::cout << ans << std::endl;

  return 0;
}
*/