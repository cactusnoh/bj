#include <iostream>

struct Node {
  Node(int _key = 0) : key(_key) {}
  int key;
  Node *prev = nullptr, *next = nullptr;
};

int N, M;
Node pool[51], *head, *tail;
int pullout[51], pullCnt, min;

void insert(Node *n) 
{
  if(head == nullptr) {
    head = tail = n;
    n->prev = n; n->next = n;
    return;
  }

  n->next = tail->next;
  tail->next = n;
  n->prev = tail;
  tail = n;
  head->prev = n;
}

void remove(Node *n)
{
  if(head == n && tail == n) {
    head = tail = nullptr;
    return;
  }

  if(head == n)
    head = n->next;
  if(tail == n)
    tail = n->prev;

  n->prev->next = n->next;
  n->next->prev = n->prev;
}

void move(int r) 
{
  while(r < 0) {
    head = head->prev;
    tail = tail->prev;
    ++r;
  } 
  while(r > 0) {
    head = head->next;
    tail = tail->next;
    --r;
  }
}

int main()
{
  std::cin >> N >> M;
  for(int i = 0; i < M; ++i)
    std::cin >> pullout[pullCnt++];

  for(int i = 1; i <= N; ++i) {
    pool[i] = Node(i);
    insert(&pool[i]);
  }

  int pullIdx = 0;
  while(pullIdx < pullCnt) {
    int clock = 0, counter_clock = 0;
    Node *curr = head;
    while(curr->key != pullout[pullIdx]) {
      curr = curr->next;
      ++clock;
    }
    curr = head;
    while(curr->key != pullout[pullIdx]) {
      curr = curr->prev;
      --counter_clock;
    }

    move((clock > (-counter_clock) ? counter_clock : clock));
    remove(head);
    min += (clock > (-counter_clock) ? -counter_clock : clock);

    ++pullIdx;
  }

  std::cout << min << std::endl;

  return 0;
}