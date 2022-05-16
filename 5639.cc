#include <iostream>

struct Node {
  Node(int _key = -1) : key(_key) {}
  int key;
  Node *left = nullptr, *right = nullptr;
};

Node given[10000];
int N;
Node *root;

void construct(int beg, int end)
{ 
  bool foundSmall = false, foundBig = false;
  int small, big;

  for(small = beg + 1; small <= end; ++small) {
    if(given[small].key < given[beg].key) {
      foundSmall = true;
      break;
    }
  }

  for(big = beg + 1; big <= end; ++big) {
    if(given[big].key > given[beg].key) {
      foundBig = true;
      break;
    }
  }

  if(foundSmall) {
    given[beg].left = &given[small];
    construct(small, big - 1);
  }
  
  if(foundBig) {
    given[beg].right = &given[big];
    construct(big, end);
  }
}

void traversal(Node *n)
{
  if(n == nullptr)
    return;
  traversal(n->left);
  traversal(n->right);
  std::cout << n->key << "\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int val;
  while(std::cin >> val) {
    if(val == EOF) break;
    given[N++].key = val;
  }

  root = &given[0];
  construct(0, N - 1);

  traversal(root);
  
  return 0;
}