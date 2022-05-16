#include <iostream>

int N, M;
int seq[100'001], tree[262'144]; 

void init(int tree_idx, int start, int end)
{
  if(start == end) {
    tree[tree_idx] = start;
    return;
  }

  int left_child = (tree_idx << 1), right_child = (tree_idx << 1) + 1;
  init(left_child, start, (start + end) >> 1);
  init(right_child, ((start + end) >> 1) + 1, end);
  tree[tree_idx] = (seq[tree[left_child]] <= seq[tree[right_child]] ? tree[left_child] : tree[right_child]);
}

int query(int tree_idx, int start, int end, int left, int right)
{
  if(end < left || right < start) return -1;

  if(left <= start && end <= right) return tree[tree_idx];

  int left_query = query(tree_idx << 1, start, (start + end) >> 1, left, right);
  int right_query = query((tree_idx << 1) + 1, ((start + end) >> 1) + 1, end, left, right);

  if(left_query == -1 || right_query == -1)
    return (left_query == -1 ? right_query : left_query);
  else
    return (seq[left_query] <= seq[right_query] ? left_query : right_query); 
}

void update_tree(int updated_index, int tree_idx, int start, int end)
{
  if(updated_index < start || updated_index > end)
    return;
  if(start == end)
    return;
  int left_child = (tree_idx << 1), right_child = (tree_idx << 1) + 1;
  update_tree(updated_index, left_child, start, (start + end) >> 1);
  update_tree(updated_index, right_child, ((start + end) >> 1) + 1, end);
  tree[tree_idx] = (seq[tree[left_child]] <= seq[tree[right_child]] ? tree[left_child] : tree[right_child]);
}

void update(int index, int val)
{
  seq[index] = val;
  update_tree(index, 1, 1, N);
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> N;
  seq[0] = 2147000000;
  for(int i = 1; i <= N; ++i)
    std::cin >> seq[i];

  init(1, 1, N);
  
  std::cin >> M;
  int cmd, arg1, arg2;
  for(int i = 0; i < M; ++i) {
    std::cin >> cmd >> arg1 >> arg2;
    if(cmd == 1)
      update(arg1, arg2);
    else
      std::cout << query(1, 1, N, arg1, arg2) << "\n";
  }

  return 0;
}