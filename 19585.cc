#include <iostream>
#include <string>
#include <unordered_set>

struct TrieNode {
  ~TrieNode() {
    for (int i = 0; i < 26; ++i) {
      if (child[i] != nullptr) {
        delete child[i];
      }
    }
  }
  bool word_exists = false;
  TrieNode *child[26] = {nullptr};
};

int C, N, Q;
TrieNode *color_root;
std::unordered_set<std::string> nicknames;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  color_root = new TrieNode();

  std::cin >> C >> N;

  std::string s;
  for (int i = 0; i < C; ++i) {
    std::cin >> s;
    TrieNode *curr = color_root;
    for (int i = 0; i < s.size(); ++i) {
      if (curr->child[s[i] - 'a'] == nullptr) {
        curr->child[s[i] - 'a'] = new TrieNode();
      }
      curr = curr->child[s[i] - 'a'];
    }
    curr->word_exists = true;
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> s;
    nicknames.emplace(s);    
  }

  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    std::cin >> s;
    bool found = false;

    TrieNode *curr = color_root;
    for (int j = 0; j < s.size(); ++j) {
      if (curr->child[s[j] - 'a'] == nullptr) {
        break;
      }
      curr = curr->child[s[j] - 'a'];
      if (curr->word_exists &&
          nicknames.find(s.substr(j + 1)) != nicknames.end()) {
        found = true;
        break;
      }
    }

    if (found) {
      std::cout << "Yes" << "\n";
    } else {
      std::cout << "No" << "\n";
    }
  }

  //delete color_root;

  return 0;
}