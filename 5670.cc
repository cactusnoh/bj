#include <iostream>
#include <iomanip>
#include <vector>

struct TrieNode {
  ~TrieNode() {
    for (int i = 0; i < 26; ++i) {
      if (children[i] != nullptr) {
        delete children[i];
      }
    }
  }

  int child_cnt = 0;
  bool end = false;
  TrieNode *children[26] = {nullptr};
};

TrieNode *root;

int N;
int tot_cnt;

void DFS(TrieNode *curr, int cnt) {
  if (curr->end) {
    tot_cnt += cnt;
  }

  for (int i = 0; i < 26; ++i) {
    if (curr->children[i] != nullptr) {
      if (curr == root || curr->child_cnt > 1 || curr->end) {
        DFS(curr->children[i], cnt + 1);
      } else {
        DFS(curr->children[i], cnt);
      }
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  while (std::cin >> N) {
    tot_cnt = 0;
    root = new TrieNode();

    char in[81];
    for (int i = 0; i < N; ++i) {
      std::cin >> in;
      TrieNode *curr = root;
      for (int j = 0; in[j] != '\0'; ++j) {
        if (curr->children[in[j] - 'a'] == nullptr) {
          curr->child_cnt++;
          curr->children[in[j] - 'a'] = new TrieNode();
        }
        curr = curr->children[in[j] - 'a'];
      }
      curr->end = true;
    }

    DFS(root, 0);
    
    std::cout << std::fixed << std::setprecision(2) <<  (double) tot_cnt / N << "\n";

    delete root;
  }

  return 0;
}