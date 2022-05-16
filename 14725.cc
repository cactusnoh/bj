#include <cstring>
#include <cstdio>

#define STRING_LEN 15

struct Node {
  char key[STRING_LEN + 1] = "";
  Node *child = nullptr, *next = nullptr, *prev = nullptr;
};

int N;
Node *root;

void printHyphen(int n)
{
  for(int i = 0; i < n; ++i)
    putchar('-');
}

void DFS(Node *n, int level)
{
  if(n == nullptr) return;

  if(n != root) {
    printHyphen(2 * level);
    printf("%s\n", n->key);
  }
  Node *curr = n->child;
  while(curr) {
    DFS(curr, level + 1);
    curr = curr->next;
  }
}

void freeTree(Node *n)
{
  Node *curr = n->child;
  while(curr) {
    Node *next = curr->next;
    freeTree(curr);
    curr = next;
  }
  delete n;
}

char target[16];

int main()
{
  root = new Node();

  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    Node *curr = root;
    int K;
    scanf("%d", &K);
    for(int j = 0; j < K; ++j) {
      bool found = false;
      scanf("%s", target);

      if(curr->child == nullptr) {
        Node *new_node = new Node();
        strcpy(new_node->key, target);
        curr->child = new_node;
        curr = new_node;
        continue;
      }

      Node *temp = curr->child, *pre_temp;
      while(temp) {
        int cmp_res = strcmp(temp->key, target);
        if(cmp_res < 0) {
          pre_temp = temp;
          temp = temp->next;
        } else if(cmp_res == 0) {
          found = true;
          curr = temp;
          break;
        } else {
          break;
        }
      }
      if(found) continue;

      Node *new_node = new Node();
      strcpy(new_node->key, target);

      if(temp == nullptr) {
        pre_temp->next = new_node;
        new_node->prev = pre_temp;
      } else {
        if(temp->prev) temp->prev->next = new_node;
        else curr->child = new_node;
        new_node->prev = temp->prev;
        new_node->next = temp;
        temp->prev = new_node;
      }
      curr = new_node;
    }
  }

  DFS(root, -1);
  freeTree(root);

  return 0;
}